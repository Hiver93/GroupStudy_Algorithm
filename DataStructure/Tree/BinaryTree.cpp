#include "BinaryTree.h"

BTreeNode* BinaryTree::MakeTreeNode()
{
	BTreeNode* temp = new BTreeNode();
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}
int BinaryTree::GetData(BTreeNode* bt)
{
	return bt->data;
}
void BinaryTree::SetData(BTreeNode* bt, int data)
{
	bt->data = data;
}

BTreeNode* BinaryTree::GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}
BTreeNode* BinaryTree::GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}
void BinaryTree::MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != nullptr)
		delete main->left;
	main->left = sub;
}
void BinaryTree::MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != nullptr)
		delete main->right;
	main->right = sub;
}

void BinaryTree::PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr)
		return;
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}
void BinaryTree::InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr)
		return;
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}
void BinaryTree::PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr)
		return;
	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

void BinaryTree::DeleteTree(BTreeNode* bt)
{
	if (bt == nullptr)
		return;
	DeleteTree(bt->left);
	DeleteTree(bt->right);
	printf("지워진 트리의 데이터: %d\n", bt->data);
	delete bt;
}