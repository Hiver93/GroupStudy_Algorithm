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
		head = new Node(data);
	else
	{
		Node* temp = new Node(data);
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
		Node* node = head;
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