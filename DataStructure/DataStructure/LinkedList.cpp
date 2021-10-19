#include <iostream>
#include <list>

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

	std::cout << std::endl;
	std::cout << 0 << std::endl;
	std::cout << std::endl;



	////////여기부터 STL

	std::list<int> iList; // 표준라이브러리(Standard Library)의 컨테이너이기 때문에 std가 붙는다.

	// 원소 삽입 함수
	iList.push_back(10); // 꼬리로 원소 삽입
	iList.push_front(20); // 머리로 원소 삽입

	// 원소 반환 함수
	std::cout << iList.front() << " ";
	std::cout << iList.back() << std::endl;
	std::cout << std::endl;

	// iterator 반환 함수
	std::list<int>::iterator it; // iterator란 간단히 말해 컨테이너의 포인터 변수
	it = iList.begin();

	auto it2 = iList.end(); // end()함수는 맨마지막 노드의 다음을 가리킨다.
	it2--;

	std::cout << *it << " ";
	std::cout << *it2 << std::endl;

	std::cout << std::endl;
	auto it3 = iList.rbegin(); 
	auto it4 = iList.rend();
	it4--;

	std::cout << *it3 << " ";
	std::cout << *it4 << std::endl; 
	std::cout << std::endl;

	// 삽입 함수
	iList.insert(it2,30); // 원래의 it2자리에 있던 원소를 뒤로밀어내고 새로운 노드 삽입.

	// 반복자를 이용한 순회
	for (auto i = iList.begin(); i != iList.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	std::cout << iList.size() << std::endl; // 원소 개수 반환
	std::cout << std::endl;

	// 노드 제거 함수
	iList.pop_back(); // 마지막 노드 제거
	for (auto i = iList.begin(); i != iList.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	iList.pop_front(); // 처음 노드 제거
	for (auto i = iList.begin(); i != iList.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;


	iList.push_front(20);
	iList.push_front(10);		
	iList.push_back(40);
	iList.push_back(50);

	for (auto i = iList.begin(); i != iList.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	
	//iList.remove(20); // 같은 값을 가진 원소 제거
	iList.remove_if([](int n) {return n > 20; }); // 조건에 맞는 값의 원소 제거
	for (auto i = iList.begin(); i != iList.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	// 그 외
	// 
	// iList.reverse() // 원소들의 순차열을 뒤집음
    // iList.sort() // 모든 원소를 오름차순으로 정렬
	// iList.splice(iter,iList2) iList의 iter가 가리키는 곳에 iList2의 모든 원소를 잘라 붙임
	// iList.splice(iter,iList2,iter2)
	// iList.unique() // 인접한 원소가 같으면 유일하게 만듬(중복 제거)
	// iList.merge(iList2) // iList2를 iList 내부로 합병하고 오름차순으로 정렬
	
}