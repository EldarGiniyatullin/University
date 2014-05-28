#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "hashtable.h"



class TestHashTable : public QObject
{
    Q_OBJECT
public:
    explicit TestHashTable(QObject *parent = 0):QObject(parent){}
    
private slots:
    void init()
    {
        hashTable = new HashTable();
    }
    void testAddToHashTable()
    {
        hashTable->addToTable(33);
        hashTable->addToTable(11);
        hashTable->addToTable(9);
        QVERIFY(hashTable->searchInTable(33));
        QVERIFY(hashTable->searchInTable(11));
        QVERIFY(hashTable->searchInTable(9));
    }
    void testDeleteFromTable()
    {
        hashTable->addToTable(33);
        hashTable->addToTable(11);
        hashTable->addToTable(9);
        hashTable->deleteFromTable(11);
        QVERIFY(hashTable->searchInTable(33));
        QVERIFY(!hashTable->searchInTable(11));
        QVERIFY(hashTable->searchInTable(9));
    }
    void testChangeHashFunction()
    {
        hashTable->addToTable(33);
        hashTable->addToTable(11);
        hashTable->addToTable(9);
        hashTable->addToTable(5);
        hashTable->addToTable(1);
        hashTable->addToTable(43);
        hashTable->addToTable(3);
        hashTable->addToTable(2);
        hashTable->addToTable(4);
        hashTable->addToTable(6);
        hashTable->addToTable(7);
        hashTable->addToTable(8);
        hashTable->addToTable(10);
        hashTable->addToTable(12);
        hashFunction = new HashFunction2();
        hashTable->setNewHashFunction(hashFunction);
        QVERIFY(hashTable->searchInTable(33));
        QVERIFY(hashTable->searchInTable(11));
        QVERIFY(hashTable->searchInTable(9));
        QVERIFY(hashTable->searchInTable(5));
        QVERIFY(hashTable->searchInTable(1));
        QVERIFY(hashTable->searchInTable(43));
        QVERIFY(hashTable->searchInTable(3));
        QVERIFY(hashTable->searchInTable(2));
        QVERIFY(hashTable->searchInTable(4));
        QVERIFY(hashTable->searchInTable(6));
        QVERIFY(hashTable->searchInTable(7));
        QVERIFY(hashTable->searchInTable(8));
        QVERIFY(hashTable->searchInTable(10));
        QVERIFY(hashTable->searchInTable(12));
    }

    void cleanup()
    {
        delete hashTable;
    }
private:
    HashTable *hashTable;
    HashFunction *hashFunction;
};
