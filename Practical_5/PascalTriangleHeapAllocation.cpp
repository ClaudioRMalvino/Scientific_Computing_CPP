#include <algorithm>
#include <format>
#include <iostream>
#include <memory>
#include <span>

// Forward declarations

int userInput();
void calcNextRow(std::span<const int> prevRow, std::span<int> nextRow,
                 int rowNum);
void printRow(std::span<const int> currentRow, int rowNum);
void pascalsTriangle(int numRows, int size);

int main(void) {

  // Asked to utilize 0 indexing for row numbers to be printed
  // userInput = N, print format: "Row 0: (...) , Row 1: (...) , ... , Row N-1:
  // (...)"
  int numRows = userInput();

  // I want to keep element[0] and element.back() = 0
  int size = numRows + 2;
  pascalsTriangle(numRows, size);

  return 0;
}

int userInput() {
  std::cout << "Pascal's Triangle Generator" << '\n';
  std::cout << "Please input an integer: " << '\n';

  int input;
  std::cin >> input;
  return input;
}

void calcNextRow(std::span<const int> prevRow, std::span<int> nextRow,
                 int rowNum) {
  for (int j = 1; j < rowNum + 2; j++) {
    nextRow[j] = prevRow[j - 1] + prevRow[j];
  }
}
void printRow(std::span<const int> currentRow, int rowNum) {
  std::cout << "Row " << rowNum << ": " << '\t';
  for (int j = 1; j < rowNum + 2; j++) {
    std::cout << currentRow[j] << '\t';
  }
  std::cout << std::endl;
}
void pascalsTriangle(int numRows, int size) {
  auto prevRow = std::make_unique<int[]>(size);
  auto nextRow = std::make_unique<int[]>(size);
  prevRow[1] = 1;
  // print Row 0;
  std::cout << "Row 0: " << '\t' << prevRow[1] << '\t' << std::endl;

  // Provides correct type for std::span
  size_t size_T = static_cast<size_t>(size);
  for (int rowNum = 1; rowNum < numRows; rowNum++) {
    calcNextRow({prevRow.get(), size_T}, {nextRow.get(), size_T}, rowNum);
    printRow({nextRow.get(), size_T}, rowNum);
    std::swap(nextRow, prevRow);
  }
}
