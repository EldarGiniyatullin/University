#include "hashfunction.h"
#include "hashtable.h"
#include "list.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

HashTable::HashTable()
{
    hashFunction = new StandartHashFunction;
    hashData = new Element*[hashFunction->hashBase];
    zeroHashData();
    oldHashBase = hashFunction->hashBase;
    usedValues = 0;
    maxList = new List();
    maxListNumber = 0;
    storedData = 0;
}


HashTable::~HashTable()
{
    usedValues = 0;
    delete maxList;
    maxListNumber = 0;
    storedData = 0;
    for (int i = 0; i < hashFunction->hashBase; i++)
    {
        while (hashData[i] != nullptr)
        {
            Element *tmp = hashData[i]->next;
            delete  hashData[i];
            hashData[i] = tmp;
        }
    }
    delete hashFunction;
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
    usedValues = 0;
    delete maxList;
    maxList = new List();
    maxListNumber = 0;
    storedData = 0;
}

void HashTable::setFunction()
{
    oldHashBase = hashFunction->hashBase;
    delete hashFunction;
    hashFunction = new StandartHashFunction;
    reHash();
}

void HashTable::setFunction(HashFunction *newFunction)
{
    oldHashBase = hashFunction->hashBase;
    delete hashFunction;
    hashFunction = newFunction;
    reHash();
}

void HashTable::reHash()
{
    Element **tempData = hashData;
    hashData = new Element* [hashFunction->hashBase];
    zeroHashData();
    Element *tmp = nullptr;
    for (unsigned int i = 0; i < oldHashBase; i++)
    {
        if (tempData[i])
        {
            while (tempData[i])
            {
                tmp = tempData[i];
                hashing(tempData[i]->data);
                tempData[i] = tmp->next;
                delete tmp;
            }
        }
    }
    delete tempData;
}

unsigned int HashTable::findValue(std::string word)
{
    unsigned int value = hashFunction->hash(word);
    Element *tmp = hashData[value];
    while (tmp)
    {
        if (word == tmp->data)
        {
            return value;
            break;
        }
    }
    if (!tmp)
        throw NoValueInHashData();

}

void HashTable::zeroHashData()
{
    for (int i = 0; i < hashFunction->hashBase; i++)
    {
        hashData[i] = nullptr;
    }
}

void HashTable::hashing(std::string word)
{
    int hashValue = hashFunction->hash(word);
    Element **tmp = &(hashData[hashValue]);
    while (*tmp)
    {
        if (word == (*tmp)->data)
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
        newEl->data = word;
        newEl->next = nullptr;
    }
    tmp = nullptr;
}

void HashTable::printHashTable(std::fstream &fout)
{
    for (int i = 0; i < hashFunction->hashBase; i++)
    {
        if (hashData[i] != nullptr)
        {
            Element *tmp =  hashData[i];
            while (tmp)
            {
                fout << tmp->data << " ";
                fout << "(" << tmp->number << ") ";
                tmp = tmp->next;
            }
            fout << std::endl;
        }
    }
}

void HashTable::refreshMaxInf()
{
    delete maxList;
    maxList = new List();
    maxListNumber = 0;
    usedValues = 0;
    for (int i = 0; i < hashFunction->hashBase; i++)
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

void HashTable::printHashDataInf(std::fstream &fout)
{
    fout << "Load factor = " << std::setprecision(6) << (float)(storedData * 1.0 /  hashFunction->hashBase) << endl;
    fout << "Average length = " << std::setprecision(6) << (float)( storedData * 1.0 /  usedValues) << endl;
    List::ListElement *max =  maxList->first;
    while (max)
    {
        fout << "The key " << max->value << " has the maximal number of words (" <<  maxListNumber << ")" << " and includes words: " << endl;
        Element *curr =  hashData[max->value];
        while (curr)
        {
            fout << " " <<  curr->data << " ";
            curr = curr->next;
        }
        max = max->next;
        fout << endl;
    }
    fout << endl;
    fout << "Totally added " <<  storedData << " words" << endl;
    fout << "\"Empty\" keys number = " <<  hashFunction->hashBase - usedValues << endl;
}

void HashTable::clearData()
{
    for (int i = 0; i < hashFunction->hashBase; i++)
    {
        if (hashData[i])
        {
            while (!hashData[i])
            {
                Element *tmp = hashData[i];
                hashData[i] = hashData[i]->next;
                delete tmp;
            }
            hashData[i] = nullptr;
        }
    }
}
