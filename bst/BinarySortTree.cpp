#include"BinarySortTree.h"
#include<iostream>
#include<queue>
using namespace std;

void Print(Tree tree)
{
	cout << endl;
	struct treeDesc
	{
	public:
		Tree node;
		int layer;
	};
	queue<treeDesc> nodes;
	treeDesc desc;
	desc.node = tree;
	desc.layer = 0;
	nodes.push(desc);
	int curLayer = 0;
	bool isExit = true;
	while (!nodes.empty())
	{
		treeDesc temp = nodes.front();
		nodes.pop();
		if (curLayer == temp.layer)
		{
			if (temp.node == nullptr)
			{
				cout << "X" << " ";
			}
			else
			{
				isExit = false;
				cout << temp.node->value << " ";
			}		
		}
		else
		{
			if (isExit)
			{
				break;
			}
			isExit = true;
			curLayer = temp.layer;
			cout << endl;
			if (temp.node == nullptr)
			{
				cout << " " << " ";
			}
			else
			{
				cout << temp.node->value << " ";
			}
		}
		if (temp.node != nullptr)
		{
			treeDesc lefttemp;
			lefttemp.layer = temp.layer + 1;
			lefttemp.node = temp.node->left;
			nodes.push(lefttemp);

			treeDesc righttemp;
			righttemp.layer = temp.layer + 1;
			righttemp.node = temp.node->right;
			nodes.push(righttemp);
		}
		else
		{
			treeDesc lefttemp;
			lefttemp.layer = temp.layer + 1;
			lefttemp.node = nullptr;
			nodes.push(lefttemp);

			treeDesc righttemp;
			righttemp.layer = temp.layer + 1;
			righttemp.node = nullptr;
			nodes.push(righttemp);
		}
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
		tree->bf = EH;
		right->bf = LH;
		LeftRotate(tree);
		break;
	case LH:
		rightLeft = right->left;
		switch (rightLeft->bf)
		{
		case EH:
			tree->bf = EH;
			right->bf = EH;
			break;
		case RH:
			tree->bf = EH;
			right->bf = LH;
			break;
		case LH:
			tree->bf = RH;
			right->bf = EH;
			break;
		default:
			break;
		}
		rightLeft->bf = EH;
		RightRotate(tree->right);
		LeftRotate(tree);
		break;
	default:
		break;
	}
}

void LeftBalance(Tree &tree)
{
	Node *left, *leftRight;
	left = tree->left;
	switch (left->bf)
	{
	case EH:
		tree->bf = EH;
		left->bf = LH;
		RightRotate(tree);
		break;
	case LH:
		tree->bf = EH;
		left->bf = EH;
		RightRotate(tree);
		break;
	case RH:
		leftRight = left->right;
		switch (leftRight->bf)
		{
		case EH:
			tree->bf = EH;
			left->bf = EH;
			break;
		case LH:
			tree->bf = EH;
			left->bf = RH;
			break;
		case RH:
			tree->bf = LH;
			left->bf = EH;
			break;
		default:
			break;
		}
		leftRight->bf = EH;
		LeftRotate(tree->left);
		RightRotate(tree);
		break;
	default:
		break;
	}
}

bool InsertAVLTree(Tree& tree, int key, bool &taller)
{
	if (!tree)
	{
		tree = new Node;
		tree->bf = EH;
		tree->left = nullptr;
		tree->right = nullptr;
		tree->value = key;
		taller = true;
		return true;
	}else
	{
		if (tree->value == key)
		{
			taller = false;
			return false;
		}
		if (key < tree->value)
		{
			//����߲���
			if (!InsertAVLTree(tree->left, key, taller))
			{
				return false;
			}
			if (taller)
			{
				switch (tree->bf)
				{
				case EH:
					tree->bf = LH;
					taller = true;
					break;
				case RH:
					tree->bf = EH;
					taller = false;
					break;
				case LH:					
					LeftBalance(tree);
					//��ƽ��֮��Ͳ�����������
					taller = false;
					break;
				default:
					break;
				}
			}
			
		}
		else
		{
			if (!InsertAVLTree(tree->right, key, taller))
			{
				return false;
			}
			if (taller)
			{
				switch (tree->bf)
				{
				case EH:
					tree->bf = RH;
					taller = true;
					break;
				case LH:
					tree->bf = EH;
					taller = false;
					break;
				case RH:
					RightBalance(tree);
					taller = false;
					break;
				default:
					break;
				}
			}
		}
		
	}
}

bool DeleteAVLTree(Tree &tree, int key, bool &lower)
{
	bool L, R;
	L = R = false;
	if (tree == nullptr)
	{
		return false;
	}
	if (key == tree->value)
	{
		Node * temp, *s;
		lower = true;
		if (tree->right == nullptr)
		{
			temp = tree;
			tree = tree->left;
			delete temp;			
			return true;
		}
		else
		{
			temp = tree;
			s = tree->right;
			while (s->left)
			{
				s = s->left;
			}
			tree->value = s->value;
			DeleteAVLTree(tree->right, s->value, lower);
			R = true;
		}
	}
	else if (key < tree->value)
	{
		DeleteAVLTree(tree->left, key, lower);
		L = true;
	}
	else
	{
		DeleteAVLTree(tree->right, key, lower);
		R = true;
	}
	if (lower)
	{
		//����нڵ�ɾ��
		if (L)
		{
			//���ɾ��������ڵ�
			switch (tree->bf)
			{
			case LH:
				tree->bf = EH;
				lower = true;
				break;
			case RH:
				RightBalance(tree);
				lower = false;
				break;
			case EH:
				tree->bf = RH;
				lower = false;
				break;
			default:
				break;
			}
		}
		else
		{
			switch (tree->bf)
			{
			case EH:
				tree->bf = LH;
				lower = false;
				break;
			case LH:
				LeftBalance(tree);
				lower = false;
				break;
			case RH:
				tree->bf = EH;
				lower = true;
				break;
			default:
				break;
			}
		}
	}
}