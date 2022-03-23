pzip: main.o
	gcc main.o -Wall -std=c99 -o pzip

main.o: main.c
	gcc -Wall -std=c99 -c main.c

clean:
	rm *.o pzip

