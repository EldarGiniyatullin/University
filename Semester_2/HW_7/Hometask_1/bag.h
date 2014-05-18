#pragma once

#include <QMap>


template <class T>
/**
 * @brief The Bag class is set of objects that can contaion more than one exemplar of the same object
 */
class Bag
{
public:
    Bag();

    ~Bag();

    void addValue(const T &value);

    /**
     * @return true if the bag contains the value; otherwise returns false.
     */
    bool doesBagContain(T value);

    /**
     * @return number of value's exemplars that are contained in current object
     */
    unsigned int valueNumber(T value)
    {
        if (doesBagContain(value))
            return data.value(value);
        else
            return 0;
    }

    void deleteValue(T value);

    /**
     * @return Bag's current size
     */
    unsigned int getSize();

    /**
     * @return union of first and second objects of Bag class
     */
    friend Bag<T> *operator +(Bag<T> &first, Bag<T> &second)
    {
        Bag<T> *tmp = new Bag<T>;
        if (!first.data.empty())
        {
            QMapIterator <T, unsigned int> i(first.data);
            while (i.hasNext())
            {
                i.next();
                tmp->data.insertMulti(i.key(), i.value());
                tmp->size += i.value();
            }
        }
        if (!second.data.empty())
        {
            QMapIterator <T, unsigned int> i(second.data);
            while (i.hasNext())
            {
                i.next();
                if (!first.doesBagContain(i.key()))
                {
                    tmp->data.insertMulti(i.key(), i.value());
                }
                else
                    tmp->data[i.key()] += i.value();
                tmp->size += i.value();
            }
        }
        return tmp;
    }

    /**
     * @return intersepcion of first and second objects of Bag class
     */
    friend Bag<T> *operator *(Bag<T> &first, Bag<T> &second)
    {
        if (first.getSize() == 0 || second.getSize() == 0)
            return new Bag<T>;

        Bag *tmp = new Bag<T>;
        QMapIterator <T, unsigned int> i(first.data);
        while (i.hasNext())
        {
            i.next();
            if (second.doesBagContain(i.key()))
            {
                tmp->data.insertMulti(i.key(), (i.value() > second.data[i.key()] ? second.data[i.key()] : i.value()));
                tmp->size += (i.value() > second.data[i.key()] ? second.data[i.key()] : i.value());
            }
        }
        return tmp;
    }

protected:
    QMap<T, unsigned int> data;

    unsigned int size;
};

template <typename T>
Bag<T>::Bag()
{
    data.clear();
    size = 0;
}

template <typename T>
Bag<T>::~Bag()
{
    data.clear();
}

template <typename T>
void Bag<T>::addValue(const T &value)
{
    if (!doesBagContain(value))
        data.insertMulti(value, 1);
    else
    {
        data[value]++;
    }
    size++;
}

template <typename T>
bool Bag<T>::doesBagContain(T value)
{
    return data.contains(value);
}

template <typename T>
void Bag<T>::deleteValue(T value)
{
    if (doesBagContain(value))
    {
        data[value]--;
        size--;
        if (data[value] == 0)
        {
            data.remove(value);
        }
    }
}

template <typename T>
unsigned int Bag<T>::getSize()
{
    return size;
}
