#pragma once

#include "list.h"
#include "userstring.h"
#include "hashfunction.h"

class HashTable
{
public:
    HashTable();

    ~HashTable();

    struct Element
    {
        int number;
        UserString string;
        Element *next;
    };

    Element **hashData;
    HashFunction *hashFunction;
    int storedData;         // сколько слов хранится
    int usedValues;        // занятых ячеек
    List *maxList;        // значения ключей у максимальных цепей
    int maxListNumber;   // максимальная длина цепочки

    void deleteHashData();

    void hashing(UserString &word);

    void refreshMaxInf();

    void countMaxInf();

    void printHashTable();

    void printHashDataInf();

    void clearData();

    void refreshHashData();

    void setFunction(HashFunction *newFunction);

    void reHash();
private:
//    static int standartFunction(UserString &string);

    unsigned int totalValues;

    class StandartHashFunction : public HashFunction
    {
    public:
        int hash(UserString &string)
        {
            int hashCode = 0;
            UserSymbol **tmp = &string.first;
            for (int i = 0; i < string.length; i++)
            {
                hashCode = (hashCode + 31 * ((int)((*tmp)->symbol))) % 1000;
                tmp = &((*tmp)->next);
            }
            return hashCode;
        }
    };

    StandartHashFunction standartFunction;
};
