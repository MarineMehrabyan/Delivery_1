from ast import literal_eval
import os
from my_matix_class import Matrix
from test import accuracy_of_the_input_file
from test import jacobi_method
from test import write_to_exit

# Reads data frm your_input.txt file, creates a matrix, initialize it,
# Calls the Gauss method on that matrix,
# and writes the result to the result.txt file
def run():
    with open('golden.txt', 'r') as g, open('result.txt', 'w') as r:
        matrix = Matrix("your_input.txt")
        res = jacobi_method(matrix)
        write_to_exit(res, "your_exit.txt")

if accuracy_of_the_input_file('your_input.txt', 'your_exit.txt')==True:
    run()




