#include <iostream>
#include <chrono>
#include <cstdint>

#define DTYPE float

extern "C" {
    void triad_low( uint64_t         i_n_values,
                    DTYPE    const * i_a,
                    DTYPE    const * i_b,
                    DTYPE          * o_c  );
}

int main(){
    uint64_t i_n_values = 100;

    DTYPE *i_a = (DTYPE*) malloc(i_n_values*sizeof(DTYPE));
    DTYPE *i_b = (DTYPE*) malloc(i_n_values*sizeof(DTYPE));
    DTYPE *io_c = (DTYPE*) malloc(i_n_values*sizeof(DTYPE));

    std::cout << "A: ";
    for (int i = 0; i < (int)i_n_values; i++)
    {
        *(i_a+i) = (DTYPE)(3*i);
        std::cout << 3*i << ", ";
    }

    std::cout << std::endl << "B: ";
    for (int i = 0; i < (int)i_n_values; i++)
    {
        *(i_b+i) = (DTYPE)(i_n_values-i);
        std::cout << (i_n_values-i) << ", ";
    }

    for (int i = 0; i < (int)i_n_values; i++)
    {
        *(io_c+i) = (DTYPE)0;
    }

    triad_low(i_n_values, i_a, i_b, io_c);

    std::cout << std::endl << "C after triad_low: ";
    for (int i = 0; i < (int)i_n_values; i++)
    {
        std::cout << io_c[i] << ", ";
    }
    
    std::cout << std::endl;

    free(i_a);
    free(i_b);
    free(io_c);
}