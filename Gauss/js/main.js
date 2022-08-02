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

// Implementation Gauss method
// function returns the the results in list
function gauss_method(matrix){
        let res = []
        matrix.triangle()
        if(matrix.is_line_of_zero()==false){
                for( let i=0; i<matrix.get_rows(); i++){
                        res.push(matrix.get_item(i,matrix.get_rows())/matrix.get_item(i,i))
                }
        }
        else {
                res = "Has no silution"
        }
        return res
}

// write the result to the  exit file 
function write_to_exit(filename, result){
        fs.truncate(filename,()=>{})
        fs.appendFile(filename, "System solutions are:\n"+ result+"\n",() => {});
}

module.exports = {
	write_to_exit,
	gauss_method,
	check
}


function run(){
        let matrix = new Matrix("your_input.txt")
        let result = gauss_method(matrix)
        write_to_exit("your_exit.txt", result)
}


if(check("your_input.txt", "your_exit.txt")){
        run()
}

