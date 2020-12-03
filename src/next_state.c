#include<stdio.h>
#include"header.h"

extern MEM data[USERNUM];

void next_state(NMEM* db)
{
    int user_device_num;

    for(int i = 0; i < 3; i++)
    {
        if(db[i].flag == 1){
            user_device_num = db[i].ln;
            data[user_device_num].state = db[i].state;
        }
    }
}
