COMPILER =clang
#CCFLAGS = 
#LIBS=-lallegro
LDFLAGS=-lallegro -lallegro_primitives

OUT=prog

all: main

main: main.o
	$(COMPILER) main.o -o $(OUT) $(INCLUDE) $(CFLAGS) $(LDFLAGS)
main.o: main.c
	$(COMPILER) -c main.c
