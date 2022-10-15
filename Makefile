#programa principal
OBJSAR = *_ar.c
OBJSPC = *_pc.c

compilarEnArduino: $(OBJSAR)
	@avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o a.o $(OBJSAR)
	@avr-gcc -mmcu=atmega328p a.o -o a.elf
	@avr-objcopy -O ihex -R .eeprom a.elf a.hex
	@avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:a.hex
limpiar:  
	@rm *.o *.elf *.hex

compilarEnC: $(OBJSPC)
	@gcc -Wall -c  $(OBJSPC) -o b.o 
	@gcc -Wall b.o -o interfaz
	@./interfaz
