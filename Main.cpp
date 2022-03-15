#include <iostream>
#include "mat.hpp"


int main(){
    int row, col;
    char symbol1, symbol2;
    cout << "Enter the number of columns and then the number of rows: ";
    cin >> col >> row;
    cout << "Enter the first and then the second symbol: ";
    cin >> symbol1 >> symbol2;
    cout << ariel::mat(col, row, symbol1, symbol2) << endl;
}