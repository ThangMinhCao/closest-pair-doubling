#ifndef CLOSESTPAIRDOUBLING_USER_IO_H
#define CLOSESTPAIRDOUBLING_USER_IO_H

#include <iostream>
#include <utility>

class user_io {
public:
    static int get_input_number(const std::string& message);
    static bool get_y_n_input();
    static std::pair<bool, bool> ask_for_BF_and_2D();
    static int ask_for_iteration_number();
};


#endif //CLOSESTPAIRDOUBLING_USER_IO_H
