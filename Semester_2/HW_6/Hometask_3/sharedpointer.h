#pragma once

template <typename T>

/**
 * @brief The SharedPointer class is analogue of shared_ptr
 */
class SharedPointer
{
public:

    /**
     * @brief constructor that creates an empty pointer
     */
    SharedPointer();

    /**
     * @brief constructor that creates a pointer to existing object
     * @param element is pointer to the object
     */
    SharedPointer(T *element);

    /**
     * @brief copying constructor
     */
    SharedPointer(const SharedPointer<T> &pointerToCopy);

    SharedPointer operator =(SharedPointer &pointer);

    ~SharedPointer();

    /**
     * @return number of pointers for the object
     */
    unsigned int count();

protected:

    /**
     * @brief The Data class contains the simple pointer to object and
     * common number of existing pointers to the object
     */
    class Data
    {
    public:
        Data(T *pointer, unsigned int number)
        {
            this->ptr = pointer;
            this->number = number;
        }

        ~Data()
        {
            delete this->ptr;
        }

        T *ptr;

        unsigned int number;
    };

    Data *data;
};

//template <typename T>

template <typename T>
SharedPointer<T>::SharedPointer() : data(new Data(nullptr, 1)) {}

template <typename T>
SharedPointer<T>::SharedPointer(T *element) : data(new Data(element, 1)) {}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T> &pointerToCopy)
{
    this->data = pointerToCopy.data;
    this->data->number++;
}

template <typename T>
SharedPointer<T> SharedPointer<T>::operator =(SharedPointer<T> &pointer)
{
    if (this->data->ptr != pointer.data->ptr)
    {
        this->data->number--;
        if (this->data->number == 0)
        {
            delete data;
        }
        this->data = pointer.data;
        this->data->number++;
    }
    return *this;

}

template <typename T>
SharedPointer<T>::~SharedPointer()
{
    this->data->number--;
    if (this->data->number == 0)
        delete data;
}

template <typename T>
T *SharedPointer<T>::pointer()
{
    return this->data->ptr;
}

template <typename T>
unsigned int SharedPointer<T>::count()
{
    return this->data->number;
}
