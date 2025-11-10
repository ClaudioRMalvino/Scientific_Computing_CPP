#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  std::ifstream pmList("PMs.txt");
  std::vector<std::string> firstNames;
  std::vector<std::string> lastNames;

  while (std::getline(pmList, firstNames)) {
  }
  return 0;
}:
