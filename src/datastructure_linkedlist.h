//
//  datastructure_linkedlist.h
//  algo_datastructure
//
//  Created by Yunpeng Hou on 9/11/17.
//
//
#include <vector>
#include <iostream>
#include <memory>

#ifndef datastructure_linkedlist_h
#define datastructure_linkedlist_h


namespace datastructure
{

class ListNode
{
public:
    int d_val;
    ListNode* d_next;
    
    ListNode(): d_val(0), d_next(nullptr)
    {}
    
    ListNode(const int val): d_val(val), d_next(nullptr)
    {}
    
};

// Not finish...
class LinkedList
{
public:
    LinkedList(const std::vector<int>& inputVector );
    LinkedList();
    ~LinkedList();
    
    void addNode(const int val);
    
private:
    ListNode* d_head;
    friend std::ostream& operator<<(std::ostream& out, const LinkedList& list);

};

} // end namespace datastructure
#endif /* datastructure_linkedlist_h */
