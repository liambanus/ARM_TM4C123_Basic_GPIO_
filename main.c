// 1. Pre-processor Directives Section
#include "TExaS.h"
 
// Constant declarations to access port registers using 
// symbolic names instead of addresses
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
// 2. Declarations Section
//   Global Variables
 
//   Function Prototypes
void PortF_Init(void);
void Delay1ms(unsigned long msec);
void EnableInterrupts(void);  // Enable interrupts
void WaitForASLow(void);
void WaitForASHigh(void);
void SetVT(void);
void ClearVT(void);
void SetReady(void);
void ClearReady(void);
 
// 3. Subroutines Section
// MAIN: Mandatory for a C Program to be executable
int main(void){
  TExaS_Init(SW_PIN_PF40, LED_PIN_PF31,ScopeOn);  // activate grader and set system clock to 80 MHz
  PortF_Init();                            // Init port PF4 PF3 PF1    
  EnableInterrupts();                      // enable interrupts for the grader  
  while(1){         // Follows the nine steps list above
    // a) Ready signal goes high
            GPIO_PORTF_DATA_R = (GPIO_PORTF_DATA_R|0x8);//change to do while?
    // b) wait for switch to be pressed
        while ((GPIO_PORTF_DATA_R&0x10) == 0x10){}
    
        //Out ^= 0x04;
    // c) Ready signal goes low
    //GPIO_PORTF_DATA_R = (GPIO_PORTF_DATA_R& (~0x8));
        GPIO_PORTF_DATA_R = (GPIO_PORTF_DATA_R& (~0xA));    
            // d) wait 10ms
                Delay1ms(10);
    // e) wait for switch to be released
                while ((GPIO_PORTF_DATA_R&0x10) == 0x00){}
                    
    // f) wait 250ms
                Delay1ms(250);    
    // g) VT signal goes high
                GPIO_PORTF_DATA_R = (GPIO_PORTF_DATA_R|0x2);    
    // h) wait 250ms
                Delay1ms(250);    
    // i) VT signal goes low
                GPIO_PORTF_DATA_R = (GPIO_PORTF_DATA_R& (~0x2));
  }
}
// Subroutine to initialize port F pins for input and output
// PF4 is input SW1 and PF3-1 is output LEDs
// Inputs: None
// Outputs: None
// Notes: ...
void PortF_Init(void){ volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000020;      // 1) F clock
  delay = SYSCTL_RCGC2_R;            // delay to allow clock to stabilize     
  GPIO_PORTF_AMSEL_R &= 0x00;        // 2) disable analog function
  GPIO_PORTF_PCTL_R &= 0x00000000;   // 3) GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R &= ~0x10;         // 4.1) PF4 input,
  GPIO_PORTF_DIR_R |= 0x0E;          // 4.2) PF3,2,1 output  
  GPIO_PORTF_AFSEL_R &= 0x00;        // 5) no alternate function
  GPIO_PORTF_PUR_R |= 0x10;          // 6) enable pullup resistor on PF4       
  GPIO_PORTF_DEN_R |= 0x1E;          // 7) enable digital pins PF4-PF1
    GPIO_PORTF_DATA_R = (GPIO_PORTF_DATA_R|0x8);
}
// Color    LED(s) PortF
// dark     ---    0
// red      R--    0x02
// blue     --B    0x04
// green    -G-    0x08
// yellow   RG-    0x0A
// sky blue -GB    0x0C
// white    RGB    0x0E
 
 
// Subroutine reads AS input and waits for signal to be low
// If AS is already low, it returns right away
// If AS is currently high, it will wait until it to go low
// Inputs:  None
// Outputs: None
void WaitForASLow(void){
// write this function
}
 
// Subroutine reads AS input and waits for signal to be high
// If AS is already high, it returns right away
// If AS is currently low, it will wait until it to go high
// Inputs:  None
// Outputs: None
void WaitForASHigh(void){
// write this function
}
 
// Subroutine sets VT high
// Inputs:  None
// Outputs: None
// Notes:   friendly means it does not affect other bits in the port
void SetVT(void){
// write this function
}
 
// Subroutine clears VT low
// Inputs:  None
// Outputs: None
// Notes:   friendly means it does not affect other bits in the port
void ClearVT(void){
// write this function
}
 
// Subroutine sets Ready high
// Inputs:  None
// Outputs: None
// Notes:   friendly means it does not affect other bits in the port
void SetReady(void){
// write this function
}
 
 
// Subroutine clears Ready low
// Inputs:  None
// Outputs: None
// Notes:   friendly means it does not affect other bits in the port
void ClearReady(void){
// write this function
}
 
// Subroutine to delay in units of milliseconds
// Inputs:  Number of milliseconds to delay
// Outputs: None
// Notes:   assumes 80 MHz clock
void Delay1ms(unsigned long time){
    unsigned long i;
    while(time > 0) {
        //i = 1333;
        i = 13333;
        while(i>0){
            i = i-1;
        }
        time = time-1;}}
