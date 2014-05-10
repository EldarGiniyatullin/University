#pragma once

#include "operatorclass.h"

/**
 * @brief The Subtraction class implements a subtraction
 */
class Subtraction : public OperatorClass
{
public:
    Subtraction()
    {
        operatorSymbol = '-';
    }
    double result()
    {
        return left->result() - right->result();
    }
};
