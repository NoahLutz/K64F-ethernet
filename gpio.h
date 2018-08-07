

#ifndef GPIO_H
#define GPIO_H

#include <MK64F12.h>

#define NUM_GPIO_PINS   3

    
typedef struct {
    PORT_Type* port;
    GPIO_Type* gpio;
    uint8_t pinNum;
} gpioPin_t;


extern gpioPin_t IO_LED_RED;
extern gpioPin_t IO_LED_BLUE;
extern gpioPin_t IO_LED_GREEN;



void initPins(void);
void outputHigh(const gpioPin_t* const pin);
void outputLow(const gpioPin_t* const pin);

#endif // GPIO_H
