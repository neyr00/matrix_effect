#include "app_Manager.hpp"
bool app_Manager::isInt(string str) {
    if (str.length() > 4)
        return false;
    else {
        for (int i = 0; i < str.length(); i++)
            if (str[i] > '9' || str[i] < '0')
                return false;
        return true;
    }
}
void app_Manager::start(int argc, char* argv[]) {
    srand(time(NULL));
    if (argc != 8 && argc > 1) {
        cout << "To run matrix.exe enter 3 parameters: speed(1 - 30 symbols/second), length(1 - 30 symbols), chance of creations lines(1-30), epilepsy mod(Y/N), chance of explosions(1 - 1000), min radius(1 - 10), max radius(1 - 10)";
        exit(0);
    }
    else if (argc == 8) {
        if (isInt(argv[1])) {
            speed = stoi(argv[1]);
            if (speed >= 1 && speed <= 30)
                correct++;
        }
        if (isInt(argv[2])) {
            length = stoi(argv[2]);
            if (length <= 30 && length >= 1)
                correct++;
        }
        if (isInt(argv[3])) {
            freq = stoi(argv[3]);
            if (freq <= 30 && freq >= 1)
                correct++;
        }
        if (!strcmp(argv[4], "Y") || !strcmp(argv[4], "y")) {
            haos = true;
            correct++;
        }
        else if (!strcmp(argv[4], "N") || !strcmp(argv[4], "n")) {
            haos = false;
            correct++;
        }
        if (isInt(argv[5])) {
            exp_chance = stoi(argv[5]);
            if (exp_chance <= 1000 && exp_chance >= 1)
                correct++;
        }
        if (isInt(argv[6])) {
            exp_min = stoi(argv[6]);
            if (exp_min <= 10 && exp_min >= 1)
                correct++;
        }
        if (isInt(argv[7])) {
            exp_max = stoi(argv[7]);
            if (exp_max <= 10 && exp_max >= 1 && exp_max >= exp_min)
                correct++;
        }
    }
    if (correct < 7) {
        win.clear_console();
        cout << "Matrix.exe" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Enter lines speed(1 - 30 symbols/second): ";
        while (true)
        {
            cin >> str_speed;
            if (isInt(str_speed)) {
                speed = stoi(str_speed);
                if (speed <= 30 && speed >= 1)
                    break;
            }
            cout << "Incorrect data. Try again: ";
        }
        cout << "Enter lines length(1 - 30 symbols): ";
        while (true)
        {
            cin >> str_length;
            if (isInt(str_length)) {
                length = stoi(str_length);
                if (length <= 30 && length >= 1)
                    break;
            }
            cout << "Incorrect data. Try again: ";
        }
        cout << "Enter frequency of creations lines(1 - 30): ";
        while (true)
        {
            cin >> str_freq;
            if (isInt(str_freq)) {
                freq = stoi(str_freq);
                if (freq <= 30 && freq >= 1)
                    break;
            }
            cout << "Incorrect data. Try again: ";
        }
        cout << "Turn on epilepsy mod?(Y/N) ";
        while (true)
        {
            cin >> swch;
            if (swch == "Y" || swch == "y") {
                haos = true;
                break;
            }
            else if (swch == "N" || swch == "n") {
                haos = false;
                break;
            }
            cout << "Incorrect data. Try again: ";
        }
        cout << "Enter chance of explosions(1 - 1000): ";
        while (true)
        {
            cin >> str_exp_chance;
            if (isInt(str_exp_chance)) {
                exp_chance = stoi(str_exp_chance);
                if (exp_chance <= 1000 && exp_chance >= 1)
                    break;
            }
            cout << "Incorrect data. Try again: ";
        }
        cout << "Enter minimum radius of explosions (1 - 10): ";
        while (true)
        {
            cin >> str_exp_min;
            if (isInt(str_exp_min)) {
                exp_min = stoi(str_exp_min);
                if (exp_min <= 10 && exp_min >= 1)
                    break;
            }
            cout << "Incorrect data. Try again: ";
        }
        cout << "Enter maximum radius of explosions(" << exp_min << " - 10): ";
        while (true)
        {
            cin >> str_exp_max;
            if (isInt(str_exp_max)) {
                exp_max = stoi(str_exp_max);
                if (exp_max <= 10 && exp_max >= 1 && exp_max>=exp_min)
                    break;
            }
            cout << "Incorrect data. Try again: ";
        }
    }
    win.cursor_hide();
    win.clear_console();
    start_time = chrono::steady_clock::now();
    while (true) {
        curr_time = chrono::steady_clock::now();
        elapsed_time = chrono::duration_cast<chrono::milliseconds>(curr_time - start_time).count();
        if (!seconds.empty() && seconds.get(0) <= elapsed_time) {
            figs.push_back(new lines(speed,length,haos,exp_chance));
            seconds.erase(0);
        }
        if (elapsed_time >= 1000) {
            start_time = chrono::steady_clock::now();
            for (int i = 0; i < freq; i++)
                seconds.push_back(rand() % 1000);
            seconds.sorted();
        }
        for (int i = 0; i < figs.getSize(); i++)
            if (figs.get(i)->isFin())
                figs.erase(i--);
            else {
                figs.get(i)->move();
                if (figs.get(i)->isExplode()) {
                    figs.push_back(new explode(figs.get(i)->getX(), figs.get(i)->getY(), exp_min, exp_max));
                }
            }
    }
}