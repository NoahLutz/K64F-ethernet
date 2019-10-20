CC=arm-linux-gnueabihf-gcc
CFLAGS=-mcpu=cortex-m4

OUTFILE=K64F_ethernet.bin
BUILD_DIR=build

DEPS=system_MK64F12.h

$(OUTFILE): $(DEPS)
	$(CC) $(CFLAGS) -o $(OUTFILE) $(DEPS)

.PHONY: clean
clean:
	$(RM) $(OUTFILE)
