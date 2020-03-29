#include "../include/p_queue.h"
#include <stdlib.h>  
// function to create a queue of given capacity.  
// It initializes size of queue as 0 
p_queue* createQueue() 
{ 
    p_queue* queue = (p_queue*) malloc(sizeof(p_queue)); 
    queue->capacity = MAX_SIZE; 
    queue->front = queue->size = 0;  
    queue->rear = MAX_SIZE - 1;  // This is important, see the enqueue 
    queue->p_arr = (proc*) malloc(queue->capacity * sizeof(proc)); 
    return queue; 
} 
  
// Queue is full when size becomes equal to the capacity  
int isFull(p_queue* queue) 
{  return (queue->size == queue->capacity);  } 
  
// Queue is empty when size is 0 
int isEmpty(p_queue* queue) 
{  return (queue->size == 0); } 
  
// Function to add an item to the queue.   
// It changes rear and size 
void enqueue_p(p_queue* queue,proc p) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1)%queue->capacity; 
    (queue->p_arr[queue->rear]).pc = p.pc,
    (queue->p_arr[queue->rear]).arrv_t = p.arrv_t;
    (queue->p_arr[queue->rear]).burst_t = p.burst_t;
    (queue->p_arr[queue->rear]).p_id = p.p_id; 
    queue->size = queue->size + 1; 
//    printf("%d enqueued to queue\n", item); 
} 
  
// Function to remove an item from queue.  
// It changes front and size 
proc dequeue_p(p_queue* queue) 
{ 
    proc dead = {0,0,0,0};
    if (isEmpty(queue)) 
        return dead; 
    proc item = queue->p_arr[queue->front]; 
    queue->front = (queue->front + 1)%queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 
  
// Function to get front of queue 
proc front(p_queue* queue) 
{ 
    proc dead = {0,0,0,0};
    if (isEmpty(queue)) 
        return dead; 
    return queue->p_arr[queue->front]; 
} 
  
// Function to get rear of queue 
proc rear(p_queue* queue) 
{ 
    proc dead = {0,0,0,0};
    if (isEmpty(queue)) 
        return dead; 
    return queue->p_arr[queue->rear]; 
} 
 





