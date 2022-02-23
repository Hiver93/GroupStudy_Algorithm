#include "LCRS_Tree.h"


Node::Node(int data)
{
	LeftChild = nullptr;
	RightSibling = nullptr;
	this->data = data;
}
void Node::SetLeftChild(Node* node)
{
	if (LeftChild == nullptr)
		LeftChild = node;
	else
	{
		Node* temp = LeftChild;
		while (temp->RightSibling != nullptr)
			temp = temp->RightSibling;
		temp->RightSibling = node;
	}
}
void Node::SetRightSibling(Node* node)
{
	RightSibling = node;
}


void LCRS_Tree::PrintTree(Node* node, int depth)
{
	for (int i = 0; i < depth; i++)
		std::cout << ' ';
	std::cout << node->data;
	std::cout << std::endl;
	if (node->LeftChild != nullptr)
	{
		PrintTree(node->LeftChild, depth + 1);
	}
	if (node->RightSibling != nullptr)
	{
		PrintTree(node->RightSibling, depth);
	}
}
LCRS_Tree::LCRS_Tree()
{
	root = nullptr;
}
void LCRS_Tree::SetRoot(Node* node)
{
	root = node;
}
Node* LCRS_Tree::CreateNode(char data)
{
	Node* temp = new Node(data);
	return temp;
}
void LCRS_Tree::DestroyTree()
{
	if (root != nullptr)
	{
		if (root->LeftChild != nullptr)
		{
			DestroyTree(root->LeftChild);
		}
		delete root;
		root = nullptr;
	}
}
void LCRS_Tree::DestroyTree(Node* node)
{
	if (node->RightSibling != nullptr)
		DestroyTree(node->RightSibling);
	if (node->LeftChild != nullptr)
		DestroyTree(node->LeftChild);
	delete node;
	
}
void LCRS_Tree::AddChildNode(Node* parent, Node* child)
{
	parent->SetLeftChild(child);
}
void LCRS_Tree::PrintTree()
{
	Node* temp = root;
	std::cout << temp->data;
	std::cout << std::endl;
	if (temp->LeftChild != nullptr)
		PrintTree(temp->LeftChild, 1);
}
void LCRS_Tree::PrintNodesAtLevel(Node* node, int level)
{
	if (level == 0)
	{
		std::cout << node->data << ' '; 
		while (node->RightSibling != nullptr)
		{
			node = node->RightSibling;
			std::cout << node->data << ' ';
		}
	}
	else
	{
		if (node->LeftChild != nullptr)
			PrintNodesAtLevel(node->LeftChild, level - 1);
		if (node->RightSibling != nullptr)
			PrintNodesAtLevel(node->RightSibling, level);
	}
}
void LCRS_Tree::PrintNodesAtLevel(int level)
{
	if (level == 0)
		std::cout << root->data << ' ';
	else
		PrintNodesAtLevel(root->LeftChild, level - 1);
	std::cout << std::endl;
}