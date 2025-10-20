#include <cmath>
#include <fstream>
#include <iostream>

// Forward declarations
double userMaxT();
double userDeltaT();
double userInitY();
void eulerMethod(const double &maxT, const double &deltaT, const double &initY);

int main(void) {

  double maxT{userMaxT()};
  double deltaT{userDeltaT()};
  double initY{userInitY()};
  eulerMethod(maxT, deltaT, initY);

  return 0;
}

double userMaxT() {
  std::cout << "Input maximum elapsed time T: ";
  double maxT;
  std::cin >> maxT;
  if (maxT <= 0) {
    std::cerr << "Total elapsed time must be greater than 0" << std::flush;
  }
  std::cout << std::endl;
  return maxT;
}
double userDeltaT() {
  std::cout << "Input time-step size: ";
  double deltaT;
  std::cin >> deltaT;
  if (deltaT <= 0) {
    std::cerr << "Time step must be greater than 0" << std::flush;
  }
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

void eulerMethod(const double &maxT, const double &deltaT,
                 const double &initY) {

  std::ofstream dataFile("ode.dat");

  double y0 = initY;
  double yNext;
  double time{0.0};

  // dataFile << 0.0 << ", " << y0 << '\n';

  while (time < maxT) {
    yNext = y0 + (deltaT * std::sqrt(y0));

    dataFile << time << ", " << yNext << '\n';
    y0 = yNext;
    time += deltaT;
  }
  dataFile.close();
}
