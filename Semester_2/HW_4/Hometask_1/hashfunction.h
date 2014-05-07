#pragma once

#include "userstring.h"

class HashFunction
{
public:
//    HashFunction(){    }
    virtual int hash(UserString &string) = 0;
//protected:
//    const unsigned int hashBase = 0;
};
