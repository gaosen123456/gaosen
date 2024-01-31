#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
 
const int MaxSize = 100;
 
typedef struct SqQueue
{
	int* base;
	int front, rear;
}SqQueue;
 
bool InitQueue(SqQueue& Q)
{
	Q.base = new int[MaxSize];
	if (Q.base == NULL)
	{
		return false;
	}
	Q.front = Q.rear = 0;
	return true;
}
 
bool Push(SqQueue& Q, int e)
{
	if ((Q.rear + 1) % MaxSize == Q.front)
	{
		return false;
	}
 
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
 
}
 
bool Pop(SqQueue& Q, int& e)
{
	if (Q.rear == Q.front)
	{
		return false;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
}
 
int Get_front(SqQueue Q)
{
	if (Q.front == Q.rear)
	{
		return -1;
	}
 
	return Q.base[Q.front];
}
 
int Get_back(SqQueue Q)
{
	if (Q.front == Q.rear)
	{
		return -1;
	}
 
	return Q.base[Q.rear - 1];
}
 
int length(SqQueue Q)
{
	return (Q.rear - Q.front + MaxSize) % MaxSize;
 
	/*if (Q.rear - Q.front >= 0)
	{
		return Q.rear - Q.front;
	}
	else
	{
		return (Q.rear - Q.front + MaxSize);
	}*/
}
 
int main()
{
 
	SqQueue S;
	InitQueue(S);
 
	int n = 0;
	cout << "请输入有多少元素" << endl;
	cin >> n;
	cout << "依次输入元素" << endl;
	while (n--)
	{
		int e;
		cin >> e;
		Push(S, e);
	}
	int L = length(S);
	for (int i = 0; i < L; i++)
	{
		cout << "队尾:"<<Get_back(S) << " "<<"队头:"<<Get_front(S)<<"---";
 
		int e = 0;
		Pop(S, e);
		cout << e <<" ";
		cout << endl;
	}
	//cout << length(S);
	cout << endl;
 
 
 
 
	system("pause");
	return EXIT_SUCCESS;
}
