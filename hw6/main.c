#include "crcbuf.h"
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE    8 
#define NUM_OF_ELEMS   (BUFFER_SIZE-1)

int main(int argc, char *argv[])
{
  CircularBuffer* que;
  KeyType a = 101;
  int isEmpty, i;
 
  CircularBufferInit(&que, BUFFER_SIZE);
        CircularBufferPrint(que);
 
        for(i=1; i<=3; i++)
        {  
            a=10*i;
            printf("\n\n===\nTest: Insert %d-%d\n", a, a+NUM_OF_ELEMS-1);
            while(! CircularBufferEnque(que, a++));
 
            //CircularBufferPrint(que);
            printf("\nRX%d:", i);
            a=0;
            isEmpty = CircularBufferDeque(que, &a); 
            while (!isEmpty)
            {
                printf("%02d ", a);
                a=0;
                isEmpty = CircularBufferDeque(que, &a); 
            }
            //CircularBufferPrint(que);
        }
 
        free(que);
        return 0;
}
