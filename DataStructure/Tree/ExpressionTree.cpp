#include "ExpressionTree.h"

BTreeNode* ExpressionTree::MakeExpTree(const char exp[])
{	
	ListStack stack;
	int i = 0;
	while (exp[i] != '\0')
	{
		if (0 <= exp[i] - '0' && 9 >= exp[i] - '0')
		{
			BTreeNode* node = new BTreeNode();
			BinaryTree::SetData(node, exp[i]);
			stack.Push((Data)node);
		}
		else
		{
			BTreeNode* node = new BTreeNode();
			BinaryTree::SetData(node, exp[i]);
			BinaryTree::MakeRightSubTree(node, (BTreeNode*)stack.Pop());
			BinaryTree::MakeLeftSubTree(node, (BTreeNode*)stack.Pop());
			stack.Push((Data)node);
		}
		i++;
	}


	return (BTreeNode*)stack.Pop();

}
int ExpressionTree::EvaluateExpTree(BTreeNode* bt)
{
	if(bt->data-'0' <= 9 && 0<= bt->data-'0')
		return bt->data-'0';
	else
		switch (bt->data)
		{
		case '+':
		{
			return EvaluateExpTree(bt->left) + EvaluateExpTree(bt->right);
		}
		case '-':
		{
			return EvaluateExpTree(bt->left) - EvaluateExpTree(bt->right);
		}
		case '*':
		{
			return EvaluateExpTree(bt->left) * EvaluateExpTree(bt->right);
		}
		case '/':
		{
			return EvaluateExpTree(bt->left) / EvaluateExpTree(bt->right);
		}
		default:
			break;
		}
}
void ExpressionTree::ShowPrefixTypeExp(BTreeNode* bt)
{
	BinaryTree::PreorderTraverse(bt, ShowCharData);
}
void ExpressionTree::ShowInfixTypeExp(BTreeNode* bt)
{
	if (bt == nullptr)
		return;
	if (bt->left != nullptr||bt->right != nullptr)
		printf("(");
	ShowInfixTypeExp(bt->left);
	printf("%c", bt->data);
	ShowInfixTypeExp(bt->right);
	if (bt->left != nullptr || bt->right != nullptr)
		printf(")");
	
}
void ExpressionTree::ShowPostfixTypeExp(BTreeNode* bt)
{
	BinaryTree::PostorderTraverse(bt, ShowCharData);
}

void ShowCharData(int data)
{
	printf("%c", data);
}