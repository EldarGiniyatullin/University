#include <iostream>
#include <fstream>
#include <string>
#include "hashfunction.h"
#include "hashfunction1.h"
#include "hashtable.h"
#include "testhash.h"

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
            string word = "";
            fin.get(ch);
            while (((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') && !fin.eof()))
            {
                word += ch;
                fin.get(ch);
            }
            currHash->hashing(word);
        }
    }
}

int main()
{
    TestHash testHash;
    QTest::qExec(&testHash);

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
                char ch;
                fin.get(ch);
                string word = "";
                while (((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') && !fin.eof()))
                {
                    word += ch;
                    fin.get(ch);
                }
                cout << word << " - ";
                try
                {
                    cout << " " << currHash->findValue(word) << "\n";
                }
                catch (HashTable::NoValueInHashData &)
                {
                    cout << "The word \"";
                    cout << word;
                    cout << "\" is not included to hash table\n";
                }
                currHash->hashing(word);
            }
        }
        delete currHash;
    }
}

