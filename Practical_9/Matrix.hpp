#include <cstddef>
#include <initializer_list>
#include <vector>

template <int SIZE, typename T = double> class Matrix {
public:
  Matrix(std::initializer_list<std::initializer_list<T>> elements)
      : m_matrix(SIZE, std::vector<T>(SIZE)) {
    int i{0};

    for (std::initializer_list<T> row : elements) {
      for (int j = 0; j < SIZE; j++) {
        m_matrix[i][j] = row.begin()[j];
      }
      i++;
    }
  }
  const int size() const;
  T operator[](int indexI, int indexj) const;
  T &operator[](int indexI, int indexJ);
  std::vector<T> operator[](int indexI);
  // std::vector<T> &operator[](int indexI);

private:
  std::vector<std::vector<T>> m_matrix;
};

template <int SIZE, typename T> const int Matrix<SIZE, T>::size() const {
  return m_matrix.size();
}

template <int SIZE, typename T>
T Matrix<SIZE, T>::operator[](int indexI, int indexJ) const {
  return m_matrix[indexI][indexJ];
}

template <int SIZE, typename T>
T &Matrix<SIZE, T>::operator[](int indexI, int indexJ) {
  return m_matrix[indexI][indexJ];
}

template <int SIZE, typename T>
std::vector<T> Matrix<SIZE, T>::operator[](int indexI) {
  return m_matrix[indexI];
}
