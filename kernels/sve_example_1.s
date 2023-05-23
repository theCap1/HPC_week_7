        .type   sve_example_1, %function
        .global sve_example_1
        
sve_example_1: 
        // start trace
        .inst 0x2520e020

        ptrue p0.d // only set every eigth bit
        ld1w {z0.s}, p0/z, [x0]
        str z0, [x1]

        //stop trace
        .inst 0x2520e040
        ret