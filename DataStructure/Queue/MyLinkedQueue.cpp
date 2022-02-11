#include "MyLinkedQueue.h"

MyLinkedQueue::MyLinkedQueue()
{
}

MyLinkedQueue::~MyLinkedQueue()
{
	Reset();
}

Node* MyLinkedQueue::CreateNode(int i)
{
	return new Node(i);
}
void MyLinkedQueue::Enqueue(int i)
{
	if (head == nullptr)
	{
		head = CreateNode(i);
		tail = head;
	}
	else
	{
		tail->next = CreateNode(i);
		tail = tail->next;
	}
}
int MyLinkedQueue::Dequeue()
{
	int temp = head->data;
	Node* node = head;
	head = head->next;
	delete node;
	return temp;
}
bool MyLinkedQueue::IsEmpty()
{
	if (head == nullptr)
		return true;
	return false;
}
void MyLinkedQueue::PrintAll()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
}
int MyLinkedQueue::Peek()
{
	return head->data;
}
void MyLinkedQueue::Reset()
{
	Node* temp = head;
	Node* obj;
	while (temp != nullptr)
	{
		obj = temp;
		temp = temp->next;
		delete obj;
	}
}
