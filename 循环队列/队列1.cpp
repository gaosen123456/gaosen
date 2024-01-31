/*----------------------------------------------------------------
����һ������ָ��front ��һ����βָ��rear ���ֱ�ָ����׺Ͷ�βԪ�ء�

�� ��ʼ����front=rear=0��
�� ����Ϊ�գ�front=rear��
�� ��������rear + 1) % MaxSize == fornt
�� ��ӣ�����Ԫ�ز���rear��ָ��λ�ã�Ȼ��rear��1��
�� ���ӣ�ɾȥfront��ָ��Ԫ�أ�Ȼ���1�����ر�ɾԪ�ء�
�� ȡ����Ԫ�أ�����forntָ���Ԫ��ֵ
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

//���г�ʼ��

void InitSeqCirQueue(SeqCirQueue* SCQ)
{
    SCQ->fornt = SCQ->rear = 0;
}

//�ж϶����Ƿ�Ϊ��
int IsEmpty(SeqCirQueue* SCQ)
{
    if (SCQ->fornt == SCQ->rear)
    {
        return 1;
    }
    return 0;
}

//�ж϶����Ƿ�Ϊ��
int IsFull(SeqCirQueue* SCQ)
{
    //βָ��+1׷�϶�ͷָ�룬��־�����Ѿ�����
    if ((SCQ->rear + 1) % MaxSize == SCQ->fornt)
    {
        return 1;
    }
    return 0;
}

//��Ӳ���
int EnterSeqCirQueue(SeqCirQueue* SCQ, DataType data)
{
    if (IsFull(SCQ))
    {
        printf("����������������ӣ�\n");
        return 0;
    }
    SCQ->Queue[SCQ->rear] = data;
    SCQ->rear = (SCQ->rear + 1) % MaxSize;   //�������ö�βָ��
}


//���Ӳ���
int DeleteSeqCirQueue(SeqCirQueue* SCQ,DataType* data)
{
    if (IsEmpty(SCQ))
    {
        printf("����Ϊ�գ�\n");
        return 0;
    }
    *data = SCQ->Queue[SCQ->fornt];
    SCQ->fornt = (SCQ->fornt + 1) % MaxSize;  //�������ö�ͷָ��
}

//ȡ����Ԫ��
int GetHead(SeqCirQueue* SCQ,DataType* data)
{
    if (IsEmpty(SCQ))
    {
        printf("����Ϊ�գ�\n");
        return 0;
    }
    *data = SCQ->Queue[SCQ->fornt];
    return *data;
}

//��ն���
void ClearSeqCirQueue(SeqCirQueue* SCQ)
{
    SCQ->fornt = SCQ->rear = 0;
}

//��ӡ����Ԫ��
void PrintSeqCirQueue(SeqCirQueue* SCQ)
{
    assert(SCQ);   //����SCQ��Ϊ��
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
    //��ʼ������
    InitSeqCirQueue(&SCQ);
    //���
    EnterSeqCirQueue(&SCQ, 1);
    EnterSeqCirQueue(&SCQ, 2);
    EnterSeqCirQueue(&SCQ, 4);
    EnterSeqCirQueue(&SCQ, 6);
    EnterSeqCirQueue(&SCQ, 8);
    EnterSeqCirQueue(&SCQ, 9);
    EnterSeqCirQueue(&SCQ, 10);
    EnterSeqCirQueue(&SCQ, 12);
    EnterSeqCirQueue(&SCQ, 13);
    printf("������Ԫ��Ϊ��\n");
    //��ӡ������Ԫ��
    PrintSeqCirQueue(&SCQ);
    EnterSeqCirQueue(&SCQ, 15);
    //����
    DeleteSeqCirQueue(&SCQ, &data);
    printf("����Ԫ��Ϊ��%d\n", data);
    printf("\n");
    printf("������Ԫ��Ϊ��\n");
    PrintSeqCirQueue(&SCQ);
    printf("15��ӣ�\n");
    EnterSeqCirQueue(&SCQ, 15);
    printf("������Ԫ��Ϊ��\n");
    PrintSeqCirQueue(&SCQ);
    system("pause");
    return 0;
}
