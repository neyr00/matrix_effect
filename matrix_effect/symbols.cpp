#include "symbols.hpp"
void symbol::out(int x, int y, bool write) {
    if (x >= 0 && y >= 0 && x < win.getWidth() && y < win.getHeight()) {
        win.setCursor(x, y);
        if (write)
            printf("%c", rand() % 94 + 33);
        else
            printf(" ");
    }
}