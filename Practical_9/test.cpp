#include "Matrix.hpp"
#include <iostream>

int main() {
  Matrix<2> matrix{{1.0, 2.0}, {3.0, 4.0}};
  std::cout << "Size = " << matrix.size() << std::endl;

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix.size(); j++) {
      std::cout << matrix[i, j] << '\n';
    }
  }

  std::cout << "From row 0: " << '\n';
  for (auto elem : matrix[0]) {
    std::cout << elem << '\n';
  }
  return 0;
}
