#include<stdio.h>
#include"header.h"

void task04(int id , NMEM* a)
{
    a[0].flag = 1;
    a[0].ln = id;
    a[0].state = 4;
    
    output(1,id,13);
}