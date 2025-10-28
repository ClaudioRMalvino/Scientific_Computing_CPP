class Date {
private:
  int m_day{};
  int m_month{};
  int m_year{};

  void advance();
  void back();

public:
  int getDay() const;
  int getMonth() const;
  int getYear() const;
  void setDay(int day);
  void setMonth(int month);
  void setYear(int year);
  void set(int day, int month, int year);
};
