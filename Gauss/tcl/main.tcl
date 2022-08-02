# Reads  numbers from the input.txt file
# and return the array
proc readData {filename} {
    set result {}
    set f [open $filename r]
    foreach line [split [read $f] \n] {
        lappend result $line
    }
    return $result
}

# square matrix is called upper triangular if all
# the entries below the main diagonal are zero.
proc triangle { data } { 
	set b 0 
	for {set j 0} {$j < [expr [llength $data]-1]} {incr j} {
		for {set i 0} {$i < [expr [llength $data]-1]} {incr i} {
			if { $i != $j } {
				set b [expr [lindex $data $i $j]*1.0/[lindex $data $j $j]]
				for {set k 0} {$k < [expr [llength $data]]} {incr k} {
					lset data $i $k [expr [lindex $data $i $k]-1.0*$b*[lindex $data $j $k]]
				}
			}
		}
	}
	return $data
}

# if upper triangular matrix  has a line of zero => the system has no solution 
proc is_line_of_zero { matrix } {
	for {set i 0} {$i < [expr [llength $matrix]-1]} {incr i} {
		if {[lindex $matrix $i $i] == 0 } {
		       	return true
	       	}
	}	
	return false
}

# Implementation of the Gauss algorithm
# Function returns a list containing the solution sets
proc gauss_method { matrix } {
	set res [triangle $matrix]
	set len [expr [llength $res]-1]	
	set solution {} 
        if { [is_line_of_zero $res] == false  } {
                for {set i 0} {$i < [expr [llength $res]-1]} {incr i} {
			lappend solutions [expr 1.0*[lindex $res $i $len]/[lindex $res $i $i]]
		}
	} else { lappend solutions "Has no solution" }
	return $solutions
}

# The function compares the values of the linear() function
# with the values of the golden.txt file
# and writes the result to the result.txt file
proc compare {golden_val gauss_val res_file } {
	set b 1
        if { $golden_val == "Solutions are real numbers" || $golden_val == "Has no solution" } {
                if { $golden_val == $gauss_val } { puts $res_file "Test passed!" }
	} else {    
		for {set i 0} {$i < [expr [llength $gauss_val]-1]} {incr i} {
			if { [expr [lindex $gauss_val 0 $i] - [lindex $golden_val 0 $i]] > 0.001} {
				set b 0
			}
		}
		if { $b == 0 } { puts $res_file "Test FAILED!"
		} else { puts $res_file "Test passed!"}
	}
}

# call the functions and make a test
proc test {} {
       	set my_data [readData "input.txt"]
	set result [ gauss_method $my_data ]
	set my_golden [readData "golden.txt"]
	set res_file [open "result.txt" "w+"]
	set fileId [open exit.txt "w+"]
	puts $fileId "System solutions are:\n$result"
	compare $my_golden $result $res_file 	
}

# call test
test 
     
