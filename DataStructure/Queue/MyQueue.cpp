#include "MyQueue.h"

MyQueue::MyQueue(int size)
{
	queue = new vector<int>(size+1);
	front = 0;
	rear = 0;
	this->size = size;
}
MyQueue::~MyQueue()
{
	delete queue;
}
void MyQueue::Enqueue(int i)
{
	if (!(IsFull()))
	{
		(*queue)[front++] = i;
		front %= size + 1;
	}
	else
	{
		cout << "Enqueue() error" << endl;
		exit(- 1);
	}
}
int MyQueue::Dequeue()
{
	if (!IsEmpty())
	{
		int temp = (*queue)[rear++];
		rear %= size + 1;
		return temp;
	}
	else
	{
		cout << "Dequeue() error" << endl;
		exit(-1);
	}
}
void MyQueue::PrintAll()
{
	int temp = rear;
	while(temp != front)
	{
		cout << (*queue)[temp++] << ' ';
		temp %= size + 1;
	}
	cout << endl;
}
bool MyQueue::IsEmpty()
{
	return !(front-rear);
}
bool MyQueue::IsFull()
{
	if (rear - front == 1||(rear == 0&&front == size))
	{
		return true;
	}
	return false;
}

int MyQueue::Peek()
{
	if (!(IsEmpty()))
	{
		return (*queue)[front];
	}
	else
	{
		cout << "Peek() error"<<endl;
		exit(-1);
	}
}

void MyQueue::Reset()
{
	front = 0;
	rear = 0;
}

void MyQueue::Reset(int size)
{
	front = 0;
	rear = 0;
	queue->resize(size);
	this->size = size;
}