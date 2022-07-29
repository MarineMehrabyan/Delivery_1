#include <fstream>
#include <iostream>
#include <string>

// Returns the GCD of two numbers
int gcd(int num1,int num2){
	if(num2==0){return num1;}
	else return gcd(num2,num1%num2);
}

// Check whether line of file is contains only numbers
bool is_numeric(std::string const &str){
	for(int i=0;i<str.length();i++){
		if((str[i]>=48 && str[i]<58) || str[i] == ' ' || str[i] =='-'){
			continue;
		}else return false;
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

// Reads 2 numbers from the input.txt file
// Calls the gcd() function for them
// compares with golden.txt file and writes the result to the result.txt file 
void test(){
	std::ifstream input("input.txt"); // you can't write but can read
	std::ofstream exit ("exit.txt");
	std::ifstream golden ("golden.txt");
	std::ofstream result ("result.txt");
	int a, b, res, test_count=0;
	while(input >> a >> b){
		exit <<"The GCD of "<< a <<" and " << b << " is " <<  gcd(a, b) << std::endl;
		golden >> res ;
		if(gcd(a,b)==res)result<<"Test "<<++test_count<<"  passed!\n";
		else result<<"Test "<<++test_count<<"  FAILED!\n";
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
