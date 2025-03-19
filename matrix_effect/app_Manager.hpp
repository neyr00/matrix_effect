#ifndef APP_MANAGER_HPP
#define APP_MANAGER_HPP
#include "lines.hpp"
#include "explode.hpp"
#include "wind.hpp"
#include "list.hpp"
#include "arrlist.hpp"
#include "llist.hpp"
#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;
class app_Manager {
private:
    wind win;
    bool isInt(string str);
    linkedlist<figure*> figs;
    arrlist<int> seconds;
    int speed = -1, length = -1, freq = -1, correct = 0, currSec = 0, exp_chance = 0, exp_min = 0, exp_max = 0, elapsed_time;
    bool haos = false;
    string str_speed, str_length, str_freq, swch, str_exp_chance, str_exp_min, str_exp_max;
    chrono::time_point<chrono::steady_clock> start_time, curr_time;
public:
    void start(int argc, char* argv[]);
};
#endif