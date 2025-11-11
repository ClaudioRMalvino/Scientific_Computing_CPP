#include <map>

class Date {
private:
  int m_day{};
  int m_month{};
  int m_year{};

  std::map<int, int> daysInMonths = {{1, 31}, {2, 28},  {3, 31},  {4, 30},
                                     {5, 31}, {6, 30},  {7, 31},  {8, 31},
                                     {9, 30}, {10, 31}, {11, 30}, {12, 31}};

  void checkValidity(int day, int month, int year);

public:
  Date(int day, int month, int year);
  void advance();
  void back();
  int day() const;
  int month() const;
  int year() const;
  void setDay(int day);
  void setMonth(int month);
  void setYear(int year);
  void set(int day, int month, int year);
};
