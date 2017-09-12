
#include "algo_sort.h"

namespace algo
{
namespace sort
{
    using namespace datastructure;

    void QuickSort::quickSort( std::vector<int>& inputVector, int begin, int end )
    {
        if( begin >= end -1 ) // need to be (end-1) to handle vector input of size 1
        {
            return;
        }
        
        int pivotIndex = partition(inputVector, begin , end);
        
        quickSort(inputVector, begin, pivotIndex);
        quickSort(inputVector, pivotIndex, end);
    }
    
    int QuickSort::partition(std::vector<int> &inputVector, int begin, int end)
    {
        if( begin >= end )
        {
            return -1;
        }
        
        // choose a pivot randomly
        int pivotIndex = std::rand() % (end-begin) + begin;
        int pivot = inputVector[pivotIndex];
        
        // Swap pivot with the last element
        std::swap(inputVector[pivotIndex], inputVector[end-1]);
        
        int i = begin - 1; // all elements before i (exclusive) should <= pivot
        
        // All elements between i and j should > pivot
        for( int j = begin; j < end-1; ++j)
        {
            if( inputVector[j] <= pivot )
            {
                ++i;
                std::swap(inputVector[i], inputVector[j]);
            }
        }
        std::swap(inputVector[i+1], inputVector[end-1]);
        return i+1;
    }
    
    void MergeSort::merge(std::vector<int> &inputVector, int begin, int mid, int end)
    {
        if( begin >= mid || mid >= end )
        {
            return;
        }
        
        std::vector<int> temp;
        
        int i = begin, j = mid;
        while( i < mid && j < end )
        {
            if(inputVector[i] <= inputVector[j])
            {
                temp.push_back(inputVector[i]);
                ++i;
            }
            else
            {
                temp.push_back(inputVector[j]);
                ++j;
            }
        }
        
        // Remember to copy the rest of array to tempvector
        while( i < mid )
        {
            temp.push_back(inputVector[i++]);
        }
        
        // Remember to copy the rest of array to tempvector
        while( j < end )
        {
            temp.push_back(inputVector[j++]);
        }
        
        for(int k = begin; k < end; ++k)
        {
            // Remember it must be k - begin,
            // since k is from begin to end, but temp is from 0 to end-begin
            inputVector[k] = temp.at(k-begin);
        }
    }
    
    void MergeSort::mergeSort(std::vector<int> &inputVector, int begin, int end)
    {
        if( begin + 1 < end )
        {
            int mid = begin + (end-begin)/2;
        
            mergeSort(inputVector, begin, mid);
            mergeSort(inputVector, mid, end);
            
            merge(inputVector, begin, mid, end);
        }
    }
    
//    void MergeSort::mergeSort( ListNode* head )
//    {
//        if(head == nullptr || head->d_next == nullptr)
//        {
//            return;
//        }
//        
//        // Cut in half
//        ListNode* nodePtr1 = head;
//        ListNode* nodePtr2 = head;
//        
//        // pay attention to the case where node1 next is null
//        while( nodePtr1 != nullptr && nodePtr2 != nullptr && nodePtr2->d_next != nullptr )
//        {
//            nodePtr1 = nodePtr1->d_next;
//            nodePtr2 = nodePtr2->d_next->d_next;
//        }
//        
//        ListNode* head1 = head;
//        nodePtr1->d_next = nullptr;
//        
//        ListNode* head2 = nodePtr2;
//        
//        mergeSort(head1);
//        mergeSort(head2);
//        
//        merge(head1, head2);
//        
//    }
//    
//    void MergeSort::merge(datastructure::ListNode *head1, datastructure::ListNode *head2)
//    {
//        ListNode dummyHead;
//        ListNode* ptr = &dummyHead;
//        
//        while( head1 != nullptr && head2 != nullptr)
//        {
//            if( head1->d_val <= head2->d_val )
//            {
//                ptr->d_next = head1;
//                head1 = head1->d_next;
//                ptr = ptr->d_next;
//            }
//            else
//            {
//                ptr->d_next = head2;
//                head2 = head2->d_next;
//                ptr = ptr->d_next;
//            }
//        }
//        
//        while( head1 != nullptr )
//        {
//            ptr->d_next = head1;
//            head1 = head1->d_next;
//            ptr = ptr->d_next;
//        }
//        
//        while( head2 != nullptr )
//        {
//            ptr->d_next = head2;
//            head2 = head2->d_next;
//            ptr = ptr->d_next;
//        }
//        return;
//        
//    }

} // end of namespace sort
} // end of namespace algo_datastructure
