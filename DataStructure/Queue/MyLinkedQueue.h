#pragma once
#include <list>
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next = nullptr;

	Node(int i)
	{
		this->data = i;
	}
};

class MyLinkedQueue
{
private:
	Node* head;
	Node* tail;
	Node* CreateNode(int i);
public:
	MyLinkedQueue();
	~MyLinkedQueue();
	void Enqueue(int i);
	int Dequeue();
	bool IsEmpty();
	bool IsFull();
	void PrintAll();
	int Peek();
	void Reset();
	void Reset(int size);
};

