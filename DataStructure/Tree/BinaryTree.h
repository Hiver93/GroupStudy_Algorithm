#pragma once
#include <iostream>
typedef struct _bTreeNode
{
	int data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

typedef void(*VisitFuncPtr)(int data);

static class BinaryTree
{
public:
	static BTreeNode* MakeTreeNode();
	static int GetData(BTreeNode* bt);
	static void SetData(BTreeNode* bt, int data);

	static BTreeNode* GetLeftSubTree(BTreeNode* bt);
	static BTreeNode* GetRightSubTree(BTreeNode* bt);

	static void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
	static void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);	

	static void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
	static void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
	static void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);
	static void DeleteTree(BTreeNode* bt);
};

