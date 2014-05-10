#pragma once

#include <fstream>
#include <iostream>

using std::ofstream;

/**
 * @brief The OperatorClass class is class that includes some binary operation and its operands
 * @detailed The OperatorClass is the basic class for other classes that implement addition,
 * subtraction and so on. The other objects of this class can act as operands.
 * This class can calculate and print itself
 */
class OperatorClass
{
public:

    /**
     * @brief OperatorClass is constructor
     */
    OperatorClass()
    {}

    /**
     * @brief result is a service method that calculates an operation with its two operands
     * @return result of operation
     */
    virtual double result() = 0;

    /**
     * @brief print prints object to file as (<operator> <operand 1> <operand 2>)
     * @param fout is output file
     */
    virtual void print(ofstream &fout)
    {
        fout << "( " << operatorSymbol << " ";
        if (left)
            left->print(fout);
        if (right)
            right->print(fout);
        fout << ") ";
    }

    friend class ParseTree;

    /**
     * @brief calculate differs from result() by exception handling
     * @return result of result(), if there is no problem, else zero
     */
    double calculate()
    {
        double tmp = 0;
        try
        {
            tmp = this->result();
        }
        catch (DivisionByZero &)
        {
            std::cout << "Division by zero!\n";
        }
        return tmp;
    }

protected:
    /**
     * @brief The divisionByZero class is a service exception type
     */
    class DivisionByZero{};

    char operatorSymbol;

    /**
     * @brief left is a pointer to first operand
     */
    OperatorClass *left;

    /**
     * @brief left is a pointer to second operand
     */
    OperatorClass *right;
};
