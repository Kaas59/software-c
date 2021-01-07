#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

CALL_REGISTER_TER1 call_register_ter1;

//CALL_REGISTER_TER1 call_register_tell1[USERNUM]={}      


int main(void)
{
    int set_or_number;
    int set_device_num;
    int user_device_num;
    int signal_id;
    int tel_num = -1;

    char set_device_num_c[30];
    char device_info[30]; //iの入力で個別データ情報の可視化
    char show_select[30]; //1か0で続けて情報をみるかを選択
    char device_info_c1[4][30];
    char device_info_c2[4][30];
    char device_info_c3[4][30];
    char log_device_num[30];

    printf("■□■□設計演習C Ver.1.3 ■□■□\n");

    while(1)
    {
        printf("初期設定変更を行いますか？Yes=1 No=0 >");
        scanf("%d",&set_or_number);

        if(set_or_number == 1)
        {
            printf("発信を許可しない端末番号入力>");
            scanf("%s",set_device_num_c);
            if(isdigit(set_device_num_c[0]))
            {   
                set_device_num = atoi(set_device_num_c);
                if(0 < set_device_num && set_device_num < 5)
                {
                    set_device_num = atoi(set_device_num_c);
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
        printf("端末番号(1-4), 着信履歴の参照(5) ->");
        scanf("%d",&user_device_num);

        if(user_device_num == 5)
        {
            while(1)
            {
                printf("どの端末の着信履歴を参照しますか？\n");
                printf("端末番号(1-4)->");
                scanf("%s",log_device_num);

                switch (log_device_num[0])
                {
                case '1': call_register(1,1);
                    break;
                case '2': call_register(2,1);
                    break;
                case '3': call_register(3,1);
                    break;
                case '4': call_register(4,1);
                    break;
                default:
                    break;
                } //参照は1、履歴の追加は0を第二引数に追加
                
                while(1)
                {
                    printf("他の情報見ますか？ Yes=1 No=0 >");
                    scanf("%s",show_select);
                    if(show_select[0] == '1' || show_select[0] == '0') break;
                }

                if     (show_select[0] == '1') continue;
                else if(show_select[0] == '0') break;
            }
            break;
        }

        if(user_device_num == 'q')
        {
            break;
        }

        if(user_device_num == 9)  //本当ならiの入力時にこのプログラムが実行される
        {
            while(1)
            { //printf("%d, %d, %d, %d", data[1].state,data[2].state, data[3].state, data[4].state); デバック

                printf("個別データ情報\n");
                printf("状態(1),発信を拒否する端末(2),相手端末(3),発着識別子(4)>");
                scanf("%s",device_info);

                switch(device_info[0]) //最初の文字で判断。
                {
                    case '1':
                        for(int x1=1; x1<5; x1++)
                        {
                            if(data[x1].state == idle) strcpy(device_info_c1[x1-1], "idle");
                            if(data[x1].state == dialtone) strcpy(device_info_c1[x1-1], "dialtone");
                            if(data[x1].state == ringing) strcpy(device_info_c1[x1-1], "ringing");
                            if(data[x1].state == talk) strcpy(device_info_c1[x1-1], "talk");
                            if(data[x1].state == busy) strcpy(device_info_c1[x1-1], "busy");
                        }

                        printf("Terminal    State\n-------------------\n");
                        printf("       1      %s\n",device_info_c1[0]);
                        printf("       2      %s\n",device_info_c1[1]);
                        printf("       3      %s\n",device_info_c1[2]);
                        printf("       4      %s\n",device_info_c1[3]);
                        break;

                    case '2':
                        for(int x2=1; x2<5; x2++)
                        {
                            if(data[x2].or_ac == NO) strcpy(device_info_c2[x2-1], "DENIAL");
                            if(data[x2].or_ac == YES) strcpy(device_info_c2[x2-1], "ACCEPT");
                        }
                        
                        printf("Terminal   Accept Flag\n------------------------\n");
                        printf("       1        %s\n",device_info_c2[0]);
                        printf("       2        %s\n",device_info_c2[1]);
                        printf("       3        %s\n",device_info_c2[2]);
                        printf("       4        %s\n",device_info_c2[3]);
                        break;
                    
                    case '3':
                        printf("Terminal   Remote \n--------------------\n");
                        printf("       1        %d\n",data[1].terminal);
                        printf("       2        %d\n",data[2].terminal);
                        printf("       3        %d\n",data[3].terminal);
                        printf("       4        %d\n",data[4].terminal);
                        break;
                    
                    case '4':
                        for(int x3=1; x3<5; x3++)
                        {
                            if(data[x3].or_ter_ident == terminate  || data[x3].or_ter_ident == 0) strcpy(device_info_c3[x3-1], "TERMINATE");
                            if(data[x3].or_ter_ident == originate) strcpy(device_info_c3[x3-1], "ORIGINATE");
                        }

                        printf("Terminal   Accept Flag\n------------------------\n");
                        printf("       1        %s\n",device_info_c3[0]);
                        printf("       2        %s\n",device_info_c3[1]);
                        printf("       3        %s\n",device_info_c3[2]);
                        printf("       4        %s\n",device_info_c3[3]);
                        break;

                    default:
                        break;
                }

                while(1)
                {
                    printf("他の情報見ますか？ Yes=1 No=0 >");
                    scanf("%s",show_select);
                    if(show_select[0] == '1' || show_select[0] == '0') break;
                }

                if     (show_select[0] == '1') continue;
                else if(show_select[0] == '0') break;
            }
            continue;
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

        if(user_device_num == 5)
        {
            
        }

        else 
        {
            printf("端末番号無効です！\n"); 
            continue;
        }
    }

return 0;
}

