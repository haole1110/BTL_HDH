#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if(q->size < MAX_QUEUE_SIZE && proc != NULL && q->size > -1) {
		q->proc[q->size] = proc;
		q->size++;
		return;
	}
	printf("ERROR ENQUENE");
	return;

}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (q->size == 0) return NULL;
	uint32_t max_priority = q->proc[0]->priority;
	int index = 0;
	for (int i=1; i<q->size; i++){
		if (max_priority < q->proc[i]->priority){
			max_priority = q->proc[i]->priority;
			index = i;
		}
	}
	struct pcb_t* temp = q->proc[index];
	q->proc[index] = q->proc[q->size - 1];
	q->size--;
	q->proc[q->size] = NULL;
	return temp;
}

