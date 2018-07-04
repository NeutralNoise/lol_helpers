#include <iostream>
#include "../RandomNum.h"

int main() {
  std::cout << "Hello World\n";

  RandomNum rng(5433);

  for(int i = 0; i < 50 ; i++) {
    std::cout << "Number " << i << ": " << rng.GenerateNumber() << "\n";
  }

  return 0;
}
