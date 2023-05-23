#include <iostream>  

extern "C" {
    void sve_example_0( uint32_t *l_dataIn,
                        uint32_t *l_dataOut);
    void sve_example_1( uint32_t *l_dataIn,
                        uint32_t *l_dataOut);
}

int main(   int i_argc,  
            char const * i_argv[] ) {
                
    if( i_argc != 2 ) {
        std::cerr << "error, run as ./sve_examples EXAMPLE_ID" << std::endl;
    }
    
    uint32_t l_dataIn[128] = {0};
    uint32_t l_dataOut[128] = {0};
    
    for( unsigned short l_en = 0; l_en < 128; l_en++ ) {
        l_dataIn[l_en] = (l_en+1) * 2;
    }

    int l_ex = atoi( i_argv[1] );
    
    if( l_ex == 0 ) {
        sve_example_0(  l_dataIn,
                        l_dataOut );
    } 
    
    if( l_ex == 1 ) {
        sve_example_1(  l_dataIn,
                        l_dataOut );
    } 

    //  […]

    if( l_ex <= 3 || l_ex == 6 ) {
        for( unsigned short l_en = 0; l_en < 64; l_en++ ) {
            std::cout << "en / in / out: " << l_en << "\t/\t "
            << l_dataIn[l_en] << "\t/\t " << l_dataOut[l_en] << std::endl;
        }
    }

    //  […]
    
    return EXIT_SUCCESS;
}
