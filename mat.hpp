#include <iostream>
#include <stdexcept>
#include <functional>
using namespace std;
using namespace std::placeholders;

namespace ariel{
    int get_index(int col, int row, int i, int j);
    void set_all_quarters(string& mat, int col, int row, int i, int j, char symbol);
    void set_all_middles(string& mat, int col, int row, int layer, char symbol);
    string mat(int col, int row, char symbol1, char symbol2);
};