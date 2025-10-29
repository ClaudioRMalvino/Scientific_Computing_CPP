class Rational {
private:
  int m_numer;
  int m_denom;

public:
  Rational(int num, int denom) : m_numer{num}, m_denom{denom} {}

  Rational &operator+(const int &num) { m_numer += (num * m_denom); }
  friend Rational operator*(const Rational &frac1, const Rational &frac2);
  Rational &operator*(const Rational &other) {
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
  Rational &operator/=(const int &num) {
    if (m_numer % num != 0) {
      m_denom *= num;
    }
    m_numer = m_numer / num;
  }
  Rational &operator+=(int num) {}
};

Rational operator*(const Rational &frac1, const Rational &frac2) {
  int numer;
  int denom;

  if ((frac2.m_numer % frac1.m_denom) == 0) {
    int reducedNumer = frac2.m_numer / frac1.m_denom;
    numer{reducedNumer};
  }
}
