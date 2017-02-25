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
#include "searchUnimodelArray.h"
#define MAX 10
using namespace std;

int main (void)
{
    int arry[MAX] = {12 , 13 , 15 , 17 , 19 , 21 , 23 , 8 , 9 , 11};
    int findMe;
    int answer;
    
    cout << "Enter the number you want to search\n";
    cin  >> findMe;

    answer = searchUnimodelArray ( arry , MAX , findMe );
    cout << answer << endl;
    return 0;

}

