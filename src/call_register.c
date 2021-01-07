#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include"header.h"

extern MEM date[USERNUM];
extern CALL_REGISTER_TER1 call_register_ter1[USERNUM];

CALL_REGISTER_TER1 *head = NULL; // リストの先頭
CALL_REGISTER_TER1 *tail = NULL; // リストの末尾
CALL_REGISTER_TER1 *createNode(void);

CALL_REGISTER_TER2 *head2 = NULL; // リストの先頭
CALL_REGISTER_TER2 *tail2 = NULL; // リストの末尾
CALL_REGISTER_TER2 *createNode2(void);

CALL_REGISTER_TER3 *head3 = NULL; // リストの先頭
CALL_REGISTER_TER3 *tail3 = NULL; // リストの末尾
CALL_REGISTER_TER3 *createNode3(void);

CALL_REGISTER_TER4 *head4 = NULL; // リストの先頭
CALL_REGISTER_TER4 *tail4 = NULL; // リストの末尾
CALL_REGISTER_TER4 *createNode4(void);

void addNodeToList(int origginate_device);
void printList(int originate_device);
char* time_get(void);



void call_register(int originate_device, int show_or_append)  //orgは発信端末,termは着信端末
{
    
addNodeToList(originate_device);


   if(show_or_append == 1) printList(originate_device);

}

void addNodeToList(int originate_device)
{
    CALL_REGISTER_TER1 *newNodePos;
    
    //call_register_ter1[originate_device] = *newNodePos;

    char* time_cat=NULL;
    time_cat = time_get();//時間取得

    // 新しいノードを作成。(1)
    newNodePos = createNode();

    newNodePos->callee_num = originate_device;
    strcpy(newNodePos->time, time_cat);
    free(time_cat);//解放
    
    
    if ((head == NULL) && (tail == NULL))
    {
        // リストが空の場合はこちら。
        // 新しいノードが、先頭かつ末尾になる。
        head = newNodePos;
        tail = newNodePos;
    }
    else
    {
        // リストに1件以上ノードが存在する場合はこちら。
        // 末尾ノード(tail)のnextに、新しいノードの場所をセット。
        tail->next = newNodePos;
        // 追加した新しいノードをtailとする。
        tail = newNodePos;
    }
    // 次のデータは無いので、nextにはNULLをセット。
    tail ->next = NULL;
    //printf("ノードを追加しました。\n");
}
    

CALL_REGISTER_TER1 *createNode(void)  // ノードを生成する関数。
{
    // 新しいノード1個分のメモリを確保し、その場所を返します。
    CALL_REGISTER_TER1 *newNodePos;
    newNodePos = (CALL_REGISTER_TER1 *)malloc(sizeof(CALL_REGISTER_TER1));
    return newNodePos;
}

CALL_REGISTER_TER2 *createNode2(void)  // ノードを生成する関数。
{
    // 新しいノード1個分のメモリを確保し、その場所を返します。
    CALL_REGISTER_TER2 *newNodePos;
    newNodePos = (CALL_REGISTER_TER2 *)malloc(sizeof(CALL_REGISTER_TER2));
    return newNodePos;
}

CALL_REGISTER_TER3 *createNode3(void)  // ノードを生成する関数。
{
    // 新しいノード1個分のメモリを確保し、その場所を返します。
    CALL_REGISTER_TER3 *newNodePos;
    newNodePos = (CALL_REGISTER_TER3 *)malloc(sizeof(CALL_REGISTER_TER3));
    return newNodePos;
}

CALL_REGISTER_TER4 *createNode4(void)  // ノードを生成する関数。
{
    // 新しいノード1個分のメモリを確保し、その場所を返します。
    CALL_REGISTER_TER4 *newNodePos;
    newNodePos = (CALL_REGISTER_TER4 *)malloc(sizeof(CALL_REGISTER_TER4));
    return newNodePos;
}
char* time_get(void)    //時間取得関数
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


void printList(int originate_device)
{
    CALL_REGISTER_TER1 *current;
    call_register_ter1[originate_device] = *current;

    if ((head == NULL) && (tail == NULL))
    {
        // 表示するものがない場合は何もせずにreturn。
        printf("リストは空です。\n");
        return;
    }
    // 先頭から表示するので、現在の位置をheadにセット。
    current = head;

    printf("<着信履歴>＊＊＊＊＊＊＊＊＊＊＊＊\n");
    while (1)
    {
        printf("相手の端末番号   : %d\n", current->callee_num);
        printf("掛かってきた時刻 : %s\n", current->time);
        printf("--------------------------------------------\n");
        if (current->next != NULL)
        {
            // 次の場所がNULLではない、つまり次のノードがある。
            // 現在の場所を次のノードに移動します。
            current = current->next;
        }
        else
        {
            // 次の場所がNULLなら、現在の場所はリストの末尾。
            // もう次のデータはないので、breakでループ終了。
            printf("最後まで表示しました。\n");
            printf("＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊\n\n");
            break;
        }
    }
}