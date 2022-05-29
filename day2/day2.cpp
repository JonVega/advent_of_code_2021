#include <iostream>
#include <fstream> //to work with files

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::stoi;

bool is_empty(ifstream &pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}

int main(void) {

    unsigned int horizontalPosition = 0;
    int depth_a = 0;
    int depth_b = 0;
    int aim = 0;
    string tempString;
    
    cout << "reading 'input-day2a.txt'.....";
    
    ifstream file ("input-day2a.txt"); //instantiate file object
    
    if(!file.is_open()){
        cout << "ERROR - FILE NOT FOUND" << endl;
        return 1;
    }
    
    if(is_empty(file) == 1) {
        cout << "ERROR - FILE IS EMPTY" << endl;
        return 1;
    }
    
    cout << "DONE" << endl;
    
    //when direction string is found, change value of submarine
    //position, then loop to the next one. If one of the three words
    //isn't found, display error and return 1.
    while(file >> tempString) {
        if(!tempString.compare("forward")) {
            file >> tempString;
            horizontalPosition += stoi(tempString);
            depth_b = depth_b + (aim * stoi(tempString));
        }
        
        else if(!tempString.compare("up")) {
            file >> tempString;
            aim -= stoi(tempString);
            depth_a = depth_a - stoi(tempString);
        }
        
        else if(!tempString.compare("down")) {
            file >> tempString;
            aim += stoi(tempString);
            depth_a += stoi(tempString);
        }
        
        else {
            cout << "ERROR - INVALID FILE STRUCTURE" << endl;
            return 1;
        }
    }
    
    cout << "Horizontal Position: " << horizontalPosition << endl;
    cout << "Depth_a: " << depth_a << endl;
    cout << "Depth_b: " << depth_b << endl;
    cout << "Aim: " << aim << endl;
    cout << endl;
    cout << "Horizontal Position * depth_a: " << horizontalPosition * depth_a << endl;
    cout << "Horizontal Position * depth_b: " << horizontalPosition * depth_b << endl;

    return 0;
}