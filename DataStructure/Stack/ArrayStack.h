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

// CreateNewNode 노드 생성 함수
// RemoveNode 노드 삭제 함수
// Push 원소 삽입 함수
// Pop 원소 삭제 및 반환 함수
// GetCount 원소 개수 반환 함수
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

	~ArrayStack() // 포인터를 널값으로 바꿀 필요가 없기 때문에 delete만 이용하여 제거
	{
		while (0 <= top)
		{
			delete nodeList[top];
			top--;
		}
	}


};