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
    if ((num % m_denom) == 0) {
      m_numer += (num / m_denom);
    } else {
      m_numer += num * m_denom;
    }
  }

  Rational &operator+=(const Rational &other) {
    int otherNumer = other.m_numer;
    int otherDenom = other.m_denom;

    if (m_denom != otherDenom) {
      int lcm = lowestCM(m_denom, otherDenom);
      m_numer *= (lcm / m_denom);
      m_denom = lcm;
      m_numer += otherNumer * (lcm / otherDenom)
    }

    reduce();
    return *this;
  }

  Rational &operator-=(const int &num) {
    if ((num % m_denom) == 0) {
      m_numer -= (num / m_denom);
    } else {
      m_numer -= num * m_denom;
    }
  }

  Rational &operator-=(const Rational &other) {
    int otherNumer = other.m_numer;
    int otherDenom = other.m_denom;

    if (m_denom != otherDenom) {
      int gcf = euclidGCF(m_denom, otherDenom);
      if (gcf == m_denom) {
        m_numer *= gcf;
        m_denom *= gcf;
        m_numer -= otherNumer;
      }
      if (gcf == otherDenom) {
        otherNumer *= gcf;
        m_numer -= otherNumer;
      }

      m_numer *= gcf;
      m_denom *= gcf;
      otherNumer *= gcf;
      m_numer -= otherNumer;
    }
  }
  Rational &operator*=(const Rational &other) {
    if ((other.m_numer % m_denom) == 0) {
      int reducedNum = other.m_numer / m_denom;
      m_numer *= reducedNum;
    } else {
      m_numer *= other.m_numer;
    }
    if (m_numer % other.m_denom == 0) {
      m_numer /= other.m_denom;
    } else {
      m_denom *= other.m_denom;
    }
  }

  Rational &operator*=(const int &num) {
    if ((num % m_denom) == 0) {
      m_numer *= (num / m_denom);
    } else {
      m_numer *= num;
    }
  }

  Rational &operator/=(const int &num) {
    if (m_numer % num != 0) {
      m_denom *= num;
    }
    m_numer = m_numer / num;
  }
  Rational &operator/=(const Rational &other) {
    int numer = other.m_denom;
    int denom = other.m_numer;

    if ((numer % m_denom) == 0) {
      m_numer *= numer / m_denom;
    }
    if ((m_numer % denom) == 0) {
      m_numer /= denom;
    }

    m_numer *= numer;
    m_denom *= denom;
  }

  friend Rational operator+(const Rational &frac1, const Rational &frac2);
  friend Rational operator-(const Rational &frac1, const Rational &frac2);
  friend Rational operator*(const Rational &frac1, const Rational &frac2);
  friend Rational operator/(const Rational &frac1, const Rational &frac2);
};

Rational operator+(const Rational &frac1, const Rational &frac2) {
  Rational result;
  Rational fracA = frac1;
  Rational fracB = frac2;

  if (fracA.m_denom != fracB.m_denom) {
    int gcf = Rational::euclidGCF(fracA.m_denom, fracB.m_denom);
    if (gcf == fracA.m_denom) {
      fracA.m_numer *= gcf;
      fracA.m_denom *= gcf;
      fracA.m_numer += fracB.m_numer;
    }
    if (gcf == fracB.m_denom) {
      fracB.m_numer *= gcf;
      fracA.m_numer += fracB.m_numer;
    }

    fracA.m_numer *= gcf;
    fracA.m_denom *= gcf;
    fracB.m_numer *= gcf;
    fracA.m_numer += fracB.m_numer;
  }
}
