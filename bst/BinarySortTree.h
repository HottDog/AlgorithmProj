#pragma once
//平衡二叉树的定义：
//左子树和右子树的深度之差的绝对值不超过1
//它的左子树和右子树都是平衡二叉树


#define EH 0    //表示左子树和右子树高度相等
#define LH 1    //表示左子树比右子树高1
#define RH -1   //表示右子树比左子树高1
typedef struct _Node {
	int value;
	int bf;   //平衡因子，左子树的深度减去右子树的深度
	int color;    //节点颜色，用于红黑树，只有红黑两种颜色
	_Node * left, *right,*parent;
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

void Print(Tree tree);

// 右旋
void RightRotate(Tree &tree);

// 左旋
void LeftRotate(Tree &tree);

// 右平衡，当右边高时
void RightBalance(Tree &tree);

// 左平衡，当左边高时
void LeftBalance(Tree &tree);

// 往avl树插入子节点
// 参数说明:
// tree 当前的树节点
// key 要插入的值
// taller 当前树有没有增高，如果增高了再插入就要平衡
bool InsertAVLTree(Tree& tree, int key,bool &taller);

// 删除avl节点
// 参数说明：
// tree 当前的树节点
// key 要删除的值
// lower 当前树有没有变矮，如果变矮了删除就要平衡
bool DeleteAVLTree(Tree &tree, int key, bool &lower);