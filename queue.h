/******************************************************************************
*
* Project:	K64F_ethernet
* Author:	Noah Lutz
*
* ----------------------------------------------------------------------------
*                                  queue.h
*
*								Circular Queue
******************************************************************************/

#include <stdint.h>
#include <stdbool.h>

typedef struct {
	uint8_t* start;
	uint8_t* end;
	uint16_t size;
} Queue_t;


Queue_t* createQueue(uint16_t size);
void freeQueue(Queue_t* queue);
uint8_t queuePeek(Queue_t* queue);
uint8_t queuePop(Queue_t* queue);
void queuePush(Queue_t* queue, uint8_t value);
bool queueEmpty(Queue_t* queue);
bool queueFull(Queue_t* queue);
