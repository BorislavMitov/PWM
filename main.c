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
int I  = 0;
int I1 = 67;
int I2 = 134;

int phi[] ={ 2000, 2063, 2126, 2189, 2251, 2314, 2376, 2438, 2499, 2560, 2621, 2680, 2739, 2798, 2855, 2912, 2967, 3022, 3076, 3129, 3180, 3231, 3280,
3328, 3374, 3419, 3463, 3505, 3546, 3585, 3623, 3659, 3694, 3726, 3757, 3787, 3814, 3840, 3863, 3885, 3905, 3924, 3940, 3954, 3967, 3977, 3985, 3992,
3996, 3999, 3999, 3998, 3994, 3989, 3982, 3972, 3961, 3947, 3932, 3915, 3896, 3875, 3852, 3827, 3800, 3772, 3742, 3710, 3677, 3641, 3604, 3566, 3526,
3484, 3441, 3397, 3351, 3304, 3255, 3206, 3155, 3102, 3049, 2995, 2940, 2883, 2826, 2769, 2710, 2650, 2590, 2530, 2469, 2407, 2345, 2283, 2220, 2157,
2094, 2031, 1968, 1905, 1842, 1779, 1716, 1654, 1592, 1530, 1469, 1409, 1349, 1289, 1230, 1173, 1116, 1059, 1004, 950, 897, 844, 793, 744, 695, 648,
602, 558, 515, 473, 433, 395, 358, 322, 289, 257, 227, 199, 172, 147, 124, 103, 84, 67, 52, 38, 27, 17, 10, 5, 1, 0, 0, 3, 7, 14, 22, 32, 45, 59, 75,
94, 114, 136, 159, 185, 212, 242, 273, 305, 340, 376, 414, 453, 494, 536, 580, 625, 671, 719, 768, 819, 870, 923, 977, 1032, 1087, 1144, 1201, 1260,
1319, 1378, 1439, 1500, 1561, 1623, 1685, 1748, 1810, 1873, 1936, 2000 };

#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */
#include "const.h"          // konstanti
#include "libpic30.h"
/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

int16_t main(void)
{
    // RB3 port configured as input for rotation direction change
//    TRISCbits.TRISC1 = 1;
    
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Configure the PWM module */
//    ConfigurePWM();

    /* Initialize IO ports and peripherals */
    InitApp();

    /* Configure ADC*/
//    ConfigureADC();

    /* Configure Interrupts */
//    ConfigureInterrupts();
    TRISAbits.TRISA1 = 0;
    
    
    /* TODO <INSERT USER APPLICATION CODE HERE> */
    while(1)
    {
        LATAbits.LATA1 = 1;
        __delay_ms(500);
        LATAbits.LATA1 = 0;
        __delay_ms(500);
    }
}


