        .type   sve_example_eor, %function
        .global sve_example_eor

/*
showcase the functionality of the sve instruction FMLALT. This operation widens the even-numbered half-precision elements in the source registers
to single precision format, performs the multiplication of the FMLA operation with these widened elements and adds the results to the respective
single precision elements of the destination register.
FMLALB <Zda>.S, <Zn>.H, <Zm>.H
@param x1 pointer to array A.         (16 bit HP values)
@param x2 pointer to array B.         (16 bit HP values)
@param x3 pointer to array C.         (32 bit FP values)
 */

sve_example_eor:
        ptrue p0.B      // activate all pipelines
        LD1d {z0.D}, p0/Z, [x0]
        LD1d {z1.D}, p0/Z, [x1]
        LD1d {z2.D}, p0/Z, [x2]

        EOR3 z2.D, z2.D, z1.D, z0.D 

        st1w {z2.D}, p0, [x2]

        ret
