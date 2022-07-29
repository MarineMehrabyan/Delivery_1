let fs = require('fs');

// verifying that the input file is correct.
// ___must not be empty
// ___must exist such a file
// ___must contains only numeric value
function check(input_path, exit_path){
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
//module.exports = check


// solve quadratic equation and return the roots
function quadratic(a, b, c){
	let discriminant = b * b - 4 * a * c
	let sqrt_val = Math.sqrt(discriminant)
	res = []
   	if (a != 0){
        	if (discriminant > 0){
            		res.push((-b - sqrt_val) / (2 * a))
            		res.push((-b +  sqrt_val) / (2 * a))
		}
		else if (discriminant === 0)res.push(-b / (2 * a))
		else res.push('Has no solution')
		
	}
	else if (a == 0 && b != 0)res.push("Has no solution")
	else if (a == 0 && b==0) res.push("The solutions are real numbers");
	else return  res.push(-b/a)

	return res
}
module.exports = { 
	check,
	quadratic
} 



// Creates an array of numbers from the input file,
// call the gcd function on them,
// then writes the result to the result.txt file
function run(){
        fs.writeFile("your_exit.txt", '', () => {})
        let array = fs.readFileSync('write_your_input.txt', 'UTF-8').split("\n");
	for(let i = 0; i <array.length-1; i++){
                array[i]= array[i].split(' ').map((item)=>{return +item})
		fs.appendFile("your_exit.txt", array[i][0]+"X^2 + "+array[i][1]+"X + "+array[i][2]+
			"  = 0  ---->  "+quadratic(array[i][0], array[i][1], array[i][2])+"\n",() => {});
        }
}

// call run
if(check('write_your_input.txt', "your_exit.txt")){
        run()
}
