compiler = gcc
options = -Wall -Werror
objects = main.o basicPrograms.o bubbleSort.o

compile: $(objects)
	$(compiler) $(options) $(objects) -o main

main.o: main.c
	$(compiler) $(options) -c main.c

basicPrograms.o: basicPrograms.c
	$(compiler) $(options) -c basicPrograms.c

bubbleSort.o: bubbleSort.c
	$(compiler) $(options) -c bubbleSort.c

run: compile main
	./main

clean:
	rm -rf *.o main
