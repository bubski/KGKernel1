AR=ar
CC=gcc
LD=ld

OBJS= \
	io.o \
	random.o \
	malloc.o \
	to.o \
	math.o \
	string.o \
	keyboard.o \
	cursor.o \
	tmp.o \
	ksys.o

all: libk.a

io.o: io.c
	$(CC) -m32 -static -nostdlib -nostdinc -fno-builtin -c io.c -o io.o -I../include

random.o: random.c
	$(CC) -m32 -static -nostdlib -nostdinc -fno-builtin -c random.c -o random.o -I../include

malloc.o: malloc.c
	$(CC) -m32 -static -nostdlib -nostdinc -fno-builtin -c malloc.c -o malloc.o -I../include

to.o: to.c
	$(CC) -m32 -static -nostdlib -nostdinc -fno-builtin -c to.c -o to.o -I../include

math.o: math.c
	$(CC) -m32 -static -nostdlib -nostdinc -fno-builtin -c math.c -o math.o -I../include

string.o: string.c
	$(CC) -m32 -static -nostdlib -nostdinc -fno-builtin -c string.c -o string.o -I../include

keyboard.o: keyboard.c
	$(CC) -m32 -static -nostdlib -nostdinc -fno-builtin -c keyboard.c -o keyboard.o -I../include

cursor.o: cursor.c
	$(CC) -m32 -static -nostdlib -nostdinc -fno-builtin -c cursor.c -o cursor.o -I../include

tmp.o: tmp.c
	$(CC) -m32 -static -nostdlib -nostdinc -fno-builtin -c tmp.c -o tmp.o -I../include

ksys.o: ksys.c
	$(CC) -m32 -static -nostdlib -nostdinc -fno-builtin -c ksys.c -o ksys.o -I../include

libk.a: $(OBJS)
	$(AR) rcs libk.a $(OBJS)

clean:
	rm $(OBJS)