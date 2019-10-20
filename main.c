#include "system_MK64F12.h"
#include <stdlib.h>
#include "MK64F12.h"
//#include "gpio.h"
//#include "queue.h"

unsigned char malloc_mempool[1024u];


int main(int argc, char **argv) {
    SystemInit();

    init_mempool(&malloc_mempool, sizeof(malloc_mempool));
	
    initPins();
    
    outputLow(&IO_LED_GREEN);

	//Queue_t* queue = createQueue(4);

	//queuePush(queue, 1);

	//if(!queueEmpty(queue)){
	//	outputLow(&IO_LED_RED);
	//}
	//
	//if(!queueFull(queue)){
	//	outputLow(&IO_LED_RED);
	//}

	//if(queuePeek(queue) != 1){
	//	outputLow(&IO_LED_RED);
	//}

	//outputLow(&IO_LED_BLUE);
    
    while (1);
}
