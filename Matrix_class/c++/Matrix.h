#pragma once

class Matrix {
    double** m_matrix;
    int  m_cols, m_rows;
public:
    Matrix(int = 4, int = 3);
    Matrix(int, int, double**);
    Matrix(const Matrix&);
    ~Matrix();
    Matrix& operator=(const Matrix&);
    friend std::istream& operator>>(std::istream&, Matrix&);
    friend std::ostream& operator<<(std::ostream&, const Matrix&);
    bool operator==(const Matrix&) const;
    bool operator!= (const Matrix&)const;
    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const Matrix&);
    double& operator()(int, int);
    double operator()(int, int) const;
    void set_cols(int);
    void set_rows(int);
    int get_cols()const;
    int get_rows()const;
    void poxel(int, int);
private:
    void allocate();
    void deallocate();
};
Matrix operator+(Matrix&, const Matrix&);
Matrix operator-(Matrix&, const Matrix&);
Matrix operator*(Matrix&, const Matrix&);
