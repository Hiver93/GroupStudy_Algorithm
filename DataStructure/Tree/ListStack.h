#pragma once

typedef int Data;
class StackNode
{
public:
	Data data;
	StackNode* next;
	StackNode(Data data)
	{
		this->data = data;
		next = nullptr;
	}
};
class ListStack
{
private:
	StackNode* head;
public:
	ListStack();
	bool IsEmpty();
	void Push(Data data);
	Data Pop();
	Data SPeek();
};

