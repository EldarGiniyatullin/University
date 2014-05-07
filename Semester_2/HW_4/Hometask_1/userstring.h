#pragma once
#include <fstream>

struct UserSymbol
{
    char symbol;
    UserSymbol *next;
};

struct UserString
{
    int length;
    UserSymbol *first;
};

enum Status{yes, no};

UserString createNew();

UserSymbol *createNewSymbol(char ch);

void readString(UserString &string, int number);

void readString(UserString &string, char limit);

void deleteSymbol(UserString &string, int number);

void deleteSymbol(UserSymbol &symbol, UserSymbol *previous);

UserString clone(UserString string);

void connect(UserString &leftString, UserString rightString);

bool areEqual(UserString string1, UserString string2);

int stringLength(UserString string);

bool isEmpty(UserString string);

UserString includedString(UserString mainString, int first, int last);

char *charification(UserString string);

void deleteString(UserString string);

void readWord(UserString &word, Status isCapitalEqualSmall);

void readWord(UserString &word, Status isCapitalEqualSmall, std::ifstream &fin);

void printString(UserString &string);
