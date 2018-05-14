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

void serialize( BinaryTreeNode* root, std::string& result );

void deSerialize( BinaryTreeNode& root, const std::string& input );

struct SimpleBinaryTreeNode
{
    SimpleBinaryTreeNode(): d_left(nullptr), d_right(nullptr), d_value(0)
    {}
    
    SimpleBinaryTreeNode(int value): d_left(nullptr), d_right(nullptr), d_value(value)
    {}
    
    ~SimpleBinaryTreeNode()
    {
        
        if(d_left != nullptr)
        {
            delete d_left;
        }
        if(d_right != nullptr)
        {
            delete d_right;
        }
        
    }
    
    SimpleBinaryTreeNode* d_left;
    SimpleBinaryTreeNode* d_right;
    int d_value;
};
    
} // end namespace datastructure
#endif
