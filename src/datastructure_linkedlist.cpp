//
//  datastructure_linkedlist.cpp
//  algo_datastructure
//
//  Created by Yunpeng Hou on 9/11/17.
//
//

#include "datastructure_linkedlist.h"

namespace datastructure
{
    LinkedList::LinkedList(const std::vector<int>& inputVector )
    {
        if( inputVector.size() <= 0 )
        {
            return;
        }
        d_head = new ListNode(inputVector[0]);
        ListNode* copyHead = d_head;
        
        for(auto begin = inputVector.begin()+1; begin != inputVector.end(); ++begin )
        {
            copyHead->d_next = new ListNode(*begin) ;
            copyHead = copyHead->d_next;
        }
    }
    
    LinkedList::~LinkedList()
    {
        while(d_head != nullptr)
        {
            ListNode* temp = d_head->d_next;
            delete d_head;
            d_head = temp;
        }
    }
    
    std::ostream& operator<<(std::ostream& out, const LinkedList& linkedList)
    {
        ListNode* head = linkedList.d_head;
        while( head != nullptr )
        {
            out << head->d_val << ",";
            head = head->d_next;
        }
        out << "\n";
        return out;
    }
    
    
} // end namespace datastructure
