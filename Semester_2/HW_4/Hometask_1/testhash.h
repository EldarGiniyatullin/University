#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "hashtable.h"
#include "hashfunction2.h"

class TestHash : public QObject
{
    Q_OBJECT

public:
    explicit TestHash(QObject *parent = 0) : QObject(parent) {}

private:
    HashTable *testHash;

private slots:
    void init()
    {
        testHash = new HashTable;
    }

    void testEmptyHashMaxList()
    {
        QVERIFY(testHash->getMaxListNumber() == 0);
    }

    void testEmptyHashStoredData()
    {
        QVERIFY(testHash->getStoredData() == 0);
    }

    void testEmptyHashUsedValues()
    {
        QVERIFY(testHash->getUsedValues() == 0);
    }

    void testDoesEmptyThrow()
    {
        bool tmp = false;
        try
        {
            int value = testHash->findValue("exapmle");
        }
        catch (HashTable::NoValueInHashData &)
        {
            tmp = true;
        }
        QVERIFY(tmp);
    }

    void testAddValueToHash()
    {
        testHash->hashing("word");
        int value;
        std::string testWord = "word";
        try
        {
            value = testHash->findValue(testWord);
        }
        catch (HashTable::NoValueInHashData &)
        {
            value = 0;
        }
        int testValue = 0;
        for (int i = 0; i < 4; i++)
        {
            testValue = (testValue + 17 * static_cast<int>(testWord[i])) % testHash->getHashBase();
        }
        QVERIFY(value == testValue);
    }

    void testClearHashData()
    {
        testHash->hashing("word");
        testHash->clearData();
        bool temp = false;
        try
        {
            int value = testHash->findValue("word");
        }
        catch (HashTable::NoValueInHashData &)
        {
            temp = true;
        }
        QVERIFY(temp);
    }

    void testVerifyNotAddedHash()
    {
        testHash->hashing("word");
        bool tmp = false;
        try
        {
            int value = testHash->findValue("exapmle");
        }
        catch (HashTable::NoValueInHashData &)
        {
            tmp = true;
        }
        QVERIFY(tmp);
        testHash->clearData();
    }

    void testingUsedVauesHash()
    {

    }
    void testingMaxNumberHash()
    {
        testHash->hashing("word");
        testHash->hashing("drow");
        testHash->hashing("wdor");
        testHash->hashing("example");
        testHash->hashing("xemalpe");
        testHash->hashing("rodw");
        testHash->refreshMaxInf();
        QVERIFY(testHash->getMaxListNumber() == 4);
        testHash->clearData();
        testHash->refreshMaxInf();
    }

    void clearMaxDataInfHash()
    {
        testHash->hashing("word");
        testHash->hashing("drow");
        testHash->hashing("wdor");
        testHash->hashing("example");
        testHash->hashing("xemalpe");
        testHash->hashing("rodw");
        testHash->refreshMaxInf();
        testHash->clearData();
        testHash->refreshMaxInf();
        QVERIFY((testHash->getMaxListNumber() == 0) && (testHash->getUsedValues() == 0));
    }


    void settingNewHashFunction()
    {
        testHash->hashing("word");
        testHash->hashing("drow");
        testHash->hashing("wdor");
        int tmp = testHash->findValue("word");
        testHash->setFunction(new HashFunction2);
        int value = 0;
        try
        {
            value = testHash->findValue("word");
        }
        catch (HashTable::NoValueInHashData &)
        {
            value = 0;
        }
        QVERIFY((value != 0) && (value != tmp));
        testHash->clearData();
    }

    void cleanup()
    {
        delete testHash;
    }
};
