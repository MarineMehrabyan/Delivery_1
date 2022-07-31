#include <iostream>
#include "Matrix.h"
#include <cassert>
using namespace std;

void Matrix::allocate() {
    m_matrix = new double* [m_rows];
    for (int i = 0; i < m_rows; i++) {
        m_matrix[i] = new double[m_cols];
    }
}

void Matrix::deallocate() {
    for (int i = 0; i < m_rows; i++) {
        delete[]m_matrix[i];
    }
    delete[] m_matrix;
}

Matrix::Matrix(int n, int m) {
    m_rows = n;
    m_cols = m;
    allocate();
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            m_matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(int n, int m, double** a) {
    m_rows = n;
    m_cols = m;
    allocate();
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            m_matrix[i][j] = a[i][j];
        }
    }
}

Matrix::Matrix(const Matrix& obj) {
    m_rows = obj.m_rows;
    m_cols = obj.m_cols;
    allocate();
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            m_matrix[i][j] = obj.m_matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
    deallocate();
}

Matrix& Matrix::operator=(const Matrix& obj) {
    if (this != &obj) {
        deallocate();
        m_rows = obj.m_rows;
        m_cols = obj.m_cols;
        allocate();
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                m_matrix[i][j] = obj.m_matrix[i][j];
            }
        }
    }
    return *this;
}

istream& operator>>(istream& in, Matrix& obj) {
    cout << "enter" << obj.m_rows << "X" << obj.m_cols << "element:";
    for (int i = 0; i < obj.m_rows; i++) {
        for (int j = 0; j < obj.m_cols; j++) {
            in >> obj.m_matrix[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const Matrix& obj) {
    out << "rows = " << obj.m_rows << "  m_cols = " << obj.m_cols << endl;
    for (int i = 0; i < obj.m_rows; i++) {
        for (int j = 0; j < obj.m_cols; j++) {
            out << obj.m_matrix[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

bool Matrix::operator==(const Matrix& obj) const {
    if (m_rows != obj.m_rows || m_cols != obj.m_cols) {
        return false;
    }
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            if (m_matrix[i][j] != obj.m_matrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!= (const Matrix& obj)const {
    return !(*this == obj);
}

Matrix& Matrix::operator+=(const Matrix& obj) {
    assert(m_rows == obj.m_rows && m_cols == obj.m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            m_matrix[i][j] += obj.m_matrix[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& obj) {
    assert(m_rows == obj.m_rows && m_cols == obj.m_cols);
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            m_matrix[i][j] -= obj.m_matrix[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& obj) {
    assert(m_cols == obj.m_rows);
    int r = m_rows, c = obj.m_cols;
    double** temp = new double* [r];
    for (int i = 0; i < r; i++) {
        temp[i] = new double[c];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < m_cols; k++) {
                temp[i][j] += m_matrix[i][k] * obj.m_matrix[k][j];
            }
        }
    }
    deallocate();
    m_rows = r;
    m_cols = c;
    m_matrix = temp;
    temp = nullptr;
    return *this;
}

double& Matrix::operator()(int row_index, int coll_index){
    assert(row_index >= 0 && row_index < m_rows&& coll_index >= 0 && coll_index < m_cols);
    return m_matrix[row_index][coll_index];
}

double Matrix::operator()(int row_index, int coll_index) const{
    assert(row_index >= 0 && row_index < m_rows&& coll_index >= 0 && coll_index < m_cols);
    return m_matrix[row_index][coll_index];
}

int Matrix::get_cols() const{
    return m_cols;
}

int Matrix::get_rows() const{
    return m_rows;
}

void Matrix::set_cols(int a){
    m_cols = a;
}

void Matrix::set_rows(int a){
    m_rows = a;
}

Matrix operator+(Matrix& ob1, const Matrix& ob2){
    return ob1 += ob2;
}
