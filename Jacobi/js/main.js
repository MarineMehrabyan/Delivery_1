let fs = require('fs');
const Matrix =  require('./matrix_class.js')

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

// Implementation Jacobi's method
// function returns the the results in list
function jacobi_method(matrix){
	let new_val = new Array(matrix.get_rows()).fill(0)
        let prev_val = new Array(matrix.get_rows()).fill(0)
        if(matrix.is_diagonally_dominant() == true){
		let count = 0
		while (true){
			prev_val.push(0)
                	for( let i=0; i<matrix.get_rows(); i++){
                        	prev_val[i] = new_val[i]
				let sum = 0
				for( let j=0; j<matrix.get_rows(); j++){
					if ( i!= j ){
						sum += matrix.get_item(i, j)* prev_val[j]
					}
				}
				prev_val[i] = new_val[i]
				new_val[i] = (matrix.get_item(i,matrix.get_rows())-sum)/matrix.get_item(i,i)
				if (Math.abs(prev_val[i]-new_val[i])<0.0001){
					count ++
				}
				if( count >= matrix.get_rows()){
					return new_val
				}
			}
		}
	}
	else{
		new_val = "Has no solution"
		return new_val
	}
}

// write the result to the  exit file
function write_to_exit(filename, result){
        fs.truncate(filename,()=>{})
        fs.appendFile(filename, "System solutions are:\n"+ result+"\n",() => {});
}


module.exports = {
	write_to_exit,
	jacobi_method,
	check
}


function run(){
        let matrix = new Matrix("your_input.txt")
        let result = jacobi_method(matrix)
        write_to_exit("your_exit.txt", result)
}

if(check("your_input.txt", "your_exit.txt")){
        run()
}

