// imports
const fs = require('fs');
let gcd = require('./main.js')

// Checks that the input file is correct
function accuracy_input_file(path){
        fs.writeFile("result.txt", '', () => {})//check if file exists
        if(!fs.existsSync(path)){
                fs.appendFile("result.txt","input file is NOT EXISTS!!\n",() => {})
                return false
        }
        let data = fs.readFileSync(path,'utf-8') // check if file is not empty
        if(data.length === 0){
                fs.appendFile('result.txt','Input file is EMPTY!',()=>{})
                return false
        }
        let array = fs.readFileSync(path, 'UTF-8').split("\n");//if file is numberic
        for(let i = 0; i <array.length-1; i++){
                for(let j=0; j<array[i].length; j++){
                        if (!((array[i][j]>= '0' && array[i][j] <= '9') || array[i][j]===' ' || array[i][j]==='-')){
                                fs.appendFile('result.txt','Input file contains a non-numeric value\b',()=>{})
                                return false
                        }
                }
        }
        return true
}

// compare golden files values and the resulting values of the gcd functions
function compare( a, b, test_count ){
         if(a==b)fs.appendFile("result.txt", "Test "+test_count+" passed!\n",() => {})
         else fs.appendFile("result.txt", "Test "+test_count+" FAILED!\n",() => {})
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
        golden_array = golden_array.map(str => { return Number(str)})

        for(let i = 0; i <array.length-1; i++){
                array[i]= array[i].split(' ').map((item)=>{return +item})
                fs.appendFile("exit.txt", "The GCD of "+array[i][0]+" and "+
array[i][1]+" is "+gcd(array[i][0], array[i][1])+"\n",() => {});
                compare(gcd(array[i][0], array[i][1]),golden_array[i], i+1)
           }
}

// call test
if(accuracy_input_file('input.txt')){
	test()
}

