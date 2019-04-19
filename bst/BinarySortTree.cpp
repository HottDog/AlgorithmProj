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
		//treeΪ��
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
		//����һ���ڵ�
		Node * temp = new Node;
		temp->value = val;
		temp->left = temp->right = nullptr;
		if (!node) {
			//����
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
		//����
		return false;
	}
	if (tree->value == val) {
		Node * temp;
		Node * s;
		if (tree->right == nullptr&&tree->left == nullptr) {
			delete tree;
		}
	    else if(tree->right == nullptr) {
			//��һ�����,������Ϊ��
			temp = tree;
			tree = tree->left;
			delete temp;
		}
		else if(tree->left==nullptr){
			//�ڶ������,������Ϊ��
			temp = tree;
			tree = tree->right;
			delete temp;
		}
		else {
			//���������,������������Ϊ��
			//Ҫ��һ��ֵ��Ҫɾ���ڵ�ֵ��ӽ��Ľڵ����滻�����ɾ���ڵ㣬
			//��������ߵģ�Ҳ�������ұߣ�Ŀǰ���ұߵ�
			s = tree->right;
			while (s->left) {
				s = s->left;
			}
			Node* temps = s;
			//����滻�Ľڵ��и��ص��ǣ�������Ϊ��
			if (s->right != nullptr) {
				//����滻�Ľڵ���������Ϊ��
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
	//��������������Ϊ���ڵ�
	tree = tree->left;
	//���µ����ڵ����������Ϊԭ�������ڵ��������
	temp->left = tree->right;
	//��ԭ�������ڵ���Ϊ�µ����ڵ��������
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