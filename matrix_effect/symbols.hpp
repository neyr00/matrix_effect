#ifndef SYMBOLS_HPP
#define SYMBOLS_HPP
#include <iostream>
#include "wind.hpp"
using namespace std;
class symbol {
private:
    char sym;
    wind win;
public:
    void out(int x, int y, bool write);
};
#endif