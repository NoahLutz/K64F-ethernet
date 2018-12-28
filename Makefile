CC=arm-none-eabi-gcc
INCLUDE_DIRS=D:\Programs\Keil_v5\ARM\PACK\Keil\Kinetis_K60_DFP\1.5.0\Device
CFLAGS=-specs=nosys.specs -mcpu=cortex-m4 -I$(INCLUDE_DIRS)

OUTFILE=K64F_ethernet.elf
BUILD_DIR=build

DEPS=system_MK64F12.h
OBJECTS= main.o system_MK64F12.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

$(OUTFILE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	$(RM) $(OUTFILE)
