#include <iostream>
#include <list>

//Append ��� �߰�
//GetNodeAt Ž�� : ������ ��ġ ��� ��ȯ
//RemoveNode ��� ����
//Insert ��� ���� : ��� ��ġ�� �����ϰ� ���� �ִ� ���� �ڷ� �̷�
//GetNodeCount ��� ���� ����

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
	
	// ��� �߰� �ϼ� Append
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
			head->prev->next = tail; // head->prev �� ���� tail
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



	////////������� STL

	std::list<int> iList; // ǥ�ض��̺귯��(Standard Library)�� �����̳��̱� ������ std�� �ٴ´�.

	// ���� ���� �Լ�
	iList.push_back(10); // ������ ���� ����
	iList.push_front(20); // �Ӹ��� ���� ����

	// ���� ��ȯ �Լ�
	std::cout << iList.front() << " ";
	std::cout << iList.back() << std::endl;
	std::cout << std::endl;

	// iterator ��ȯ �Լ�
	std::list<int>::iterator it; // iterator�� ������ ���� �����̳��� ������ ����
	it = iList.begin();

	auto it2 = iList.end(); // end()�Լ��� �Ǹ����� ����� ������ ����Ų��.
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

	// ���� �Լ�
	iList.insert(it2,30); // ������ it2�ڸ��� �ִ� ���Ҹ� �ڷιо�� ���ο� ��� ����.

	// �ݺ��ڸ� �̿��� ��ȸ
	for (auto i = iList.begin(); i != iList.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	std::cout << iList.size() << std::endl; // ���� ���� ��ȯ
	std::cout << std::endl;

	// ��� ���� �Լ�
	iList.pop_back(); // ������ ��� ����
	for (auto i = iList.begin(); i != iList.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	iList.pop_front(); // ó�� ��� ����
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
	
	//iList.remove(20); // ���� ���� ���� ���� ����
	iList.remove_if([](int n) {return n > 20; }); // ���ǿ� �´� ���� ���� ����
	for (auto i = iList.begin(); i != iList.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	// �� ��
	// 
	// iList.reverse() // ���ҵ��� �������� ������
    // iList.sort() // ��� ���Ҹ� ������������ ����
	// iList.splice(iter,iList2) iList�� iter�� ����Ű�� ���� iList2�� ��� ���Ҹ� �߶� ����
	// iList.splice(iter,iList2,iter2)
	// iList.unique() // ������ ���Ұ� ������ �����ϰ� ����(�ߺ� ����)
	// iList.merge(iList2) // iList2�� iList ���η� �պ��ϰ� ������������ ����
	
}