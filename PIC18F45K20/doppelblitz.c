//
// PICkit3 Debug Express
// PIC18F45K20 Doppelblitz an RD7
//

// xc8-cc -mcpu=18F45K20
//        -mdfp="c:/DevTools/Microchip/packs/PIC18F-K_DFP/1.15.303/xc8"
//        doppelblitz.c
//

// Configuration Bits
#pragma config FOSC = INTIO67, FCMEN = OFF, IESO = OFF                  // CONFIG1H
               // INTIO67 = Internal oscillator block, port function on RA6 and RA7
               // INTIO7 = Internal oscillator block, CLKOUT function on RA6, port function on RA7
// Power-up Timer, Brown-out Reset, Brown-out Voltage
#pragma config PWRT = OFF, BOREN = SBORDIS, BORV = 30                   // CONFIG2L
// Watchdog Timer, Watchdog Timer Postscaler
#pragma config WDTEN = OFF, WDTPS = 32768                               // CONFIG2H
// MCLR pin disabled (RE3 is input), PORTB A/D enable on reset, ...
#pragma config MCLRE = OFF, LPT1OSC = OFF, PBADEN = ON, CCP2MX = PORTC  // CONFIG3H
// ...
#pragma config STVREN = ON, LVP = OFF, XINST = OFF                      // CONFIG4L
// Code Protection
#pragma config CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF               // CONFIG5L
#pragma config CPB = OFF, CPD = OFF                                     // CONFIG5H
// Write Protection
#pragma config WRT0 = OFF, WRT1 = OFF, WRT2 = OFF, WRT3 = OFF           // CONFIG6L
#pragma config WRTB = OFF, WRTC = OFF, WRTD = OFF                       // CONFIG6H
// Table Read Protection
#pragma config EBTR0 = OFF, EBTR1 = OFF, EBTR2 = OFF, EBTR3 = OFF       // CONFIG7L
#pragma config EBTRB = OFF                                              // CONFIG7H

#include <xc.h>

#define _XTAL_FREQ 1000000    // The default frequency after reset is 1 MHz
               // INTOSC = 16 MHz, Postscaler = ???, PLL = off???

void main(void)
{
  TRISD = 0b01111111;         // PORTD bit 7 output (0); bits 6:0 inputs (1)

  while(1)
  {
      LATDbits.LATD7 = 1;     // LED ein
      __delay_ms(70);         // für 70 ms
      LATDbits.LATD7 = 0;     // LED aus
      __delay_ms(70);         // für 70 ms
      LATDbits.LATD7 = 1;     // LED ein
      __delay_ms(70);         // für 70 ms
      LATDbits.LATD7 = 0;     // LED aus
      __delay_ms(790);        // für den Rest von 1000 ms, also 790 ms
  }
}


// https://github.com/adamj537/PICkit3DebugExpress/tree/master
