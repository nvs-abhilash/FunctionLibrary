 #
 # FunctionLibrary
 # Copyright (C) 2017  NVS Abhilash <nvs232@gmail.com>
 #
 # This program is free software: you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
 # the Free Software Foundation, either version 3 of the License, or
 # any later version.
 #
 # This program is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 # GNU General Public License for more details.
 #
 # You should have received a copy of the GNU General Public License
 # along with this program.  If not, see <http://www.gnu.org/licenses/>
 #

compiler = gcc
options = -Wall -Werror
objects = main.o basicPrograms.o bubbleSort.o

compile: $(objects)
	$(compiler) $(options) $(objects) -o main

main.o: main.c
	$(compiler) $(options) -c main.c

basicPrograms.o: include/basicPrograms.c
	$(compiler) $(options) -c include/basicPrograms.c

bubbleSort.o: bubbleSort.c
	$(compiler) $(options) -c bubbleSort.c

run: compile main
	./main

clean:
	rm -rf *.o main
