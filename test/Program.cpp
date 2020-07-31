#include <limits>
#include <PointList.h>
#include "Program.h"
#include "Test.h"

int get_input_number() {
  int input;
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

int Program::display_menu() {
  int choice = RANDOM - 1;
  std::cout << "Choose an option below:" << std::endl;
  std::cout << "**** Please note the program only deals with 2D metric spaces ****" << std::endl;
  std::cout << RANDOM << ". Random generated points in Euclidean space" << std::endl;
  std::cout << GRID << ". Grid generated points in Euclidean space" << std::endl;
  std::cout << EXIT << ". Exit the program" << std::endl;
  while (!choice || choice < RANDOM || choice > EXIT) {
    std::cout << "Your selection: ";
    choice = get_input_number();
  }
  std::cout << std::endl;
  return choice;
}

PointList Program::menu_random_initialize() {
  int point_num;
  int range_start, range_end;
  std::cout << "Enter the number of points: ";
  point_num = get_input_number();
  std::cout << "Enter the range: " << std::endl;
  std::cout << "- The lower bound: ";
  range_start = get_input_number();
  std::cout << "- The upper bound: ";
  range_end = get_input_number();

  PointList list = PointList();
  list.random_initializer(2, point_num, range_start, range_end);
  return list;
}

PointList Program::menu_grid_initialize() {
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

  PointList list = PointList();
  list.grid_initializer(distance, y_factor, x_factor, 0);
  return list;
}

bool get_y_n_input(){
  char input;
  do {
    std::cin >> input;
  } while (input != 'y' and input != 'Y' and input != 'n' and input != 'N');
  return input == 'y' or input =='Y';
}

std::pair<bool, bool> ask_for_BF_and_2D() {
  std::pair<bool,bool> result;
  std::cout << "Do you want to run Brute-force after? (y/n) ";
  result.first = get_y_n_input();
  std::cout << "Do you want to run 2D algorithm after? (y/n) ";
  result.second = get_y_n_input();
  return result;
}

void Program::execute_choice(int choice) {
  PointList list;
  std::pair<bool,bool> bf_and_2D;
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
  bf_and_2D = ask_for_BF_and_2D();
  std::cout << std::endl;
  Test::closest_pair_test(CLOSEST_DOUBLING, list, 2);
  if (bf_and_2D.first) {
    Test::closest_pair_test(BRUTE_FORCE, list, 2);
  }
  if (bf_and_2D.second) {
    Test::closest_pair_test(CLOSEST_2D, list, 2);
  }
}

void Program::launch() {
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

