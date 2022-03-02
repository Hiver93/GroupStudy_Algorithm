#include "ListStack.h"
ListStack::ListStack()
{
	head = nullptr;
}
bool ListStack::IsEmpty()
{
	if (head == nullptr)
		return 1;
	return 0;
}
void ListStack::Push(Data data)
{
	if (head == nullptr)
		head = new StackNode(data);
	else
	{
		StackNode* temp = new StackNode(data);
		temp->next = head;
		head = temp;
	}
}
Data ListStack::Pop()
{
	Data temp;
	temp = head->data;
	if (head->next != nullptr)
	{
		StackNode* node = head;
		head = head->next;
		delete node;
	}
	else
	{
		delete head;
		head = nullptr;
	}

	return temp;
}
Data ListStack::SPeek()
{
	return head->data;
}