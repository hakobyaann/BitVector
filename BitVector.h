#ifndef VECTOR_BIT
#define VECTOR_BIT

#include <iostream>

class BitVector
{
private:
        unsigned long long *_ptr;
        unsigned long long _size;
public:
        BitVector();
        BitVector(unsigned long long);
        ~BitVector();
public:
        void resize(unsigned long long);
        void set(unsigned long long, const bool);
        bool operator[](unsigned long long);
        friend std::ostream& operator<< (std::ostream&, const BitVector&); 
        unsigned long long get_size();
};

#endif