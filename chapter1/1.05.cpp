#include <iostream>

int main() {
  int v1, v2;
  std::cout << "enter two numbers" << std::endl;
  std::cin >> v1 >> v2;
  std::cout << "The multiplication of ";
  std::cout << v1;
  std::cout << " and ";
  std::cout << v2;
  std::cout << " is ";
  std::cout << v1 * v2;
  std::cout << std::endl;
  return 0;
}