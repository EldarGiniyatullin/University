#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "doublylinkedlist.h"

class ListTest : public QObject
{
    Q_OBJECT

public:
    explicit ListTest(QObject *parent = 0) : QObject(parent) {}

private:
    DoublyLinkedList<int> *testDoublyLinkedList;

private slots:
    void initTestCase()
    {
        testDoublyLinkedList = new DoublyLinkedList<int>;
    }

    void testEmptyDLList()
    {
        QVERIFY(testDoublyLinkedList->numberOfElements == 0);
    }

    void testDeleteElementFromEmptyDLList()
    {
        testDoublyLinkedList->deleteElement(1);
        QVERIFY(testDoublyLinkedList->numberOfElements == 0);
    }

    void testAddElementToDLList()
    {
        testDoublyLinkedList->addElement(1);
        QVERIFY(testDoublyLinkedList->numberOfElements == 1);
        testDoublyLinkedList->deleteElement(1);
    }

    void testAddAndDeleteElementDLList()
    {
        testDoublyLinkedList->addElement(1);
        testDoublyLinkedList->deleteElement(1);
        QVERIFY(testDoublyLinkedList->numberOfElements == 0);
    }

    void testAddAndDeleteDifferentElementsDLList()
    {
        testDoublyLinkedList->addElement(1);
        testDoublyLinkedList->deleteElement(2);
        QVERIFY(testDoublyLinkedList->numberOfElements == 1);
    }

    void cleanupTestCase()
    {
        delete testDoublyLinkedList;
    }
};

