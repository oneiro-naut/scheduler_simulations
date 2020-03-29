#ifndef P_QUEUE_H
#define P_QUEUE_H
#include "proc.h"

#define MAX_SIZE 1000000

typedef struct p_queue{ 
    long front,rear,size;
    unsigned long capacity;
    proc* p_arr;
}p_queue;

p_queue* createQueue();
int isFull(p_queue* queue); // 0 or 1
int isEmpty(p_queue* queue);
void enqueue_p(p_queue* queue,proc p);
proc dequeue_p(p_queue* queue);
proc front(p_queue* queue);
proc rear(p_queue* queue);

#endif