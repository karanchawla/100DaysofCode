//
//  chapter3.hpp
//  
//
//  Created by Karan Chawla on 10/29/17.
//

#ifndef chapter3_hpp
#define chapter3_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#endif /* chapter3_hpp */

class FixedMultiStack
{
public:
    FixedMultiStack(int stackCapacity);
    virtual ~FixedMultiStack();
    
    void push(int stackNum, int val);

    void pop(int stackNum);
    
    int top(int stackNum) const;
    void isEmpty(int stackNum) const;
    void isFull(int stackNum) const;
private:
    int numOfStack = 3;
    int stackCapacity;
    int *stackArr;
    int *stackCapacityUsed;
    
    int indexOfTop(int stackNum) const;
}
