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
using namespace std;

int searchUnimodelArray (int arry[], int MAX, int findMe)
{
    int i = 0, peak = 0;
    int startPos = 0 , endPos = MAX - 1;
    int mid = (startPos + endPos) / 2;

    // finding the position of the largest element 
    for ( i = 0; i < MAX-1; i++)
    {
        if ( arry[i] > arry[i+1] && arry[i] > arry[i-1] )
        {
            peak = i;
            break;
        }
        else if ( arry[i] < arry[i+1] )
            startPos = mid + 1;
        else
            endPos = mid - 1;
    }
    
    // do the binary search in the first half of the arry
    if( findMe >= arry[0])
    {
        startPos = 0;
        endPos = peak;
        while ( startPos <= endPos ) 
        {
            mid = (startPos + endPos) / 2;
            if (arry[mid] == findMe)
            {
                return mid;
            }
            else if ( arry[mid] < findMe )
            {
                startPos = mid + 1;
            }
            else
                endPos = mid - 1;
        }
    }
    
    // do the search binary search in the second half of the arry
    else
    {
        startPos = peak + 1;
        endPos = MAX - 1;
        while( startPos <= endPos ) 
        {
            mid = ( startPos + endPos )/ 2;
            if ( arry[mid] == findMe )
            {
                return mid;
            }
            else if ( arry[mid] < findMe )
            {
                startPos = mid + 1;
            }
            else
                endPos = mid - 1;
        }
    }
    
    return -1;
}