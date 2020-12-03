#include<stdio.h>
#include"header.h"

extern MEM data[USERNUM];

void next_state(NMEM* m)
{
    int t_num;

    for(int i = 0; i < 3; i++)
    {
        if(m[i].flag == 1){

            t_num = m[i].ln;
            data[t_num].state = m[i].state;

        }

    }


}
