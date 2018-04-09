#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include "vector.h"
#include "Integer.h"


// utility function for printing a vector
// (notice that it woul be much better to implement it as operator<< in the Vector class)
void print_vector(const sax::Vector& v){
    std::cout << "\nCapacity: " << v.capacity() << ", Size: " << v.size() << "\n";
    for (int i = 0; i < v.size(); ++i){
        std::cout << "Element at index: ";
        std::cout << i << " : " << v[i] << "\n";
    }
}

void demo_vector(){
    std::cout << "\n\n------sax::Vector demo-----\n\n";

    constexpr int capacity{4};

    //default-construction of vector
    //it's capacity will be 16
    auto vec1 = sax::Vector{};
    vec1.push_back(42);

    //here vec2 is copy-constructed from vec1
    auto vec2 = vec1;
    vec2.push_back(55);

    std::cout << "\nvec1:";
    print_vector(vec1);
    std::cout << "\nvec2:";
    print_vector(vec2);


    std::cout << "\nCopy assigning vec2 to vec1" << "\n";
    //copy assignment
    vec1 = vec2;

    std::cout << "\nvec1:";
    print_vector(vec1);
    std::cout << "\nvec2:";
    print_vector(vec2);

}

void demo_integer(){
    std::cout << "\n\n------Integer demo-----\n\n";

    Integer a = 2; //this uses the implicit constructor from int
    Integer b{3};
    std::cout << "a= " << (int)a << "\n";
    std::cout << "b= " << static_cast<int>(b) << "\n"; // C++ way of casting, btw casting to int is possible because of operator int()

    a *= b; // using the operator*=
    std::cout << "a= " << static_cast<int>(a) << "\n";

    std::cout << std::boolalpha; //just a switch for std::cout so it will print bool's as 'true' and 'false'

    std::cout << "a < b? " << (a < b) << "\n";  //testing the operator<

    //now this one is tricky, what happens under tha hood is this:
    // Integer temp{2};
    // a = temp;
    // so the compiler first creates a temporary object of type Integer using the constructor that takes an int
    // and than uses a copy assignment operator to assign this temporary object to a
    a = 2;
    b = 3;


    std::cout << "a= " << a << "\n";    // uses stream output operator
    std::cout << "b= " << b << "\n";    // uses stream output operator

    std::cout << "a > b? " << (a > b) << "\n";  // free func. operator >

    std::cout << "a^b= " <<  (a^b) << "\n";     // free func. operator ^

}

int main() {
    demo_vector();

    demo_integer();
}