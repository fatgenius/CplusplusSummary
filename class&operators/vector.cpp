//
// Created by
//

#include "vector.h"
#include <stdexcept>

// it's a good idea to put your code into a namespace, the name of the namespace can be anything you want
namespace sax {
    Vector::Vector(int capacity) :
            // this is the member initializer list in a constructor
            m_size{0},
            m_capacity{capacity}
    {
        if (capacity < 0) throw std::length_error{"Size smaller than 0"};
        //the m_elements is initialized here, because we need to check the capacity first
        m_elements = std::make_unique<double[]>(capacity);
    }

    //this is the default constructor, it takes no arguments
    // it also delegates its work to the constructor that takes the initial capacity as argumnet
    Vector::Vector() : Vector(16)
    {}

    Vector::Vector(std::initializer_list<double> list) :
        Vector(list.size())
    {
        for (auto d : list){
            push_back(d);
        }
    }

    //this is the copy constructor.
    Vector::Vector(const Vector &other):
        m_capacity{other.m_capacity},
        m_size{other.m_size},
        m_elements{std::make_unique<double[]>(other.m_capacity)} // here a new array of doubles is made with same capacity as the other's m_elements
    {
        for (int i = 0; i < m_size; ++i) {
            m_elements[i] = other.m_elements[i];
        }
    }

    // copy assignment operator
    Vector& Vector::operator=(const Vector& other) {
        if (this != &other){    // first always check if an object is not being assigned to itself!
            if (m_capacity != other.m_capacity){    // in case the other vector capacity is different, fix this
                m_elements = std::make_unique<double[]>(other.m_capacity);
                m_capacity = other.m_capacity;
            }
            //finally copy the size and all the elements
            m_size = other.m_size;
            for (int i = 0; i < m_size; ++i) {
                m_elements[i] = other.m_elements[i];
            }
        }
        return *this;   // operators that return a reference of the object's type usually must return *this
    }

    // move constructor.
    Vector::Vector(Vector&& other) noexcept:
            m_capacity{std::exchange(other.m_capacity, 0)},
            m_size{std::exchange(other.m_size, 0)},
            m_elements{std::move(other.m_elements)}
    { }

    // move assignment operator
    Vector& Vector::operator=(Vector&&  other) noexcept {
        if (this != &other){
            m_capacity = std::exchange(other.m_capacity, 0);
            m_size = std::exchange(other.m_size, 0);
            m_elements = std::move(other.m_elements);
        }
        return *this;
    }

    //the push_back function, it just adds a number at the end of the Vector
    void Vector::push_back(double e) {
        // check if the vector can still fit a new element
        if (m_size == m_capacity){

            if (m_capacity > 0)
                m_capacity *= 2;
            else
                m_capacity = 1;
            // if it cannot, resize the internal array:
            // here a new array of doubles is constructed
            auto p_new_elements = new double[m_capacity];

           // auto elements = std::make_unique<double[]>(m_capacity);
            //all the old elements are copied from the old array to the new one
            for (int i = 0; i < m_size; ++i) {
                p_new_elements[i] = m_elements[i];
            }
           // m_elements = std::move(elements);
            //finally the unique_ptr is reset with the new array
            //it will delete the array it currently owns and replace it with the new array
            m_elements.reset(p_new_elements);
        }
        if (m_size == m_capacity) throw std::out_of_range{"push_back: Index out of range"};
        m_elements[m_size++] = e;
    }

    //accessing the elements of the vector by index
    double& Vector::at(int ind) {
        if (ind < 0 || ind >= m_size) throw std::out_of_range{"at: Index out of range"};
        return m_elements[ind];
    }

    // removing the last element from the vector
    double Vector::pop_back() {
        if (m_size == 0) throw std::out_of_range{"No elements"};
        return m_elements[--m_size];
    }

    //array subscript operator, with this we can access elements like this: v[ind]
    double& Vector::operator[](int ind) {
        if (ind >= size()) throw std::out_of_range{"Index out of range"};
        return m_elements[ind];
    }

    //the const variant of the array subscript operator
    const double& Vector::operator[](int ind) const {
        if (ind >= size()) throw std::out_of_range{"Index out of range"};
        return m_elements[ind];
    }

    //
    Vector& Vector::operator+=(const Vector& other) {
        for(int i = 0; i < other.size(); ++i){
            push_back(other[i]);
        }
        return *this;
    }

    Vector& Vector::operator+=(std::initializer_list<double> &list) {
        throw std::runtime_error("not implemented");
    }


    Vector& Vector::operator*=(const double d) {
        for (int i = 0; i < m_size; ++i) {
            m_elements[i] *= d;
        }
        return *this;
    }


    Vector::operator bool() const {
        return m_size > 0;
    }
}
