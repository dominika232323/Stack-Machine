#pragma once
#include <string>
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

    std::string getElementName(Operation<T>* op)
    {
        return op->getName();
    }

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

    OperationList(const OperationList& list)
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
            Operation<T>* toRemove = operations.back();
            operations.pop_back();
            delete toRemove;
        }
    }

    int size()
    {
        return operations.size();
    }

    Operation<T>* operator[](int index)
    {
        return operations[index];
    }

    friend std::ostream& operator<<(std::ostream& os, OperationList<T> opList)
    {
        for (int i = 0; i < opList.size(); i++)
        {
            os << std::to_string(i + 1) << std::string(". ") << opList.getElementName(opList[i]) << "\n";
        }

        return os;
    }
};