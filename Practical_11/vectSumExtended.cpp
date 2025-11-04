#include <iostream>
#include <type_traits>
#include <vector>

template <typename T> class isReal {
private:
  static const bool value;

public:
  template <typename U = T>
  std::enable_if_t<std::is_floating_point_v<U>, T> static sumVector(
      const std::vector<T> &vect) {
    T sum{0.0};
    T correction{0.0};

    for (int i = 0; i < vect.size(); i++) {
      T temp = sum + vect[i];
      if (std::abs(sum) >= std::abs(vect[i])) {
        correction += (sum - temp) + vect[i];
      } else {
        correction += (vect[i] - temp) + sum;
      }
      sum = temp;
    }
    return (sum + correction);
  }
  template <typename U = T>
  std::enable_if_t<std::is_integral_v<U>, T> static sumVector(
      const std::vector<T> &vect) {

    T sum{0};
    for (int i = 0; i < vect.size(); i++) {
      sum += vect[i];
    }
    return sum;
  }
};

int main(void) {
  std::vector<int> vect1(10);
  std::vector<double> vect2(10);

  for (int i = 0; i < vect1.size(); i++) {
    vect1[i] = i + 2;
  }

  for (int i = 0; i < vect2.size(); i++) {
    vect2[i] = static_cast<double>(i) + 4.222222222222;
  }
  int intSum = isReal<int>::sumVector(vect1);
  double doubleSum = isReal<double>::sumVector(vect2);

  std::cout << "Int sum = " << intSum << std::endl;
  std::cout << "Double sum = " << doubleSum << std::endl;
}
