
// std lib
#include <iostream>
#include <vector>
#include <string>
#include <regex>

// Self lib
#include "algo_sort.h"
#include "datastructure_linkedlist.h"
#include "datastructure_binary_index_tree.h"
#include "algo_string_enhance.h"
#include "datastructure_binary_tree.h"

using namespace algo;
using namespace datastructure;

BinaryTreeNode* test(int val)
{
    return std::unique_ptr<BinaryTreeNode>(new BinaryTreeNode(val)).get();
}

int main(int argc, const char * argv[])
{
//    BinaryTreeNode root(2);
//    root.d_left = std::unique_ptr<BinaryTreeNode>(new BinaryTreeNode(1));
//    root.d_right = std::unique_ptr<BinaryTreeNode>(new BinaryTreeNode(3));
//
//    root.d_left->d_right = std::unique_ptr<BinaryTreeNode>(new BinaryTreeNode(4));
//
//    std::string result;
//
//    serialize(&root, result);
//    std::cout << result << "\n";
//
//    BinaryTreeNode root2;
//
//    deSerialize(root2, result);
//
//    std::string result2;
//    serialize(&root2, result2);
//    std::cout << "after serialize: " << result2 << "\n";
    std::string input = " abc def c ";
    std::vector<std::string> result = algo::string_enhance::splitBySpaces(input);
    for(auto str: result)
    {
        std::cout << str << "\n";
        
    }
    
    
    return 0;
}
