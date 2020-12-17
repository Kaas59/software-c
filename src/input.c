#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include"header.h"

ST_ANA_TABLE st_ana_table;
MEM data[USERNUM]={
        {-1  , -1  ,-1,  -1,-1},
        {4001, idle, 0, YES, 0},
        {4002, idle, 0, YES, 0},
        {4003, idle, 0, YES, 0},
        {4004, idle, 0, YES, 0}
    };

int main(void)
{
    int set_or_number;
    int set_device_num;
    int user_device_num;
    int signal_id;
    int tel_num = -1;

    char set_device_num_c[30];

    printf("■□■□設計演習C Ver.1.3 ■□■□\n");

    while(1)
    {
        printf("初期設定変更を行いますか？Yes=1 No=0 >");
        scanf("%d",&set_or_number);

        if(set_or_number == 1)
        {
            printf("発信を許可しない端末番号入力>");
            scanf("%s",set_device_num_c);
            printf("1\n");
            if(isdigit(set_device_num_c[0]))
            {   
                printf("2\n");
                set_device_num = atoi(set_device_num_c);
                printf("3\n");
                if(0 < set_device_num && set_device_num < 5)
                {
                    printf("4\n");
                    set_device_num = atoi(set_device_num_c);
                    printf("5\n");
                    printf("端末[%d]を発信不可にしました. \n",set_device_num);
                    data[set_device_num].or_ac = NO;
                }
                else continue;
            }
            else continue;
            
        }

        else if(set_or_number == 0) break; //0入力で繰り返し終了
        
        else continue; //０と1以外は繰り返し
    }
    
    while(1)
    {
        printf("端末番号(1-4)>");
        scanf("%d",&user_device_num);

        if(user_device_num == 'q')
        {
            break;
        }

        if(0 < user_device_num && user_device_num <5)
        {
            printf("イベント(0:offhook   1:onhook   2:dial)>");
            scanf("%d",&signal_id);

            if(signal_id == 2)
            {
                printf("電話番号(4001-4004)>");
                scanf("%d",&tel_num);
            }

            tk_select(user_device_num,signal_id,tel_num);
        }

        else 
        {
            printf("端末番号無効です！"); 
            continue;
        }
    }

return 0;
}