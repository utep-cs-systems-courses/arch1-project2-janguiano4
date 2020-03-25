# makfile configuration
COMMON_OBJECTS	=
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

#switch the compiler
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: project.elf

#additional rules for files
project.elf: ${COMMON_OBJECTS} buzzer.o stateMachines.o dimStateMachines.o led.o projectMain.o wdInterruptHandler.o p1_interrupt_handler.o switches.o ../lib/libTimer.a  
	${CC} ${CFLAGS} -o $@ $^

load: project.elf
	msp430loader.sh project.elf

clean:
	rm -f *.o *.elf

buzzer.c: buzzer.h

projectMain.c: buzzer.h switches.h led.h

wdInterruptHandler.o: stateMachines.h dimStateMachines.h switches.h led.h

stateMachines.o: buzzer.h stateMachines.h led.h
