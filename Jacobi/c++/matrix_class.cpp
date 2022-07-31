#include <cassert>
#include "matrix.h"

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

std::istream& operator>>(std::istream& in, Matrix& obj) {
	std::cout << "enter" << obj.m_rows << "X" << obj.m_cols << "element:";
	for (int i = 0; i < obj.m_rows; i++) {
		for (int j = 0; j < obj.m_cols; j++) {
			in >> obj.m_matrix[i][j];
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& obj) {
	out << "rows = " << obj.m_rows << "  m_cols = " << obj.m_cols << std::endl;
	for (int i = 0; i < obj.m_rows; i++) {
		for (int j = 0; j < obj.m_cols; j++) {
			out << obj.m_matrix[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}

double& Matrix::operator()(int row_index, int coll_index){
	assert(row_index >= 0 && row_index < m_rows&& coll_index >= 0 && coll_index < m_cols);
	return m_matrix[row_index][coll_index];
}

double Matrix::operator()(int row_index, int coll_index) const{
	assert(row_index >= 0 && row_index < m_rows&& coll_index >= 0 && coll_index < m_cols);
	return m_matrix[row_index][coll_index];
}

int Matrix::get_rows() const{
	return m_rows;
}

void Matrix::initialize_matrix(std::ifstream& input){
	//	std::ifstream input("input.txt");
	for(int i=0;i<m_rows;i++){
		for(int j=0;j<m_rows+1;j++){
			input >> m_matrix[i][j];
		}
	}
	//	input.close();
}

//check the condition of having a solution
bool Matrix::is_diagonally_dominant(){
	int i, j;
	float sum = 0;	
	for(i = 0; i < m_rows; i++){
		sum = 0;
		for(j = 0; j < m_rows; j++){
			if(i != j){
				sum += std::abs(m_matrix[i][j]);
			}
		}
		if(std::abs(m_matrix[i][i]) <= sum){
			return false;
		}
		else continue; 
	}
	return true;
}



