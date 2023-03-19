#include "CircuralBuffer.h"

#define BUFF_SIZE 32

char outBuff[BUFF_SIZE];

int main(int argc, char **argv)
{
    char* data = argv[1];
    size_t dataSize = BUFF_SIZE;
    CircularBuffer buffer;
    CircularBuffer_init(&buffer, &dataSize);
    
    for(int i = 0; i < dataSize; i++)
    {
        CircularBuffer_putData(&buffer, data[i]);
    }

    char output;

    for(int i = 0; i < (dataSize); i++)
    {
        CircularBuffer_getData(&buffer, &output);
        if(0x00 == output)
            break;

        outBuff[i] = output;
    }

    CircularBuffer_clear(&buffer);
    printf("============================================================\n");
    CircularBuffer_deinit(&buffer);
    printf("============================================================\n");

    for(int i = 0; i < BUFF_SIZE; i++)
    {
        if(0x00 == outBuff[i])
            break;
        
        printf("\033[31m%c", outBuff[i]);
        
    }
    printf("\033[0m");
    printf("\n============================================================\n");

    return 0;
}
