#include <iostream>

//Append 노드 추가
//GetNodeAt 탐색 : 임의의 위치 노드 반환
//RemoveNode 노드 삭제
//Insert 노드 삽입 : 어느 위치에 삽입하고 원래 있던 것은 뒤로 미룸
//GetNodeCount 노드 개수 새기

class Node
{
public:
	int data;
	Node* prev = nullptr;
	Node* next = nullptr;
	Node(int i)
	{
		this->data = i;
	}
};

class CLinkedList
{
public:
	Node* head = nullptr;
	
	// 노드 추가 암수 Append
	void Append(int i)
	{
		if (head == nullptr)
		{
			head = new Node(i);
			head->next = head;
			head->prev = head;
		}
		else
		{
			Node* tail = new Node(i);
			head->prev->next = tail; // head->prev 은 기존 tail
			tail->prev = head->prev;
			tail->next = head;
			head->prev = tail;
		}
	}

	Node* GetNodeAt(int location)
	{
		Node* temp = head;
		while(temp->next != nullptr&&location != 0)
		{
			temp = temp->next;
			location--;
		}

		return temp;
	}

	void RemoveNode(Node* node)
	{
		if (head->next == head)
		{
			delete head;
		}
		else
		{
			node->next->prev = node->prev;
			node->prev->next = node->next;
			delete node;
		}
	}

	void Insert(Node* node, int i)
	{
		Node* temp = new Node(i);
		temp->prev = node->prev;
		node->prev = temp;
		temp->prev->next = temp;
		temp->next = node;
	}

	void Insert(int location, int i)
	{
		Insert(GetNodeAt(location), i);
	}

	int GetNodeCount()
	{
		int count = 1;
		Node* temp = head;

		while (temp->next != head)
		{
			temp = temp->next;
			count++;
		}

		return count;
	}

	~CLinkedList()
	{
		if (head != nullptr)
		{		 
			Node* temp = head; 
			temp = head->prev;
			temp->prev->next = nullptr;
			head->prev = nullptr;
			delete temp;
			head = head->next;

			while (head->next != nullptr)
			{
				temp = head->prev;
				head->prev = nullptr;
				delete temp;
				head = head->next;
			}
			delete head;
		}
	}
	
};

int main()
{
	CLinkedList* cLL = new CLinkedList();

	cLL->Append(1);
	cLL->Append(2);
	cLL->Append(3);
	cLL->Append(4);
	std::cout << cLL->head->prev->data << std::endl;
	//cLL->RemoveNode(cLL->GetNodeAt(3));
	std::cout << cLL->head->prev->data << std::endl;
	cLL->Insert(2, 2);
	std::cout << cLL->GetNodeCount() << std::endl;

	delete cLL;

	std::cout << 1 << std::endl;
	
}