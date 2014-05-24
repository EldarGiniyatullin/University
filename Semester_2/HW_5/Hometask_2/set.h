#pragma once

#include <QList>

template <typename T>

/**
 * @brief The Set class реаализует множество неповторяющихся элементов типа T
 */
class Set
{
public:
    /**
     * @brief Set - конструктор, создающиий пустое множество
     */
    Set();

    ~Set();

    /**
     * @brief addValue - добавить элемент в множество
     * @param value - элемент для добавления
     */
    void addValue(T value);

    /**
     * @brief doesSetContain проверяет, принадлежит ли элемент value множеству
     * @return true/false, если принадлежит/не принадлежит
     */
    bool doesSetContain(T value);

    /**
     * @brief deleteValue - исключить элемент value из множества (если существует)
     */
    void deleteValue(T value);

    /**
     * @brief getSize - получить количество элементов в множестве
     */
    unsigned int getSize();

    /**
     * @brief operator + получить объединение двух множеств
     * @return третье множество - объединение множеств
     */
    Set<T> *operator +(Set<T> &second);

    /**
     * @brief operator * получить пересечение двух множеств
     * @return третье множество - пересечение множеств
     */
    Set<T> *operator *(Set<T> &second);

protected:
    /**
     * @brief data - список элементов
     */
    QList<T> *data;

    /**
     * @brief size - количество элементов в множестве
     */
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
