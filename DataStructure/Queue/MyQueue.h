#pragma once
#include <vector>
#include <iostream>
using namespace std;
class MyQueue
{
private:
	vector<int> *queue;
	int front;
	int rear;
	int count;
	int size;

public:
	MyQueue(int);
	~MyQueue();
	void Enqueue(int i);
	int Dequeue();
	bool IsEmpty();
	bool IsFull();
	void PrintAll();
};

