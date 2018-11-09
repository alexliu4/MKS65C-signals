all: signal.o
	gcc signal.o

run: all
	./a.out

file.o: signal.c
	gcc -c signal.c

clean:
	rm *.o
	rm *.out
