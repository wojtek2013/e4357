/* UCSCX 4357 - HW1 - Wojciech Wojciak
   write functions converting gray o binary and binary to gray
   REFERENCES / ACKNOWLEDGMENTS:
   http://en.wikipedia.org/wiki/Gray_code
/*

/* exemplary (4bit) Gray / Binary table

    Gray <-> Binary
    0000     0000  0
    0001     0001  1
    0011     0010  2
    0010     0011  3
    0110     0100  4
    0111     0101  5
    0101     0110  6
    0100     0111  7
    1100     1000  8
    1101     1001  9
    1111     1010  A
    1110     1011  B
    1010     1100  C
    1011     1101  D
    1001     1110  E
    1000     1111  F
*/

#include <stdio.h>


/*************************************************************/
/* FUNCTION bin2gray
   INPUT: unsigned int
   OUTPUT: unsigned int
   ALGORITHM: return input shifted right once and XOR-ed with original input
*/
unsigned int bin2gray(unsigned int bin)
{
  return ( bin >> 1 ) ^ bin;
}

/*************************************************************/
/* FUNCTION gray2bin
   INPUT: unsigned int
   OUTPUT: unsigned int
   ALGORITHM: 1. shift input right once and use it as a mask.
              2. XOR input with mask
              3. repeat 1 & 2 until mask is 0.
*/
unsigned int gray2bin(unsigned int gray)
{
  unsigned int mask;
  unsigned int ret = gray;
  for( mask = gray >> 1; mask != 0; mask = mask >> 1 ) {
    ret = ret ^ mask;
  }
  return ret;
}

/*************************************************************/
/* FUNCTION printUsage()*/
void printUsage()
{
  printf("usage: convertBG <mode> [<input>]\n");
  printf("       mode: 0 - bin to gray\n");
  printf("       mode: 1 - gray to bin\n");
  printf("       mode: 2 - test 0-15\n");
  printf("       input: integer number\n");
}

/*************************************************************/
int main( int argc, char* argv[] )
{

  if(argc < 2) {
    printUsage();
    return -1;
  }

  int mode = atoi(argv[1]);

  if( argc==3 && mode > 1 ) {
    printUsage();
    return -1;
  }

  if( argc==2 && mode != 2) {
    printUsage();
    return -1;
  }
 
  unsigned int inp;
  unsigned int i;
  if(mode==0) {
    inp = (unsigned int) atoi(argv[2]);
    printf("binary %u converted to gray is: %u\n", inp, bin2gray(inp));
  } else if(mode==1) {
    inp = (unsigned int) atoi(argv[2]);
    printf("gray %u converted to binary is: %u\n", inp, gray2bin(inp));
  } else if(mode==2) {
    for(i=0; i<16; i++) {
      printf("binary %u converted to gray is: %u\n", i, bin2gray(i));
    }
    for(i=0; i<16; i++) {
      printf("gray %u converted to binary is: %u\n", i, gray2bin(i));
    }
  } else {
    printUsage();
  }

  return 0;
}
