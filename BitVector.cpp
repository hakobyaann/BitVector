#include "BitVector.h"

//Default constructor
BitVector::BitVector()
{
    this->_size = 1;
    this->_ptr = new unsigned long long[_size];
}

//Constructor with parameters
BitVector::BitVector(unsigned long long size)
{
    this->_size = (size / (sizeof(unsigned long long) * 8)) + 1;
    unsigned long long chlp = size / (sizeof(unsigned long long) * 8);
    this->_ptr = new unsigned long long[++chlp];
}

//Destructor
BitVector::~BitVector()
{
    delete this->_ptr;
    this->_ptr = nullptr;
    this->_size = 0;
}

void BitVector::resize(unsigned long long size)
{
    unsigned long long tmp = size / ((sizeof(long long) * 8));
    unsigned long long* ptr = new unsigned long long[++tmp];

    for (int i = 0; i < _size; ++i)
    {
        ptr[i] = _ptr[i];
    }

    delete[] _ptr;
    _ptr = ptr;
    ptr = nullptr;
    this->_size = tmp;
}

unsigned long long BitVector::get_size()
{
    return this->_size;    
}

//set&reset
void BitVector::set(unsigned long long index, const bool value)
{
    
    if (index >= this->_size * sizeof(long long) * 8) 
    {
        this->resize(index);
    }

    unsigned long long i = index / (sizeof(unsigned long long) * 8);
    unsigned long long shift = index - (i * (sizeof(unsigned long long) * 8));

    if (value)  
    { 
        _ptr[i] |= (value << shift); 
    }
    else 
    {
        _ptr[i] &= ~(1 << shift); 
    }
}

//Operator<< overloading
std::ostream& operator<< (std::ostream& os, const BitVector& b) 
{
    unsigned long long tmp = b._size;
    for (int i = 0; i < tmp; ++i)
    {
       os << b._ptr[i] << " ";
    }
    os << std::endl;
    return os;
}

//Operator[] overloading
bool BitVector::operator[](const unsigned long long index)
{
    unsigned long long i = index / (sizeof(unsigned long long) * 8);
    unsigned long long shift = index - (i * (sizeof(unsigned long long) * 8));

    return _ptr[i] & (1 << shift); 
}