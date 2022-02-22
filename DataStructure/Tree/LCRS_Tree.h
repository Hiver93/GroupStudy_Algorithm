#pragma once
#include <iostream>

class Node {
public:
	Node* LeftChild;
	Node* RightSibling;
	char data;
	Node(int data);
	void SetLeftChild(Node* node);
	void SetRightSibling(Node* node);
};

class LCRS_Tree
{
private:
	Node* root;
	void PrintTree(Node* node, int depth);
public:
	LCRS_Tree();
	void SetRoot(Node* node);
	Node* CreateNode(char data);
	void AddChildNode(Node* parent, Node* child);
	void PrintTree();
};