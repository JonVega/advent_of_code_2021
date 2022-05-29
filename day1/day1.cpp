/*
 *	day1.cpp - Advent of Code 2021
 *
 *	Author: Jonathan Vega
 * 
 *	Purpose: Finds which measures are larger than the previous measurement, both
 *			in single-sliding window and three-sliding windows.
 *	Usage: run the program with a file called 'input-day1a.txt' in the same
 *		  directory of the executable.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
#include <iostream>
#include <vector>
#include <fstream> //to work with files

using std::cout;
using std::endl;
using std::vector;
using std::ifstream;

bool is_empty(ifstream &pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}

int main(void) {

    vector<int> numbersFromTXT;
    int tempValue = 0;
    int counter = 0;
    
    cout << "reading 'input-day1a.txt'" << endl;
    
    ifstream file ("input-day1a.txt"); //instantiate file object
    
    if(!file.is_open()){
        cout << "ERROR - FILE NOT FOUND" << endl;
        return 1;
    }
    
    if(is_empty(file) == 1) {
        cout << "ERROR - FILE IS EMPTY" << endl;
        return 1;
    }

    while(file >> tempValue) {
        numbersFromTXT.push_back(tempValue);
    }
    
 	for(int i = 0; i < numbersFromTXT.size()-1; i++) {
        if(numbersFromTXT.at(i) < numbersFromTXT.at(i+1)) {
            counter++;
        }
    }
    
    cout << "measurements larger than prev measurement: " << counter << endl;
    counter = 0;

    //since we are comparing 3 numbers at a time, we can lower the
    //range by 3
        for(int i = 0; i < numbersFromTXT.size()-3; i++) {
        if(numbersFromTXT.at(i) + numbersFromTXT.at(i+1) + numbersFromTXT.at(i+2) < numbersFromTXT.at(i+1) + numbersFromTXT.at(i+2) + numbersFromTXT.at(i+3)) {
            counter++;
        }
    }
    
    cout << "measurements larger than prev measurement in three-sliding window: " << counter << endl;

    return 0;
}