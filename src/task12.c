#include <stdio.h>
#include "header.h"

void task12(int t12, int ta12, NMEM* jo)
{
    jo[2].flag = 1;
    jo[2].ln = t12; //端末番号
    jo[2].state = 2; //次状態(ringing)

next_state(jo);

output(disconnect, t12, SR);
output(disconnect, t12, DIALTONE);
output(connect, t12, RINGBACKTONE);
output(connect, ta12, RINGINGTONE);
}