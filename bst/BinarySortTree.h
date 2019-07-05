#pragma once
//ƽ��������Ķ��壺
//�������������������֮��ľ���ֵ������1
//����������������������ƽ�������


#define EH 0    //��ʾ���������������߶����
#define LH 1    //��ʾ����������������1
#define RH -1   //��ʾ����������������1
typedef struct _Node {
	int value;
	int bf;   //ƽ�����ӣ�����������ȼ�ȥ�����������
	int color;    //�ڵ���ɫ�����ں������ֻ�к��������ɫ
	_Node * left, *right,*parent;
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

// ��avl�������ӽڵ�
// ����˵��:
// tree ��ǰ�����ڵ�
// key Ҫ�����ֵ
// taller ��ǰ����û�����ߣ�����������ٲ����Ҫƽ��
bool InsertAVLTree(Tree& tree, int key,bool &taller);

// ɾ��avl�ڵ�
// ����˵����
// tree ��ǰ�����ڵ�
// key Ҫɾ����ֵ
// lower ��ǰ����û�б䰫������䰫��ɾ����Ҫƽ��
bool DeleteAVLTree(Tree &tree, int key, bool &lower);