#include <stdio.h>
#include "header.h"
extern MEM data[USERNUM];
void task12(int user_device_num, int ring_device_num, NMEM* db_update)
{
    db_update[0].flag = 1;
    db_update[0].ln = user_device_num;
    db_update[0].state = ringing;
    data[user_device_num].terminal = ring_device_num;
    data[user_device_num].or_ter_ident = originate;

    db_update[1].flag = 1;
    db_update[1].ln = ring_device_num;
    db_update[1].state = ringing; 
    data[ring_device_num].terminal = user_device_num;
    data[ring_device_num].or_ter_ident = terminate;
    

    next_state(db_update);

    output(disconnect, user_device_num, SR);
    output(disconnect, user_device_num, DIALTONE);
    output(connect, user_device_num, RINGBACKTONE);
    output(connect, ring_device_num, RINGINGTONE);

    call_register(-1, 0, user_device_num, ring_device_num, TASK12);
}
