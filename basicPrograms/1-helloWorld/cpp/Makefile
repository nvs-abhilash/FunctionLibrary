 #
 # FunctionLibrary
 # Copyright (C) 2017  Aakash Sinha <aakash.sinha@st.niituniversity.in>
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
objects = helloWorld.o

compile: $(objects)
	$(compiler) $(options) $(objects) -o helloWorld

helloWorld.o: helloWorld.cpp
	$(compiler) $(options) -c helloWorld.cpp

run: compile helloWorld
	./helloWorld

clean:
	rm -rf *.o helloWorld
	
