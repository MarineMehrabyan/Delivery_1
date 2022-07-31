#ifndef MY_LIB
#define MY_LIB
#include <fstream>
#include <iostream>

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
	int get_rows()const;
	double& operator()(int, int);
    	double operator()(int, int) const;
	void initialize_matrix(std::ifstream&);
	void get_the_triangular_look();
	bool is_there_a_line_of_zero();
	private:
	void allocate();
	void deallocate();

};

#endif
