#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <vector>

#include "utils/utils.hpp"
#include "utils/SparseMatrix.hpp"


#ifdef SPARSE
    #define INNER_CONTAINER unordered_map<uint, T>
    #define MATRIX_DATA_STRUCTURE SparseMatrix<T>
#else
    #define INNER_CONTAINER std::vector<T>
    #define MATRIX_DATA_STRUCTURE std::vector<std::vector<T>>
#endif

template <typename T>
class Matrix {
public:
    Matrix();
    Matrix(const Matrix & matrix);
    Matrix(uint numberOfNodes);
    Matrix(uint row, uint col);

    Matrix & operator = (const Matrix & matrix);
    INNER_CONTAINER & operator [] (uint node1);

    const T get(uint node1, uint node2) const;
    uint size() const;
private:
   MATRIX_DATA_STRUCTURE data;
};

template <typename T>
inline INNER_CONTAINER & Matrix<T>::operator [] (uint node1) {
    return data[node1];
}

template <typename T>
Matrix<T>::Matrix(uint row, uint col) {
#ifdef SPARSE
    data = MATRIX_DATA_STRUCTURE(row);
#else
    data = MATRIX_DATA_STRUCTURE(row,
           std::vector<T>(col, T()));
#endif
}

template <typename T>
inline const T Matrix<T>::get(uint node1, uint node2) const {
#ifdef SPARSE
    return data.get(node1, node2);
#else
    return data[node1][node2];
#endif
}

template <typename T>
Matrix<T>::Matrix() {
}

template <typename T>
Matrix<T>::Matrix(const Matrix & matrix) {
    data = matrix.data;
}

template <typename T>
Matrix<T>::Matrix(uint numberOfNodes) {
#ifdef SPARSE
    data = MATRIX_DATA_STRUCTURE(numberOfNodes);
#else
    data = MATRIX_DATA_STRUCTURE(numberOfNodes,
           std::vector<T>(numberOfNodes, T()));
#endif
}

template <typename T>
Matrix<T> & Matrix<T>::operator = (const Matrix & matrix) {
    data = matrix.data;
    return *this;
}

template <typename T>
uint Matrix<T>::size() const {
    return data.size();
}

#endif /* MATRIX_HPP_ */
