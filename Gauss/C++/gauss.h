// Implementation of the Gauss algorithm
// Function returns a dynamic array containing the solution sets
double*  Gauss_method(Matrix M){
	double* result = new double [M.get_rows()];
	M.get_the_triangular_look();// to make the matrix triangular
	//if there is a line of zero, then according to the method the system has no solution
	if(M.is_there_a_line_of_zero() == 0 ){
		for(int i=0;i<M.get_rows(); i++){
			result[i]= M(i, M.get_rows())/M(i,i);
		}
	}else {
		result = nullptr;
	}
	return result;
}


// Calss the Gauss Method funtion and
//  writes the returned values to the exit.txt file
void call_gauss_method(Matrix M, std::ofstream& exit, double*& res, int size){
	res = Gauss_method(M);
	if(res!=nullptr){
		exit << "The solutions of the ordinal system are:\n";
		for(int k = 0; k< size; k++){
			exit << "X" << k+1 << "=" << res[k]<<"\t";
		}
		exit <<"\n\n";
	}
	else{
		exit << "The system has no solution\n\n";
	}
}

