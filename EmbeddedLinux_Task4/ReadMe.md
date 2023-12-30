
<span style="color:purple">**Codes and Screenshots**</span>

1-$AVR_GCC -c *.c -I ../include/

2- $AVR_AR -rcs libMCAL.a *.o

3-cd ../

4-$AVR_GCC main.c -o main.elf -mmcu=atmega32 -I include/ -L MCAL/ -lMCAL 

![WhatsApp Image 2023-12-30 at 6 09 46 PM](https://github.com/RanianMustafa17/EmbeddedLinux/assets/101398177/ba095f1f-9cd4-4e73-810d-ae00036a7236)
![WhatsApp Image 2023-12-30 at 6 11 51 PM](https://github.com/RanianMustafa17/EmbeddedLinux/assets/101398177/adf39b6c-4c64-4f22-84c6-6db7e4973fd2)
![WhatsApp Image 2023-12-30 at 6 12 33 PM](https://github.com/RanianMustafa17/EmbeddedLinux/assets/101398177/26f86f25-6fa8-43e7-8d98-1d91c4864bf6)
![WhatsApp Image 2023-12-30 at 6 12 54 PM](https://github.com/RanianMustafa17/EmbeddedLinux/assets/101398177/791cf946-ca43-4195-ac2c-f0e1d5fcb507)
