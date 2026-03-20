set PROJECT=doppelblitz.c

rem Jungfr„ulicher Chip mit OSCCAL bei 0x03FF
rem xc8-cc -mcpu=12F675 -mdfp="c:/DevTools/Microchip/packs/PIC10-12Fxxx_DFP/1.8.184/xc8" -Wa,-a %PROJECT%

rem Neu Schreiben eines bekannten(!!!) OSCCAL-Wertes
rem xc8-cc -mcpu=12F675 -mdfp="c:/DevTools/Microchip/packs/PIC10-12Fxxx_DFP/1.8.184/xc8" -Wa,-a -moscval=55 %PROJECT%

rem Komplett ohne Kalibirierung
xc8-cc -mcpu=12F675 -mdfp="c:/DevTools/Microchip/packs/PIC10-12Fxxx_DFP/1.8.184/xc8" -Wa,-a -mno-osccal %PROJECT%
