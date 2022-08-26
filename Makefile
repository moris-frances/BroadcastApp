CC = gcc
CFLAGS = -D_DEFAULT_SOURCE -Wall -Wextra -pedantic -Wno-unused-parameter
CFILES = $(wildcard *.c)
HFILES = $(wildcard *.h)
EXENAME = broCast

${EXENAME}: ${CFILES} ${HFILES}
	${CC} ${CFLAGS} ${CFILES} ${HFILES} -o ${EXENAME}

s: ${CFILES} ${HFILES}
	${CC} ${CFLAGS} sender.c sharedMem.c ${HFILES} -o sender

r: ${CFILES} ${HFILES}
	${CC} ${CFLAGS} receiver.c sharedMem.c ${HFILES} -o receiver

clean: ${EXENAME}
	rm -f ${EXENAME}.o ${EXENAME}
	echo Clean done
