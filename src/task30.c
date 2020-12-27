#include <stdio.h>
#include <time.h>
#include "header.h"
extern MEM data[USERNUM];
extern int start_time;

void task30(int disconnect_device_num, NMEM* db_update)
{
    int device_num;
    device_num = data[disconnect_device_num].terminal;

    db_update[0].flag = 1;
    db_update[0].ln = disconnect_device_num;
    db_update[0].state = idle;
    db_update[1].flag = 1;
    db_update[1].ln = device_num;
    db_update[1].state = busy;

/*
料金計算
task23で入手したstart_timeのもってきかたが分からなかった。
    time_t end_time;
    end_time = time(NULL);

    int talk_time;
    int money;
    talk_time = end_time - start_time;
    money = talk_time/2;
*/
    printf("[%d]と[%d]=>切断\n", disconnect_device_num, device_num);
    //printf("料金：%d円\n", money);
    output(connect, device_num, 13);
   
}
