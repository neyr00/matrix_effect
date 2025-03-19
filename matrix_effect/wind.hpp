#ifndef WIND_HPP
#define WIND_HPP
#include <windows.h>
class wind {
private:
    HANDLE handle_Console = GetStdHandle(STD_OUTPUT_HANDLE);
    int width;
    int height;
    COORD coord;
public:
    int getWidth();
    int getHeight();
    void setCursor(int x, int y);
    void clear_console();
    void color(int color);
    void cursor_hide();
};
#endif