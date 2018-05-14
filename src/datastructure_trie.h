//
//  datastructure_trie.h
//  algo_datastructure
//
//  Created by Yunpeng Hou on 12/31/17.
//

#ifndef datastructure_trie_h
#define datastructure_trie_h

#include <vector>
#include <memory>
#include <string>

namespace datastructure
{

    
class TrieNode
{
public:
    TrieNode(): d_children(ALPHABET_SIZE), isEndOfWord(false)
    {}
    
    const std::size_t ALPHABET_SIZE = 26;
    
    bool find(const std::string& word);
    
    void insert(const std::string& word);
    
private:
    std::vector<std::unique_ptr<TrieNode> > d_children;
    bool isEndOfWord;
};
    
} // end namespace datastructure
#endif /* datastructure_trie_h */
