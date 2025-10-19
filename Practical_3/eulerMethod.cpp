#include <cmath>
#include <iostream>

// Forward declarations
double userMaxT();
double userDeltaT();
double userInitY();
double eulerMethod(const double &maxT, const double &deltaT,
                   const double &initY);

int main(void) { return 0; }

double userMaxT() {
  std::cout << "Input maximum elapsed time T: ";
  double maxT;
  std::cin >> maxT;
  std::cout << std::endl;
  return maxT;
}
double userDeltaT() {
  std::cout << "Input time-step size: ";
  double deltaT;
  std::cin >> deltaT;
  std::cout << std::endl;
  return deltaT;
}
double userInitY() {
  std::cout << "Input initial position: ";
  double initY;
  std::cin >> initY;
  std::cout << std::endl;
  return initY;
}
