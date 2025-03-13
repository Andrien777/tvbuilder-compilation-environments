# User-configurable
target=rom
OPTIMIZATION=-O1
.PHONY : clean
.PHONY : asm

#Change only if you know what you are doing
CC=ia16-elf-gcc
LD=ia16-elf-ld
CFLAGS=-nostdlib ${OPTIMIZATION} -ffunction-sections
LDFLAGS=--oformat binary -T link.ld --library=tvb --library-path=./

SOURCES=$(wildcard *.c)
OBJS=$(SOURCES:.c=.o)

$(target) : $(OBJS)
	$(LD) -o $@.bin $(OBJS)  $(LDFLAGS)
	split --bytes 2048 $@.bin -d -a 1 $@_ --additional-suffix=.bin

$(OBJS) : $(SOURCES) 
	$(CC) -c $(CFLAGS) -o $@ $<

clean :
	rm ./*.o $(target)*

asm : $(SOURCES)
	$(CC) -c $(CFLAGS) -masm=intel -S $<





















