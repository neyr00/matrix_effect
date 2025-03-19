#include "explode.hpp"
bool explode::isFin() { return finish; }
int explode::pick_color() { return rand() % 15 + 1; }
int explode::getY() { return y; }
int explode::getX() { return x; }
bool explode::isExplode() { return false; }
void explode::drawCircle(int radius, int centerX, int centerY, bool write) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (x <= y) {
        win.color(pick_color());
        sym.out(centerX + x, centerY + y, write);
        win.color(pick_color());
        sym.out(centerX + y, centerY + x, write);
        win.color(pick_color());
        sym.out(centerX - y, centerY + x, write);
        win.color(pick_color());
        sym.out(centerX - x, centerY + y, write);
        win.color(pick_color());
        sym.out(centerX - x, centerY - y, write);
        win.color(pick_color());
        sym.out(centerX - y, centerY - x, write);
        win.color(pick_color());
        sym.out(centerX + y, centerY - x, write);
        win.color(pick_color());
        sym.out(centerX + x, centerY - y, write);

        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else {
            d = d + 4 * x + 6;
        }
    }
}
void explode::move() {
    curr_time = chrono::steady_clock::now();
    elapsed_time = chrono::duration_cast<chrono::milliseconds>(curr_time - start_time).count();
    if (elapsed_time >= 500 && !finish) {
        if (currR <= exp_max) {
            drawCircle(currR, x, y, true);
                drawCircle(currR - 1, x, y, false);
            currR++;
            start_time = chrono::steady_clock::now();
        }
        else {
            drawCircle(currR - 1, x, y, false);
            finish = true;
        }
    }
}
explode::explode(int x, int y, int exp_min, int exp_max) : x(x), y(y), currR(exp_min), exp_max(exp_max) {
    drawCircle(currR, x, y, true);
    currR++;
    start_time = chrono::steady_clock::now();
}