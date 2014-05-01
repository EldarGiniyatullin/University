#include "simplecalculator.h"

int SimpleCalculator::calculate(int firstOperand, int operation, int secondOperand)
{
    /**
      * @brief the value of parameter operation
      * 0 - for +
      * 1 - for -
      * 2 - for *
      * 3 - for /
      */
    switch(operation)
    {
    case 0:
        return firstOperand + secondOperand;
        break;
    case 1:
        return firstOperand - secondOperand;
        break;
    case 2:
        return firstOperand * secondOperand;
        break;
    case 3:
        /**
          *@brief to prevent dividing by zero
          */
        if (secondOperand != 0)
            return firstOperand / secondOperand;
        else
            return 0;
        break;
    default:
        return 0;
        break;
    }
}
