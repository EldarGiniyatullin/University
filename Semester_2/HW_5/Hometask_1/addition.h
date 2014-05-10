#pragma once

#include "operatorclass.h"

/**
 * @brief The Addition class implements an addition
 */
class Addition : public OperatorClass
{
public:
    /**
     * @brief Addition() is constructor
     */
    Addition()
    {
        operatorSymbol = '+';
    }

    double result()
    {
        return left->result() + right->result();
    }
};
