//
// Created  on 12/11/2017.
//

#ifndef INC_01_TRY_INTEGER_H
#define INC_01_TRY_INTEGER_H


#include <ostream>

// Integer is a header-only class
// It is a common practice to write header-only implementations for very simple classes

class Integer{
private:
    //private variable holding the value as primitive type
    int m_number;

public:
    // ctor, notice it's not explicit, because it actually makes sense to have automatic type conversion like this:
    // Integer n = 5;
    Integer(int number): m_number{ number } {}

    // below is the copy constructor marked as deleted
    // copy constructor is synthesized automatically by the compiler
    // if you uncomment the line below, the compiler won't synthesize copy constructor
    // see what happens then if you try to compile the program
//    Integer(const Integer& other) = delete;

    // this is an implementation of the copy assignment operator
    // this function is automagically synthesized by the compiler
    // but you are free to re-implement it yourself
    // here just some logging to std::cout was added
    Integer& operator=(const Integer& o){
        std::cout << "copy-assigning " << o.m_number << " to " << m_number << "\n";
        m_number = o.m_number;
        return *this;
    }

    // operator *=
    // this operator is used to multiply some other integer with the current instance
    // that's why after doing multiplication we need to return this
    Integer& operator*=(const Integer& other){
        m_number *= other.m_number;
        //this is a pointer to the current instance
        //since we need to return a reference and not a pointer, we need to de-reference this by using *
        return *this;
    }

    // less than operator
    // note that this function is const. It is a good practice to mark the function that do not modify the class as const
    bool operator<(const Integer& rhs) const {
        return m_number < rhs.m_number;
    }

    // type conversion operator, thanks to this one we can cas Integer to int
    operator int() const { return m_number; }
};

// Below are the operators that are implemented as free functions:

//multiplication operator, we are re-using *= operator defined in the Integer class
inline Integer operator*(Integer lhs, Integer rhs){
    lhs *= rhs;
    return lhs;
}

// greater than oerator
inline bool operator>(const Integer& lhs, const Integer& rhs){
    return rhs < lhs;
}

// and now something weired, normally the ^ operator performs bitwise XOR
// but for the Integer objects we want it to perform exponentiation:
inline Integer operator^(Integer base, Integer exponent){
    int _exponent{exponent};
    Integer mul{base};
    while(--_exponent){
        base *= mul;
    }
    return base;
}

// and the last and a very useful one stream output operator
// with this one we'll be able to print Integer objects likes this:
// std::cout << a;
inline std::ostream& operator<<(std::ostream &os, const Integer &integer) {
    os << "Integer: " << static_cast<int>(integer);
    return os;
}

#endif //INC_01_TRY_INTEGER_H
