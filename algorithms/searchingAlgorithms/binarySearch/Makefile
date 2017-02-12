 #
 # FunctionLibrary
 # Copyright (C) 2017  Siddharth Shashikar <siddharth.shashikar@st.niituniversity.in>
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

compiler = g++
options = -Wall -Werror
objects = main.o BinarySearch.o

compile: $(objects)
	$(compiler) $(options) $(objects) -o main

main.o: main.cpp
	$(compiler) $(options) -c main.cpp

BinarySearch.o: BinarySearch.cpp
	$(compiler) $(options) -c BinarySearch.cpp

run: compile main 
	./main

clean:
	rm -rf *.o main