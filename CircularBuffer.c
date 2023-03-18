#include "CircuralBuffer.h"


bool CircularBuffer_init(CircularBuffer* cb, size_t* size)
{
    if(cb == NULL)
        return false;
    cb->size = *size;
    cb->buff = (char*)malloc(cb->size);
    cb->count = 0;
    cb->head = 0;
    cb->tail = 0;
    printf("\nINIT DONE!\n");
    return true;
}

void CircularBuffer_deinit(CircularBuffer* cb)
{
    free(cb->buff);
    printf("\nMemory has been freed\n");
}

bool CircularBuffer_isFull(CircularBuffer* cb)
{
    if(cb->count == cb->size)
        return true;
    else
        return false;
}

bool CircularBuffer_isEmpty(CircularBuffer* cb)
{
    if(0 == cb->count)
        return true;
    
    return false;
}

bool CircularBuffer_clear(CircularBuffer* cb)
{
    if(NULL == cb)
        return false;

    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

bool CircularBuffer_putData(CircularBuffer* cb, char in)
{
    if(NULL == cb)
        return false;
    
    if(CircularBuffer_isFull(cb))
        return false;
    
    cb->buff[cb->head] = in;
    cb->count++;
    cb->head = (cb->head + 1) % cb->size;
    return true;
}

bool CircularBuffer_getData(CircularBuffer* cb, char* out)
{
    if(NULL == cb)
        return false;
    
    if(CircularBuffer_isEmpty(cb))
        return false;
    
    *out = cb->buff[cb->tail];
    cb->tail = (cb->tail + 1) % cb->size;
    cb->count--;
    return true;
}