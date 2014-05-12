#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "doublylinkedlist.h"
#include "linkedlist.h"

class ListTest : public QObject
{
    Q_OBJECT

public:
    explicit ListTest(QObject *parent = 0) : QObject(parent) {}

private:
    DoublyLinkedList *doublyLinkedList;
    LinkedList *linkedList;

private slots:
    void initTestCase()
    {
        doublyLinkedList = new DoublyLinkedList;
        linkedList = new LinkedList;
    }

    void testEmptyDLList()
    {
        QVERIFY(doublyLinkedList->numberOfElements == 0);
    }

    void testEmptyLList()
    {
        QVERIFY(linkedList->numberOfElements == 0);
    }

    void testDeleteElementFromEmptyDLList()
    {
        doublyLinkedList->deleteElement(1);
        QVERIFY(doublyLinkedList->numberOfElements == 0);
    }

    void testDeleteElementFromEmptyLList()
    {
        linkedList->deleteElement(1);
        QVERIFY(linkedList->numberOfElements == 0);
    }

    void testAddElementToDLList()
    {
        doublyLinkedList->addElement(1);
        QVERIFY(doublyLinkedList->numberOfElements == 1);
        doublyLinkedList->deleteElement(1);
    }

    void testAddElementToLList()
    {
        linkedList->addElement(1);
        QVERIFY(linkedList->numberOfElements == 1);
        linkedList->deleteElement(1);
    }

    void testAddAndDeleteElementDLList()
    {
        doublyLinkedList->addElement(1);
        doublyLinkedList->deleteElement(1);
        QVERIFY(doublyLinkedList->numberOfElements == 0);
    }

    void testAddAndDeleteElementLList()
    {
        linkedList->addElement(1);
        linkedList->deleteElement(1);
        QVERIFY(linkedList->numberOfElements == 0);
    }

    void testAddAndDeleteDifferentElementsDLList()
    {
        doublyLinkedList->addElement(1);
        doublyLinkedList->deleteElement(2);
        QVERIFY(doublyLinkedList->numberOfElements == 1);
    }

    void testAddAndDeleteDifferentElementsLList()
    {
        linkedList->addElement(1);
        linkedList->deleteElement(2);
        QVERIFY(linkedList->numberOfElements == 1);
    }

    void cleanupTestCase()
    {
        delete doublyLinkedList;
        delete linkedList;
    }
};

