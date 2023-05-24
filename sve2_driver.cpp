#include <iostream>
#include <cstdint>
#include <arm_fp16.h>

#define DTYPE float16_t

extern "C" {
    void sve_example_fmlalt(    DTYPE    const * i_a,
                                DTYPE    const * i_b,
                                float          * io_c  );
    void sve_example_fmlalb(    DTYPE    const * i_a,
                                DTYPE    const * i_b,
                                float          * io_c  );
    void sve_example_eor(       int    const * i_a,
                                int    const * i_b,
                                int          * io_c  );
}

void printBits(int* array, int size){
    for (int i = 0; i < size; i++) {
        for (int j = 7; j >= 0; j--) {
            std::cout << ((array[i] >> j) & 1);
        }
        std::cout << " / ";
    }
    std::cout << std::endl;
}

void setAllBitsToOne(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = ~0;  // Set all bits to 1
    }
}

void setEverySecondBitToOne(int* array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < 8; j += 2) {
            array[i] |= (1 << j);  // Set every second bit to 1
        }
    }
}

void setEveryThirdBitToOne(int* array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 2; j < 8; j += 3) {
            array[i] |= (1 << j);  // Set every third bit to 1
        }
    }
}

int main(   int i_argc,  
            char const * i_argv[] ){

    if( i_argc != 2 ) {
        std::cerr << "error, run as ./sve_examples EXAMPLE_ID" << std::endl;
    }
    
    int l_ex = atoi( i_argv[1] );
    
    uint64_t i_n_values = 0;

    if (l_ex <= 1)
    {
        i_n_values = 20;

        DTYPE *i_a = (DTYPE*) malloc(i_n_values*sizeof(DTYPE));
        DTYPE *i_b = (DTYPE*) malloc(i_n_values*sizeof(DTYPE));
        float *io_c = (float*) malloc(i_n_values*sizeof(float));

        // std::cout << "A: ";
        for (int i = 0; i < (int)i_n_values; i++)
        {
            *(i_a+i) = (DTYPE)(3*i);
            // std::cout << 3*i << ", ";
        }

        // std::cout << std::endl << "B: ";
        for (int i = 0; i < (int)i_n_values; i++)
        {
            *(i_b+i) = (DTYPE)(i_n_values-i);
            // std::cout << (i_n_values-i) << ", ";
        }

        for (int i = 0; i < (int)i_n_values; i++)
        {
            *(io_c+i) = (DTYPE)i;
        }

        if (l_ex == 0)
        {
            sve_example_fmlalt(i_a, i_b, io_c);
            std::cout << "After fmlalt: ";
            std::cout << "A/ B index" << " / " << "i_a[i]" << " / " << "i_b[i]" << " / " << "io_c[i]" << " / " << "C index" << std::endl;
            for (int i = 0; i < (int)(i_n_values/2); i++)
            {
                std::cout << i*2 << " / " << i_a[2*i] << " / " << i_b[2*i] << std::endl;
                std::cout << i*2+1 << " / " << i_a[2*i+1] << " / " << i_b[2*i+1] << " / " << io_c[i] << " / " << i << std::endl;
            }
        }

        if (l_ex == 1)
        {
            sve_example_fmlalb(i_a, i_b, io_c);
            std::cout << "After fmlalb: ";
            std::cout << "A/ B index" << " / " << "i_a[i]" << " / " << "i_b[i]" << " / " << "io_c[i]" << " / " << "C index" << std::endl;
            for (int i = 0; i < (int)(i_n_values/2); i++)
            {
                std::cout << i*2 << " / " << i_a[2*i] << " / " << i_b[2*i] << " / " << io_c[i] << " / " << i << std::endl;
                std::cout << i*2+1 << " / " << i_a[2*i+1] << " / " << i_b[2*i+1] << std::endl;
            }
        }    
        
        std::cout << std::endl;

        free(i_a);
        free(i_b);
        free(io_c);
    }
    
    if (l_ex == 2)
    {
        i_n_values = 8;

        int *i_a = (int*) malloc(i_n_values*sizeof(int));
        int *i_b = (int*) malloc(i_n_values*sizeof(int));
        int *io_c = (int*) malloc(i_n_values*sizeof(int));
        int *old_c = (int*) malloc(i_n_values*sizeof(int));

        setAllBitsToOne(i_a, i_n_values);
        setEverySecondBitToOne(i_b, i_n_values);
        setEveryThirdBitToOne(io_c, i_n_values);
        setEveryThirdBitToOne(old_c, i_n_values);


        sve_example_eor(i_a, i_b, io_c);
        

        std::cout << "After EOR3: " << std::endl;
        std::cout << "i_a[i]:\t\t";
        printBits(i_a, i_n_values);

        std::cout << "i_b[i]:\t\t";
        printBits(i_b, i_n_values);
        

        std::cout << "old_c[i]:\t";
        printBits(old_c, i_n_values);
        

        std::cout << "io_c[i]:\t";
        printBits(io_c, i_n_values);
        

        free(i_a);
        free(i_b);
        free(io_c);
        free(old_c);
    }
    
    
}