//Bradley Macdonald
//2018
#include <iostream>
#include <string>
#include "../Hash.h"

int main() {
  std::cout << "Hello World\n";

  std::string s = "Test String";
  std::string s2 = "Another Test String";

  long hash = djb2Hash((char*)s.c_str());
  long hash2 = djb2Hash((char*)s2.c_str());

  unsigned long long pair = pairing_function(hash, hash2);

  std::cout << "Hash: " << hash << std::endl;
  std::cout << "Hash2: " << hash2 << std::endl;
  std::cout << "Pair: " << pair << std::endl;

  return 0;
}
