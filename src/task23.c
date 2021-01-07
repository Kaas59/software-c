#include <stdio.h>
#include <time.h>
#include <string.h>
#include "header.h"
extern MEM data[USERNUM];
MEMT data_time[USERNUM] = {
    {-1, -1},
    {4001, -1},
    {4002, -1},
    {4003, -1},
    {4004, -1}
}; 

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

    char s[300] = {'\0'};
    time_t start_time;
    struct tm *timeptr;
    start_time = time(NULL); 
    timeptr = localtime(&start_time);

    strftime(s, 300, "%Y-%m-%d %H:%M:%S", timeptr);    

    strcpy(data_time[ring_device_num].talk_start_time,s);
    strcpy(data_time[user_device_num].talk_start_time,s);

    output(disconnect, user_device_num, 12);
    output(disconnect, ring_device_num, 11);
    printf("[%d]と[%d]=>接続\n", user_device_num, ring_device_num);
    }
