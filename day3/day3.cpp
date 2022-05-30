/*
 *	day3.cpp - Advent of Code 2021
 *
 *	Author: Jonathan Vega
 * 
 *	Purpose: Uses the binary numbers from the text file to calculate the gamma
 *           rate and the epsilon rate as well as the CO2 Scrubber Rating and
 *           Oxygen Generator Rating
 *	Usage: Run the program with a file called 'input-day3a.txt' in the same
 *		   directory of the executable.
 *  Note: You can remove the bitset if you want. They don't affect the outcome,
 *        I just wanted to see the Gamma and Epsilon rate, you can remove it.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <vector>
#include <fstream> //to work with files
#include <math.h> //to use pow
#include <bitset> //to use bitset

using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::string;
using std::cin;
using std::bitset;

bool is_empty(ifstream &pFile) {
    //peeks at first character in the txt file
    return pFile.peek() == ifstream::traits_type::eof();
}

int co2ScrubberRating(vector<string> numbersFromTXT) {
	int counter = 0;
	int decimalValue = 0;
    for(int i = 0; i < numbersFromTXT.at(0).length(); i++) {
    	for(int j = 0; j < numbersFromTXT.size(); j++) {
    		if(numbersFromTXT.at(j).at(i) == '0') {
    			counter++;
    		}
    	}
		//if more zeroes than ones
		if(counter <= numbersFromTXT.size()-counter && numbersFromTXT.size() != 1) {
			for(int k = 0; k < numbersFromTXT.size(); k++) {
				if(numbersFromTXT.at(k).at(i) == '1') {
					numbersFromTXT.erase(numbersFromTXT.begin()+k);
					k--;
				}
			}
		}
		else if (numbersFromTXT.size() != 1) {
			for(int k = 0; k < numbersFromTXT.size(); k++) {
				if(numbersFromTXT.at(k).at(i) == '0') {
					numbersFromTXT.erase(numbersFromTXT.begin()+k);
					k--;
				}
			}
		}

    	counter = 0; //reset counter to sum next string column
    }
    
    for(int i = 0; i < numbersFromTXT.at(0).length(); i++) {
    	if(numbersFromTXT.at(0).at(i) == '1') {
    		decimalValue = decimalValue + pow(2,numbersFromTXT.at(0).length()-1-i);
    	}
    }
    return decimalValue;
}

int oxygenGeneratorRating(vector<string> numbersFromTXT) { //vector is copied, changes won't reflect
	int counter = 0;
	int decimalValue = 0;
    for(int i = 0; i < numbersFromTXT.at(0).length(); i++) {
    	for(int j = 0; j < numbersFromTXT.size(); j++) {
    		if(numbersFromTXT.at(j).at(i) == '0') {
    			counter++;
    		}
    	}//end adding of frequent zeroes

		//if more zeroes than ones
		if(counter > numbersFromTXT.size()-counter && numbersFromTXT.size() != 1) {
			for(int k = 0; k < numbersFromTXT.size(); k++) {
				if(numbersFromTXT.at(k).at(i) == '1') {
					numbersFromTXT.erase(numbersFromTXT.begin()+k);
					k--;
				}
			}
		}
		else if (numbersFromTXT.size() != 1) {
			for(int k = 0; k < numbersFromTXT.size(); k++) {
				if(numbersFromTXT.at(k).at(i) == '0') {
					numbersFromTXT.erase(numbersFromTXT.begin()+k);
					k--;
				}
			}
		}

    	counter = 0; //reset counter to sum next string column
    }
    
    for(int i = 0; i < numbersFromTXT.at(0).length(); i++) {
    	if(numbersFromTXT.at(0).at(i) == '1') {
    		decimalValue = decimalValue + pow(2,numbersFromTXT.at(0).length()-1-i);
    	}
    }
    return decimalValue;
}

int main(void) {

    vector<string> numbersFromTXT;
    string tempValue;
    int gammaRate = 0;
    int epsilonRate = 0;
    int counter = 0; //counts number of zeroes in binary string

/* Open Text File */
	cout << "reading 'input-day3a.txt'" << endl;
    
    ifstream file ("input-day3a.txt"); //instantiate file object
    
    if(!file.is_open()){
        cout << "ERROR - FILE NOT FOUND / CLOSING" << endl;
        return 1;
    }
    
    if(is_empty(file) == 1) {
        cout << "ERROR - FILE IS EMPTY / CLOSING" << endl;
        return 1;
    }
    
    while(file >> tempValue) {
        numbersFromTXT.push_back(tempValue);
    }
    
/* Calculate Gamma & Epsilon Rates */
    for(int i = 0; i < numbersFromTXT.at(0).length(); i++) {
    	for(int j = 0; j < numbersFromTXT.size(); j++) {
    		if(numbersFromTXT.at(j).at(i) == '0') {
    			counter++;
    		}
    	}
    	if(counter > numbersFromTXT.size()/2) {
    		epsilonRate = epsilonRate + pow(2,numbersFromTXT.at(0).length()-1-i);
    	}
    	
    	else {
    		gammaRate = gammaRate + pow(2,numbersFromTXT.at(0).length()-1-i);
    	}
    	counter = 0; //reset counter to sum next string column
    }
    
/* Print Rates in Decimal and Binary */
	cout << endl;
	cout << "Gamma Rate:     " << bitset<5>(gammaRate) << " | " << gammaRate << endl;
	cout << "Epsilon Rate:   " << bitset<5>(epsilonRate) << " | " << epsilonRate << endl;
    cout << "Submarine Power Consumption: " << gammaRate * epsilonRate << endl;
    
/* Calculate Life Support Rating */
	cout << "Life Support Rating: " << oxygenGeneratorRating(numbersFromTXT) * co2ScrubberRating(numbersFromTXT) << endl;

	file.close();
	return 0;
}