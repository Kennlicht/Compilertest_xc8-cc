//
// PIC12F629/675 Doppelblitz an GP5
//

// xc8-cc -mcpu=12F675     --> oder 12F629
//        -mdfp="c:/DevTools/Microchip/packs/PIC10-12Fxxx_DFP/1.8.184/xc8"
//        -Wa,-a           --> *.lst erzeugen
//                         --> beim Flashen aufpassen und 0x03FF nicht löschen _ODER_
//        -mno-osccal      --> keine Kalibrierung beim Start _ODER_
//        -moscval=55      --> bekannten(!) Wert für OSCCAL in 0x03FF schreiben
//        doppelblitz.c
//

#include <xc.h>

// Configuration Bits
//#pragma config FOSC = INTRCIO    // Select internal oscillator: I/O function on GP4/CLKOUT and GP5/CLKIN
#pragma config FOSC = INTRCCLK   // Select internal oscillator: CLKOUT (1 MHz) on GP4 and I/O function on GP5/CLKIN
#pragma config WDTE = OFF        // Disable Watchdog Timer
#pragma config MCLRE = OFF       // Disable MCLR Pin (GP3/MCLR is digital input)
#pragma config BOREN = OFF       // Disable Brown-out Detect
#pragma config PWRTE = OFF       // Disable Power-Up Timer

// When calibrated, the internal oscillator provides a fixed 4 MHz system clock, macro needed for __delay_ms()
#define _XTAL_FREQ 4000000
  
void main(void)
{
  #ifdef _12F675
   ANSEL = 0x00;                 // No analog functions, all pins are digital I/O
  #endif
  
   GPIObits.GPIO5 = 1;           // LED aus, initial
   TRISIObits.TRISIO5 = 0;       // GP5 is digital output
     
   while(1)
   {
      GPIObits.GPIO5 = 0;        // LED ein
      __delay_ms(70);            // für 70 ms
      GPIObits.GPIO5 = 1;        // LED aus
      __delay_ms(70);            // für 70 ms
      GPIObits.GPIO5 = 0;        // LED ein
      __delay_ms(70);            // für 70 ms
      GPIObits.GPIO5 = 1;        // LED aus
      __delay_ms(790);           // für den Rest von 1000 ms, also 790 ms
   }
}