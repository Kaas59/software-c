
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include"header.h"

char* time_get(void); 
void show_log(int count[USERNUM], int show_device_num);

extern MEM date[USERNUM];
extern MEMT data_time[USERNUM];

void call_register(int show_device_num, int show_or_record,int user_device_num, int ring_device_num, int task_num)
{
    static int count[USERNUM] = {0,0,0,0,0};
    char call_device_name[30]; 

    if(show_or_record == 1)
    {
        show_log(count,show_device_num);
    }

    else if(show_or_record == 0)
    {
        if(task_num == TASK12)
        {
            char* time_t12=NULL;
            time_t12 = time_get();

            switch (user_device_num)
            {
                case 1: strcpy(call_device_name, "端末1から不在着信:");
                    break;
                case 2: strcpy(call_device_name, "端末2から不在着信:");
                    break;
                case 3: strcpy(call_device_name, "端末3から不在着信:");
                    break;
                case 4: strcpy(call_device_name, "端末4から不在着信:");
                    break;
                default:
                    break;
            }

            switch (count[ring_device_num])
            {
                case 0:
                    strcpy(data_time[ring_device_num].log_1, call_device_name);
                    strcat(data_time[ring_device_num].log_1, time_t12);
                    count[ring_device_num]++;
                    break;
                
                case 1:
                    strcpy(data_time[ring_device_num].log_2, call_device_name);
                    strcat(data_time[ring_device_num].log_2, time_t12);
                    count[ring_device_num]++;
                    break;
                case 2:
                    strcpy(data_time[ring_device_num].log_3, call_device_name);
                    strcat(data_time[ring_device_num].log_3, time_t12);
                    count[ring_device_num]++;
                    break;
                case 3:
                    strcpy(data_time[ring_device_num].log_1, data_time[ring_device_num].log_2);
                    strcpy(data_time[ring_device_num].log_2, data_time[ring_device_num].log_3);
                    strcpy(data_time[ring_device_num].log_3, call_device_name);
                    strcat(data_time[ring_device_num].log_3, time_t12);
                    break;
            }
            free(time_t12);
        }

        else if(task_num == TASK23)
        {
            char* time_t23=NULL;
            time_t23 = time_get();

            switch (user_device_num)
            {
            case 1: strcpy(call_device_name, "端末1から着信　　:");
                break;
            case 2: strcpy(call_device_name, "端末2から着信　　:");
                break;
            case 3: strcpy(call_device_name, "端末3から着信　　:");
                break;
            case 4: strcpy(call_device_name, "端末4から着信　　:");
                break;
            default:
                break;
            }

            switch(count[ring_device_num])
            {
                case 1:
                    //data_time[ring_device_num].log_1 = "\0";
                    strcpy(data_time[ring_device_num].log_1, call_device_name);
                    strcat(data_time[ring_device_num].log_1, time_t23);

                    break;
                case 2:
                    strcpy(data_time[ring_device_num].log_2, call_device_name);
                    strcat(data_time[ring_device_num].log_2, time_t23);
                    break;
                case 3:
                    strcpy(data_time[ring_device_num].log_3, call_device_name);
                    strcat(data_time[ring_device_num].log_3, time_t23);                  
                    break;
            }
            free(time_t23);
        }
        else exit(1);
    }
    else exit(1);
}

