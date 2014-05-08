#pragma once

#include <fstream>
#include "list.h"
#include "userstring.h"
#include "hashfunction.h"

using std::fstream;

class HashTable
{
public:
    HashTable();

    ~HashTable();


    class NoValueInHashData
    {

    };

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

    void printHashTable(fstream &fout);

    void printHashDataInf(fstream &fout);

    void clearData();

    void refreshHashData();

    void setFunction(HashFunction *newFunction);

    void reHash();

    unsigned int findValue(UserString &word);
private:
//    static int standartFunction(UserString &string);

    class StandartHashFunction : public HashFunction
    {
    public:
        StandartHashFunction()
        {
            hashBase =  1000;
        }
        int hash(UserString &string)
        {
            int hashCode = 0;
            UserSymbol **tmp = &string.first;
            for (int i = 0; i < string.length; i++)
            {
                hashCode = (hashCode + 17 * ((int)((*tmp)->symbol))) % hashBase;
                tmp = &((*tmp)->next);
            }
            return hashCode;
        }
    };

    StandartHashFunction standartFunction;

    void zeroHashData();

    unsigned int oldHashBase;
};
