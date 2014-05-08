#include "hashfunction.h"

class HashFunction1 : public HashFunction
{
public:
    HashFunction1()
    {
        hashBase = 500;
    }
    int hash(UserString &string)
    {
        int hashCode = 0;
        UserSymbol **tmp = &string.first;
        for (int i = 0; i < string.length; i++)
        {
            hashCode = (hashCode + 19 * ((int)((*tmp)->symbol))) % hashBase;
            tmp = &((*tmp)->next);
        }
        return hashCode;
    }
};
