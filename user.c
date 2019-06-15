/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC33E__)
    	#include <p33Exxxx.h>
    #elif defined(__dsPIC33F__)
    	#include <p33Fxxxx.h>
    #endif
#endif

#include <stdint.h>          /* For uint16_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include "user.h"            /* variables/params used by user.c               */
#include "const.h"
/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /* TODO Initialize User Ports/Peripherals/Project here */

    /* Setup analog functionality and port direction */
ConfigurePWM();
    /* Initialize peripherals */
}

void ConfigurePWM(void)
{
    // Set timer resolution
    P1TPER   = mnogo;
    
//    PWM1CON1 = 0x0077;

    //P1TCONbits.PTCKPS  = 0b00;          // PWM time base input clock period is 1 TCY (1:1 prescale)
    
    PWM1CON1bits.PMOD1 = 1;             // PWM I/O pin pair is in the Independent PWM Output mode
    PWM1CON1bits.PEN1H = 1;             // PWM1H pin is enabled for PWM 
    PWM1CON1bits.PEN1L = 1;             // PWM1L pin is enabled for PWM output
    
    PWM1CON1bits.PMOD2 = 1;             // PWM I/O pin pair is in the Independent PWM Output mode
    PWM1CON1bits.PEN2H = 1;             // PWM2H pin is enabled for PWM 
    PWM1CON1bits.PEN2L = 1;             // PWM2L pin is enabled for PWM output
    
    PWM1CON1bits.PMOD3 = 1;             // PWM I/O pin pair is in the Independent PWM Output mode
    PWM1CON1bits.PEN3H = 1;             // PWM3H pin is enabled for PWM 
    PWM1CON1bits.PEN3L = 1;             // PWM3L pin is enabled for PWM output
    
    //  P1DTCON1; Set the Dead time register
    P1DTCON1bits.DTBPS = 0b00;          // Clock period for Dead-Time Unit B is TCY
    P1DTCON1bits.DTB   = 19;            // Tdeadtime=500ns, 500ns/25ns=20, 20-1=19
    P1DTCON1bits.DTAPS = 0b00;          // Clock period for Dead-Time Unit A is TCY
    P1DTCON1bits.DTA   = 19;            // TdeadTIme=500ns; 600ns/25ns=2; 20-1=19
    
    // P1DTCON2; Set the Dead time for the PWD module
    P1DTCON2bits.DTS2A = 0;     // Dead time A to PWD module 2
    P1DTCON2bits.DTS2I = 0;     // Dead time A to PWD module 2
    P1DTCON2bits.DTS1A = 1;     // Dead time B to PWD module 1
    P1DTCON2bits.DTS1I = 1;     // Dead time B to PWD module 1
    
   
    P1DC1 = mnogo;           // Sets the Duty cycle of the PWD1 module    
    P1DC2 = mnogo;           // Sets the Duty cycle of the PWD2 module  
    P1DC3 = mnogo/5+mnogo;   // Sets the Duty cycle of the PWD3 module 
    
    // Enables PWM module
    P1TCONbits.PTEN = 1;
    
}//ConfigurePWM

void ConfigureADC(void){
    AD1CON1bits.AD12B = 1;          // 12-bit, 1-channel ADC operation
    AD1CON1bits.SSRC  = 3;          // Motor Control PWM1 interval ends sampling and starts conversion
    AD1CON1bits.ASAM  = 1;          // Sampling begins immediately after last conversion. SAMP bit is auto-set
    AD1CON2bits.SMPI  = 0b1111;     // Interrupts at the completion of conversion for each 16th sample/convert sequence
    AD1CON3bits.ADCS  = 5;          // TADC = 5*TCY
    AD1CON1bits.ADON  = 1;          // Turn On ADC
}//ConfigureADC

void ConfigureInterrupts(void){
    
    /* Interrupt nesting enabled here */
    INTCON1bits.NSTDIS = 0;
    
    IEC3bits.PWM1IE = 1;                // PWM1 Interrupt Enable bit
    
    /*
    IFS0bits.AD1IF  = 0;                // Clear ADC1 interrupt flag
    IEC0bits.AD1IE  = 1;                // ADC1 interrupt enabled
    IPC3bits.AD1IP  = 0b111;            // ADC1 Interrupt is priority 7 (highest priority interrupt)
    
    AD1PCFGLbits.PCFG6 = 1;             // AN6(RC0) pin is digital    
    CNEN1bits.CN8IE    = 1;             // Enable CN interrupt on CN8(RC0) pin
    
    IFS1bits.CNIF = 0;             // Clear CN interrupt flag 
    IEC1bits.CNIE = 1;             // Enable CN interrupts
    IPC4bits.CNIP = 4;             // Set interrupt priority to 4
    */
}//ConfigureInterrupts

