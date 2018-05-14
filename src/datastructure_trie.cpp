//
//  datastructure_trie.cpp
//  algo_datastructure
//
//  Created by Yunpeng Hou on 12/31/17.
//

// std
#include <iostream>
#include <string>

#include "datastructure_trie.h"
using namespace std;

namespace datastructure
{
    bool TrieNode::find(const string& word)
    {
        TrieNode* node = this;
        for( int i=0; i < word.size(); ++i )
        {
            int index = word[i] - 'a';
            if( node->d_children[index] != nullptr )
            {
                node = node->d_children[index].get();
            }
            else
            {
                return false;
            }
        }
        return node->isEndOfWord;
    }
    
    void TrieNode::insert(const string& word)
    {
        TrieNode* node = this;
        for( int i=0; i < word.size(); ++i )
        {
            int index = word[i] - 'a';
            
            std::cout << "index: " << index << "\n";
            
            node->d_children[index] = std::unique_ptr<TrieNode>(new TrieNode);
            node = node->d_children[index].get();
        }
        node->isEndOfWord = true;
    }
} // end namespace datastructure
