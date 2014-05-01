#pragma once

/**
 * @brief The SimpleCalculator class is class for calculating simple binary expressions
 */
class SimpleCalculator
{
public:
    /**
     * @brief calculate calculates the result of binary operation
     * @param firstOperand is first number
     * @param operation is number of binary operation (look more in mainwindow.cpp)
     * @param secondOperand is second number
     * @return the result of binary operation
     */
    static int calculate(int firstOperand, int operation, int secondOperand);
};
