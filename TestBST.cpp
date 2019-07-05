#include"TestBST.h"
#include"bst/BinarySortTree.h"
#include<iostream>
using namespace std;
bool TestBST::Run() {
	TestAVLTree();
	return true;
}

void TestBST::TestAVLTree()
{
	Tree tree = nullptr;
	bool taller = false;
	InsertAVLTree(tree, 10, taller);      
	InsertAVLTree(tree, 40, taller);
	InsertAVLTree(tree, 3, taller);
	InsertAVLTree(tree, 7, taller);
	InsertAVLTree(tree, 9, taller);
	InsertAVLTree(tree, 14, taller);
	InsertAVLTree(tree, 6, taller);
	InsertAVLTree(tree, 23, taller);
	InsertAVLTree(tree, 34, taller);
	InsertAVLTree(tree, 16, taller);
	InsertAVLTree(tree, 8, taller);
	
	bool lower = false;
	DeleteAVLTree(tree, 9, lower);
	DeleteAVLTree(tree, 8, lower);
	DeleteAVLTree(tree, 23, lower);
	InorderRevers(tree);
	cout << endl;
	Print(tree);
}

void TestBST::Testbst()
{
	Tree tree = nullptr;
	AddNode(tree, 10);
	AddNode(tree, 40);
	AddNode(tree, 3);
	AddNode(tree, 7);
	AddNode(tree, 9);
	AddNode(tree, 14);
	AddNode(tree, 6);
	InorderRevers(tree);
	cout << endl;
	Node * temp;
	int value = 7;
	if (SearchTree(tree, value, tree, temp))
	{
		if (temp->left != nullptr)
		{
			cout << "节点" << value << "的左子树是" << temp->left->value << endl;
		}
		if (temp->right != nullptr)
		{
			cout << "节点" << value << "的右子树是" << temp->right->value << endl;
		}
	}

	DeleteNode(tree, 7);
	InorderRevers(tree);
	Print(tree);
}