#pragma once
#include <fstream>

struct MySymbol
{
    char symbol;
    MySymbol *next;
};

struct MyString
{
    int length;
    MySymbol *first;
};

enum Status{yes, no};

MyString createNew();

MySymbol *createNewSymbol(char ch);

void readString(MyString &string, int number);

void readString(MyString &string, char limit);

void deleteSymbol(MyString &string, int number);

void deleteSymbol(MySymbol &symbol, MySymbol *previous);

MyString clone(MyString string);

void connect(MyString &leftString, MyString rightString);

bool areEqual(MyString string1, MyString string2);

int stringLength(MyString string);

bool isEmpty(MyString string);

MyString includedString(MyString mainString, int first, int last);

char *charification(MyString string);

void deleteString(MyString string);

void readWord(MyString &word, Status isCapitalEqualSmall);

void readWord(MyString &word, Status isCapitalEqualSmall, std::ifstream &fin);

void printString(MyString &string);
