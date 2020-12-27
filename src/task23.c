#include <stdio.h>
#include <time.h>
#include "header.h"
extern MEM data[USERNUM];
void task23(int ring_device_num, NMEM* db_update)
{
    int user_device_num;

    db_update[0].flag = 1;
    db_update[0].ln = ring_device_num;
    db_update[0].state = talk;        

    user_device_num = data[ring_device_num].terminal;

    db_update[1].flag = 1;
    db_update[1].ln = user_device_num;
    db_update[1].state = talk;

    time_t start_time;
    start_time = time(NULL); 

    output(disconnect, user_device_num, 12);
    output(disconnect, ring_device_num, 11);
    printf("[%d]と[%d]=>接続\n", user_device_num, ring_device_num);
    }
