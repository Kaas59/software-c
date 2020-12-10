#include <stdio.h>
#include "header.h"

extern MEM data[USERNUM];

ST_ANA st_ana(int user_device_num, int signal_id)
{
  ST_ANA st_data = {-1};
  int db_state = -1;
  for(int idx = 1; idx < USERNUM; idx++)
  {
    // printf("==============\ntelnum：%d\nstate：%d\nterminal：%d\nor_ac：%d\nor_ter_ident：%d\n==============\n",&data[idx].telnum,&data[idx].state,&data[idx].terminal,&data[idx].or_ac,&data[idx].or_ter_ident);
    if(data[idx].telnum%4000 == user_device_num)
    {
      // printf("端末確認：%d\n",data[idx].telnum%4000);
      db_state = data[idx].state;
      break;
    }
  }

  switch(db_state)
  {
    case 0:
      if (signal_id == 0)
      {
        st_data.anal = 40;
      }
      else
      {
        printf("異常検知①\n");
      }
      break;
    case 1:
      if (signal_id == 1)
      {
        st_data.task = 510;
      }
      else if (signal_id == 2)
      {
        st_data.anal = 41;
      }
      else
      {
        printf("異常検知②\n");
      }
      break;
    case 2:
      if (signal_id == 0)
      {
        st_data.task == 523;
      }
      else if (signal_id == 1)
      {
        st_data.task = 520;
      }
      else
      {
        printf("異常検知③\n");
      }
      break;
    case 3:
      if (signal_id == 1)
      {
        st_data.task = 530;
      }
      else
      {
        printf("異常検知④\n");
      }
      break;
    case 4:
      if (signal_id == 1)
      {
        st_data.task = 540;
      }
      else
      {
        printf("異常検知⑤\n");
      }
      break;
    default:
      printf("異常検知⑥\n");
      break;
    }
  return st_data;
}