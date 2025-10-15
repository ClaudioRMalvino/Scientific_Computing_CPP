#include <cmath>
#include <iostream>
#include <utility>

// Forward declerations
double userInputA();
double userInputB();
double userInputC();
std::pair<double, double> quadraticEq(double a, double b, double c);
void printResults(std::pair<double, double> &results);

int main(void) {
  std::cout << "Solving a*x*x + b*x + c = 0" << std::flush;

  double a{userInputA()};
  double b{userInputB()};
  double c{userInputC()};

  std::pair<double, double> result = quadraticEq(a, b, c);
  printResults(result);

  return 0;
}

double userInputA() {
  std::cout << "Enter a: " << std::endl;
  double a;
  std::cin >> a;
  return a;
}
double userInputB() {
  std::cout << "Enter b: " << std::endl;
  double b;
  std::cin >> b;
  return b;
}
double userInputC() {
  std::cout << "Enter c: " << std::endl;
  double c;
  std::cin >> c;
  return c;
}

/**
 * @brief Function calculates the quadratic equation for a
 * polynomial.
 *
 * @param a the x^2 coefficient
 * @param b the x coefficient
 * @param c the constant
 * @return std::pair with the first element as the plus result and
 * second element the minus plusResult
 */
std::pair<double, double> quadraticEq(double a, double b, double c) {

  double radicand = (b * b) - 4 * (a * c);
  if (radicand < 0) {
    std::cerr << "There are no real solution." << std::endl;
  }
  double rightTerm{std::sqrt(radicand) / (2 * a)};
  double plusResult{-b + rightTerm};
  double minusResult{-b - rightTerm};
  return std::make_pair(plusResult, minusResult);
}

void printResults(std::pair<double, double> &results) {
  std::cout << "The roots are: (" << results.first << ", " << results.second
            << ")" << std::endl;
}
