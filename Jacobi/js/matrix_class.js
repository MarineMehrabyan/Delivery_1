let fs = require('fs');

class Matrix {
	constructor(input_file){
		this.matrix = []
		this.rows = 0;
                let array = fs.readFileSync('input.txt', 'UTF-8').split("\n");
                for(let i = 0; i <array.length-1; i++){
                        array[i]= array[i].split(' ').map((item)=>{return +item})
			this.matrix.push(array[i])
			this.rows++
		}
	}
	
	is_diagonally_dominant(){
		let sum = 0
		for( let i = 0; i<this.rows; i++){
			sum = 0
			for( let  j=0; j<this.rows; j++){
				if ( i!= j ){
					sum += Math.abs(this.matrix[i][j])
				}
			}
			if (Math.abs(this.matrix[i][i]) <= sum){
				return false
			}
		}
		return true
	}


	get_item(i,j){
		return this.matrix[i][j]
        }

	get_rows(){
		return this.rows
	}
}

module.exports = Matrix
