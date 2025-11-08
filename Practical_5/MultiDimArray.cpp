#include <format>
#include <iostream>
#include <string>

int userDimensionInput();
int **allocateMatrix(int dims);
void userElementInput(int **matrix, int dims);
void matrixProduct(int **matrixA, int **matrixB, int **matrixC, int dims);
void printMatrix(int **matrix, int dims);
void freeMatrix(int **matrix, int dims);

int main(void) {

  int dimension{userDimensionInput()};
  auto matrixA = allocateMatrix(dimension);
  auto matrixB = allocateMatrix(dimension);
  auto matrixC = allocateMatrix(dimension);

  userElementInput(matrixA, dimension);
  userElementInput(matrixB, dimension);
  matrixProduct(matrixA, matrixB, matrixC, dimension);

  printMatrix(matrixA, dimension);
  std::cout << " X" << std::endl;
  printMatrix(matrixB, dimension);
  std::cout << " =" << std::endl;
  printMatrix(matrixC, dimension);
  std::cout << std::endl;

  freeMatrix(matrixA, dimension);
  freeMatrix(matrixB, dimension);
  freeMatrix(matrixC, dimension);

  return 0;
}

int userDimensionInput() {
  std::cout << "Input dimension of your NxN matrix: ";
  int input;
  std::cin >> input;
  std::cout << std::endl;
  if (input <= 0) {
    throw std::invalid_argument("Your matrix must have dimensions greater > 0");
  }
  return input;
}

int **allocateMatrix(int dims) {
  int **matrix;
  matrix = new int *[dims];
  for (int i = 0; i < dims; i++) {
    matrix[i] = new int[dims];
  }
  return matrix;
}

void userElementInput(int **matrix, int dims) {
  int element;
  for (int i = 0; i < dims; i++) {
    for (int j = 0; j < dims; j++) {
      std::cout << std::endl;
      std::string inputRqstStr =
          std::format("Input integer for element[{},{}]: ", i, j);
      std::cout << inputRqstStr;
      std::cin >> element;
      matrix[i][j] = element;
    }
  }
}

void matrixProduct(int **matrixA, int **matrixB, int **matrixC, int dims) {
  for (int k = 0; k < dims; k++)
    for (int i = 0; i < dims; i++) {
      int sum{0};
      for (int j = 0; j < dims; j++) {
        sum += matrixA[k][j] * matrixB[j][i];
      }
      matrixC[k][i] = sum;
    }
}

void printMatrix(int **matrix, int dims) {
  for (int i = 0; i < dims; i++) {
    std::cout << "[ ";
    for (int j = 0; j < dims; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "]" << std::endl;
  }
}
void freeMatrix(int **matrix, int dims) {
  for (int i = 0; i < dims; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}
