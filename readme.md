____This is an interpreter for a sub-set of the Scheme programming language____

*This is a current high-level overview of the interpreter
      +----------------+
      |    Scheme      |
      |  source code   |
      |                |
      +-------+--------+
              |
              |
             \|/
      +----------------+
      |  High-Level    |
      |  Interpreter   |
      |                |
      +-------+--------+
              |
              |
             \|/

           Output

*To use the interpreter
1. write your Scheme code into a text file 
2. run interpreter.py, passing the file name as a command-line argument
**for example: 
	python3 interpreter.py


__The interpreter supports  arithmetic, logical and equality operators,
 basic math operators (cos, sin, abs, ...) , the length, remainder, 
begin, car, cdr, list operations, if/else statement  display,
 define, define-syntax, syntax_rules and lambda.

Each statement in the source file will be evaluated in turn,
and any printable results will be displayed to standard output.

_Project description_

The program receives a text file, divides it into action blocks.
In order to correctly organize the sequence of operations,
 there is a recursively written function called compile, 
to understand which operation should be performed first.
The function is called through the compile function,
 which performs the next operation of the list and returns a value.
The value returned by the function is placed instead of a sequential list.
Since Nones are generated during the return values of the functions,
 there is a clean function that cleans the current list from unnecessary
 values every time.
The program also uses a few more functions that are used in the 
functions listed above, this was done to have more readable code and 
concise functions.
Then, due to recursion, this operation continues until the end of operations.


