#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "CircuralBuffer.h"



int main(int argc, char **argv)
{
    char* data = argv[1];
    size_t dataSize = sizeof(data);
    printf("DataSize = %d", dataSize);
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
        printf("Output: %c\n", output);
    }
    CircularBuffer_clear(&buffer);
    printf("============================================================\n");
    data = argv[2];
    dataSize = sizeof(data);
    for(int i = 0; i < dataSize; i++)
    {
        CircularBuffer_putData(&buffer, data[i]);
    }
    for(int i = 0; i < (dataSize); i++)
    {
        CircularBuffer_getData(&buffer, &output);
        if(0x00 == output)
            break;
        printf("Output: %c\n", output);
    }
    CircularBuffer_deinit(&buffer);

    return 0;
}
