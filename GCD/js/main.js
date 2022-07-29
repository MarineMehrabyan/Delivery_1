// imports
const fs = require('fs');

// Returns the GCD of two numbers
function gcd(num1,num2){
        if(num2===0) return num1
        else return gcd(num2,num1%num2)
}
module.exports = gcd

// Checks that the input file is correct
function accuracy_of_the_input_file(path){
        fs.writeFile("your_exit.txt", '', () => {})
        if(!fs.existsSync(path)){
                fs.appendFile("your_exit.txt","input file is NOT EXISTS!!\n",() => {})
                return false
        }
        let data = fs.readFileSync(path,'utf-8')
        if(data.length === 0){
                fs.appendFile("your_exit.txt",'Input file is EMPTY!',()=>{})
                return false
        }
        let array = fs.readFileSync(path, 'UTF-8').split("\n");
        for(let i = 0; i <array.length-1; i++){
                for(let j=0; j<array[i].length; j++){
                        if (!((array[i][j]>= '0' && array[i][j] <= '9') || array[i][j]===' ' || array[i][j]==='-')){
				fs.appendFile('your_exit.txt','Input file contains a non-numeric value\n',()=>{})
                                return false
			}
                }
        }
        return true
}


// Creates an array of numbers from the input file,
// call the gcd function on them,
// then writes the result to the result.txt file
function run(){
        fs.writeFile("your_exit.txt", '', () => {})
        let array = fs.readFileSync('write_your_input.txt', 'UTF-8').split("\n");
        for(let i = 0; i <array.length-1; i++){
                array[i]= array[i].split(' ').map((item)=>{return +item})
                fs.appendFile("your_exit.txt", "The GCD of "+array[i][0]+" and "+
array[i][1]+" is "+gcd(array[i][0], array[i][1])+"\n",() => {});
           }
}


// call run
if(accuracy_of_the_input_file('write_your_input.txt')){
        run()
}