char* time_get(void)
{
    time_t t = time(NULL);
	struct tm *local = localtime(&t);
	local->tm_hour += 9;

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

void show_log(int count[USERNUM], int show_device_num)
{
    char call_device_name[30];
    char strcmp_c[10];
    char strcmp_c2[10];
    char strcmp_c3[10];

    printf("\n-------------------------------------------------\n");
    printf("着信履歴を上から最新３件まで表示します\n");
        if(count[show_device_num] == 0)
        {
            printf("\n着信履歴はありません\n\n");
        }
        else if(count[show_device_num] == 1)
        {
            printf("(赤文字 → 不在着信   青文字 → 着信)\n");
            strncpy(strcmp_c, data_time[show_device_num].log_1+13, 6);
            strcmp_c[6] = '\0';   
            if(strcmp("不在",strcmp_c)==0)
            {
                printf("\x1b[31m%s\033[m\n",data_time[show_device_num].log_1);
            }
            else
            {
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_1);
            }
            printf("-------------------------------------------------\n");
        }
        else if(count[show_device_num] == 2)
        {
            printf("(赤文字 → 不在着信   青文字 → 着信)\n");
            strncpy(strcmp_c, data_time[show_device_num].log_1+13, 6);
            strcmp_c[6] = '\0'; 
            strncpy(strcmp_c2, data_time[show_device_num].log_2+13, 6);
            strcmp_c2[6] = '\0'; 
    
            if(strcmp("不在",strcmp_c)==0 && strcmp("不在",strcmp_c2)==0 )
            {
                printf("\x1b[31m%s\033[m\n",data_time[show_device_num].log_2);//赤
                printf("\x1b[31m%s\033[m\n",data_time[show_device_num].log_1);//赤
            }
            else if(strcmp("着信",strcmp_c)==0 && strcmp("不在",strcmp_c2)==0 )
            {
                printf("\x1b[31m%s\x1b[m\n",data_time[show_device_num].log_2);//赤
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_1);//青
            }
            else if(strcmp("着信",strcmp_c2)==0 && strcmp("不在",strcmp_c)==0 )
            {
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_2);//赤
                printf("\x1b[31m%s\x1b[m\n",data_time[show_device_num].log_1);//青
            }
            else
            {
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_2);//青
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_1);//青
            }
            printf("-------------------------------------------------\n");
        }
        else if(count[show_device_num] == 3)
        {
             printf("(赤文字 → 不在着信   青文字 → 着信)\n");
            strncpy(strcmp_c, data_time[show_device_num].log_1+13, 6);
            strcmp_c[6] = '\0'; 
            strncpy(strcmp_c2, data_time[show_device_num].log_2+13, 6);
            strcmp_c2[6] = '\0'; 
            strncpy(strcmp_c3, data_time[show_device_num].log_3+13, 6);
            strcmp_c3[6] = '\0'; 

            if(strcmp("不在",strcmp_c)==0 && strcmp("不在",strcmp_c2)==0 && strcmp("不在",strcmp_c3)==0)
            {
                printf("\x1b[31m%s\033[m\n",data_time[show_device_num].log_3);//赤
                printf("\x1b[31m%s\033[m\n",data_time[show_device_num].log_2);//赤
                printf("\x1b[31m%s\033[m\n",data_time[show_device_num].log_1);//赤
            }
            else if(strcmp("着信",strcmp_c)==0 && strcmp("着信",strcmp_c2)==0 && strcmp("不在",strcmp_c3)==0)
            {
                printf("\x1b[31m%s\x1b[m\n",data_time[show_device_num].log_3);//赤
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_2);//青
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_1);//青
            }
            else if(strcmp("着信",strcmp_c)==0 && strcmp("不在",strcmp_c2)==0 && strcmp("着信",strcmp_c3)==0)
            {
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_3);//青
                printf("\x1b[31m%s\x1b[m\n",data_time[show_device_num].log_2);//赤
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_1);//青
            }
            else if(strcmp("不在",strcmp_c)==0 && strcmp("着信",strcmp_c2)==0 && strcmp("着信",strcmp_c3)==0)
            {
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_3);//青
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_2);//青
                printf("\x1b[31m%s\x1b[m\n",data_time[show_device_num].log_1);//赤
            }
            else if(strcmp("着信",strcmp_c)==0 && strcmp("不在",strcmp_c2)==0 && strcmp("不在",strcmp_c3)==0)
            {
                printf("\x1b[31m%s\x1b[m\n",data_time[show_device_num].log_3);//赤
                printf("\x1b[31m%s\x1b[m\n",data_time[show_device_num].log_2);//赤
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_1);//青
            }
            else if(strcmp("不在",strcmp_c)==0 && strcmp("着信",strcmp_c2)==0 && strcmp("不在",strcmp_c3)==0)
            {
                printf("\x1b[31m%s\x1b[m\n",data_time[show_device_num].log_3);//赤
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_2);//青
                printf("\x1b[31m%s\x1b[m\n",data_time[show_device_num].log_1);//赤
            }
            else if(strcmp("不在",strcmp_c)==0 && strcmp("不在",strcmp_c2)==0 && strcmp("着信",strcmp_c3)==0)
            {
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_3);//青
                printf("\x1b[31m%s\x1b[m\n",data_time[show_device_num].log_2);//赤
                printf("\x1b[31m%s\x1b[m\n",data_time[show_device_num].log_1);//赤
            }
            else
            {
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_3);//青
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_2);//青
                printf("\x1b[34m%s\x1b[m\n",data_time[show_device_num].log_1);//青
            }
            printf("-------------------------------------------------\n");
        } 
}
