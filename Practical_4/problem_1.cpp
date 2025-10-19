#include <iostream>

int sum(const int &a, const int &b) { return a + b; }

void decrease(int &a, const int &b) { a -= b; }

int q(double a, double b, double c, double &x1, double &x2) {
  int singleSolution{1};
  int twoSolutions{2};

  if (a < 1e-8) {
    x1 = c / b;
    return singleSolution;
  }
  double determinant{b * b - 4 * (a * c)};
  if (determinant < 0) {
    std::cerr << "This quadratic has not real values";
  }

  x1 = (-b + determinant) / (2 * a);
  x2 = (-b - determinant) / (2 * a);

  return twoSolutions;
}

int main(void) {
  int a{4};
  int b{2};
  int c{1};

  double x1, x2;
  decrease(a, b);

  std::cout << "Sum = " << sum(a, b) << std::endl;
  std::cout << "Decrease of a = " << a << std::endl;
  std::cout << "Solutions to quadratic = (" << x1 << ", " << x2 << ")"
            << std::endl;
}
