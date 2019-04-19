#pragma once
typedef struct _Node {
	int value;
	int bf;   //ƽ�����ӣ�
	_Node * left, *right;
} Node,*Tree;

//����˵����
// tree ��ǰ�жϵĽڵ�
// val ��ѯ��ֵ
// pre ��ǰ��ѯ���ӽڵ����һ�����ڵ�
// result ���ز�ѯ���Ľڵ� 
bool SearchTree(Tree tree,int val,Tree pre,Tree & result);

// ��ӽڵ�
//����˵����
// tree bst��
// val �����ֵ
bool AddNode(Tree& tree, int val);

bool DeleteNode(Tree& tree,int val);

// ���������������ӽڵ�
void InorderRevers(Tree tree);