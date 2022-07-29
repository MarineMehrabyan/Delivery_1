
// When the discriminant is positive, it has 2 roots, 
// When the discriminant is 0, it has 1 root,
// When the discriminant is smaller than 0, then the equation has no root,
// When the coefficient of x^2 is 0, the equation becomes a linear equation,
// Writes the roots in exit.txt file
double* quadratic(std::ofstream& exit, double& a, double& b, double& c, double*& res, int& size){
        if(a!=0){
                double d=b*b-4*a*c;
                if (d>0){
                        size = 2;
                        res[0] = (-b-sqrt(d))/(2*a);
                        res[1] = (-b+sqrt(d))/(2*a);
                        exit<<"The set of solutions to the equation are:\n";
                        exit << std::setprecision(5)<<"X1="<< res[0] << "\tX2=" << res[1] << "\n\n";
                }else if(d==0){
                        size = 1;
                        res[0]=(-b)/(2*a);
                        exit<<"The  equation has one root, which is:\n";
                        exit << std::setprecision(5)<<"X1="<< res[0]<< "\n\n";
                }else{
                        size = 0;
                        res = nullptr;
                        exit<<"The equation has no solution!\n\n";
                }
        }else{
                if(b==0 && c!=0){
                        size = 0;
                        res = nullptr;
                        exit<<"The equation has no solution!\n\n";
                }else if(b==0 && c==0){
                        size = 3;
                        exit<<"The solutions to the equation are real numbers\n\n";
                        res[0]=res[1]=res[2]=0; // full
                }else if (b!=0 && c==0){
                        size = 1;
                        exit<<"The  equation has one root, which is:\n";
                        exit << std::setprecision(5)<<"X1="<< 0 << "\n\n";
                }else{
                        size = 1;
                        res[0] = -b/c;
                        exit<<"The  equation has one root, which is:\n";
                        exit << std::setprecision(5)<<"X1="<<res[0] << "\n\n";
                }
        }
        return res;
}

// convert string to double
double convert(std::string& string) {
        std::stringstream s(string);
        double ret=0;
        s >> ret;
        return ret;
}
// this is called when we compare the answer with the golden.txt file,
//  because there may not be as many numbers in the line as there are roots
int count_numbers_in_the_line(std::string line){
        std::stringstream str(line);
        double x; int count = 0;
        while (str >> x){
                count++ ; // here we store the number of numbers in a row
        }
        return count;
}

