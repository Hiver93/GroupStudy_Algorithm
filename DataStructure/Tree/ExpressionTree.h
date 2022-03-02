#pragma once
#include "BinaryTree.h"
#include "ListStack.h"

static void ShowCharData(int data);

static class ExpressionTree
{
public:		
	static BTreeNode* MakeExpTree(const char exp[]);
	static int EvaluateExpTree(BTreeNode* bt);

	static void ShowPrefixTypeExp(BTreeNode* bt);
	static void ShowInfixTypeExp(BTreeNode* bt);
	static void ShowPostfixTypeExp(BTreeNode* bt);	
};

