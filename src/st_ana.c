#include <stdio.h>
#include "header.h"

extern MEM data[USERNUM];

ST_ANA st_ana(int user_device_num, int signal_id)
{
  ST_ANA st_data = { NULL };
  int db_state = -1;
  int db_terminal = -1;
  int db_or_ter_ident = -1;
  for(int idx = 1; idx < USERNUM; idx++)
  {
    if(data[idx].telnum % 1000 == user_device_num)
    {
      db_state = data[idx].state;
      db_terminal = data[idx].terminal;
      db_or_ter_ident = data[idx].or_ter_ident;
    }
  }

  switch(db_state)
  {
    case idle:
      if (signal_id == offhook)
      {
        st_data.anal = OR_ANA_FUNC;
      }
      else
      {
        printf("イベント(%d)は無効！\n",signal_id);
      }
      break;
    case dialtone:
      if (signal_id == onhook)
      {
        st_data.task = TASK10;
      }
      else if (signal_id == dial)
      {
        st_data.anal = NUM_ANA_FUNC;
      }
      else
      {
        printf("イベント(%d)は無効！\n",signal_id);
      }
      break;
    case ringing:
      if (signal_id == offhook && db_or_ter_ident == terminate)
      {
        st_data.task == TASK23;
        printf("[%d]=>呼び返し音切断\n",db_terminal);
        printf("[%d]=>呼び出し音切断\n",db_state);
        printf("[%d]と[%d]=>接続\n",db_terminal,db_state);
      }
      else if (signal_id == onhook && db_or_ter_ident == originate)
      {
        st_data.task = TASK20;
      }
      else
      {
        printf("イベント(%d)は無効！\n",signal_id);
      }
      break;
    case talk:
      if (signal_id == onhook)
      {
        st_data.task = TASK30;
      }
      else
      {
        printf("イベント(%d)は無効！\n",signal_id);
      }
      break;
    case busy:
      if (signal_id == onhook)
      {
        st_data.task = TASK40;
      }
      else
      {
        printf("イベント(%d)は無効！\n",signal_id);
      }
      break;
    default:
      printf("イベント(%d)は無効！\n",signal_id);
      break;
  }
  return st_data;
}