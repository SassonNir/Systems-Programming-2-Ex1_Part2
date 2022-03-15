#include "mat.hpp"

namespace ariel {

int get_index(int col, int row, int i, int j) {
    return i * col + j + i;  // Index in mat is i * col + j and then add the number of new lines up to i
}

void set_all_quarters(string& mat, int col, int row, int i, int j, char symbol) {
    mat[get_index(col, row, i, j)] = symbol;                      // top left
    mat[get_index(col, row, i, col - 1 - j)] = symbol;            // top right
    mat[get_index(col, row, row - 1 - i, j)] = symbol;            // bottom left
    mat[get_index(col, row, row - 1 - i, col - 1 - j)] = symbol;  // bottom right
}

void set_all_middles(string& mat, int col, int row, int layer, char symbol) {
    mat[get_index(col, row, layer, col / 2)] = symbol;            // middle top
    mat[get_index(col, row, row - 1 - layer, col / 2)] = symbol;  // middle bottom
    mat[get_index(col, row, row / 2, layer)] = symbol;            // middle left
    mat[get_index(col, row, row / 2, col - 1 - layer)] = symbol;  // middle right
}

/*
Input: col=9, row=7, a='@', b='-'
Output:
@@@@@@@@@
@-------@
@-@@@@@-@
@-@---@-@
@-@@@@@-@
@-------@
@@@@@@@@@

Input: col=13, row=5, a='@', b='-'
Output:
@@@@@@@@@@@@@
@-----------@
@-@@@@@@@@@-@
@-----------@
@@@@@@@@@@@@@
*/
string mat(int col, int row, char symbol1, char symbol2) {
    string result;
    if (col <= 0 || row <= 0) {
        throw std::invalid_argument("Mat size is always positive");
    }
    if (col % 2 == 0 || row % 2 == 0) {
        throw std::invalid_argument("Mat size is always odd");
    }
    string s;
    int num_of_chars = col * row + (row - 1);  // row * (col + 1) - 1 // row - 1 is number of new lines with except the last line
    s.reserve(num_of_chars);
    for (int i = 1; i <= num_of_chars; ++i) {
        if (i % (col + 1) == 0) {
            s.push_back('\n');
        } else {
            s.push_back(' ');
        }
    }

    auto set_quarters = bind(&set_all_quarters, std::ref(s), col, row, _1, _2, _3);
    auto set_middles = bind(&set_all_middles, std::ref(s), col, row, _1, _2);
    
    for (int i = 0; i <= row / 2; ++i) {
        for (int j = 0; j <= col / 2; ++j) {
            if (i == j) {
                set_middles(min(i, j), min(i, j) % 2 == 0 ? symbol1 : symbol2);
            }
            set_quarters(i, j, min(i, j) % 2 == 0 ? symbol1 : symbol2);
        }
    }
    return s;
}

}  // namespace ariel
