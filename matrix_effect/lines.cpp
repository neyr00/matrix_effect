#include "lines.hpp"
bool lines::isFin() { return finish; }
int lines::pick_color(bool haos) { return (haos) ? rand() % 15 + 1 : 2; }
int lines::getX() { return width; }
int lines::getY() { return y+1; }
bool lines::isExplode() { 
    if (isExpl) {
        isExpl = false;
        return true;
    }
    return false;
}
void lines::move() {
    curr_time = chrono::steady_clock::now();
    elapsed_time = chrono::duration_cast<chrono::milliseconds>(curr_time - start_time).count();
    if (elapsed_time >= speed && !finish) { 
        win.color(color);
        if (y < height) {
            sym.out(width, y++, true);
            if (currLength == length)
                sym.out(width, y - currLength - 1, false);
            else
                currLength++;
            if (rand() % 1000 < exp_chance) {
                isExpl = true;
                sym.out(width, --y, false);
                currLength--;
                length--;
                if (!length) 
                    finish = true;
            }
        }
        else
            sym.out(width, height - currLength--, false);
        if (!(currLength))
            finish = true;
        start_time = chrono::steady_clock::now();
    }
}
lines::lines(int speed, int length, bool haos, int exp_chance) : speed(1000 / speed), length(length), haos(haos), exp_chance(exp_chance){
    color = pick_color(haos);
    start_time = chrono::steady_clock::now();
    width = rand() % win.getWidth();
    height = win.getHeight();
}