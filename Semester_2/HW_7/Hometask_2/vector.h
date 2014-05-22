#pragma once

template <typename T, unsigned int dim>
/**
 * @brief The Vector class implements vector
 */
class Vector
{
public:
    /**
     * @brief constructor that do not set vector's coordinates
     */
    Vector();

    /**
     * @brief constructor that sets coordinate value to all vector's coordinates
     */
    Vector(const T &coordinate);

    /**
     * @brief constructor that sets i-param to vector's i-coordinate
     */
    Vector(T coordinate1, T coordinate2, ...);

    /**
     * @return vector - result of first and second vectors' sum
     */
    Vector operator +(const Vector<T, dim> &second);

    ~Vector();

    /**
     * @return T-variable - result of first and second vectors' scalar multiplication
     */
    T operator *(const Vector<T, dim> &second);


    /**
     * @return vector's i-coordinate
     */
    T getDimensionValue(unsigned int i);

    /**
     * @return true if the vector is equal to null-vector; otherwise returns false.
     */
    bool isNullVector();

private:
    T *coordinates;

    unsigned int dimension;
};


template <typename T, unsigned int dim>
Vector<T, dim>::Vector()
{
    dimension = dim;
    coordinates = new T[dim];
}

template <typename T, unsigned int dim>
Vector<T, dim>::Vector(const T &coordinate)
{
    dimension = dim;
    coordinates = new T[dim];
    for (int i = 0; i < dim; i++)
        coordinates[i] = coordinate;
}

template <typename T, unsigned int dim>
Vector<T, dim>::Vector(T coordinate1, T coordinate2, ...)
{
    T *curr = &coordinate1;
    dimension = dim;
    coordinates = new T[dim];
    for (int i = 0; i < dim; i++)
    {
        coordinates[i] = *curr;
        curr++;
    }
}

template <typename T, unsigned int dim>
Vector<T, dim> Vector<T, dim>::operator +(const Vector<T, dim> &second)
{
    Vector<T, dim> tmp;
    for (int i = 0; i < dim; i++)
        tmp.coordinates[i] = this->coordinates[i] + second.coordinates[i];
    return tmp;
}

template <typename T, unsigned int dim>
Vector<T, dim>::~Vector()
{
    delete[] coordinates;
}

template <typename T, unsigned int dim>
T Vector<T, dim>::operator *(const Vector<T, dim> &second)
{
    T tmp = 0;
    for (int i = 0; i < dim; i++)
        tmp = tmp + (this->coordinates[i] * second.coordinates[i]);
    return tmp;
}

template <typename T, unsigned int dim>
T Vector<T, dim>::getDimensionValue(unsigned int i)
{
    return coordinates[i];
}

template <typename T, unsigned int dim>
bool Vector<T, dim>::isNullVector()
{
    for (int i = 0; i < dimension; i++)
    {
        if (coordinates[i] != 0)
        {
            return false;
        }
    }
    return true;
}
