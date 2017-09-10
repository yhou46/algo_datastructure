#include <iostream>
#include <vector>

class TreeNode
{
public:
	TreeNode(): d_val(0), d_left(nullptr), d_right(nullptr)
	{}

	int d_val;
	TreeNode* d_left;
	TreeNode* d_right;
}