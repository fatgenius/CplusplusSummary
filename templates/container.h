//
// Created on 19/11/2017.
//

#ifndef INC_SAX_CONTAINER_H
#define INC_SAX_CONTAINER_H
namespace sax {

    // random access container
    template <typename T>
    class rax_container {
    public:

        // constructor
        rax_container(): m_size{0}{}

        using size_type = int;
        using value_type = T;

        size_type size() const { return m_size; }

        // index access by function
        virtual value_type& at(size_type ind) = 0;
        virtual const value_type& at(size_type ind) const = 0;

        //index access operator to get the elements out of Vector in a pleasing way
        virtual value_type& operator[](size_type ind) = 0;
        // const variant of the index access operator
        virtual const value_type& operator[](size_type ind) const = 0;

        virtual ~rax_container() {};

    protected:
        size_type m_size;

    };
}
#endif //INC_SAX_CONTAINER_H
