1-$AVR_GCC -c *.c -I ../include/
2- $AVR_AR -rcs libMCAL.a *.o
3-cd ../
4-$AVR_GCC main.c -o main.elf -mmcu=atmega32 -I include/ -L MCAL/ -lMCAL 

![WhatsApp Image 2023-12-30 at 6 09 46 PM](https://github.com/RanianMustafa17/EmbeddedLinux/assets/101398177/ba095f1f-9cd4-4e73-810d-ae00036a7236)
