#pragma once

#include "operatorclass.h"

using std::ofstream;

/**
 * @brief The NumericalOperand class implements a simple operand (double number)
 */
class NumericalOperand : public OperatorClass
{
public:
    NumericalOperand(double number)/* : left(nullptr), right(nullptr), value(number)*/
    {
        left = nullptr;
        right = nullptr;
        value = number;
    }
    virtual void print(ofstream &fout) override
    {
        fout << value << " ";
    }
    /**
     * @brief value is numerical value of operand
     */
    double value;
protected:
    double result()
    {
        return value;
    }
};
