#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include"header.h"

char* time_get(void);

int main(void)  //orgは発信端末,termは着信端末
{
    char* time_cat=NULL;
    time_cat = time_get();

    printf("%s\n",time_cat);
    free(time_cat);

    return 0;

    
}

char* time_get(void)
{
    time_t t = time(NULL);
	struct tm *local = localtime(&t);

	char buf[128];
    char* a=NULL;
	strftime(buf,sizeof(buf),"%Y/%m/%d %H:%M:%S %A",local);

    a = (char*)malloc(sizeof(char) * 27);

    if (a == NULL) {
        printf("配列作成失敗\n");
    }

    strcpy(a,buf);
    return a;
}