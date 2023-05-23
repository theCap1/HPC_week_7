        .text
        .align 4
        .type   triad_low, %function
        .global triad_low
        /*
        On a high level this kernel shall implement the following high level function

        void triad_high(uint64_t         i_n_values,
                        float    const * i_a,
                        float    const * i_b,
                        float          * o_c ) {
            for( uint64_t l_va = 0; l_va < i_n_values; l_va++ ) {
                o_c[l_va] = i_a[l_va] + 2.0f * i_b[l_va];
            }
        }

        This means we get i_n_values values in the arrays i_a, i_b and o_c and we shall implement a fused multiply add
        operation with the elements of the arrays of the same index and the multiplicant 2 like
        C[i] = A[i] + 2 * B[i]

        @param x0 value of i_n_values.  (64 bit)
        @param x1 pointer to A.         (32 bit values)
        @param x2 pointer to B.         (32 bit values)
        @param x3 pointer to C.         (32 bit values)
        */
triad_low:
        mov x4, #0                      // initialize x4

        loop:
            whilelt p0.s, x4, x0        // only activate as many pipelines as needed
            LD1W {z0.s}, p0/Z, [x1]     // get values from A into active pipelines of register
            LD1W {z1.s}, p0/Z, [x2]     // get values from B into active pipelines of register
            fmov z2.s, p0/M, #2         // move contant value 2 into active pipelines of register
            fmla z0.s, p0/M, z2.s, z1.s // execute A[i] += 2 * B[i] for individual elements in registers
            st1w {z0.s}, p0, [x3]       // store previous results from fmla to C[i]
            addvl x1, x1, #1            // change address of A so that next iteration values are read from the right place in memory
            addvl x2, x2, #1            // change address of B so that next iteration values are read from the right place in memory
            addvl x3, x3, #1            // change address of C so that next iteration values are written to the right place in memory
            addpl x4, x4, #2            // add 2*#bytes of predicate register to x4 -> number of values that fit into one full vector
            b.last loop                 // loop if last active entry was false
        ret