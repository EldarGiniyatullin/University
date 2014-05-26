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
        //
        QVERIFY(hashTable->searchInTable(33));
        QVERIFY(hashTable->searchInTable(11));
        QVERIFY(hashTable->searchInTable(9));
        QVERIFY(hashTable->searchInTable(5));
        QVERIFY(hashTable->searchInTable(43));
        QVERIFY(hashTable->searchInTable(1));
        QVERIFY(hashTable->searchInTable(3));
        QVERIFY(!hashTable->searchInTable(86));
        //
        hashFunction = new HashFunction2();
        hashTable->setNewHashFunction(hashFunction);
        QVERIFY(hashTable->searchInTable(33));
        QVERIFY(hashTable->searchInTable(11));
        QVERIFY(hashTable->searchInTable(9));
        QVERIFY(hashTable->searchInTable(5));
        QVERIFY(hashTable->searchInTable(1));
        //чудесным образом (виной хэш-функция) вместо 43 значение превращалось в 0
        //QVERIFY(hashTable->searchInTable(0)); выдавал true
        QVERIFY(hashTable->searchInTable(43));
        QVERIFY(!hashTable->searchInTable(86));
        QVERIFY(hashTable->searchInTable(3));
    }

    void cleanup()
    {
        delete hashTable;
    }

private:
    HashTable *hashTable;
    HashFunction *hashFunction;
};
