#include "mat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
const int limL = 33;
const int limR = 126;

// First step - build a expected matrix.
// Second step - add the expected matrix to a string and return the string.
string ariel::mat(int cols , int rows , char symbol1 , char symbol2){
    checkInput1(rows, cols);
    checkInput2(symbol1,symbol2);
    vector<vector<char>> matrix(rows, vector<char> (cols,symbol1));
    int top = 0;
    int left = 0;
    int right = cols - 1; // cols
    int bottom = rows - 1; // rows  
    int size = cols * rows;
    int count = 0;
    int mod = 0;
    // Each time adding a frame to the matrix.
    // From large frame to small frame ( out --> in).
    while(count < size){
        for(int i = left; i <= right && count < size; i++){
            matrix[top][i] = mod % 2 == 0 ?  symbol1 : symbol2;
            count++;
        }
        top++;
        for(int i = top; i <= bottom && count < size; i++){
            matrix[i][right] = mod % 2 == 0 ? symbol1 : symbol2;
            count++;
        }
        right--;
        for(int i = right; i >= left && count < size; i--){
            matrix[bottom][i] = mod % 2 == 0 ?  symbol1 : symbol2;
            count++;
        }
        bottom--;
        for(int i = bottom; i >= top && count < size; i--){
            matrix[i][left] = mod % 2 == 0 ? symbol1 : symbol2;
            count++;
        }
        left++;
        mod++;
    }
    string result = matrixToString(matrix, cols);
    return result;
}
string ariel::matrixToString(vector<vector<char>> matrix, int cols){
    string result;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < cols; j++){
            result += matrix[i][j];
        }
        result += '\n';
    }
    return result;
}
void ariel::checkInput1(int rows, int cols){
    if(rows % 2 == 0 || cols % 2 == 0 || rows < 1 || cols < 1){
        __throw_invalid_argument("rows and columns must be odd and positive.");
    }
}
void ariel::checkInput2(char symbol1, char symbol2){
    if(symbol1 < limL || symbol1 > limR || symbol2 < limL || symbol2 > limR){
        __throw_invalid_argument("invalid symbols.");
    }
}