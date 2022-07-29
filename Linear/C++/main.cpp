#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
// Returns the root of a linear equation if it has exactly one root
double linear(double num1, double num2){
	return double(-num2/num1);
}

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

// convert string to double
double convert(std::string& string) {
    std::stringstream s(string);
    double ret=0;
    s >> ret;
    return ret;
}

// Reads 2 numbers from the input.txt file
// Calls the linear() function for them or counts excceptional casses here 
// compares with golden.txt file and writes the result to the result.txt file 
void test(){
	std::ifstream input("input.txt"); 
	std::ofstream exit ("exit.txt");
	std::ifstream golden ("golden.txt");
	std::ofstream result ("result.txt");
	float a, b; 
	int test_count=0;
	std::string line;
	input >> a >> b;
        getline(golden, line);
	while(!input.eof()){
		if(a==0 && b!=0){
			exit << "The equation "<<a<<"x+"<<b <<"=0 has NO SOLUTION!" << std::endl;
			if(line == "Has no solution")result<<"Test "<<++test_count<<"  passed!\n";
			else result<<"Test "<<++test_count<<"  FAILED!\n";
		}
		else if (a==0 && b==0){
			exit <<"The solutions to the  equation "<<a<<"x+"<< b <<"=0 are real numbers" << std::endl;
			if(line == "Solutions are real numbers")result<<"Test "<<++test_count<<"  passed!\n";
			else result<<"Test "<<++test_count<<"  FAILED!\n";
		}
		else {
			exit <<std::setprecision(5)<< linear(a, b) << std::endl;
			double num = convert(line);		
			if(std::abs(num-linear(a, b))<0.001)result<<"Test "<<++test_count<<"  passed!\n";
                        else result<<"Test "<<++test_count<<"  FAILED!\n";
		}
		getline(golden, line);
		input >> a >>b;
	}
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
