#include "hashfunction.h"
#include "hashtable.h"
#include "list.h"
#include "userstring.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

HashTable::HashTable()
{
    totalValues = 1000;
    hashData = new Element*[totalValues];
    for (int i = 0; i < totalValues; i++)
    {
        hashData[i] = nullptr;
    }
    usedValues = 0;
    maxList = new List();
    maxListNumber = 0;
    storedData = 0;
    hashFunction = new StandartHashFunction;
}


HashTable::~HashTable()
{
    delete hashFunction;
    totalValues = 0;
    usedValues = 0;
    delete maxList;
    maxListNumber = 0;
    storedData = 0;
    for (int i = 0; i < 1000; i++)
    {
        while (hashData[i] != nullptr)
        {
            Element *tmp = hashData[i]->next;
            deleteString(hashData[i]->string);
            delete  hashData[i];
            hashData[i] = tmp;
        }
    }
    delete[] hashData;
}

void HashTable::refreshHashData()
{
    for (int i = 0; i < 1000; i++)
    {
        while (hashData[i] != nullptr)
        {
            Element *tmp =  hashData[i]->next;
            delete  hashData[i];
            hashData[i] = tmp;
        }
    }
    totalValues = 0;
    usedValues = 0;
    delete maxList;
    maxList = new List();
    maxListNumber = 0;
    storedData = 0;
}

void HashTable::setFunction(HashFunction *newFunction)
{
    delete hashFunction;
    hashFunction = newFunction;
    reHash();
}

void HashTable::reHash()
{
    Element **tempData = hashData;
    hashData = new Element* [totalValues];
    Element *tmp = nullptr;
    for (unsigned int i = 0; i < totalValues; i++)
    {
        if (tempData[i])
        {
            while (tempData[i])
            {
                tmp = tempData[i];
                hashing(tempData[i]->string);
                tempData[i] = tmp->next;
                delete tmp;
            }
        }
    }
    delete tempData;
}

void HashTable::hashing(UserString &word)
{
    int hashValue = hashFunction->hash(word);
    Element **tmp = &(hashData[hashValue]);
    while (*tmp)
    {
        if (areEqual(word, (*tmp)->string))
        {
            (*tmp)->number++;
            break;
        }
        else tmp = &((*tmp)->next);
    }
    if ((*tmp) == nullptr)
    {
        Element *newEl = new Element;
        *tmp = newEl;
        newEl->number = 1;
        newEl->string = clone(word);
        newEl->next = nullptr;
    }
    tmp = nullptr;
}

void HashTable::printHashTable()
{
    for (int i = 0; i < totalValues; i++)
    {
        if ( hashData[i] != nullptr)
        {
            Element *tmp =  hashData[i];
            while (tmp)
            {
                printString(tmp->string);
                cout << "(" << tmp->number << ") ";
                tmp = tmp->next;
            }
            cout << std::endl;
        }
    }
}

void HashTable::refreshMaxInf()
{
    delete maxList;
    maxList = new List();
    maxListNumber = 0;
    usedValues = 0;
    for (int i = 0; i < totalValues; i++)
    {
        Element *curr =  hashData[i];
        int tmp = 0;
        while (curr)
        {
            tmp++;
            curr = curr->next;
        }
        if (tmp > 0)
        {
            usedValues++;
            storedData += tmp;
            if (tmp > maxListNumber)
            {
                delete maxList;
                maxList = new List();
                maxListNumber = tmp;
            }
            if (tmp ==  maxListNumber)
            {
                maxList->addValueList(i);
            }
        }
    }
}

void HashTable::printHashDataInf()
{
    cout << "Load factor = " << std::setprecision(6) << (float)(storedData * 1.0 /  totalValues) << endl;
    cout << "Average length = " << std::setprecision(6) << (float)( storedData * 1.0 /  usedValues) << endl;
    List::ListElement *max =  maxList->first;
    while (max)
    {
        cout << "The key " << max->value << " has the maximal number of words (" <<  maxListNumber << ")" << " and includes words: " << endl;
        Element *curr =  hashData[max->value];
        while (curr)
        {
            cout << " ";
            printString(curr->string);
            cout << " ";
            curr = curr->next;
        }
        max = max->next;
        cout << endl;
    }
    cout << endl;
    cout << "Totally added " <<  storedData << " words" << endl;
    cout << "\"Empty\" keys number = " <<  totalValues - usedValues << endl;
}

void HashTable::clearData()
{
    for (int i = 0; i < totalValues; i++)
        delete hashData[i];
}

/*int HashTable::standartFunction(UserString &string)
{
    int hashCode = 0;
    UserSymbol **tmp = &string.first;
    for (int i = 0; i < string.length; i++)
    {
        hashCode = (hashCode + 31 * ((int)((*tmp)->symbol))) % 1000;
        tmp = &((*tmp)->next);
    }
    return hashCode;
}*/
