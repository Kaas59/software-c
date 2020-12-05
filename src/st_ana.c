#include <stdio.h>
#include "header.h"

extern MEM data[USERNUM];

ST_ANA st_ana(int user_device_num, int signal_id){
  ST_ANA st_data = {-1};
  int db_state = -1;
  for(int idx = 1; idx < USERNUM; idx++){
    if(data[idx].telnum == user_device_num){
      db_state = data[idx].state;
      break;
    }
  }
  
  if(db_state == -1) return st_data;

  switch(db_state){
    
  }

  switch(signal_id){
    case 0:
      if(db_state == 1) st_data.task = 510;
      else if(db_state == 2) st_data.task = 520;
      else if(db_state == 3) st_data.task = 530;
      else if(db_state == 4) st_data.task = 540;
      else ;// Task 異常な信号 
      break;
    case 1:
      if(db_state == 4) st_data.anal = 40;
      else ;// Task 異常な信号 
      break;
    case 2:
      if(db_state == 4) st_data.task = 514;
      else ;// Task 異常な信号 
      break;
    default:
      // Task 異常な信号
      break;
  }

  // 523
  
  // 
  // 40,41
  st_data.task = 500;
  st_data.anal = 40;
  return st_data;
}