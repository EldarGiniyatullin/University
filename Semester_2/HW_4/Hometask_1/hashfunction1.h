#include "hashfunction.h"

class HashFunction1 : public HashFunction
{
public:
//    HashFunction1()
//    {
//        hashBase = static_cast<const unsigned int>(1000);
//    }
    int hash(UserString &string)
    {
        int hashCode = 0;
        UserSymbol **tmp = &string.first;
        for (int i = 0; i < string.length; i++)
        {
            hashCode = (hashCode + 19 * ((int)((*tmp)->symbol))) % 1000;
            tmp = &((*tmp)->next);
        }
        return hashCode;
    }
};
