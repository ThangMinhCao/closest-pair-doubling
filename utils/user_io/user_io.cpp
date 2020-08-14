#include <limits>
#include "user_io.h"

int user_io::get_input_number(const std::string &message) {
  int input;
  std::cout << message;
  while (true) {
    std::cin >> input;
    if (std::cin.fail()) {
      std::cout << "Invalid input!" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    break;
  }
  return input;
}

bool user_io::get_y_n_input() {
  char input;
  do {
    std::cin >> input;
  } while (input != 'y' and input != 'Y' and input != 'n' and input != 'N');
  return input == 'y' or input =='Y';
}

std::pair<bool, bool> user_io::ask_for_BF_and_2D() {
  std::pair<bool,bool> result;
  std::cout << "Do you want to run Brute-force after? (y/n) ";
  result.first = get_y_n_input();
  std::cout << "Do you want to run 2D algorithm after? (y/n) ";
  result.second = get_y_n_input();
  return result;
}

int user_io::ask_for_iteration_number() {
  return get_input_number("How many times do you want to run the program? ");
}
