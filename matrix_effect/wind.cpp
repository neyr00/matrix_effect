#include "wind.hpp"

int wind::getWidth() { 
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(handle_Console, &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left;
    return width; 
}
int wind::getHeight() { 
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(handle_Console, &csbi);
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return height; 
}
void wind::color(int color) { SetConsoleTextAttribute(handle_Console, WORD(color)); }
void wind::clear_console() { system("cls"); }
void wind::setCursor(int x, int y) { 
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(handle_Console, coord); 
}
void wind::cursor_hide() {
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 1;
    cursor.bVisible = false;
    SetConsoleCursorInfo(handle_Console, &cursor);
}