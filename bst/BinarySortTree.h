#pragma once
typedef struct _Node {
	int value;
	int bf;   //平衡因子，
	_Node * left, *right;
} Node,*Tree;

//参数说明：
// tree 当前判断的节点
// val 查询的值
// pre 当前查询的子节点的上一级树节点
// result 返回查询到的节点 
bool SearchTree(Tree tree,int val,Tree pre,Tree & result);

// 添加节点
//参数说明：
// tree bst树
// val 插入的值
bool AddNode(Tree& tree, int val);

bool DeleteNode(Tree& tree,int val);

// 中序遍历输出所有子节点
void InorderRevers(Tree tree);