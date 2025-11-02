#include <algorithm>

class Rational {
private:
  int m_numer{0};
  int m_denom{0};

  void reduce() {
    int gcf = euclidGCF(m_numer, m_denom);
    m_numer /= gcf;
    m_denom /= gcf;

    if (m_denom < 0) {
      m_numer = -m_numer;
      m_denom = -m_denom;
    }
  }

  static int euclidGCF(int num1, int num2) {
    int biggerNum{0};
    int smallerNum{0};
    int gcf{0};

    if (num1 > num2) {
      biggerNum = num1;
    } else {
      biggerNum = num2;
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
  Rational(int num, int denom) : m_numer{num}, m_denom{denom} {}

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
};

Rational operator+(const Rational &frac1, const Rational &frac2) {
  Rational result{0, 0};
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
  Rational result{0, 0};
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
  Rational result{1, 1};

  result.m_numer = frac1.m_numer * frac2.m_numer;
  result.m_denom = frac1.m_denom * frac2.m_denom;

  result.reduce();
  return result;
}

Rational operator/(const Rational &frac1, const Rational &frac2) {
  Rational result{1, 1};

  result.m_numer = frac1.m_numer * frac2.m_denom;
  result.m_denom = frac1.m_denom * frac2.m_numer;

  result.reduce();
  return result;
}
