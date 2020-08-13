#ifndef CLOSESTPAIRDOUBLING_PROGRAM_H
#define CLOSESTPAIRDOUBLING_PROGRAM_H

#include <iostream>
#include "point_list.h"

enum CHOICE {
    RANDOM=1,
    GRID=2,
    NON_EU = 3,
    EXIT=4,
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
