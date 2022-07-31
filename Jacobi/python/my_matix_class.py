from ast import literal_eval

# Matrix class implementaion
class Matrix:
    def __init__(self, input_file):
        self.matrix = self.get_matrix(input_file)

    def get_matrix(self, input_file):
        with open(input_file, 'r') as inpt:
            lines = inpt.readlines()
            matrix = []
            for i in range(0, len(lines)):
                matrix.append([literal_eval(x) for x in lines[i].split(' ')])
            return matrix
    
    def get_readable_matrix_string(self, matrix):
        strings = []
        for row in matrix:
            strings.append(str(row))
        return '\n'.join(strings)

    def __str__(self):
        return self.get_readable_matrix_string(self.matrix)
    
    def __len__(self):
        return len(self.matrix)

    def __getitem__(self, item):
        return self.matrix[item]

    def getElement(self, i, j):
        return self.matrix[i][j]
    
    def setElement(self, i, j, element):
        self.matrix[i-1][j-1] = element


    def is_diagonally_dominant(self):
        for i in range(0,len(self.matrix)):
            sum = 0
            for j in range(0,len(self.matrix)):
                if i!=j:
                    sum +=abs(self.matrix[i][j])
            if abs(self.matrix[i][i])<=sum:
                return False
        return True


