#include <iostream>

int main(void) {
  int a = -5;
  int b = -2;
  std::cout << a << "/" << b << "= " << a / b << std::endl;

  int result = (a / b) * b + (a % b);

  if (result == a) {
    std::cout << "This is true." << std::endl;
  }
  return 0;
}
