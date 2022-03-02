#include <iostream>
#include "LCRS_Tree.h"
#include "BinaryTree.h"
#include "ExpressionTree.h"
#include "ListStack.h"
void ShowIntData(int data);
int main()
{	
	
	// Left Child Right Sibling Tree
	{
		/*LCRS_Tree t;
		Node* A = t.CreateNode('A');
		t.SetRoot(A);
		Node* B = t.CreateNode('B');
		Node* C = t.CreateNode('C');
		Node* D = t.CreateNode('D');
		Node* E = t.CreateNode('E');
		Node* F = t.CreateNode('F');
		Node* G = t.CreateNode('G');
		Node* H = t.CreateNode('H');
		Node* I = t.CreateNode('I');
		Node* J = t.CreateNode('J');
		Node* K = t.CreateNode('K');

		t.AddChildNode(A, B);
		t.AddChildNode(B, C);
		t.AddChildNode(B, D);
		t.AddChildNode(D, E);
		t.AddChildNode(D, F);
		t.AddChildNode(A, G);
		t.AddChildNode(G, H);
		t.AddChildNode(A, I);
		t.AddChildNode(I, J);
		t.AddChildNode(J, K);

		t.PrintTree();
		t.PrintNodesAtLevel(2);
		t.PrintNodesAtLevel(3);

		t.DestroyTree();*/
	}

	// Binary Tree, Traverse
	{
		//BTreeNode* bt1 = BinaryTree::MakeTreeNode();
		//BTreeNode* bt2 = BinaryTree::MakeTreeNode();
		//BTreeNode* bt3 = BinaryTree::MakeTreeNode();
		//BTreeNode* bt4 = BinaryTree::MakeTreeNode();

		//BinaryTree::SetData(bt1, 1);
		//BinaryTree::SetData(bt2, 2);
		//BinaryTree::SetData(bt3, 3);
		//BinaryTree::SetData(bt4, 4);

		//BinaryTree::MakeLeftSubTree(bt1, bt2);
		//BinaryTree::MakeRightSubTree(bt1, bt3);
		//BinaryTree::MakeLeftSubTree(bt2, bt4);

		//printf("%d \n", BinaryTree::GetData(BinaryTree::GetLeftSubTree(bt1)));

		//printf("%d \n", BinaryTree::GetData(BinaryTree::GetLeftSubTree(BinaryTree::GetLeftSubTree(bt1))));
		//BinaryTree::InorderTraverse(bt1, ShowIntData);
		//printf("\n");
		//BinaryTree::DeleteTree(bt1);
	}

	//Expression Tree
	{
		BTreeNode* node = ExpressionTree::MakeExpTree("12+7*");
		ExpressionTree::ShowInfixTypeExp(node);
		std::cout << std::endl;
		std::cout << ExpressionTree::EvaluateExpTree(node);
	}
}

void ShowIntData(int data)
{
	printf("%d ", data);
}