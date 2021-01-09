#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "header.h"
extern MEM data[USERNUM];
extern MEMT data_time[USERNUM];

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

    time_t end_time;
    end_time = time(NULL);

    struct tm timeptr;
    char *s =data_time[disconnect_device_num].talk_start_time;

    strptime(s,"%Y-%m-%d %H:%M:%S", &timeptr);

    time_t start_time = mktime(&timeptr);

    output(disconnect, disconnect_device_num, device_num);
    printf("料金：%d円\n", (int)(end_time - start_time)/2);
    output(connect, device_num, 13);
   
}