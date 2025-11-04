#include <iostream>
#include <vector>

template <typename T> T sumVector(const std::vector<T> &vect) {
  T sum{0};
  for (int i = 0; i < vect.size(); i++) {
    sum += vect[i];
  }
  return sum;
}

template <> double sumVector<double>(const std::vector<double> &vect) {
  double sum{0.0};
  double correction{0.0};

  for (int i = 0; i < vect.size(); i++) {
    double temp = sum + vect[i];
    if (std::abs(sum) >= std::abs(vect[i])) {
      correction += (sum - temp) + vect[i];
    } else {
      correction += (vect[i] - temp) + sum;
    }
    sum = temp;
  }
  return (sum + correction);
}

int main(void) {
  std::vector<int> vect1(10);
  std::vector<double> vect2(10);

  for (int i = 0; i < vect1.size(); i++) {
    vect1[i] = i + 2;
  }

  for (int i = 0; i < vect2.size(); i++) {
    vect2[i] = static_cast<double>(i) + 4.222222222222;
  }
  int intSum = sumVector(vect1);
  double doubleSum = sumVector(vect2);

  std::cout << "Int sum = " << intSum << std::endl;
  std::cout << "Double sum = " << doubleSum << std::endl;
}
