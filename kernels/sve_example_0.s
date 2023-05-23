        .text
        .align 4
        .type   sve_example_0, %function
        .global sve_example_0
sve_example_0:
        // start trace
        .inst 0x2520e020

        ldr z0, [x0]
        str z0, [x1]

        //stop trace
        .inst 0x2520e040
        ret