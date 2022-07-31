from ast import literal_eval
import os
from my_matix_class import Matrix

# verifying that the input file is correct.
# ___must not be empty
# ___must exist such a file
# ___must contains only numeric value
def accuracy_of_the_input_file(input_file, exit_file):
    with open(exit_file, 'w') as output:
        filesize = os.path.getsize(input_file)
        if filesize == 0:
            output.write('input file is EMPTY!\n')
            return False
        if os.path.isfile(input_file) == 0:
            output.write('input file is NOT EXISTS!\n')
            return False
        with open(input_file) as f:
            lines = f.readlines()
            for line in lines:
                result = all(c.isalnum() or c.isspace() or c=='-' for c in line)
                if result == False:
                    output.write('input file contains a non-numeric value!\n')
                    return False
        return True


# Implementation of the Gauss algorithm
# Function returns a list containing the solution sets
def jacobi_method(matrix):
    new_val = [0]*len(matrix)
    prev_val = [0]*len(matrix)
    if matrix.is_diagonally_dominant() == True:
        count = 0 
        while True:
            prev_val.append(0)
            for i in range(0,len(matrix)):
                prev_val[i]=new_val[i]
                sum = 0
                for j in range(0, len(matrix)):
                    if i!=j:
                        sum += matrix.getElement(i,j)*prev_val[j]
                prev_val[i]=new_val[i]
                new_val[i]=(matrix.getElement(i,len(matrix))-sum)/matrix.getElement(i,i)
                if abs(prev_val[i]-new_val[i])<0.0001:
                    count +=1
                if count>=len(matrix):
                    return new_val
    else:
        new_val = "Has no solution"
        return new_val

# The function receives the set of solutions of 
# the regular system and write them to the exit.txt file
def write_to_exit(res, exit_file):
    if res != "Has no solution":
        res = ['%.4f' % a for a in res]
    with open(exit_file, 'w') as e:
        e.write("The solutions of the  system are: {}\n".format(res))


# Reads data frm input.txt file, creates a matrix, initialize it,
# Calls the Gauss method on that matrix,
# Compares the answers with the golden file
# and writes the result to the result.txt file
def test():
    with open('golden.txt', 'r') as g, open('result.txt', 'w') as r:
        matrix = Matrix('input.txt')
        res = jacobi_method(matrix)
        write_to_exit(res, "exit.txt")
        count = 0
        line = g.readline()
        if line != "Has no solution" and res != "Has no solution":
            golden_values = [float(i) for i in line.split(" ")]
            for i in range(0, len(res)):
                if abs(res[i]-golden_values[i])<0.001:
                    count +=1
                else:
                    r.write("Test FAILED !!!\n")
            if count == len(res):
                r.write("Test passed Successfilly :)\n")
        elif res=="Has no solution" and line == "Has no solution":
            r.write("Test passed Successfilly :)\n")
        else:
            r.write("Test FAILED !!!\n")

if accuracy_of_the_input_file('input.txt', 'exit.txt')==True:
    test()
                                            
