#compiler flags. -g for debug, -03 for optimization
CFLAGS= -g -03

all:
	gcc main.c src/tokenizer.c src/history.c -o reader

# include file dependencies
src/tokenizer.c:src/tokenizer.h
src/history.c:src/history.h

src: src/tokenizer.c src/history.c
	cc -o $@ $^ $(CLAGS)

clean:
	rm -f *.o src
