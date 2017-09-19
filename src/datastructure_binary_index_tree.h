//
//  datastructure_binary_index_tree.h
//  algo_datastructure
//
//  Created by Yunpeng Hou on 9/16/17.
//
//

#include <vector>


#ifndef datastructure_binary_index_tree_h
#define datastructure_binary_index_tree_h

namespace datastructure {

    class BinaryIndexTree
    {
    public:
        
        // input vector index should from 0
        BinaryIndexTree( const std::vector<int>& inputVector );
        
        int size() { return d_inputData.size()-1; }
        
        // Get sum from [0,index], both inclusive
        int getPrefixSum( int index);
        
        // Get sum from [begin,end]
        int getRangeSum( int begin, int end );
        
        // Add value to specific index
        void addValue( int index, int value );
        
        // Update value at specific index
        void updateValue( int index, int value );
        
    private:
        
        // vector index should from 1, 0 is kept invalid
        std::vector<int> d_treeData; // Tree data, size is 1 more than original data
        std::vector<int> d_inputData; // Stores original data
    };
    
    // 2D binary index tree
    class BinaryIndexTree2D
    {
    public:
        BinaryIndexTree2D( const std::vector< std::vector<int> >& inputMatrix );
        
        int getTotalSum(int x, int y);
        
        int getRegionSum( int x1, int y1, int x2, int y2 );
        
        void updateValue( int x, int y, int val );
        void addValue( int x, int y, int val );
        
        friend std::ostream& operator<<(std::ostream& out, const BinaryIndexTree2D& bit2D);
        
    private:
        
        std::vector< std::vector<int> > d_inputMatrix;
        std::vector< std::vector<int> > d_treeMatrix;
    };
    
}

#endif /* datastructure_binary_index_tree_h */
