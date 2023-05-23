#include <iostream>  

void triad_high( uint64_t         i_n_values,
                 float    const * i_a,
                 float    const * i_b,
                 float          * o_c ) {
    for( uint64_t l_va = 0; l_va < i_n_values; l_va++ ) {
        o_c[l_va] = i_a[l_va] + 2.0f * i_b[l_va];
    }
}