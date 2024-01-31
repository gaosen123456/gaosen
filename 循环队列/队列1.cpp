/*----------------------------------------------------------------
设立一个队首指针front ，一个队尾指针rear ，分别指向队首和队尾元素。

◆ 初始化：front=rear=0。
◆ 队列为空：front=rear。
◆ 队满：（rear + 1) % MaxSize == fornt
◆ 入队：将新元素插入rear所指的位置，然后rear加1。
◆ 出队：删去front所指的元素，然后加1并返回被删元素。
◆ 取队首元素：返回fornt指向的元素值
-----------------------------------------------------------------*/

#include<stdio.h>
#include<Windows.h>
#include<assert.h>

#define MaxSize 10
typedef int DataType;
typedef struct SeqQueue
{
    DataType Queue[MaxSize];
    int fornt;
    int rear;
}SeqCirQueue;

//队列初始化

void InitSeqCirQueue(SeqCirQueue* SCQ)
{
    SCQ->fornt = SCQ->rear = 0;
}

//判断队列是否为空
int IsEmpty(SeqCirQueue* SCQ)
{
    if (SCQ->fornt == SCQ->rear)
    {
        return 1;
    }
    return 0;
}

//判断队列是否为满
int IsFull(SeqCirQueue* SCQ)
{
    //尾指针+1追上队头指针，标志队列已经满了
    if ((SCQ->rear + 1) % MaxSize == SCQ->fornt)
    {
        return 1;
    }
    return 0;
}

//入队操作
int EnterSeqCirQueue(SeqCirQueue* SCQ, DataType data)
{
    if (IsFull(SCQ))
    {
        printf("队列已满，不能入队！\n");
        return 0;
    }
    SCQ->Queue[SCQ->rear] = data;
    SCQ->rear = (SCQ->rear + 1) % MaxSize;   //重新设置队尾指针
}


//出队操作
int DeleteSeqCirQueue(SeqCirQueue* SCQ,DataType* data)
{
    if (IsEmpty(SCQ))
    {
        printf("队列为空！\n");
        return 0;
    }
    *data = SCQ->Queue[SCQ->fornt];
    SCQ->fornt = (SCQ->fornt + 1) % MaxSize;  //重新设置队头指针
}

//取队首元素
int GetHead(SeqCirQueue* SCQ,DataType* data)
{
    if (IsEmpty(SCQ))
    {
        printf("队列为空！\n");
        return 0;
    }
    *data = SCQ->Queue[SCQ->fornt];
    return *data;
}

//清空队列
void ClearSeqCirQueue(SeqCirQueue* SCQ)
{
    SCQ->fornt = SCQ->rear = 0;
}

//打印队列元素
void PrintSeqCirQueue(SeqCirQueue* SCQ)
{
    assert(SCQ);   //断言SCQ不为空
    int i = SCQ->fornt;
    if (SCQ->fornt < SCQ->rear)
    {
        for (; i < SCQ->rear; i++)
        {
            printf("%-3d", SCQ->Queue[i]);
        }
    }
    else
    {
        for (i; i <SCQ->rear + MaxSize; i++)
        {
            printf("%-3d", SCQ->Queue[i]);
        }
    }
    printf("\n");
}

int main()
{
    SeqCirQueue SCQ;
    DataType data;
    //初始化队列
    InitSeqCirQueue(&SCQ);
    //入队
    EnterSeqCirQueue(&SCQ, 1);
    EnterSeqCirQueue(&SCQ, 2);
    EnterSeqCirQueue(&SCQ, 4);
    EnterSeqCirQueue(&SCQ, 6);
    EnterSeqCirQueue(&SCQ, 8);
    EnterSeqCirQueue(&SCQ, 9);
    EnterSeqCirQueue(&SCQ, 10);
    EnterSeqCirQueue(&SCQ, 12);
    EnterSeqCirQueue(&SCQ, 13);
    printf("队列中元素为：\n");
    //打印队列中元素
    PrintSeqCirQueue(&SCQ);
    EnterSeqCirQueue(&SCQ, 15);
    //出队
    DeleteSeqCirQueue(&SCQ, &data);
    printf("出队元素为：%d\n", data);
    printf("\n");
    printf("队列中元素为：\n");
    PrintSeqCirQueue(&SCQ);
    printf("15入队：\n");
    EnterSeqCirQueue(&SCQ, 15);
    printf("队列中元素为：\n");
    PrintSeqCirQueue(&SCQ);
    system("pause");
    return 0;
}
