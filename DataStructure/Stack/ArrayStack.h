#pragma once
#include <vector>
class Node
{
public:
	double data;
	
	Node(double data)
	{
		this->data = data;
	}
};

// CreateNewNode ��� ���� �Լ�
// RemoveNode ��� ���� �Լ�
// Push ���� ���� �Լ�
// Pop ���� ���� �� ��ȯ �Լ�
// GetCount ���� ���� ��ȯ �Լ�
class ArrayStack
{
public:
	int capacity;
	int top = -1;	
	std::vector<Node*> nodeList;

	ArrayStack(int capacity)
	{
		this->capacity = capacity;
		nodeList.resize(capacity);
	}

	Node* CreateNewNode(double data)
	{
		return new Node(data);
	}

	void RemoveNode(int index)
	{
		delete nodeList[index];
		nodeList[index] = nullptr;
	}

	void Push(double data)
	{
		top++;
		nodeList[top] = CreateNewNode(data);
	}

	double Pop()
	{
		double returnData = nodeList[top]->data;
		RemoveNode(top);
		top--;
		return returnData;
	}

	int GetCount()
	{
		return top+1;
	}

	~ArrayStack() // �����͸� �ΰ����� �ٲ� �ʿ䰡 ���� ������ delete�� �̿��Ͽ� ����
	{
		while (0 <= top)
		{
			delete nodeList[top];
			top--;
		}
	}


};