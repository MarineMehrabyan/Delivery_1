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
                result = all(c.isalnum() or c.isspace() for c in line)
                if result == False:
                    return False
        return True


# Function to find GCD the of two numbers
# Using Euclidian algorithm
def gcd(x, y):
   while(y):
       x, y = y, x % y
   return x

# Reads  numbers from the input.txt file
# Calls the gcd() function for them
# compares gcd() value with the value in the golden.txt file
# and writes the result to the result.txt file 
def test():
    with open('exit.txt', 'w') as e, open('golden.txt', 'r') as g,\
            open('result.txt', 'w') as r, open("input.txt", 'r') as i:
                lst = [int(x) for x in i.read().split()]
                golden_lst = [int(x) for x in g.read().split()]
                test_count = 0
                for j in range(0, len(golden_lst)):
                    res = gcd(lst[test_count], lst[test_count+1])
                    e.write("The GCD of {} and {} is {}\n".format(lst[test_count], lst[test_count+1], res))
                    test_count += 2
                    if abs(res - golden_lst[j])<0.001:
                        r.write("Test {} passed\n".format(j+1))
                    else:
                        r.write("Test {} FAILED!\n".format(j+1))

if accuracy_of_the_input_file()==True:
    test()
else:
    print("Something get wrong\n")
