#include"TestBST.h"
#include"bst/BinarySortTree.h"
#include<iostream>
using namespace std;
bool TestBST::Run() {
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
	if (SearchTree(tree, value, tree, temp)) {
		if (temp->left != nullptr) {
			cout << "节点"<<value<<"的左子树是" << temp->left->value << endl;
		}
		if (temp->right != nullptr) {
			cout << "节点" << value << "的右子树是" << temp->right->value << endl;
		}
	}

	DeleteNode(tree, 7);
	InorderRevers(tree);
	
	return true;
}