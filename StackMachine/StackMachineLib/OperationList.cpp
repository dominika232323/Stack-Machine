#pragma once
#include <string>
#include "Stack.cpp"
#include "OperationAddition.cpp"
#include "OperationSubtraction.cpp"
#include "OperationMultiplication.cpp"
#include "OperationDivision.cpp"
#include "OperationAnd.cpp"
#include "OperationOr.cpp"
#include "OperationXor.cpp"
#include "OperationNot.cpp"
#include "OperationDuplicate.cpp"
#include "OperationSwap.cpp"


template<typename T>
class OperationList
{
private:
    std::vector<Operation<T>*> operations;

    void addOperations()
    {
        operations.push_back(new OperationAddition<T>());
        operations.push_back(new OperationSubtraction<T>());
        operations.push_back(new OperationMultiplication<T>());
        operations.push_back(new OperationDivision<T>());
        operations.push_back(new OperationAnd<T>());
        operations.push_back(new OperationOr<T>());
        operations.push_back(new OperationXor<T>());
        operations.push_back(new OperationNot<T>());
        operations.push_back(new OperationDuplicate<T>());
        operations.push_back(new OperationSwap<T>());
    }

public:
    OperationList()
    {
        addOperations();
    }

    OperationList(const OperationList& list)
    {
        addOperations();
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
            os << std::to_string(i + 1) << std::string(". ") << opList[i]->getName() << "\n";
        }

        return os;
    }
};