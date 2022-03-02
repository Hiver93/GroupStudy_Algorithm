#pragma once
typedef int Data;
class Node
{
public:
	Data data;
	Node* next;
	Node(Data data)
	{
		this->data = data;
	}
};
class ListStack
{
private:
	Node* head;
public:
	ListStack();
	bool IsEmpty();
	void Push(Data data);
	Data Pop();
	Data SPeek();
};

