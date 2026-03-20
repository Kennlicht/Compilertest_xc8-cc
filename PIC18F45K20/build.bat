set PROJECT=doppelblitz.c

xc8-cc -mcpu=18F45K20 -mdfp="c:/DevTools/Microchip/packs/PIC18F-K_DFP/1.15.303/xc8" -Wa,-a -O2 -msummary=+psect,-class,+mem,-hex,-file %PROJECT%


