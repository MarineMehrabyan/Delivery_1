import math
import os
from ast import literal_eval

# verifying that the input file is correct.
# ___must not be empty
# ___must exist such a file
# ___must contains only numeric value
def accuracy_of_the_input_file():
    with open('exit.txt', 'w') as output:
        filesize = os.path.getsize('input.txt')
        if filesize == 0:
            output.write('input.txt file is EMPTY!\n')
            return False
        if os.path.isfile('input.txt') == 0:
            output.write('input.txt file is NOT EXISTS!\n')
            return False
        with open('input.txt') as f:
            lines = f.readlines()
            for line in lines:
                result = all(c.isalnum() or c.isspace() or c=="-" for c in line)
                if result == False:
                    return False
        return True

# Find the equation solutions and return values
def quadratic_eq__roots(a, b, c):
    dis = b * b - 4 * a * c
    sqrt_val = math.sqrt(abs(dis))
    res = []
    if a != 0:
        if dis > 0:
            x1 = (-b - sqrt_val) / (2 * a)
            x2 = (-b + sqrt_val) / (2 * a)
            res.append(literal_eval('{:.6f}'.format(x1)))
            res.append(literal_eval('{:.6f}'.format(x2)))
        elif dis == 0:
            res.append(literal_eval('{:.6f}'.format(-b / (2 * a))))
        else:
            res.append('Has no solution')
    else:
        if b == 0 and c != 0:
            res.append('Has no solution')
        elif b == 0 and c == 0:
            res.append('Solution are real numbers')
        else:
            res.append(literal_eval('{:.6f}'.format(-c / b)))
    return res


# Compares quadratic_eq__roots() value with the value in the golden.txt file
def compare(res, golden_line):
    if len(res)==1:
        s = ''.join(str(x) for x in golden_line)
        return  True if golden_line==s else  False
    else:
        golden_list = list(golden_line.split(" "))
        for i in range(0, len(res)):
            if abs(literal_eval(golden_list[i]) - res[i]) > 0.001:
                return False
        return len(golden_list) == len(res)


# Reads  numbers from the input.txt file
# Calls the quadratic_eq__roots() and Compares() functions for them
# and writes the result to the result.txt file
def test():
    with open('exit.txt', 'w') as e, open('input.txt', 'r') as i,\
            open('golden.txt', 'r') as g, open('result.txt', 'w') as r:
                lst = [literal_eval(x) for x in i.read().split()]
                lines = g.readlines()
                golden_values = [line.rstrip() for line in lines]
                number_of_test = 0
                for i in range(0, len(lst),3):
                    number_of_test += 1
                    res = quadratic_eq__roots(lst[i],lst[i+1],lst[i+2])
                    e.write("{}. The solution of the {}x^2+{}x+{}=0 equation is: {}\n\n".format(\
                            number_of_test,lst[i],lst[i+1],lst[i+2],res))
                    if compare(res,golden_values[number_of_test-1])==True:
                        r.write("Test {} passed :)\n".format(number_of_test+1))
                    else:
                        r.write("Test {} FAILED!\n".format(number_of_test+1))


# the main 
if accuracy_of_the_input_file()==True:
    test()
else:
    print("Something get wrong with input.txt file\n")
