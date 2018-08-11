/******************************************************************************
*
* Project:	K64F_ethernet
* Author:	Noah Lutz
*
* ----------------------------------------------------------------------------
*                                  queue.c
*
*								Circular Queue
******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include "queue.h"


typedef struct {
	uint8_t* start;
	uint8_t* end;
	uint16_t size;
	uint16_t numItems;
	uint8_t* inPtr;
	uint8_t* outPtr;
} PrivateQueue_t;


/******************************************************************************
*
* Function:		createQueue()
*
* Description:	Initializes a queue of a given size
*
* Parameters:	size - size of queue
*
* Returns:		pointer to queue
*
******************************************************************************/
Queue_t* createQueue(uint16_t size) {
	PrivateQueue_t* queue;

	// Allocate memory for buffer
	uint8_t* buffer = malloc(size);

	queue->start = buffer;
	queue->end = buffer + size;
	queue->size = size;
	queue->numItems = 0;
	queue->inPtr = buffer;
	queue->outPtr = buffer;

	return (Queue_t*) queue;
}

/******************************************************************************
*
* Function:		freeQueue()
*
* Description:	Frees a queue
*
* Parameters:	queue - queue to free
*
* Returns:		None
*
******************************************************************************/
void freeQueue(Queue_t* queue) {
	free(queue->start);

	// Zero out queue info
	memset(queue, 0u, sizeof(PrivateQueue_t));
}

/******************************************************************************
*
* Function:		queuePeek()
*
* Description:	Returns the next item in the queue without removing it
*				if not empty
*
* Parameters:	queue -  
*
* Returns:		Next value in queue
*
******************************************************************************/
uint8_t queuePeek(Queue_t* queue) {
	PrivateQueue_t* pq = (PrivateQueue_t*) queue;
	
	if (!queueEmpty(queue)) {
		return *(pq->outPtr);
	}

	return NULL;
}

/******************************************************************************
*
* Function:		queuePop()
*
* Description:	pops the next item in the queue, if not empty
*
* Parameters:	queue -  
*
* Returns:		Next value in queue
*
******************************************************************************/
uint8_t queuePop(Queue_t* queue) {
	PrivateQueue_t* pq = (PrivateQueue_t*) queue;
	
	if (!queueEmpty(queue)){

		uint8_t value = *(pq->outPtr);

		// Increment outPtr and wrap around if needed
		if (pq->outPtr >= pq->end){
			pq->outPtr = pq->start;
		}
		else {
			pq->outPtr++;
		}

		pq->numItems--;

		return value;
	}

	return NULL;
}

/******************************************************************************
*
* Function:		queuePush()
*
* Description:	Pushes an item to the queue if not full
*
* Parameters:	queue -  
*
* Returns:		None
*
******************************************************************************/
void queuePush(Queue_t* queue, uint8_t value) {
	PrivateQueue_t* pq = (PrivateQueue_t*) queue;
	
	if (!queueFull(queue)) {

		*(pq->inPtr) = value;

		// increment inPtr and wrap around if needed
		if (pq->inPtr >= pq->end) {
			pq->inPtr = pq->start;
		}
		else {
			pq->inPtr++;
		}

		pq->numItems++;
	}
}

/******************************************************************************
*
* Function:		queueEmpty()
*
* Description:	Checks if queue is empty
*
* Parameters:	queue -  
*
* Returns:		true - empty
*				false - not empty
*
******************************************************************************/
bool queueEmpty(Queue_t* queue) {
	PrivateQueue_t* pq = (PrivateQueue_t*) queue;

	return pq->numItems == 0;
}

/******************************************************************************
*
* Function:		queueFull()
*
* Description:	Checks if queue is full
*
* Parameters:	queue -  
*
* Returns:		true - full
*				false - not full
*
******************************************************************************/
bool queueFull(Queue_t* queue) {
	PrivateQueue_t* pq = (PrivateQueue_t*) queue;

	return pq->numItems == pq->size;
}
