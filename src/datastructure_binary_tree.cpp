//
//  datastructure_binary_tree.cpp
//  algo_datastructure
//
//  Created by Yunpeng Hou on 11/29/17.
//

#include <iostream>

#include "datastructure_binary_tree.h"

namespace datastructure
{

    void dfs( BinaryTreeNode* root )
    {
        if( root == nullptr )
        {
            return;
        }
        
        if( root->d_left != nullptr )
        {
            dfs( root->d_left.get() );
        }
        
        if( root->d_right != nullptr )
        {
            dfs( root->d_right.get() );
        }
        
        std::cout << root->d_value << "\n";
        
    }
    
} // end namespace datastructure
