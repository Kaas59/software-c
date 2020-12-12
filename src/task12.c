#include <stdio.h>
#include "header.h"

void task12(int user_device_num, int ring_device_num, NMEM* db_update)
{
    db_update[2].flag = 1;
    db_update[2].ln = user_device_num;
    db_update[2].state = 2; 

next_state(db_update);

output(disconnect, t12, SR);
output(disconnect, t12, DIALTONE);
output(connect, t12, RINGBACKTONE);
output(connect, ta12, RINGINGTONE);
}
