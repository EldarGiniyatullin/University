#pragma once

class List
{
public:
    List();

    ~List();

    struct ListElement
    {
        int value;
        ListElement *next;
    };

    ListElement *first;

    void addValueList(int value);

    void printList();
};
