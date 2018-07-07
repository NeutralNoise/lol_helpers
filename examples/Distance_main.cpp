#include <iostream>
#include "../Distance.h"

int main() {

  std::cout << "Some distance funactions!\n";

  int x = 4;
  int y = 8;
  int x2 = 70;
  int y2 = 543;

  std::cout << "ManhattanDistance() -> " << ManhattanDistance(x,y,x2,y2) << std::endl;
  std::cout << "EuclideanDistance() -> " << EuclideanDistance(x,y,x2,y2) << std::endl;

  std::cout << "Hit enter to close.\n";
  std::cin.get();

  return 0;
}
