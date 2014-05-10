#pragma once

#include "operatorclass.h"

/**
 * @brief The Division class implements a division
 */
class Division : public OperatorClass
{
public:
    Division()
    {
        operatorSymbol = '/';
    }

    double result()
    {
        double tmp = right->result();
        if (tmp == 0)
        {
            throw DivisionByZero();
        }
        else
            return left->result() / right->result();
    }
};

