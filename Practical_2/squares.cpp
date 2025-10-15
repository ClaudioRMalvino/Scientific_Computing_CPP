#include <fstream>
#include <iostream>

int main(void) {

  std::ofstream dataFile("squares.dat");

  std::cout << "Please enter the maximum square: ";
  int input;
  std::cin >> input;
  if (input <= 0) {
    std::cerr << "Input a positive integer." << std::endl;
  }

  for (int i = 0; i < (input + 1); i++) {
    int square = i * i;
    std::cout << i << " * " << i << " = " << square << std::endl;
    dataFile << i << ", " << square << '\n';
  }
  dataFile.close();
  return 0;
}
