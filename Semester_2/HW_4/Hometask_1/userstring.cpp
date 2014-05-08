#include <iostream>
#include <cctype>
#include "userstring.h"
#include <fstream>

using std::cin;
using std::cout;
using std::fstream;
using std::ofstream;


UserString createNew()
{
    UserString string;
    string.first = NULL;
    string.length = 0;
    return string;
}

UserSymbol *createNewSymbol(char ch)
{
    UserSymbol *symbol = new UserSymbol;
    symbol->symbol = ch;
    symbol->next = NULL;
    return symbol;
}

void readWord(UserString &word, Status isCapitalEqualSmall)
{
    char ch;
    cin.get(ch);
    word.first = createNewSymbol(ch);
    UserSymbol *tmp = word.first;
    word.length++;
    cin.get(ch);
    while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        if (isCapitalEqualSmall == no)
            ch = (char)tolower(ch);
        tmp->next = createNewSymbol(ch);
        tmp = tmp->next;
        word.length++;
        cin.get(ch);
    }
}

void readWord(UserString &word, Status isCapitalEqualSmall, fstream &fin)
{
    char symbol;
    fin.get(symbol);
    word.first = createNewSymbol(symbol);
    UserSymbol *tmp = word.first;
    word.length++;
    fin.get(symbol);
    while ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z'))
    {
        if (isCapitalEqualSmall == no)
            symbol = (char)tolower(symbol);
        tmp->next = createNewSymbol(symbol);
        tmp = tmp->next;
        word.length++;
        fin.get(symbol);
    }
}

void readString(UserString &string, int number)
{
    char ch;
    cin.get(ch);
    string.first = createNewSymbol(ch);
    UserSymbol *tmp = string.first;
    string.length++;
    number--;
    while (number != 0)
    {
        cin.get (ch);
        tmp->next = createNewSymbol(ch);
        tmp = tmp->next;
        string.length++;
        number--;
    }
}

void readString(UserString &string, char limit)
{
    char ch;
    cin.get(ch);
    string.first = createNewSymbol(ch);
    UserSymbol *tmp = string.first;
    string.length++;
    cin.get(ch);
    while (ch != limit)
    {
        tmp->next = createNewSymbol(ch);
        tmp = tmp->next;
        string.length++;
        cin.get(ch);
    }
}

void deleteSymbol(UserSymbol *symbol, UserSymbol *previous)
{
    if (symbol != NULL)
    {
        previous->next = symbol->next;
        delete symbol;
    }
}

void deleteSymbol(UserString &string, int number)
{
    if (number <= string.length)
    {
        string.length--;
        UserSymbol *curr = string.first;
        if (number == 1)
        {
            string.first = curr->next;
            delete curr;
        }
        else
        {
            number--;
            while(number != 1)
            {
                curr = curr->next;
                number--;
            }
            deleteSymbol(curr->next, curr);
        }
    }
}

UserString clone(UserString string)
{
    UserString newString = createNew();
    UserSymbol *curr = string.first;
    newString.length = string.length;
    if (newString.length > 0)
    {
        newString.first = createNewSymbol(string.first->symbol);
        curr = curr->next;
        UserSymbol *newCurr = newString.first;
        while (curr != NULL)
        {
            newCurr->next = createNewSymbol(curr->symbol);
            curr = curr->next;
            newCurr = newCurr->next;
        }
    }
    return newString;
}

void connect(UserString &leftString, UserString rightString)
{
    leftString.length += rightString.length;
    UserSymbol *tmp = leftString.first;
    UserString rightClone = clone(rightString);
    if (!isEmpty(leftString))
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = rightClone.first;
    }
    else
        leftString.first = rightClone.first;
    rightClone.first = NULL;
}

bool areEqual(UserString string1, UserString string2)
{
    if (string1.length == string2.length)
    {
        UserSymbol *curr1 = string1.first;
        UserSymbol *curr2 = string2.first;
        while (curr1 != NULL && curr1->symbol == curr2->symbol)
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return (curr1 == NULL) ? true : false;
    }
    else return false;
}

int stringLength(UserString string)
{
    return string.length;
}

bool isEmpty(UserString string)
{
    return string.first == NULL ? true : false;
}

UserString includedString(UserString mainString, int first, int last)
{
    UserString newString = createNew();
    if (first <= last)
    {
        UserSymbol *curr = mainString.first;
        last -= first;
        first--;
        while (first != 0)
        {
            curr = curr->next;
            first--;
        }
        newString.length = last + 1;
        newString.first = createNewSymbol(curr->symbol);
        curr = curr->next;
        UserSymbol *newCurr = newString.first;
        while (last != 0 && curr != NULL)
        {
            last--;
            newCurr->next = createNewSymbol(curr->symbol);
            curr = curr->next;
            newCurr = newCurr->next;
        }
    }
    return newString;
}

char* charification(UserString string)
{
    char *array = new char[string.length];
    UserSymbol *curr = string.first;
    int i = 0;
    while (curr != NULL)
    {
        array[i] = curr->symbol;
        curr = curr->next;
        i++;
    }
    return array;
}

void deleteString(UserString string)
{
    UserSymbol *tmp = string.first;
    while (string.first != NULL)
    {
        string.first = string.first->next;
        delete tmp;
        tmp = string.first;
    }
    string.length = 0;
}

void printString(UserString &string, fstream &fin)
{
    UserSymbol *curr = string.first;
    for (int i = 0; i < string.length; i++)
    {
        fin << curr->symbol;
        curr = curr->next;
    }
}

void printString(UserString &string)
{
    UserSymbol *curr = string.first;
    for (int i = 0; i < string.length; i++)
    {
        cout << curr->symbol;
        curr = curr->next;
    }
}

