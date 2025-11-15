#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <stdexcept>

class Rational {
private:
  int m_numer;
  int m_denom;

  void reduce() {
    int gcf = euclidGCF(m_numer, m_denom);
    m_numer /= gcf;
    m_denom /= gcf;

    if (m_denom < 0) {
      m_numer = -m_numer;
      m_denom = -m_denom;
    }
  }
  double value() {
    double val = static_cast<double>(m_numer) / static_cast<double>(m_denom);
    return val;
  }

  static int euclidGCF(const int &num1, const int &num2) {
    int biggerNum{0};
    int smallerNum{0};
    int gcf{0};

    if (num1 > num2) {
      biggerNum = num1;
      smallerNum = num2;
    } else {
      biggerNum = num2;
      smallerNum = num1;
    }

    int remainder = biggerNum % smallerNum;
    if (remainder == 0) {
      return smallerNum;
    }

    while (remainder > 0) {
      std::swap(biggerNum, smallerNum);
      smallerNum = remainder;
      gcf = remainder;
      remainder = biggerNum % smallerNum;
    }
    return gcf;
  }

  static int lowestCM(const int &denomA, const int &denomB) {
    return std::abs(denomA * denomB) / euclidGCF(denomA, denomB);
  }

public:
  Rational(int num, int denom) : m_numer{num}, m_denom{denom} {
    if (denom == 0) {
      throw std::invalid_argument("Denominator cannot be 0.");
    }
    reduce();
  }
  Rational() {};

  Rational &operator+=(const int &num) {
    int newNum = num * m_denom;
    m_numer = m_numer + newNum;
    reduce();
    return *this;
  }

  Rational &operator+=(const Rational &other) {
    if (m_denom != other.m_denom) {
      int lcm = lowestCM(m_denom, other.m_denom);
      m_numer *= (lcm / m_denom);
      m_denom = lcm;
      m_numer += other.m_numer * (lcm / other.m_denom);
    } else {
      m_numer += other.m_numer;
    }
    reduce();
    return *this;
  }

  Rational &operator-=(const int &num) {
    int newNum = num * m_denom;
    m_numer = m_numer - newNum;
    reduce();
    return *this;
  }

  Rational &operator-=(const Rational &other) {

    if (m_denom != other.m_denom) {
      int lcm = lowestCM(m_denom, other.m_denom);
      m_numer *= (lcm / m_denom);
      m_denom = lcm;
      m_numer -= other.m_numer * (lcm / other.m_denom);
    }

    reduce();
    return *this;
  }

  Rational &operator*=(const Rational &other) {
    m_numer = m_numer * other.m_numer;
    m_denom = m_denom * other.m_numer;
    reduce();
    return *this;
  }

  Rational &operator*=(const int &num) {
    m_numer = m_numer * num;
    reduce();
    return *this;
  }

  Rational &operator/=(const int &num) {
    m_denom = m_denom * num;
    reduce();
    return *this;
  }

  Rational &operator/=(const Rational &other) {
    m_numer *= other.m_denom;
    m_denom *= other.m_numer;
    ;
    reduce();
    return *this;
  }

  friend Rational operator+(const Rational &frac1, const Rational &frac2);
  friend Rational operator-(const Rational &frac1, const Rational &frac2);
  friend Rational operator*(const Rational &frac1, const Rational &frac2);
  friend Rational operator/(const Rational &frac1, const Rational &frac2);
  friend std::ostream &operator<<(std::ostream &os, const Rational &r);
  friend std::istream &operator>>(std::ostream &os, Rational &r);
};

Rational operator+(const Rational &frac1, const Rational &frac2) {
  Rational result;
  Rational fracA = frac1;
  Rational fracB = frac2;

  if (frac1.m_denom != frac2.m_denom) {
    int lcm = Rational::lowestCM(fracA.m_denom, fracB.m_denom);
    fracA.m_numer *= lcm / fracA.m_denom;
    fracB.m_numer *= lcm / fracB.m_denom;
    result.m_numer = fracA.m_numer + fracB.m_numer;
    result.m_denom = lcm;
  } else {
    result.m_numer = fracA.m_numer + fracB.m_numer;
    result.m_denom = fracA.m_denom;
  }
  result.reduce();
  return result;
}

Rational operator-(const Rational &frac1, const Rational &frac2) {
  Rational result;
  Rational fracA = frac1;
  Rational fracB = frac2;

  if (frac1.m_denom != frac2.m_denom) {
    int lcm = Rational::lowestCM(fracA.m_denom, fracB.m_denom);
    fracA.m_numer *= lcm / fracA.m_denom;
    fracB.m_numer *= lcm / fracB.m_denom;
    result.m_numer = fracA.m_numer - fracB.m_numer;
    result.m_denom = lcm;
  } else {
    result.m_numer = fracA.m_numer - fracB.m_numer;
    result.m_denom = fracA.m_denom;
  }
  result.reduce();
  return result;
}

Rational operator*(const Rational &frac1, const Rational &frac2) {
  Rational result;

  result.m_numer = frac1.m_numer * frac2.m_numer;
  result.m_denom = frac1.m_denom * frac2.m_denom;

  result.reduce();
  return result;
}

Rational operator/(const Rational &frac1, const Rational &frac2) {
  Rational result;

  result.m_numer = frac1.m_numer * frac2.m_denom;
  result.m_denom = frac1.m_denom * frac2.m_numer;

  result.reduce();
  return result;
}

std::ostream &operator<<(std::ostream &os, const Rational &r) {
  os << r.m_numer << "/" << r.m_denom << std::endl;
  return os;
}

std::istream &operator>>(std::istream &is, Rational &r) {
  int numer;
  char slash;
  int denom;

  if (is >> numer >> slash >> denom) {
    if (slash == '/' && denom != 0) {
      r = {numer, denom};
    } else {
      is.setstate(std::ios::failbit);
      throw std::invalid_argument("Input must be A/B, where B != 0");
    }
  }
  return is;
}
