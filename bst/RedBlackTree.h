#pragma once
#include"BinarySortTree.h"
#define RED 1
#define BLACK -1

//红黑树(5个条件)
//1、每个节点要么是红色，要么是黑色
//2、根节点永远是黑色的
//3、所有的叶节点都是是黑色的（注意这里说叶子节点其实是上图中的 NIL 节点）
//4、每个红色节点的两个子节点一定都是黑色
//5、从任一节点到其子树中每个叶子节点的路径都包含相同数量的黑色节点

//主要有两个操作比较困难，插入和删除
//插入的话，基本比较难处理的就是条件4和5
//所以可以在插入的时候，把插入的节点都设置为红色，这样就可以保证条件5一直满足，
//这样只需要保证条件4就可以了

//有两种操作:
//1、变色，就是树节点和子节点同时变色
//2、旋转，旋转不改变原树结构的颜色分布

// 往红黑树中插入节点
// 参数说明：
//	tree 红黑树树节点
//	val 要插入的值
bool InsertRBT(Tree &tree,int val);

// 删除红黑树中的节点
// 参数说明：
//	tree 红黑树树节点
//  val 要删除的值
bool DeleteRBT(Tree &tree, int val);

bool LeftTransform(Tree &tree);

bool RightTransform(Tree &tree);