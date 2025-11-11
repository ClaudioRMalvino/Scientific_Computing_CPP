#include "date.hpp"
#include <iostream>
#include <stdexcept>

Date::Date(int day, int month, int year)
    : m_day(day), m_month(month), m_year(year) {

  checkValidity(day, month, year);
}

void Date::checkValidity(int day, int month, int year) {
  if (m_day > daysInMonths[m_month]) {
    throw std::invalid_argument(
        "Selected date doesn't fall within range of the selected month");
  }
  if ((day > 31) || (day < 1)) {
    throw std::invalid_argument("Days range from [1, 31]");
  }
  if ((month < 1) || (month > 12)) {
    throw std::invalid_argument("Months range from [1, 12]");
  }
  if (year < 0) {
    throw std::invalid_argument("The year can't be a negative value.");
  }
}

void Date::advance() {
  int currentDay = m_day;
  int currentMonth = m_month;
  int currentYear = m_year;

  if ((currentDay + 1) <= daysInMonths[currentMonth]) {
    m_day += 1;
  } else {
    if ((currentMonth + 1) <= 12) {
      m_day = 1;
      m_month += 1;
    } else {
      m_day = 1;
      m_month = 1;
      m_year += 1;
    }
  }
}

void Date::back() {
  int currentDay = m_day;
  int currentMonth = m_month;
  int currentYear = m_year;

  if ((currentDay - 1) >= 1) {
    m_day -= 1;
  } else {
    if ((currentMonth - 1) >= 1) {
      m_month -= 1;
      m_day = daysInMonths[m_month];
    } else {
      m_month = 12;
      m_day = 31;
      m_year -= 1;
    }
  }
}

int Date::day() const { return m_day; }

int Date::month() const { return m_month; }

int Date::year() const { return m_year; }

void Date::setDay(int day) {
  checkValidity(day, m_month, m_year);
  m_day = day;
}

void Date::setMonth(int month) {
  checkValidity(m_day, month, m_year);
  m_month = month;
}

void Date::setYear(int year) {
  checkValidity(m_day, m_month, year);
  m_year = year;
}

void Date::set(int day, int month, int year) {
  checkValidity(day, month, year);
  m_day = day;
  m_month = month;
  m_year = year;
}
