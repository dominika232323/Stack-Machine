#pragma once
#include "Stack.cpp"
#include "OperationAddition.cpp"
#include "OperationSubtraction.cpp"
#include "OperationMultiplication.cpp"
#include "OperationDivision.cpp"
#include "OperationXor.cpp"
#include "OperationNot.cpp"
#include "OperationSwap.cpp"


template<typename T>
class OperationList
{
private:
    std::vector<Operation<T>*> operations;

public:
    OperationList()
    {
        operations.push_back(new OperationAddition<T>());
        operations.push_back(new OperationSubtraction<T>());
        operations.push_back(new OperationMultiplication<T>());
        operations.push_back(new OperationDivision<T>());
        operations.push_back(new OperationXor<T>());
        operations.push_back(new OperationNot<T>());
        operations.push_back(new OperationSwap<T>());
    }

    ~OperationList()
    {
        while (!operations.empty())
        {
            Operation* toRemove = operations.back();
            operations.pop_back();
            delete toRemove;
        }
    }

    Operation* operator[](int index)
    {
        return operations[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const StackMachine<T>& stackMachine)
    {
        for (int i = 0; i < operations.size(); i++)
        {
            os << i + 1 << ". " << operations[i]->getName() << "\n";
        }
        
        return os;
    }
};

