#programa principal
OBJS = *_ar.c
OBJSPC = *_pc.c

compilarEnArduino: $(OBJS)
	@avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o a.o $(OBJS)
	@avr-gcc -mmcu=atmega328p a.o -o a.elf
	@avr-objcopy -O ihex -R .eeprom a.elf a.hex
	@avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB1 -b 115200 -U flash:w:a.hex
limpiar:  
	@rm *.o *.elf *.hex

compilarEnC: $(OBJSPC)
	@gcc -Wall $(OBJSPC) termset.c -o escribe_caracter
	@./escribe_caracter
	@rm escribe_caracter
