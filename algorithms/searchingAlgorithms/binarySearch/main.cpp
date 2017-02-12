/*
* FunctionLibrary
* Copyright (C) 2017  Siddharth Shashikar <siddharth.shashikar@st.niituniversity.in>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>
*
*/
#include <iostream>
#include "binarySearch.h"
#define MAX 10
using namespace std;

int main (void)
{
    int arry[MAX] = {1 , 3 , 5 , 7 , 9 , 11 , 13 , 15 , 17 , 19};
    int findMe;
    
    cout << "Enter the number you want to search for\n";
    cin  >> findMe;

    binarySearch (arry , MAX , findMe);
    return 0;
}

