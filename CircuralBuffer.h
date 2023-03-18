#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct {
    char* buff;
    int head, tail, count, size;
} CircularBuffer;


bool CircularBuffer_init(CircularBuffer* cb, size_t* size);
void CircularBuffer_deinit(CircularBuffer* cb);
bool CircularBuffer_isFull(CircularBuffer* cb);
bool CircularBuffer_isEmpty(CircularBuffer* cb);
bool CircularBuffer_clear(CircularBuffer* cb);
bool CircularBuffer_putData(CircularBuffer* cb, char in);
bool CircularBuffer_getData(CircularBuffer* cb, char* out);

#endif
