#include "simplecalculator.h"

int SimpleCalculator::calculate(int operand_1, int operation, int operand_2)
{
    switch(operation)
    {
    case 0:
        return operand_1 + operand_2;
        break;
    case 1:
        return operand_1 - operand_2;
        break;
    case 2:
        return operand_1 * operand_2;
        break;
    case 3:
        if (operand_2 != 0)
            return operand_1 / operand_2;
        else
            return 0;
        break;
    default:
        return 0;
        break;
    }
}
