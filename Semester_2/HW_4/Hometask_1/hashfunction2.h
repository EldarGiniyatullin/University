#include "hashfunction.h"

class HashFunction2 : public HashFunction
{
public:
    HashFunction2()
    {
        hashBase = 500;
    }
    int hash(std::string string)
    {
        int hashCode = 0;
        for (int i = 0; string[i] != '\0'; i++)
        {
            hashCode = (hashCode + 3 * static_cast<int>(string[i])) % hashBase;
        }
        return hashCode;
    }
};
