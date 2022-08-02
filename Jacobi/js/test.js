let fs = require('fs');
const Matrix =  require('./matrix_class.js')
const my_lib =  require('./main.js')
let check = my_lib.check
let jacobi_method = my_lib.jacobi_method
let write_to_exit = my_lib.write_to_exit


// compare the solutions with the golden file items
function compare(result){
        let golden_string = fs.readFileSync('golden.txt', 'UTF-8')
        if(golden_string != "Has no solution" && result!="Has no solution"){
                let arr = golden_string.split(' ');
                for( let i=0; i<arr.length; i++){
                        if (Math.abs(Number(arr[i])- result[i])>0.0001){
                                fs.writeFile("result.txt", "Test FAILED!\n",() => {})
                        }
                }
                fs.writeFile("result.txt", "Test passed!\n",() => {})
        }else if (golden_string == "Has no solution" && result =="Has no solution"){
                fs.writeFile("result.txt", "Test passed!\n",() => {})
        }else {fs.writeFile("result.txt", "Test FAILED!\n",() => {})}
}

// make a test
function test(){
        let matrix = new Matrix("input.txt")
        let result = jacobi_method(matrix)
	write_to_exit("exit.txt", result)
        compare(result)
}


if(check("input.txt", "result.txt")){
        test()
}


