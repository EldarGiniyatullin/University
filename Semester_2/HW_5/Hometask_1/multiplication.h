#pragma once

#include "operatorclass.h"

/**
 * @brief The Multiplication class implements a multiplication
 */
class Multiplication : public OperatorClass
{
public:
    Multiplication()
    {
        operatorSymbol = '*';
    }
    double result()
    {
        return left->result() * right->result();
    }
};

