#pragma once

#include <string>

class HashFunction
{
public:
    HashFunction(){    }
    virtual int hash(std::string word) = 0;
//protected:
    unsigned int hashBase;
};
