#include <limits>
#include <point_list.h>
#include "program.h"
#include "algorithm_runner.h"
#include "../utils/non_Euclidean_problem/test/program_non_Eu_part.h"
#include "user_controller/user_input_controller.h"

int program::display_menu() {
  int choice = RANDOM - 1;
  std::cout << "\nChoose an option below:" << std::endl;
  std::cout << "**** Please note the program only deals with 2D metric spaces ****" << std::endl;
  std::cout << RANDOM << ". Random generated points in Euclidean space" << std::endl;
  std::cout << GRID << ". Grid generated points in Euclidean space" << std::endl;
  std::cout << NON_EU << ". Random generated points in non-Euclidean space" << std::endl;
  std::cout << EXIT << ". Exit the program" << std::endl;
  while (!choice || choice < RANDOM || choice > EXIT) {
    choice = user_input_controller::get_input_number("Your selection: ");
  }
  std::cout << std::endl;
  return choice;
}

point_list program::menu_random_initialize() {
  int point_num;
  int range_start, range_end;
  point_num = user_input_controller::get_input_number("Enter the number of points: ");
  std::cout << "Enter the range: " << std::endl;
  range_start = user_input_controller::get_input_number("- The lower bound: ");
  range_end = user_input_controller::get_input_number("- The upper bound: ");

  point_list list = point_list();
  list.random_initializer(2, point_num, range_start, range_end);
  return list;
}

point_list program::menu_grid_initialize() {
  double distance;
  int x_factor, y_factor;
  std::cout << "Enter two integer factors to make the number of points (eg: X x Y =  4 x 3 = 12 points): " << std::endl;
  std::cout << "- Enter the X factor: ";
  std::cin >> x_factor;
  std::cout <<"- Enter the y factor: ";
  std::cin >> y_factor;
  std::cout << "Enter the squares' sides (the closest-pair distance): ";
  std::cin >> distance;
  std::cout << std::endl;

  point_list list = point_list();
  list.grid_initializer(distance, y_factor, x_factor, 0);
  return list;
}

void program::execute_choice(int choice) {
  if (choice == NON_EU) {
    program_non_Eu_part::execute_non_Eu_program();
    return;
  }
  std::pair<bool, bool> bf_and_2D;
    point_list list;
    switch (choice) {
      case RANDOM:
        list = menu_random_initialize();
        break;
      case GRID:
        list = menu_grid_initialize();
        break;
      default:
        return;
    }
  bf_and_2D = user_input_controller::ask_for_BF_and_2D();
  int number_of_iteration = user_input_controller::ask_for_iteration_number();
  for (int i = 0; i < number_of_iteration; i++) {
    std::cout << "\nNumber of points: " << (int) list.points.size() << std::endl;
    algorithm_runner::closest_pair_test(CLOSEST_DOUBLING, list, 2);
    if (bf_and_2D.first) {
      algorithm_runner::closest_pair_test(BRUTE_FORCE, list, 2);
    }
    if (bf_and_2D.second) {
      algorithm_runner::closest_pair_test(CLOSEST_2D, list, 2);
    }
  }
}

void program::launch() {
  int choice;
  srand((unsigned)time(nullptr));
  do {
    choice = display_menu();
    if (choice == EXIT) {
      break;
    }
    execute_choice(choice);
  } while (true);
}

