#include <system_MK64F12.h>
#include "MK64F12.h"
#include "gpio.h"

int main(int argc, char **argv) {
    SystemInit();
    
    initPins();
    
    outputLow(&IO_LED_GREEN);
    
    while (1);
}
