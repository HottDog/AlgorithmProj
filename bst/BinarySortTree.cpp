#include"BinarySortTree.h"
#include<iostream>
#include<queue>
using namespace std;

void Print(Tree tree,int layer)
{
	struct treeDesc
	{
		Tree node;
		int layer;
	};
	queue<treeDesc> nodes;
	nodes.push(tree   Desc(tree,0));
	while (!nodes.empty())
	{
		
	}
}

bool SearchTree(Tree tree, int val, Tree pre, Tree & result)
{
	if (!tree) {
		//tree为空
		result = pre;
		return false;
	}
	if (val == tree->value) {
		result = tree;
		return true;
	}
	if (val < tree->value) {
		SearchTree(tree->left, val, tree, result);
	}else if (val > tree->value) {
		SearchTree(tree->right, val, tree, result);
	}
}

bool AddNode(Tree& tree, int val) {
	Node * node;
	if (!SearchTree(tree, val, tree, node)) {
		//构建一个节点
		Node * temp = new Node;
		temp->value = val;
		temp->left = temp->right = nullptr;
		if (!node) {
			//空树
			tree = temp;
		}
		else {
			if (val < node->value) {
				node->left = temp;
			}
			else {
				node->right = temp;
			}
		}
		return true;
	}
	else {
		return false;
	}

}

bool DeleteNode(Tree& tree, int val) {
	if (!tree) {
		//空树
		return false;
	}
	if (tree->value == val) {
		Node * temp;
		Node * s;
		if (tree->right == nullptr&&tree->left == nullptr) {
			delete tree;
		}
	    else if(tree->right == nullptr) {
			//第一种情况,右子树为空
			temp = tree;
			tree = tree->left;
			delete temp;
		}
		else if(tree->left==nullptr){
			//第二种情况,左子树为空
			temp = tree;
			tree = tree->right;
			delete temp;
		}
		else {
			//第三种情况,左右子树都不为空
			//要找一个值跟要删除节点值最接近的节点来替换这个被删除节点，
			//可以找左边的，也可以找右边，目前找右边的
			s = tree->right;
			while (s->left) {
				s = s->left;
			}
			Node* temps = s;
			//这个替换的节点有个特点是，左子树为空
			if (s->right != nullptr) {
				//如果替换的节点右子树不为空
				s = s->right;
			}
			temp = tree;
			temps->left = tree->left;
			temps->left = tree->left;
			tree = temps;
			delete temp;
		}
		return true;
	}
	else if (val < tree->value) {
		DeleteNode(tree->left, val);
	}
	else {
		DeleteNode(tree->right, val);
	}
}

void InorderRevers(Tree tree) {
	if (tree == nullptr) {
		return;
	}
	InorderRevers(tree->left);
	cout << tree->value << ",";
	InorderRevers(tree->right);
}

void RightRotate(Tree &tree)
{
	Node * temp = tree;
	//将树的左子树置为树节点
	tree = tree->left;
	//将新的树节点的右子树置为原来的树节点的左子树
	temp->left = tree->right;
	//把原来的树节点置为新的树节点的右子树
	tree->right = temp;
	
}

void LeftRotate(Tree &tree)
{
	Node * temp = tree;
	tree = tree->right;
	temp->right = tree->left;
	tree->left = temp;
}

void RightBalance(Tree &tree)
{
	Node * right,*rightLeft;
	right = tree->right;
	switch (right->bf)
	{
	case RH:
		tree->bf = EH;
		right->bf = EH;
		LeftRotate(tree);
		break;
	case EH:
		tree->bf = RH;
		right->bf = LH;
		LeftRotate(tree);
		break;
	case LH:
		rightLeft = right->left;
		switch (rightLeft->bf)
		{
		case EH:
			tree->bf = EH;
			break;
		case RH:
			tree->bf = EH;
			break;
		case LH:
			tree->bf = RH;
			right->bf = EH;
		}
	default:
		break;
	}
}

void LeftBalance(Tree &tree)
{

}