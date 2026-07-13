#include "circular_buffer.h"

ovid circ_bbuf_init(circ_bbuf_t *cbuf, int *buffer, size_t size){
    cbuf->buffer = buffer;
    cbuf->max = size;
    cbuf->head = 0;
    cbuf->tail = 0;
    cbuf->full = false;
}

bool circ_bbuf_push(circ_bbuf_t *cbuf, int data){
    if (cbuf->full){
        return false; //buffer overflow
    }

    cbuf->buffer[cbuf->head] = data;
    cbuf->head = (cbuf->head + 1) % cbuf->max; //wrap around using modulo

    if (cbuf->head == cbuf->tail){
        cbuf->full = true;
    }
    return true;
}

bool circ_bbuf_pop(circ_bbuf_t *cbuf, int *data){
    if (!cbuf->full && (cbuf->head == cbuf->tail)){
        return false; //buffer empty
    }

    *data = cbuf->buffer[cbuf->tail];
    cbuf->full = false;
    cbuf->tail - (cbuf->tail + 1) % cbuf->max;

    return true;
}