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
    Vector()
    {
        dimension = dim;
        coordinates = new T[dim];
    }

    /**
     * @brief constructor that sets coordinate value to all vector's coordinates
     */
    Vector(T coordinate)
    {
        dimension = dim;
        coordinates = new T[dim];
        for (int i = 0; i < dim; i++)
            coordinates[i] = coordinate;
    }

    /**
     * @brief constructor that sets i-param to vector's i-coordinate
     */
    Vector(T coordinate1, T coordinate2,...)
    {
        T* curr = &coordinate1;
        dimension = dim;
        coordinates = new T[dim];
        for (int i = 0; i < dim; i++)
        {
            coordinates[i] = *curr;
            curr++;
        }
    }

    /**
     * @return vector - result of first and second vectors' sum
     */
    friend Vector operator +(Vector<T, dim> &first, Vector<T, dim> &second)
    {
        Vector<T, dim> tmp;
        for (int i = 0; i < dim; i++)
            tmp.coordinates[i] = first.coordinates[i] + second.coordinates[i];
        return tmp;
    }

    /**
     * @return T-variable - result of first and second vectors' scalar multiplication
     */
    friend T operator *(Vector<T, dim> &first, Vector<T, dim> &second)
    {
        T tmp = 0;
        for (int i = 0; i < dim; i++)
            tmp = tmp + (first.coordinates[i] * second.coordinates[i]);
        return tmp;
    }


    /**
     * @return vector's i-coordinate
     */
    T getDimensionValue(unsigned int i)
    {
        return coordinates[i];
    }

    /**
     * @return true if the vector is equal to null-vector; otherwise returns false.
     */
    bool isNullVector()
    {
        bool tmp = true;
        for (int i = 0; i < dimension; i++)
        {
            if (coordinates[i] != 0)
            {
                tmp = false;
                break;
            }
        }
        return tmp;
    }

private:
    T *coordinates;

    unsigned int dimension;
};
