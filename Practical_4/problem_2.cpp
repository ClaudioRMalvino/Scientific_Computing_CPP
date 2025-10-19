#include <iostream>
#include <vector>

void partialSum(const std::vector<int> &vect1, std::vector<int> &vect2) {

  int currIndex{0};

  for (int i = 0; i < vect2.size(); i++) {
    int sum{0};

    for (int j = 0; i <= currIndex; j++) {
      sum += vect1[j];
    }
    vect2[i] = sum;
    currIndex++;
  }
}

void printArray(const std::vector<int> &vect) {
  for (size_t i = 0; i < vect.size(); i++) {
    std::cout << vect[i] << std::endl;
  }
}

int main(void) {
  std::vector<int> vect1(20);
  std::vector<int> vect2(20);

  for (int i = 0; i < vect1.size(); i++) {
    vect1[i] = i;
  }

  partialSum(vect1, vect2);
  printArray(vect2);
  return 0;
}
