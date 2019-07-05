#include"RedBlackTree.h"
bool InsertRBT(Tree &tree,Tree &parent, int val,bool &change)
{
	if (tree == nullptr)
	{
		if (parent == nullptr)
		{
			tree = new Node;
			tree->value = val;
			tree->color = BLACK;
			tree->left = nullptr;
			tree->right = nullptr;
			tree->parent = nullptr;
			change = false;
			return true;
		}
		else
		{
			tree = new Node;
			tree->value = val;
			tree->color = RED;
			tree->left = nullptr;
			tree->right = nullptr;
			tree->parent = parent;
			change = true;
			return true;
		}
	}
	if (tree->value == val)
	{
		return false;
	}
	Node * brother;
	if (tree->value < val)
	{
		//��߲���
		InsertRBT(tree->left, tree, val,change);
		if (change)
		{
			if (tree->color == BLACK)
			{
				change = false;
			}
			else
			{
				brother = parent->right;
				if (brother == nullptr || brother->color == BLACK)
				{
					//��ת�Ϳ���
				}else{
					//��ɫ�Ϳ���
					//����ڵ�
					tree->color = BLACK;
					brother->color = BLACK;
					parent->color = RED;
					change = true;
				}
				
			}
		}
	}
	else
	{
		//�ұ߲���
		//InsertRBT(tree->right, root, val);
	}
}


bool LeftTransform(Tree &tree)
{
	return true;
}

bool RightTransform(Tree &tree)
{
	return true;
}