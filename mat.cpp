#include "mat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// First step - build a expected matrix.
// Second step - add the expected matrix to a string and return the string.
string ariel::mat(int cols , int rows , char symbol1 , char symbol2){
    if(rows % 2 == 0 || cols % 2 == 0 || rows < 1 || cols < 1){
        __throw_invalid_argument("rows and columns must be odd and positive.");
    }
    char matrix[rows][cols];
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
    string result;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result += matrix[i][j];
        }
        result += '\n';
    }
    return result;
}
 