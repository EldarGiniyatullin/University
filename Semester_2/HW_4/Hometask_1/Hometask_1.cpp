#include <iostream>
#include <fstream>
#include "userstring.h"
#include "hashfunction.h"
#include "hashfunction1.h"
#include "hashtable.h"

using namespace std;

void readingFromFile(fstream &fin, HashTable *currHash)
{
    char ch;
    while (!fin.eof())
    {
        fin.get(ch);
        while (!((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || fin.eof()))
        {
            fin.get(ch);
        }
        if (!fin.eof())
        {
            fin.putback(ch);
            UserString word = createNew();
            readWord(word, yes, fin);
            currHash->hashing(word);
            deleteString(word);
        }
    }
}

int main()
{
    fstream fin("text.txt");
    if (!fin.is_open())
    {
        cout << "Couldn\'t open file";
    }
    else
    {
        HashTable *currHash = new HashTable();
        readingFromFile(fin, currHash);
        fin.close();
        currHash->refreshMaxInf();
        fin.open("output.txt", ios_base::out | ios_base::trunc);
        currHash->printHashTable(fin);
        currHash->printHashDataInf(fin);
        currHash->setFunction(new HashFunction1);
        // за добавление нового слова в таблицу отвечает currHash->hashing(word);
        currHash->refreshMaxInf();
        currHash->printHashTable(fin);
        currHash->printHashDataInf(fin);
        fin.close();
        fin.open("input.txt", ios_base::in);
        if (!fin.is_open())
        {
            cout << "Couldn\'t open file";
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                UserString word = createNew();
                readWord(word, yes, fin);
                printString(word);
                cout << " - ";
                try
                {
                    cout << " " << currHash->findValue(word) << "\n";
                }
                catch (HashTable::NoValueInHashData)
                {
                    cout << "The word\"";
                    printString(word);
                    cout << "\"is not included to hash table\n";
                }
            }
        }
        delete currHash;
    }
}

