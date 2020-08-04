#ifndef CLOSESTPAIRDOUBLING_PROGRAM_H
#define CLOSESTPAIRDOUBLING_PROGRAM_H

#include <iostream>

enum CHOICE {
    RANDOM=1,
    GRID=2,
    EXIT=3,
};

class program {
private:
    static int display_menu();
    static point_list menu_random_initialize();
    static point_list menu_grid_initialize();
    static void execute_choice(int choice);

public:
    static void launch();
};

#endif //CLOSESTPAIRDOUBLING_PROGRAM_H
