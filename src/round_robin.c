#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <pthread.h>
#include "../include/proc.h"
#include "../include/p_queue.h"
#include <time.h>

#define DEFAULT_BURST 40
#define TIME_SLICE 40


unsigned long T;
unsigned int next_free_p_id;
unsigned last_pid;
unsigned no_of_p_exited;
p_queue* arrival_q = NULL;
p_queue* ready_q = NULL;
p_queue* departure_q = NULL;


void process_generator(int max_burst)    //random_process_generator thread
{
    //if(T>=50)return;
    
    unsigned int burst_r =DEFAULT_BURST+(rand()%(max_burst-DEFAULT_BURST));
    proc p = {0,T,burst_r,next_free_p_id};
    if(rand()%5 == 0)
    {
        enqueue_p(ready_q,p);
        printf("Process %d arrived with burst time = %d\n",next_free_p_id,burst_r);
        last_pid = next_free_p_id;
        next_free_p_id = next_free_p_id + 1;

    }

}


void process_execute(int slice) // our CPU kinda
{
    proc current_p = dequeue_p(ready_q);
    //printf("prcocess%d pc = %d burst_t = %d  \n",current_p.p_id,current_p.pc,current_p.burst_t);
    printf("Executing process : %d\n",current_p.p_id);
    register int cc = 0;
    for(cc=0;cc <= slice; cc++,(current_p.pc)++,T++)
    {
        if(T<1000)process_generator(250);
        if(current_p.pc == current_p.burst_t)
        {
            printf("Process %d exited\n",current_p.p_id);
            no_of_p_exited++;
            return;
        }

    }
    printf("Switching to next process\n");
    enqueue_p(ready_q,current_p);
}



int main()
{
    srand(time(NULL));//seed
    T = 0;//this global var is TIME var used to synchronize the entire simulation the global counter we approximated time to be discrete tho
    no_of_p_exited = 0;
    next_free_p_id = 1;
    arrival_q = createQueue();
    ready_q = createQueue();
    departure_q = createQueue();
    while((T>=1000)?(no_of_p_exited != last_pid):1)
    {
        if(!isEmpty(ready_q))process_execute(30);
        T++;
        if(T<1000)process_generator(250);

    }



    return 0;
}