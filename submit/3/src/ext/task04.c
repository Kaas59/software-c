#include<stdio.h>
#include"header.h"

void task04(int user_device_num , NMEM* db_update)
{
    db_update[0].flag = 1;
    db_update[0].ln = user_device_num;
    db_update[0].state = busy;
    
    output(1,user_device_num,13);
}
