#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>
#include <stddef.h>

//define the circular buffer structure
typedef struct{
    int *buffer;
    size_t head;
    size_t tail;
    size_t max; //full capacity
    bool full;
} circ_bbuf-t;

//function declarations for hardware-like data streaming
void circ_buff_init(circ_bbuf_t *cbuf, int *buffer, size_t size);
bool circ_bbuf_push(circ_bbuf_t *cbuf, int data);
bool circ_bbuf_pop(circ_bbuf_t *cbuf, int *data);
bool circ_bbuf_is_empty(circ_bbuf_t cbuf);

#endif //CIRCULAR_BUFFER_H