#include <studio.h>
#include "circular_buffer.h"

#define BUFFER_SIZE 5

int main(){
    //1. allocating a raw array in memory fo rthe data
    int raw_memory[BUFFER_SIZE];

    //2. creating the buffer management structure
    circ_bbuf_t my_buffer;

    //3. inizializing it
    circ_bbuf_init (&my_buffer, raw_memory, BUFFER_SIZE);
    printf("Buffer initialized!\n");

    //4. trying to push data into it
    printf("Pushing 10, 20, 30...\n");
    circ_bbuf_push(&my_buffer, 10);
    circ_bbuf_push(&my_buffer, 20);
    circ_bbuf_push(&my_buffer, 30);

    //5. trying to pop data out
    int popped_val;
    if(circ_bbuf_pop(&my_buffer, &popped_val)){
        printf("Popped value: %d (Expected: 10)\n", popped_val);
    }
    
    return 0;
}