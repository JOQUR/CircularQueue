#include "CircuralBuffer.h"


bool CircularBuffer_init(CircularBuffer* cb, size_t* size)
{
    if(cb == NULL)
        return false;
    CB(size) = *size;
    CB(buff) = (char*)malloc(CB(size));
    CB(count) = 0;
    CB(head) = 0;
    CB(tail) = 0;
    printf("\nINIT DONE!\n");
    return true;
}

void CircularBuffer_deinit(CircularBuffer* cb)
{
    free(CB(buff));
    printf("Memory has been freed\n");
}

bool CircularBuffer_isFull(CircularBuffer* cb)
{
    if(CB(count) == CB(size))
        return true;
    else
        return false;
}

bool CircularBuffer_isEmpty(CircularBuffer* cb)
{
    if(0 == CB(count))
        return true;
    
    return false;
}

bool CircularBuffer_clear(CircularBuffer* cb)
{
    if(NULL == cb)
        return false;

    CB(head) = 0;
    CB(tail) = 0;
    CB(count) = 0;
}

bool CircularBuffer_putData(CircularBuffer* cb, char in)
{
    if(NULL == cb)
        return false;
    
    if(CircularBuffer_isFull(cb))
        return false;
    
    CB(buff)[CB(head)] = in;
    CB(count)++;
    CB(head) = (CB(head) + 1) % CB(size);
    return true;
}

bool CircularBuffer_getData(CircularBuffer* cb, char* out)
{
    if(NULL == cb)
        return false;
    
    if(CircularBuffer_isEmpty(cb))
        return false;
    
    *out = CB(buff)[CB(tail)];
    CB(tail) = (CB(tail) + 1) % CB(size);
    CB(count)--;
    return true;
}