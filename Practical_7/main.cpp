#include "date.cpp"
#include <cassert>

int main(void) {
  Date startOfTerm(6, 10, 2023);
  startOfTerm.advance();
  assert(startOfTerm.day() == 7);
  assert(startOfTerm.month() == 10);
  assert(startOfTerm.year() == 2023);
  Date halloween(31, 10, 2023);
  halloween.advance();
  assert(halloween.day() == 1);
  assert(halloween.month() == 11);
  assert(halloween.year() == 2023);
  /* This should fail (exit) at run−time because
  there is no 31st November. */
  // halloween.setDay(31);
  halloween.set(31, 10, 2023); // This should succeed
  /* This should fail (exit) at run−time because
  there is no 31st November. */
  halloween.setMonth(11);
  Date startOfYear(1, 1, 2024);
  startOfYear.back();
  assert(startOfYear.day() == 31);
  assert(startOfYear.month() == 12);
  assert(startOfYear.year() == 2023);
  const Date endOfYear = startOfYear;
  assert(endOfYear.day() == 31);
  // endOfYear.setMonth(10); // Should fail at *compile−time*
  // endOfYear = halloween;  // Should fail at *compile−time*

  return 0;
}
