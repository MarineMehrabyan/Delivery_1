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
	
	triangle(){
		let b = 0
		for( let j =0; j<this.rows; j++){
			for( let i =0; i<this.rows; i++){
				if ( i!= j ){
					b = this.matrix[i][j]/this.matrix[j][j]
					for(let k=0; k<this.rows+1; k++){
						this.matrix[i][k]=this.matrix[i][k]-b*this.matrix[j][k]
					}
				}
			}
		}
	}


	is_line_of_zero(){
		for( let i =0; i<this.rows; i++){
			let b=true
			for( let j =0; j<this.rows+1; j++){
				if(this.matrix[i][j] !=0){b= false}
			}
			if(b==false){return false}
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
