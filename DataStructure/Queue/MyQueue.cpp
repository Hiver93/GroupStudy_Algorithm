#include "MyQueue.h"

MyQueue::MyQueue(int size)
{
	queue = new vector<int>(size+1);
	front = 0;
	rear = 0;
	count = 0;
	this->size = size;
}
MyQueue::~MyQueue()
{
	delete queue;
}
void MyQueue::Enqueue(int i)
{
	(*queue)[front++] = i;
	front %= size+1;
	count++;
}
int MyQueue::Dequeue()
{
	int temp = (*queue)[rear++];
	rear %= size+1;
	count--;
	return temp;
}
void MyQueue::PrintAll()
{
	int temp = rear;
	while(temp != front)
	{
		cout << (*queue)[temp++] << ' ';
		temp %= size + 1;
	}
}
bool MyQueue::IsEmpty()
{
	return !(front-rear);
}
bool MyQueue::IsFull()
{
	return count;
}
