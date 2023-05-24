        .type   sve_example_fmlalb, %function
        .global sve_example_fmlalb

/*
showcase the functionality of the sve instruction FMLALT. This operation widens the even-numbered half-precision elements in the source registers
to single precision format, performs the multiplication of the FMLA operation with these widened elements and adds the results to the respective
single precision elements of the destination register.
FMLALB <Zda>.S, <Zn>.H, <Zm>.H
@param x1 pointer to array A.         (16 bit HP values)
@param x2 pointer to array B.         (16 bit HP values)
@param x3 pointer to array C.         (32 bit FP values)
 */

sve_example_fmlalb:
        ptrue p0.B      // activate all pipelines
        LD1h {z0.h}, p0/Z, [x0]
        LD1h {z1.h}, p0/Z, [x1]
        LD1w {z2.s}, p0/Z, [x2]

        fmlalb z2.s, z0.h, z1.h 

        st1w {z2.s}, p0, [x2]

        ret
