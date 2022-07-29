#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
#include "quadratic.h"

// Check whether line of file is contains only numbers
bool is_numeric(std::string const &str){
	for(int i=0;i<str.length();i++){
		if((str[i]>=48 && str[i]<58) || str[i] == ' ' || str[i] == 45)
			continue;
		else return false;
	}
	return true;
}

// verifying that the input file is correct.
// ___must not be empty
// ___must exist such a file
// ___must contains only numeric value
bool accuracy_of_the_input_file(){
	std::ifstream input("input.txt");
	std::ofstream exit("exit.txt");
	if(!input){ //check if the file exists
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
	std::string line;
	getline(input, line);
	while(!input.eof()){
		if(!is_numeric(line)){
			exit<<"input.txt file contains a non-numeric value !"<<std::endl;
			input.close(); exit.close();
			return false;
		}
		getline(input, line);
	}
	return true;
}

// compares with the value in golden.txt, writes the answer in result.txt
void write_result_file( std::ofstream& result,std::string line, 
		 double*&res, const int& size, int& test_count){
	if(size==0 && line == "Has no solution"){
		result<<"Test "<<++test_count<<"  passed!\n";
	}else if (size == 3 && line == "Solution are real numbers"){
		result<<"Test "<<++test_count<<"  passed!\n";
	}else if(size == 2 && count_numbers_in_the_line(line)==2){
		std::stringstream str(line);
		double num1, num2;
		str >> num1 >> num2;
		if((std::abs(num1-res[0])<0.001 && std::abs(num2-res[1])<0.001) || 
				(std::abs(num2-res[0])<0.001 && std::abs(num1-res[1])<0.001)){
			result<<"Test "<<++test_count<<"  passed!\n";
		}
	}	
	else if(size == 1 && count_numbers_in_the_line(line)==1){
		double num=convert(line);
		if(std::abs(num-res[0])<0.001){
			result<<"Test "<<++test_count<<"  passed!\n";
		}
	}else result<<"Test "<<++test_count<<"  FAILED!\n";
}

// opens the necessary files,
// using the functions of the quadratic_equation.h library, 
// calls the function to solve the equation for the given case,
// these functions include writing the answers to the exit.txt file, 
// comparing the answer with the answer written in golden.txt,
// and writing the result.txt file
void test(){
	std::ifstream input("input.txt");
	std::ofstream exit ("exit.txt");
	std::ifstream golden ("golden.txt");
	std::ofstream result ("result.txt");
	double a, b, c;
	int size = 0;
	int test_count=0;
	std::string line;
	getline(golden, line);
	while(input >> a >> b >> c){
		test_count+=1;
		double* res = new double [3];
		res = quadratic(exit,a,b,c, res, size);
		write_result_file( result, line,res,size, test_count);
		delete [] res;
		getline(golden, line);
	}
	golden.close();
	result.close();
	input.close();
	exit.close();
}

int main(){
	if(accuracy_of_the_input_file()){
		test();
	}
	return 0;
}
