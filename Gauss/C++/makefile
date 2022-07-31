MyProject: matrix_class.o main.cpp
	g++ main.cpp matrix_class.o -o MyProject
	./MyProject

matrix_class.o: matrix_class.cpp
	g++ -c matrix_class.cpp -o matrix_class.o

clean:
	rm MyProject matrix_class.o result.txt exit.txt
