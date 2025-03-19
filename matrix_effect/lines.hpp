#ifndef LINES_HPP
#define LINES_HPP
#include "symbols.hpp"
#include "wind.hpp"
#include "figure.hpp"
#include <chrono>
using namespace std;
class lines: public figure {
private:
    int length, speed, elapsed_time, color, width, height, y = 0, currLength = 0, exp_chance;
    bool haos, finish = false, isExpl = false;
    symbol sym;
    wind win;
    int pick_color(bool haos);
    chrono::time_point<chrono::steady_clock> start_time, curr_time;
public:
    int getX() override;
    int getY() override;
    void move() override;
    bool isFin() override;
    bool isExplode() override;
    lines(int speed, int length, bool haos,int exp_chance);
};
#endif