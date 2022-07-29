let fs = require('fs');
let accuracy_of_the_input_file = require('./main.js')

// solve linear equation and return the roots
function linear(a, b){
        if (a == 0 && b != 0)return "Has no solution"
        else if (a == 0 && b==0) return "The solutions are real numbers";
        else return  -b/a
}

//compare golden files values( if it is not number) and the resulting values of the gcd functions 
function compare_string( a, b, test_count ){
         if(a==b)fs.appendFile("result.txt", "Test "+test_count+" passed!\n",() => {})
         else fs.appendFile("result.txt", "Test "+test_count+" FAILED!\n",() => {})
}

//compare golden files values( if it is number) and the resulting values of the gcd functions 
function compare_number(a,b,test_count){
	if(Math.abs(a-Number(b))<0.0001)
		fs.appendFile("result.txt", "Test "+test_count+" passed!\n",() => {})
        else 
		fs.appendFile("result.txt", "Test "+test_count+" FAILED!\n",() => {})
}

// Creates an array of numbers from the input file,
// call the gcd function on them,
// sends it to compare with the golden file
// then writes the result to the result.txt file
function test(){
        fs.writeFile("exit.txt", '', () => {})
        fs.writeFile("result.txt", '', () => {})
        let array = fs.readFileSync('input.txt', 'UTF-8').split("\n");
        let golden_array = fs.readFileSync('golden.txt', 'UTF-8').split("\n");
	
	for(let i = 0; i <array.length-1; i++){
                array[i]= array[i].split(' ').map((item)=>{return +item})
		fs.appendFile("exit.txt", "The set of solutions of the "+array[i][0]+"X + "+
			array[i][1]+" = 0  is: "+linear(array[i][0], array[i][1])+"\n",() => {});
		if (isNaN(+golden_array[i])){
			console.log(golden_array[i])
			compare_string(linear(array[i][0], array[i][1]),golden_array[i], i+1)
                }
		else compare_number(linear(array[i][0], array[i][1]),golden_array[i], i+1)
	}
}

//console.log(accuracy_of_the_input_file("input.txt", "result.txt"))
// call test
if(accuracy_of_the_input_file("input.txt", "result.txt")){
	test()
}
