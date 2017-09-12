
// std lib
#include <iostream>
#include <vector>


// self lib
#include "datastructure_linkedlist.h"

#ifndef algo_sort_h
#define algo_sort_h

namespace algo
{
namespace sort
{

class QuickSort
{
public:
    
    static void quickSort( std::vector<int>& inputVector, int begin, int end );
    
private:
    
    // Partition vector from begin(inclusive) to end(exclusive)
    // Return the pivot index
    static int partition( std::vector<int>& inputVector, int begin, int end);
    
};

class MergeSort
{
public:
    static void mergeSort( std::vector<int>& inputVector, int begin, int end );
    
    static void mergeSort( datastructure::ListNode* head );
    
private:
    
    // Merge 2 arrays: begin(inclusive) -> mid(exclusive), mid(inclusive) -> end(exclusive)
    static void merge( std::vector<int>& inputVector, int begin, int mid, int end  );
    
    static void merge( datastructure::ListNode* head1, datastructure::ListNode* head2 );
    
};

} // end of namespace sort
} // end of namespace algo_datastructure

# endif
