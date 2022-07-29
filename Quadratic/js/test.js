let fs = require('fs');
const my_lib =  require('./main.js')
let check = my_lib.check
let quadratic = my_lib.quadratic

//compare golden files values( if it is not number) and the resulting values of the gcd functions 
function compare_string( a, b, test_count ){
	if(a==b)fs.appendFile("result.txt", "Test "+test_count+" passed!\n",() => {})
        else fs.appendFile("result.txt", "Test "+test_count+" FAILED!\n",() => {})
}

//compare golden files values( if thre is two number) and the resulting values of the gcd functions 
function compare_two_number(res,arr,test_count){
	if(Math.abs(Number(res[0])-Number(arr[0]))<0.0001 && 
			Math.abs(Number(res[1])-Number(arr[1]))<0.0001)
		fs.appendFile("result.txt", "Test "+test_count+" passed!\n",() => {})
        else 
		fs.appendFile("result.txt", "Test "+test_count+" FAILED!\n",() => {})
}

//compare golden files values( if there  is 1 number) and the resulting values of the gcd functions 
function compare_one_number(a,b,test_count){
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
		let val = quadratic(array[i][0], array[i][1], array[i][2])
		fs.appendFile("exit.txt", array[i][0]+"X^2 + "+array[i][1]+"X + "+array[i][2]+
                        "  = 0  ---->  "+val+"\n",() => {});
		const arr = golden_array[i].split(' ');
  		let length = arr.filter(word => word !== '').length;
		if(length === 2)compare_two_number(res,arr, i+1)
		else if (length == 1)compare_one_number(res[0],arr[0],i+1)
		else compare_string(val,golden_array[i] , i+1)
	}
}

// call test
if(check("input.txt", "result.txt")){
	test()
}
