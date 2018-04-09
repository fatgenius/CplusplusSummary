//
// Created by Dawid Zalewski on 06/11/2017.
//

#ifndef INC_SAX_VECTOR_H
#define INC_SAX_VECTOR_H

#include <memory>
#include <ostream>
#include "container.h"

namespace sax {
    template <typename T>
    class Vector : public rax_container<T>{

        using rax_container<T>::m_size; //when using templates, names of base classes need to be imported: m_size)

    public:
        using rax_container<T>::size;   //when using templates, names of base classes need to be imported: size()
        using size_type = typename rax_container<T>::size_type; //we can also redefine something
        using value_type = typename rax_container<T>::value_type;

        Vector() : Vector(16)
        {}

        explicit Vector(size_type capacity) :
                rax_container<T>(),
                // this is the member initializer list in a constructor
                m_capacity{capacity}
        {
            if (capacity < 0) throw std::length_error{"Size smaller than 0"};
            //the m_elements is initialized here, because we need to check the capacity first
            m_elements = std::make_unique<double[]>(capacity);
        }  //constructor that constructs a vector with given capacity

        Vector(std::initializer_list<double> list) :
                Vector(list.size())
        {
            for (auto d : list){
                push_back(d);
            }
        }

        //this is the copy constructor.
        Vector(const Vector &other):
                rax_container<T>(other),
                m_capacity{other.m_capacity},
                m_elements{std::make_unique<double[]>(other.m_capacity)} // here a new array of doubles is made with same capacity as the other's m_elements
        {
            for (size_type i = 0; i < m_size; ++i) {
                m_elements[i] = other.m_elements[i];
            }
        }

        // move constructor.
        Vector(Vector&& other) noexcept:
                rax_container<T>(other),
                m_capacity{std::exchange(other.m_capacity, 0)},
                m_elements{std::move(other.m_elements)}
        {}

        // copy assignment operator
        Vector& operator=(const Vector& other) {
            if (this != &other){    // first always check if an object is not being assigned to itself!
                rax_container<T>::operator=(other);

                if (m_capacity != other.m_capacity){    // in case the other vector capacity is different, fix this
                    m_elements = std::make_unique<double[]>(other.m_capacity);
                    m_capacity = other.m_capacity;
                }
                //finally copy the size and all the elements
                m_size = other.m_size;
                for (size_type i = 0; i < m_size; ++i) {
                    m_elements[i] = other.m_elements[i];
                }
            }
            return *this;   // operators that return a reference of the object's type usually must return *this
        }

        // move assignment operator
        Vector& operator=(Vector&&  other) noexcept {
            if (this != &other){
                rax_container<T>::operator=(other);
                m_capacity = std::exchange(other.m_capacity, 0);
                m_elements = std::move(other.m_elements);
            }
            return *this;
        }


        //functions for getting capacity and size
        //they are defined withing the header file
        size_type capacity() const { return m_capacity;}

        //the push_back function, it just adds a number at the end of the Vector
        void push_back(value_type e) {
            // check if the vector can still fit a new element
            if (m_size == m_capacity){

                if (m_capacity > 0)
                    m_capacity *= 2;
                else
                    m_capacity = 1;
                // if it cannot, resize the internal array:
                // here a new array of doubles is constructed
                auto p_new_elements = new value_type[m_capacity];

                // auto elements = std::make_unique<value_type[]>(m_capacity);
                //all the old elements are copied from the old array to the new one
                for (size_type i = 0; i < m_size; ++i) {
                    p_new_elements[i] = m_elements[i];
                }
                // m_elements = std::move(elements);
                //finally the unique_ptr is reset with the new array
                //it will delete the array it currently owns and replace it with the new array
                m_elements.reset(p_new_elements);
            }
            m_elements[m_size++] = e;
        }

        // removing the last element from the vector
        value_type pop_back() {
            if (m_size == 0) throw std::out_of_range{"No elements"};
            return m_elements[--m_size];
        }


        //accessing the elements of the vector by index
        value_type& at(size_type ind) {
            if (ind < 0 || ind >= m_size) throw std::out_of_range{"at: Index out of range"};
            return m_elements[ind];
        }

        const value_type& at(size_type ind) const {
            if (ind < 0 || ind >= m_size) throw std::out_of_range{"at: Index out of range"};
            return m_elements[ind];
        }

        //array subscript operator, with this we can access elements like this: v[ind]
        value_type& operator[](size_type ind) {
            if (ind >= size()) throw std::out_of_range{"Index out of range"};
            return m_elements[ind];
        }

        //the const variant of the array subscript operator
        const value_type& operator[](size_type ind) const {
            if (ind >= size()) throw std::out_of_range{"Index out of range"};
            return m_elements[ind];
        }

        // += operators
        Vector& operator+=(const Vector& other) {
            for(size_type i = 0; i < other.size(); ++i){
                push_back(other[i]);
            }
            return *this;
        }

        Vector& operator+=(std::initializer_list<value_type> &list) {
            throw std::runtime_error("not implemented");
        }

        operator bool() const {
            return m_size > 0;
        }

    private:
        size_type m_capacity;   //current capacity

        std::unique_ptr<T[]> m_elements; //smart pointer to an array of double's
    };

}

#endif //INC_SAX_VECTOR_H
