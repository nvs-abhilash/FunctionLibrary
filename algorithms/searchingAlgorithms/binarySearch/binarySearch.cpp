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
using namespace std;

// function that searches for a number using binary search algorithm.
void binarySearch (int arry[] , int length , int findMe) 
{
    int startPos , endPos , midVal;
    bool check = false;
    
    startPos = 0;
    endPos = length-1;
    midVal = (startPos + endPos) /2;

    while (startPos <= endPos)
    {
        midVal = (startPos + endPos) /2;  
        if (arry[midVal] == findMe)
        {
            cout << findMe << " is at " << midVal+1 <<" position\n";
            check = true;
            break;
        }
        else if (arry[midVal] > findMe)
        {
            endPos = midVal - 1;
        }
        else   
            startPos = midVal + 1;
    }
    
    if(!check)
    {
        cout << "Number not found\n";
    }
}

