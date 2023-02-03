#include "BitVector.h"

int main()
{
    BitVector bitvector;
    bitvector.set(1, 1);
    bitvector.set(65, 1);
    bitvector.set(129, 1);
    std::cout << bitvector; //The output should be 2 2 2
}