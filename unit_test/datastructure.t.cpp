
// google test framework
#include "gtest/gtest.h"

// std
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <chrono>
#include <thread>

// Self headers
#include "datastructure_trie.h"
#include "datastructure_binary_tree.h"

using namespace std;

TEST(TrieTest, TrieTest_find)
{
	using namespace datastructure;
    
    TrieNode root;
    
    string input = "apple";
    root.insert(input);
    bool result = root.find(input);
    EXPECT_EQ(result, true);
    
    string input2 = "pear";
    root.insert(input2);
    result = root.find("pea");
    EXPECT_EQ(result, false);
    result = root.find(input);
    EXPECT_EQ(result, true);
}

TEST(BinaryTreeTest, BinaryTest_memory)
{
    using namespace datastructure;
    
    int count = 100;
    auto root = std::unique_ptr<SimpleBinaryTreeNode>(new SimpleBinaryTreeNode(-1));
    SimpleBinaryTreeNode* nodePtr = root.get();
    for(int i=0; i < count; ++i)
    {
        nodePtr->d_left = new SimpleBinaryTreeNode(i);
        nodePtr->d_right = new SimpleBinaryTreeNode(i);
        nodePtr = nodePtr->d_left;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    
}

