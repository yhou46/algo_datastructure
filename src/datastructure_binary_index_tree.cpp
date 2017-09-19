//
//  datastructure_binary_index_tree.cpp
//  algo_datastructure
//
//  Created by Yunpeng Hou on 9/16/17.
//
//

// STL
#include <exception>
#include <sstream>
#include <iostream>

// Custom
#include "datastructure_binary_index_tree.h"


namespace datastructure
{
    BinaryIndexTree::BinaryIndexTree( const std::vector<int>& inputVector ): d_treeData( inputVector.size()+1, 0 ), d_inputData(inputVector)
    {
        for( int i=0; i < d_inputData.size(); ++i )
        {
            addValue(i, inputVector[i]);
        }
    }
    
    int BinaryIndexTree::getPrefixSum(int index)
    {
        ++index;
        if( index > d_treeData.size() || index <0 )
        {
            std::stringstream errMsgStream;
            errMsgStream << "Index: " << index
                         << " out of bound, size: " << d_treeData.size()-1;
            throw std::range_error( errMsgStream.str() );
        }
        
        if(index == 0)
        {
            return 0;
        }
        
        int sum = 0;
        while( index > 0 )
        {
            sum += d_treeData[index];
            
            // Get last digit of 1
            index -= (index & -index);
        }
        return sum;
    }
    
    void BinaryIndexTree::addValue( int index, int value )
    {
        ++index;
        if( index >= d_treeData.size() || index <=0 )
        {
            std::stringstream errMsgStream;
            errMsgStream << "Index: " << index
            << " out of bound, size: " << d_treeData.size()-1;
            throw std::range_error( errMsgStream.str() );
        }
        
        while( index <= d_inputData.size() )
        {
            d_treeData.at(index) += value;
            index += ( index & -index );
        }
    }
    
    void BinaryIndexTree::updateValue(int index, int value)
    {
        int delta = value - d_inputData[index];
        d_inputData[index] = value;
        
        addValue(index, delta);
    }
    
    
    int BinaryIndexTree::getRangeSum( int begin, int end )
    {
        if( begin == 0 )
        {
            return getPrefixSum(end);
        }
        
        ++end; // convert to internal index
        
        int sum = d_treeData[end];
        
        // Move end to position less or equal to begin
        while( end > begin && end >0 )
        {
            end -= (end & -end);
        }
        
        while( begin >0 && begin != end )
        {
            sum -= d_treeData[begin];
            begin -= (begin & -begin);
        }
        
        return sum;
    }
    
    // ---------------------------------------------------------
    // ---------------------------------------------------------
    
    void BinaryIndexTree2D::addValue( int x, int y, int val )
    {
        d_inputMatrix[x][y] += val;
        
        ++x;
        ++y;
        
        int tempY = y;
        while( x < d_treeMatrix.size() )
        {
            y = tempY;
            
            while( y < d_treeMatrix[0].size() )
            {
                d_treeMatrix[x][y] += val;
                y += ( y & -y );
                
            }
            x += ( x & -x );
        }
    }
    
    void BinaryIndexTree2D::updateValue( int x, int y, int val )
    {
        int delta = val - d_inputMatrix[x][y];
        
        addValue(x, y, delta);
    }
    
    BinaryIndexTree2D::BinaryIndexTree2D( const std::vector< std::vector<int> >& inputMatrix )
    {
        if( inputMatrix.size() <= 0 )
        {
            return;
        }
        
        int rowMax = inputMatrix.size();
        int colMax = inputMatrix[0].size();
        
        for( int i=0; i < rowMax; ++i )
        {
            d_inputMatrix.push_back( std::vector<int>( colMax, 0) );
            d_treeMatrix.push_back( std::vector<int>( colMax+1, 0) );
        }
        d_treeMatrix.push_back( std::vector<int>( colMax+1, 0) );
        
        for( int i=0; i < rowMax; ++i )
        {
            for(int j=0; j < colMax; ++j)
            {
                addValue(i, j, inputMatrix[i][j]);
            }
        }
    }
    
    int BinaryIndexTree2D::getTotalSum(int x, int y)
    {
        int sum = 0;
        
        ++x;
        ++y;
        
        int tempY = y;
        while( x > 0 )
        {
            y = tempY;
            while( y > 0 )
            {
                sum += d_treeMatrix[x][y];
                y -= (y & -y);
            }
            
            x -= ( x & -x );
        }
        return sum;
    }
    
    int BinaryIndexTree2D::getRegionSum(int x1, int y1, int x2, int y2)
    {
        return getTotalSum(x2, y2) - getTotalSum(x2, y1-1) - getTotalSum(x1-1, y2) + getTotalSum(x1-1, y1-1);
    }
    
    std::ostream& operator<<(std::ostream& out, const BinaryIndexTree2D& bit2D)
    {
        int rowMax = bit2D.d_inputMatrix.size();
        int colMax = bit2D.d_inputMatrix[0].size();
        
        out << "input data: \n";
        for(int i=0; i < rowMax; ++i)
        {
            for(int j = 0; j < colMax; ++j)
            {
                out << bit2D.d_inputMatrix[i][j] <<", ";
            }
            out << "\n";
        }
        
        out << "\ntree data: \n";
        for(int i=0; i < rowMax+1; ++i)
        {
            for(int j = 0; j < colMax+1; ++j)
            {
                out << bit2D.d_treeMatrix[i][j] <<", ";
            }
            out << "\n";
        }
        return out;
    }
    
}    
