#include <fstream>
#include <iostream>
#include <string>
#include "matrix.h"
#include <sstream>
#include "gauss.h"

int  MAX_SIZE = 100; // The maximum number of matrixes in the input.txt file

// The dimensions are'nt given in the file, so we count the
// number of rows, and the number of columns will be one more :)
int get_matrix_rows_count(std::ifstream& input){
	int counter = 0;
	std::string temp = "";
	std::getline(input, temp);
	std::stringstream str(temp);
	int x ;
	while (str >> x){
		counter++; //here we store the number of numbers in a row
	}
	int rows = counter-1;
	while(rows--){ // go row by row untin the rows of the matrix are finished
		std::getline(input, temp);
	}
	return  counter-1; // the number of rows
}

// verifying that the input file is correct.
// ___must not be empty
// ___must exist such a file
// ___must be correctly dimensioned
bool accuracy_of_the_input_file(){
	std::ifstream input("input.txt");
	std::ofstream exit("exit.txt");
	if(!input){
		exit<<"input.txt file is NOT EXISTS!"<<std::endl;
		input.close(); exit.close();
		return false;
	}
	bool isEmpty = input.peek() == EOF;
	if (isEmpty){
		exit<<"input.txt file is EMPTY!"<<std::endl;
		input.close(); exit.close();
		return false;
	}
	int rows = 0, cols = 0;
	while(!input.eof()){
		rows = get_matrix_rows_count(input);
		cols = rows + 1;
		if(rows <= 0 || cols != rows+1){
			exit << "ERROR related to matrix sizes!!" << std::endl;
			input.close(); exit.close();
			return false;
		}
	}
	return true;
}

// The function receives the set of solutions of the regular system
// Compares it with the golden file and writes the result to the result.txt file
void write_result(double*& res, int size, int test_count,std::ifstream& golden, std::ofstream& result){
	int  i = 0;
	std::string golden_str;
	getline(golden, golden_str);
	if(!golden.eof()){
		if(golden_str == "The system has no solution" && res==nullptr){
			result << "Test  "<< test_count << "  passed!\n\n";
		}
		else if(golden_str == "The system has no solution" && res!=nullptr){
			result << "Test  "<< test_count<< "FAILED!\n\n";
		}
		else{ // compare the numbers in gonden.txt with the answers we got
			bool check = true;
			std::istringstream is(golden_str);
			double n;
			while( is >> n ) {
				if(n != res[i]){
					check = false;
					result << "Test  "<< test_count<< "FAILED!\n\n";
					break;
				}
				else {
					check = true;
				}
			}
			if(check){
				result << "Test  "<< test_count << "  passed!\n\n";

			}
		}
	}
}

// Reads data frm input.txt file, creates a matrix, and initialize it
// Calls the Gauss method on that matrix,
// sends the result to the write_result() funtion
void test(){
	std::ifstream input("input.txt"); // you can't write but can read
	std::ofstream exit ("exit.txt");
	std::ifstream golden ("golden.txt");
	std::ofstream result ("result.txt");
	//count the number of rows of all matrixes in the file and store in an array
	int rows[MAX_SIZE]={0}, index=0;
	while(!input.eof()){
		rows[index++] = get_matrix_rows_count(input);
		if(index >= MAX_SIZE){
			exit << "The number of matrixs in the file is more than expected,\
				so need to increase the size of MAX_SIZE  (MAX_SIZE is the number of matrixs) \n";
			return;
		}
	}
	input.close();
	//open the input.txt file again to read the data
	std::ifstream input2("input.txt");
	int cols = 0, i=0;
	while(!input2.eof() && i!=index){ // here we use methods of matrix class
		cols = rows[i] + 1;
		Matrix M(rows[i], cols);
		M.initialize_matrix(input2);
		double *res = new double[rows[i]]{0};
		call_gauss_method(M,exit,res, rows[i]);
		write_result(res, rows[i], i+1, golden, result);
		i++;
		delete [] res;
	}
	input2.close();
	exit.close();
	golden.close();
	result.close();
}

int main(){
	if(accuracy_of_the_input_file()){
		test();
	}
	return 0;
}
