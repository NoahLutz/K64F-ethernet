
#include "gpio.h"

gpioPin_t IO_LED_RED = {PORTB, PTB, 22};
gpioPin_t IO_LED_BLUE = {PORTB, PTB, 21};
gpioPin_t IO_LED_GREEN = {PORTE, PTE, 26};


void initPins(void) {
    // Enable ports
    SIM_SCGC5 |= (SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTE_MASK);
    
    // Set pin to GPIO and pulldown/pullup
    IO_LED_RED.port->PCR[IO_LED_RED.pinNum] |= (PORT_PCR_PE_MASK | PORT_PCR_PS_MASK | PORT_PCR_MUX(0x001));
    IO_LED_BLUE.port->PCR[IO_LED_BLUE.pinNum] |= (PORT_PCR_PE_MASK | PORT_PCR_PS_MASK | PORT_PCR_MUX(0x001));
    IO_LED_GREEN.port->PCR[IO_LED_GREEN.pinNum] |= (PORT_PCR_PE_MASK | PORT_PCR_PS_MASK | PORT_PCR_MUX(0x001));
    
    // Set output pins
    IO_LED_RED.gpio->PDDR |= (uint32_t)0x00000001 << IO_LED_RED.pinNum;
    IO_LED_BLUE.gpio->PDDR |= (uint32_t)0x00000001 << IO_LED_BLUE.pinNum;
    IO_LED_GREEN.gpio->PDDR |= (uint32_t)0x00000001 << IO_LED_GREEN.pinNum;
    
    // Set default pin state
    outputHigh(&IO_LED_RED);
    outputHigh(&IO_LED_BLUE);
    outputHigh(&IO_LED_GREEN);
}


void outputHigh(const gpioPin_t* const pin) {
    pin->gpio->PSOR |= (uint32_t)0x00000001 << pin->pinNum;
}

void outputLow(const gpioPin_t* const pin) {
    pin->gpio->PCOR |= (uint32_t)0x00000001 << pin->pinNum;
}
