#include <format>
#include <iostream>
#include <string>
#include <vector>

// Function Decleration
template <typename T = int> std::vector<std::vector<T>> userElementInput();
template <typename T>
T calcDeterminant(const std::vector<std::vector<T>> &matrix);
template <typename T> T calcTrace(const std::vector<std::vector<T>> &matrix);
template <typename T> void printResults(const T &determinant, const T &trace);

int main() {
  auto userMatrix = userElementInput();
  auto determinant = calcDeterminant(userMatrix);
  auto trace = calcTrace(userMatrix);
  printResults(determinant, trace);
  return 0;
}

// Function definitions
template <typename T> std::vector<std::vector<T>> userElementInput() {
  int dims = 3;
  std::vector<std::vector<T>> usrMatrix(3, std::vector<T>(3));
  int element;
  for (int i = 0; i < dims; i++) {
    for (int j = 0; j < dims; j++) {
      std::string inputRqstStr =
          std::format("Input integer for element[{},{}]: ", i, j);
      std::cout << inputRqstStr;
      std::cin >> element;
      usrMatrix[i][j] = element;
    }
  }
  return usrMatrix;
}

template <typename T>
T calcDeterminant(const std::vector<std::vector<T>> &matrix) {
  T firstTerm = matrix[0][0] *
                ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]));
  T secondTerm = matrix[0][1] * ((matrix[1][0] * matrix[2][2]) -
                                 (matrix[1][2] * matrix[2][0]));
  T thirdTerm = matrix[0][2] *
                ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]));
  return firstTerm - secondTerm + thirdTerm;
}

template <typename T> T calcTrace(const std::vector<std::vector<T>> &matrix) {
  T sum{0};
  for (int i = 0; i < matrix[0].size(); i++) {
    sum += matrix[i][i];
  }
  return sum;
}

template <typename T> void printResults(const T &determinant, const T &trace) {
  std::cout << "Determinant = " << determinant << '\n';
  std::cout << "Trace = " << trace << std::endl;
}
