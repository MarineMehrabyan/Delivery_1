import os

# verifying that the input file is correct.
# ___must not be empty
# ___must exist such a file
# ___must contains only numeric value
def accuracy_of_the_input_file():
    with open("exit.txt", 'w') as output:
        filesize = os.path.getsize("input.txt")
        if filesize == 0:
            output.write("input.txt file is EMPTY!\n")
            return False
        if os.path.isfile('input.txt')==0:
            output.write("input.txt file is NOT EXISTS!\n")
            return False
        with open('input.txt') as f:
            lines = f.readlines()
            for line in lines:
                result = all(c.isalnum() or c.isspace() or c=="-" for c in line)
                if result == False:
                    return False
        return True



# Function solves a linear equation and return the root of the equation
def linear(a, b):
    if a == 0 and b != 0:
        return "Has no solution"
    elif a == 0 and b == 0:
        return "The solutions are real numbers"
    elif b==0:
        return b/a
    else: 
        return -b/a


# The function compares the values of the linear() function
# with the values of the golden.txt file
# and writes the result to the result.txt file
def compare(res, size):
    with open('golden.txt', 'r') as g, open('result.txt', 'w') as r:
        lines = g.readlines()
        golden_values = [line.rstrip() for line in lines]
        for i in range(0,len(res)):
            if golden_values[i]=="The solutions are real numbers" or \
                    golden_values[i]=="Has no solution":
                if str(res[i])==golden_values[i]:
                    r.write("Test {} passed :)\n".format(i+1))
                else:
                    r.write("Test {} FAILED!\n".format(i+1))
            else:
                if abs(res[i]-float(golden_values[i]))<0.00001:
                    r.write("Test {} passed :)\n".format(i+1))
                else:
                    r.write("Test {} FAILED!\n".format(i+1))


# Reads  numbers from the input.txt file
# Calls the linear() function for them
# compares linear() value with the value in the golden.txt file
# and writes the result to the result.txt file 
def test():
    with open('exit.txt', 'w') as e, open("input.txt", 'r') as i:
                lst = [x for x in i.read().split()]
                number_of_test = 0
                res = []
                for j in range(0, len(lst),2):
                    res.append(linear(float(lst[j]), float(lst[j+1])))
                    e.write("{}. The solution of the {}x+{}=0 equation is: {}\
                            \n".format(number_of_test,lst[j], lst[j+1], res[number_of_test]))
                    number_of_test += 1
                compare(res, len(lst)/2)

if accuracy_of_the_input_file()==True:
    test()
else:
    print("Something get wrong\n")
