#
# FunctionLibrary
# Copyright (C) 2017  Mohit Raj <mohit.raj@st.niituniversity.in>
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
objects = mergeLL.o linkedListLibrary.o heapLibrary.o

compile: $(objects)
	$(compiler) $(options) $(objects) -o mergeLL

mergeLL.o: mergeLL.cpp
	$(compiler) $(options) -c mergeLL.cpp

linkedListLibrary.o: linkedListLibrary.cpp
	$(compiler) $(options) -c linkedListLibrary.cpp

heapLibrary.o: heapLibrary.cpp
	$(compiler) $(options) -c heapLibrary.cpp

run: compile mergeLL
	./mergeLL

clean:
	rm -rf *.o mergeLL
