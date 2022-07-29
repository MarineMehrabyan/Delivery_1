let fs = require('fs');

// solve linear equation and return the roots
function linear(a, b){
	if (a == 0 && b != 0)return "Has no solution"
	else if (a == 0 && b==0) return "The solutions are real numbers";
	else return  -b/a
}

// verifying that the input file is correct.
// ___must not be empty
// ___must exist such a file
// ___must contains only numeric value
function accuracy_of_the_input_file(input_path, exit_path){
        fs.writeFile(exit_path, '', () => {})
        if(!fs.existsSync(input_path)){
                fs.appendFile(exit_path,"input file is NOT EXISTS!!\n",() => {})
                return false
        }
        let data = fs.readFileSync(input_path,'utf-8')
        if(data.length === 0){
                fs.appendFile(exit_path,'Input file is EMPTY!',()=>{})
                return false
        }
        let array = fs.readFileSync(input_path, 'UTF-8').split("\n");
        for(let i = 0; i <array.length-1; i++){
                for(let j=0; j<array[i].length; j++){
                        if (!((array[i][j]>= '0' && array[i][j] <= '9') || array[i][j]===' ' || array[i][j]==='-')){
				fs.appendFile(exit_path,'Input file contains a non-numeric value\n',()=>{})
                                return false
			}
                }
        }
        return true
}
module.exports = accuracy_of_the_input_file

// Creates an array of numbers from the input file,
// call the gcd function on them,
// then writes the result to the result.txt file
function run(){
        fs.writeFile("your_exit.txt", '', () => {})
        let array = fs.readFileSync('write_your_input.txt', 'UTF-8').split("\n");
        
	for(let i = 0; i <array.length-1; i++){
                array[i]= array[i].split(' ').map((item)=>{return +item})
		fs.appendFile("your_exit.txt", "The set of solutions of the "+array[i][0]+"X + "+
			array[i][1]+" = 0  is: "+linear(array[i][0], array[i][1])+"\n",() => {});
        }  
}

// call run
if(accuracy_of_the_input_file('write_your_input.txt', "your_exit.txt")){
        run()
}

