#include <string>
using namespace std;
namespace ariel{
    string mat(int cols, int rows, char symbol1, char symbol2);
    string matrixToString(vector<vector<char> > matrix, int cols);
    void checkInput1(int rows, int cols);
    void checkInput2(char symbol1, char symbol2);
}