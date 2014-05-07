#include <iostream>
#include "userstring.h"
#include "hashfunction.h"
#include "hashfunction1.h"
#include "hashtable.h"

using namespace std;

int main()
{
    ifstream fin("text.txt"); // для работы с большим текстом подключите здесь text.txt
    if (!fin.is_open())
    {
        cout << "Couldn\'t open file";
    }
    else
    {
        char ch;
        HashTable *currHash = new HashTable();
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
        fin.close();
        currHash->refreshMaxInf();
        currHash->printHashTable();
        currHash->printHashDataInf();
        currHash->setFunction(new HashFunction1);
        // за добавление нового слова в таблицу отвечает currHash->hashing(word);
        currHash->refreshMaxInf();
        currHash->printHashTable();
        currHash->printHashDataInf();
        delete currHash;
    }
}

