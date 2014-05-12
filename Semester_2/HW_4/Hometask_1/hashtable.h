#pragma once

#include <string>
#include <fstream>
#include "list.h"
#include "hashfunction.h"

using std::fstream;
using std::string;

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
        std::string data;
        Element *next;
    };

    void deleteHashData();

    void hashing(std::string word);

    void refreshMaxInf();

    void printHashTable(fstream &fout);

    void printHashDataInf(fstream &fout);

    void clearData();

    void refreshHashData();

    void setFunction();

    void setFunction(HashFunction *newFunction);

    void reHash();

    unsigned int findValue(std::string word);

    int getMaxListNumber()
    {
        return maxListNumber;
    }

    int getUsedValues()
    {
        return usedValues;
    }

    int getStoredData()
    {
        return storedData;
    }

    int getHashBase()
    {
        return hashFunction->hashBase;
    }

protected:

    Element **hashData;
    HashFunction *hashFunction;
    int storedData;         // сколько слов хранится
    int usedValues;        // занятых ячеек
    List *maxList;        // значения ключей у максимальных цепей
    int maxListNumber;   // максимальная длина цепочки

private:

    class StandartHashFunction : public HashFunction
    {
    public:
        StandartHashFunction()
        {
            hashBase = 1000;
        }
        int hash(std::string string)
        {
            int hashCode = 0;
            for (int i = 0; string[i] != '\0'; i++)
            {
                hashCode = (hashCode + 17 * static_cast<int>(string[i])) % hashBase;
            }
            return hashCode;
        }
    };

    StandartHashFunction standartFunction;

    void zeroHashData();

    unsigned int oldHashBase;
};
