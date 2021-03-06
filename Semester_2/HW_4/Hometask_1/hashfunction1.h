#include "hashfunction.h"

class HashFunction1 : public HashFunction
{
public:
    HashFunction1()
    {
        hashBase = 500;
    }
    int hash(std::string string)
    {
        int hashCode = 0;
        for (int i = 0; string[i] != '\0'; i++)
        {
            hashCode = (hashCode + 19 * static_cast<int>(string[i])) % hashBase;
        }
        return hashCode;
    }
};
