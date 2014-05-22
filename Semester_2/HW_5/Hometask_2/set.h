#pragma once

#include <QList>

template <typename T>
class Set
{
public:
    Set();

    ~Set();

    void addValue(T value);

    bool doesSetContain(T value);

    void deleteValue(T value);

    unsigned int getSize();

    Set<T> *operator +(Set<T> &second);

    Set<T> *operator *(Set<T> &second);

protected:
    QList<T> *data;

    unsigned int size;
};


template <typename T>
Set<T>::Set() : data(new QList<T>), size(0)
{
}

template <typename T>
Set<T>::~Set()
{
    delete data;
}

template <typename T>
void Set<T>::addValue(T value)
{
    if (!doesSetContain(value))
    {
        data->push_back(value);
        size++;
    }
}

template <typename T>
bool Set<T>::doesSetContain(T value)
{
    return data->contains(value);
}

template <typename T>
void Set<T>::deleteValue(T value)
{
    if (doesSetContain(value))
    {
        data->removeOne(value);
        size--;
    }
}

template <typename T>
unsigned int Set<T>::getSize()
{
    return size;
}

template <typename T>
Set<T> *Set<T>::operator +(Set<T> &second)
{
    Set<T> *tmp = new Set<T>;
    if (!data->isEmpty())
    {
        for (int i = 0; i < data->size(); i++)
        {
            tmp->addValue(data->at(i));
        }
    }
    if (!second.data->isEmpty())
    {
        for (int i = 0; i < second.data->size(); i++)
        {
            if (!tmp->doesSetContain(second.data->at(i)))
                tmp->addValue(second.data->at(i));
        }
    }
    return tmp;
}

template <typename T>
Set<T> *Set<T>::operator *(Set<T> &second)
{
    if (getSize() == 0 || second.getSize() == 0)
        return new Set<T>;

    Set *tmp = new Set<T>;
    for (int i = 0; i < data->size(); i++)
    {
        if (second.doesSetContain(data->at(i)))
        {
            tmp->addValue(data->at(i));
        }
    }
    return tmp;
}
