#pragma once
#define EH 0    //��ʾ������
#define LH 1    //��ʾ����������������1
#define RH -1   //��ʾ����������������1
typedef struct _Node {
	int value;
	int bf;   //ƽ�����ӣ�����������ȼ�ȥ�����������
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

void Print(Tree tree);

// ����
void RightRotate(Tree &tree);

// ����
void LeftRotate(Tree &tree);

// ��ƽ�⣬���ұ߸�ʱ
void RightBalance(Tree &tree);

// ��ƽ�⣬����߸�ʱ
void LeftBalance(Tree &tree);