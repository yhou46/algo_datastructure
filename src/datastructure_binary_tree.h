#ifndef datastructure_binarytree_h
#define datastructure_binarytree_h

#include <iostream>
#include <vector>
#include <memory>

namespace datastructure
{

class BinaryTreeNode
{
public:
	BinaryTreeNode(): d_value(0), d_left(nullptr), d_right(nullptr)
	{}

    BinaryTreeNode(int value): d_value(value), d_left(nullptr), d_right(nullptr)
    {}
    
	int d_value;
    std::unique_ptr<BinaryTreeNode> d_left;
	std::unique_ptr<BinaryTreeNode> d_right;
};

    void dfs( BinaryTreeNode* root );

    // void bfs( BinaryTreeNode* root );

} // end namespace datastructure
#endif
