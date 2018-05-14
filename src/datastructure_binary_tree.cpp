//
//  datastructure_binary_tree.cpp
//  algo_datastructure
//
//  Created by Yunpeng Hou on 11/29/17.
//

#include <iostream>
#include <queue>
#include <sstream>
#include <regex>

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
    
    void serialize( BinaryTreeNode* root, std::string& result )
    {
        result = "";
        
        if(root == nullptr)
        {
            return;
        }
        
        std::stringstream ss;
        std::queue<BinaryTreeNode*> nodeQueue;
        nodeQueue.push(root);
        
        while(!nodeQueue.empty())
        {
            BinaryTreeNode* nodePtr = nodeQueue.front();
            nodeQueue.pop();
            if(nodePtr != nullptr)
            {
                ss << (nodePtr->d_value) << ",";
            }
            else
            {
                ss << "n,";
                continue;
            }
            
            if(nodePtr->d_left != nullptr)
            {
                nodeQueue.push(nodePtr->d_left.get());
            }
            else
            {
                nodeQueue.push(nullptr);
            }
            
            if(nodePtr->d_right != nullptr)
            {
                nodeQueue.push(nodePtr->d_right.get());
            }
            else
            {
                nodeQueue.push(nullptr);
            }
        }
        result = ss.str();
        return;
    }
    
    
    void deSerialize( BinaryTreeNode& root, const std::string& input )
    {
        std::regex regexExpression(",");
        std::sregex_token_iterator tokenIter(input.begin(), input.end(), regexExpression,-1);
        std::vector<std::string> tokens(tokenIter, std::sregex_token_iterator());
        
        if(tokens.size() == 0 || tokens[0] == "n")
        {
            return;
        }
        
        std::queue<BinaryTreeNode*> nodeQueue;
        root = BinaryTreeNode(std::stoi(tokens[0]));
        nodeQueue.push(&root);
        
        int i = 1;
        while(i < tokens.size())
        {
            BinaryTreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            
            if(tokens[i] != "n")
            {
                node->d_left = std::unique_ptr<BinaryTreeNode>(new BinaryTreeNode(std::stoi(tokens[i]) ) );
                nodeQueue.push(node->d_left.get());
            }
            ++i;
            
            if(tokens[i] != "n")
            {
                node->d_right = std::unique_ptr<BinaryTreeNode>(new BinaryTreeNode(std::stoi(tokens[i]) ) );
                nodeQueue.push(node->d_right.get());
            }
            ++i;
        }
    }
    
    
    
} // end namespace datastructure
