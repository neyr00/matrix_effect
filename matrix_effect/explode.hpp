#ifndef EXPLODE_HPP
#define EXPLODE_HPP
#include "figure.hpp"
#include "symbols.hpp"
#include "wind.hpp"
#include <cmath>
#include <chrono>
using namespace std;
class explode : public figure{
private:
	int exp_max, currR, x, y, elapsed_time;
	bool finish = false;
	int pick_color();
	symbol sym;
	wind win;

	chrono::time_point<chrono::steady_clock> start_time, curr_time;
	void drawCircle(int radius, int centerX, int centerY, bool write);
public:
	void move() override;
	bool isFin() override;
	int getY() override;
	int getX() override;
	bool isExplode() override;
	explode(int x, int y, int exp_min, int exp_max);
};
#endif