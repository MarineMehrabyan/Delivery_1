// In this funtion we get what epsilon deviation the algorithm will work with,
// and we implement the algorithm for the given matrix,
// The function modifies the previous_val and new_val arrays,
// and return whether the system has a solution or not
bool Jacobi_method(Matrix M, double*&previous_val, double*&new_val, double epsilon = 0.001){
	double sum = 0;
	int count = 0;
	while(true){
		for(int i = 0; i < M.get_rows(); i++){
			sum = 0;
			for(int j = 0; j < M.get_rows(); j++){
				if(i != j){
					sum += M(i,j)*previous_val[j];
				}
			}
			previous_val[i] = new_val[i];
			new_val[i] = (M(i, M.get_rows()) - sum)/M(i,i);
			if(std::abs(previous_val[i]-new_val[i]) < epsilon){
				count++;
			}
			if(count > M.get_rows()-1){
				return false;
			}
		}
	}
	for(int i=0;i<M.get_rows(); i++)
		std::cout<<new_val[i]<<"        ";
	std::cout<<"\n";
	return true;
}

// Checks the existence condition of diagonal dominance, and
// if it exists, calls the Jacobi mehthod funtion,
//if there is no diagonal dominance, the system has no solution
// writes the result to the e exit file
void  call_jacobi_method(Matrix M, std::ofstream& exit, double*& new_val, int size){
	if(M.is_diagonally_dominant() == true ){
		double* previous_val = new double[size]{0};
		if(Jacobi_method(M, previous_val, new_val) == 0){
			exit << " The solutions of the ordinal system are:\n";
			for(int k = 0; k< size; k++){
				double diff = std::abs(previous_val[k]-new_val[k]);
				exit << "X" << k+1 << "=" << new_val[k]<<" :" <<"\t"<<
					"Epsilon accuracy is: "<<diff<<std::endl;
			}
			exit <<"\n\n";
		}else{
			exit << "The system has no solution\n\n\n";
		}
		delete [] previous_val;
	}
	else {
		exit << "The system has no solution\nBut it is possible to change the rows or columns of the matrix and the resulting matrix will have a solution :) \n\n\n";
		new_val = nullptr;
	}

}
