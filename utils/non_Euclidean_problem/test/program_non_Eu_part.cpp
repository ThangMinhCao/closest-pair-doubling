#include "program_non_Eu_part.h"
#include "algorithm_runner_non_Eu.h"
#include "user_controller/user_input_controller.h"

bool ask_for_BF() {
  std::cout << "Do you want to run Brute-force after? (y/n) ";
  return user_input_controller::get_y_n_input();
}

PointList menu_random_non_Eu_initialize() {
  int point_num;
  int n;
  point_num = user_input_controller::get_input_number("Enter the number of 'points': ");
  n = user_input_controller::get_input_number("Enter the upper bound of the points' values range (1 to n): ");

  PointList list = PointList();
  list.strange_metric_initializer(point_num, n);
  return list;
}

void program_non_Eu_part::execute_non_Eu_program() {
  PointList list = menu_random_non_Eu_initialize();
  bool bf = ask_for_BF();
  int number_of_iteration = user_input_controller::ask_for_iteration_number();
  for (int i = 0; i < number_of_iteration; i++) {
    Test::closest_pair_test_with_strange_space(list, CLOSEST_DOUBLING);
    if (bf) {
      Test::closest_pair_test_with_strange_space(list, BRUTE_FORCE);
    }
  }
}
