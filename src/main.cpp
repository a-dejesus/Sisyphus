#include "stm32f4xx.h"
#include <stdio.h>

void delay(uint32_t ms);
void init_led(void);
void toggle_led(void);

void init_led(void) {

  RCC   ->  AHB1ENR   |=  RCC_AHB1ENR_GPIOAEN;    // Enable GPIOA clock
  GPIOA ->  MODER     |=  GPIO_MODER_MODE5_0;     // Set GPIOA Pin 5 as output
  GPIOA ->  OTYPER    &= ~GPIO_OTYPER_OT5;        // Set output type as push-pull
  GPIOA ->  OSPEEDR   |=  GPIO_OSPEEDER_OSPEEDR5; // Set output speed as high
  GPIOA ->  PUPDR     &= ~GPIO_PUPDR_PUPDR5;      // Disable pull-up and pull-down
}

void toggle_led(void) {
  GPIOA ->  ODR       ^=  GPIO_ODR_OD5; // Toggle LED state
}

void delay(uint32_t ms) {
  uint32_t delay_count = 8400 * ms; // 1ms delay at 168MHz CPU clock
  printf("In the delay function");
  while (delay_count--){
  }
}


int main(void) {
  init_led();

  while (1) {
    toggle_led();
    delay(1000);
  }
}
