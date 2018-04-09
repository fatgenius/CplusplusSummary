//
// Created by
//

#ifndef INC_SAX_VECTOR_H
#define INC_SAX_VECTOR_H

#include <memory>
#include <ostream>

namespace sax {
    class Vector {
        //a container that can hold double's
    public:
        Vector();       //default constructor
        explicit Vector(int capacity);   //constructor that constructs a vector with given capacity
        Vector(std::initializer_list<double> list); //constructor taking initializer_list of doubles

        Vector(const Vector& other);        // copy constructor
        Vector(Vector&& other) noexcept;    // move constructor

        Vector& operator=(const Vector& other); // copy assignment
        Vector& operator=(Vector&& other) noexcept; // move assignment


        //functions for getting capacity and size
        //they are defined withing the header file
        int capacity() const { return m_capacity;}
        int size() const { return m_size; }

        // element access and modification functions
        void push_back(double e);
        double pop_back();
        double& at(int ind);

        //index access operator to get the elements out of Vector in a pleasing way
        double& operator[](int ind);
        // const variant of the index access operator
        const double& operator[](int ind) const;


        // += operators
        Vector& operator +=(const Vector& other);
        Vector& operator +=(std::initializer_list<double>& list);

        //
        Vector& operator *=(double d);

        explicit operator bool() const;

    private:
        int m_size;       //count of stored elements
        int m_capacity;   //current capacity

        std::unique_ptr<double[]> m_elements; //smart pointer to an array of double's
    };

}

#endif //INC_SAX_VECTOR_H
