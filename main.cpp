#include <iostream>
#include <stdexcept>
#include  <cmath>
#include "mat.hpp"
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

const int limL = 33;
const int limR = 126;
using namespace std;
using namespace ariel;

// checking if input of user is valid.
// if valid - string to int.
bool getNum(const string& str,int *stringToInt)
{
    *stringToInt = 0;
    int len = str.length();
    for (int i = 0; i < str.length(); i++)
    {
        int val = str[i] -'0';
        if (i==0){
            if (val==0){
                return false;
            }
        }
        if (val< 0|| val >9){
            return false;
        }
        else{
            *stringToInt+= val * pow(10, len - 1);
            len--;

        }
    }
    return true;
}


int main() {
    cout << "This program printing mattresses!\n";
    cout << "All you need to do is enter 2 valid numbers and 2 valid characters.\n";
    cout << "Valid number is a odd number bigger than 0.\n";
    cout << "Valid character is a character between 33-126 in ascii value.\n";
    int columns=0;
    int rows = 0;
    string num1, num2;
    string char1, char2; // for the characters input
    char valid_char1, valid_char2; // for the mattress characters
    bool validTotalInput= false;
    // while loop until total input is valid.
    while (!validTotalInput) {
        cout << "Enter a valid number for the columns: ";
        cin >> num1;
        // while loop until num1 valid
        while (!(getNum(num1, &columns)) || columns % 2 == 0) {
            cout << "input not valid. Enter another number: ";
            cin >> num1;
        }
        cout << "enter a valid number for the rows: ";
        cin >> num2;
        // while loop until num2 valid
        while (!(getNum(num2, &rows)) || rows % 2 == 0) {
            cout << "input not valid. Enter another number: ";
            cin >> num2;
        }
        cout << "Enter the first character: ";
        cin >> char1;
        // while loop until char1 valid
        while (char1.length() != 1) {
            cout << "input not valid, Enter another character: ";
            cin >> char1;
        }
        valid_char1 = *char1.c_str();
        cout << "Enter the second character: ";
        cin >> char2; // getting the input from the user
        // while loop until char2 valid
        while (char2.length() != 1) {
            cout << "input not valid, Enter another character: ";
            cin >> char2;
        }
        valid_char2 = *char2.c_str();
        try {
            cout << mat(columns, rows, valid_char1, valid_char2) << endl;
            validTotalInput = true;
        }
        catch (invalid_argument err) {
            cout << "\n" << err.what();
            cout << "\nPlease try again !\n" << endl;
        }
    }
    cout << "\n Finish - hope you like your mattress ;)" << endl;
}