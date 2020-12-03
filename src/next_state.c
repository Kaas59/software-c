#include<stdio.h>
#include"header.h"

extern MEM data[USERNUM];

void next_state(NMEM* db)
{
    int t_num;

    for(int i = 0; i < 3; i++)
    {
        if(db[i].flag == 1){

            t_num = db[i].ln;
            data[t_num].state = db[i].state;

        }

    }


}
