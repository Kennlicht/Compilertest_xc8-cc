//
// PICkit3 Debug Express
// PIC18F45K20 Lauflicht
//

// xc8-cc -mcpu=18F45K20
//        -mdfp="c:/DevTools/Microchip/packs/PIC18F-K_DFP/1.15.303/xc8"
//        lauflicht.c
//

// Configuration Bits
// Oscillator (CONFIG1H)
#pragma config FOSC = INTIO67, FCMEN = OFF, IESO = OFF
               // INTIO67 = Internal oscillator block, port function on RA6 and RA7
               // INTIO7 = Internal oscillator block, CLKOUT function on RA6, port function on RA7
// Power-up Timer, Brown-out Reset, Brown-out Voltage (CONFIG2L)
#pragma config PWRT = OFF, BOREN = SBORDIS, BORV = 30
// Watchdog Timer, Watchdog Timer Postscaler (CONFIG2H)
#pragma config WDTEN = OFF, WDTPS = 32768
// MCLR pin disabled (RE3 is input), PORTB A/D enable on reset, ... (CONFIG3H)
#pragma config MCLRE = OFF, LPT1OSC = OFF, PBADEN = ON, CCP2MX = PORTC
// ... (CONFIG4L)
#pragma config STVREN = ON, LVP = OFF, XINST = OFF
// Code Protection (CONFIG5L+CONFIG5H)
#pragma config CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF, CPB = OFF, CPD = OFF
// Write Protection (CONFIG6L+CONFIG6H)
#pragma config WRT0 = OFF, WRT1 = OFF, WRT2 = OFF, WRT3 = OFF, WRTB = OFF, WRTC = OFF, WRTD = OFF
// Table Read Protection (CONFIG7L+CONFIG7H)
#pragma config EBTR0 = OFF, EBTR1 = OFF, EBTR2 = OFF, EBTR3 = OFF, EBTRB = OFF                                              // CONFIG7H

#define _XTAL_FREQ 1000000    // The default frequency after reset is 1 MHz
               // INTOSC = 16 MHz, Postscaler = ???, PLL = off???

#include <xc.h>
#include <stdint.h>

void main(void)
{
  uint8_t bitpos = 0x01;
  
  PORTD = 0x00;
  TRISD = 0x00;             // PORTD bits 7:0 output (0)
  
  INTCON2bits.RBPU = 0;     // enable PORTB internal pullups
  WPUBbits.WPUB0 = 1;       // RB0 weak pull-up enabled
  ANSELHbits.ANS12 = 0;     // RB0 is digital input (Default state is determined by PBADEN in CONFIG3H)
  TRISBbits.TRISB0 = 1;     // RB0 is input

  while(1)
  {
    LATD = bitpos;          // LED on
    __delay_ms(70);         // for 70 ms
    LATD = 0x00;            // all LEDs off
    __delay_ms(70);         // for 70 ms
    LATD = bitpos;          // LED on
    __delay_ms(70);         // for 70 ms
    LATD = 0x00;            // all LEDs off
    __delay_ms(790);        // for the remaining part of 1000 ms, that is 790 ms
    
    // Rotate
    bitpos = (uint8_t) ((bitpos << 1) | (bitpos >> 7));
    // XC8 macht daraus zwei RLCF, schiebt also durchs Carry-Flag. Ein einzelner RLNCF würde es auch tun...
    
    if (PORTBbits.RB0 == 0) // Switch pressed; read once in a while, therefore no debouncing
    {
      // Zweite LED zu- oder abschalten
      if (bitpos > 0x0F)
        bitpos ^= (uint8_t) (bitpos >> 4);
      else
        bitpos ^= (uint8_t) (bitpos << 4);
    }
  }
}

