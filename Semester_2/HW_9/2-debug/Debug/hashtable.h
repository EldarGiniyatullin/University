#pragma once
#include "hashfunction.h"
#include "list.h"


/**
  ����� ��� �������
  */
class HashTable
{
public:
    /**
      �����������
      */
    HashTable();
    /**
      ������� ���������� � �������
      */
    void addToTable(int key);
    /**
      �������� �� �������
      */
    void deleteFromTable(int key);
    /**
      ����� � �������
      ���������� 1 ��� 0
      */
    bool searchInTable(int key);
    /**
      ������� ���������� ��� �������
      */
    void statistic();
    /**
      ������������ �������
      */
    void rehash(int capacityNew);
    /**
      ������ ��� �������
      */
    void setNewHashFunction(HashFunction *funHash);

    class StandHF : public HashFunction
    {
        int hash(int key)
        {
            return key % 21;
        }
    };

    ~HashTable();

private:
    List *hashtable;
    int size;
    int capacity;
    double loadfactor;
    HashFunction *hashFunction;
};
