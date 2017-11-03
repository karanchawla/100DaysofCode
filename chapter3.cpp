//
//  chapter3.cpp
//  
//
//  Created by Karan Chawla on 10/29/17.
//

#include "chapter3.hpp"

FixedMultiStack::FixedMultiStack(int stackCapacity)
: stackCapacity(stackCapacity)
{
    stackArr = new int[numOfStack*stackCapacity]();
    stackCapacityUsed = new int[numOfStack]();
}

FixedMultiStack::~FixedMultiStack()
{
    delete [] stackArr;
    delete [] stackCapacityUsed;
}

void FixedMultiStack::push(int stackNum, int value)
{
    if(isFull(stackNum))
        cout << "Stack " << stackNum << " is full";
    else
    {
        stackCapacityUsed[stackNum]++;
        stackArr[indexOfTop(stackNum)] = value;
    }
}

void FixedMultiStack::pop(int stackNum)
{
    if(isEmpty(stackNum))
        std::cout << "Stack " << stackNum << " is empty.\n";
    else
    {
        int topIndex = indexOfTop(stackNum);
        stackArr[stackNum] = 0;
        stackCapacityUsed[stackNum]--;
    }
}

int FixedMultiStack::top(int stackNum) const
{
    if(isEmpty(stackNum))
        cout << "Stack " << stackNum << " is empty.\n";
    else
    {
        return stackArr[indexOfTop(stackNum)];
    }
}

int FixedMultiStack::isEmpty(int stackNum) const
{
    return (stackCapacityUsed[stackNum]==0);
}

int FixedMultiStack::isFull(int stackNum) const
{
    return (stackCapacityUsed[stackNum] == stackCapacity);
}

int FixedMultiStack::indexOfTop(int stackNum) const
{
    int startIndex = stackNum * stackCapacity;
    int capacity = stackCapacityUsed[stackNum];
    return (startIndex + capacity - 1);
}









