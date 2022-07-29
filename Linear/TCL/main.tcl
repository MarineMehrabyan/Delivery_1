# Function solves a linear equation and return the root of the equation
proc linear {a b} {
	if {$a == 0 && $b != 0} {return "Has no solution"
	} elseif {$a == 0 && $b == 0 }  {return "The solutions are real numbers"
	} else {return [expr -1.0*$b/$a]}
}
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
# The function compares the values of the linear() function
# with the values of the golden.txt file
# and writes the result to the result.txt file
proc compare {golden_val gcd_val res_file} {
	if {$golden_val=="The solutions are real numbers" && $gcd_val =="The solutions are real numbers"} {
		puts $res_file "Test passed!"
        } elseif {$golden_val=="Has no solution" && $gcd_val =="Has no solution"} {
                puts $res_file "Test passed!"
	} elseif {[expr $golden_val  - $gcd_val]< 0.00001}  {
		puts $res_file "Test passed!"
	} else {puts $res_file "Test FAILED!"}
}

# call the functions and make a test
proc test {} {
	set my_data [readData "input.txt"]
        set my_golden [readData "golden.txt"]
	set fileId [open exit.txt "w+"]
	set res_file [open result.txt "w+"]
	for {set i 0} {$i < [expr [llength $my_data]-1]} {incr i} {
		set a [lindex $my_data $i 0]
		set b [lindex $my_data $i 1]
		set res [linear $a $b]
		puts $fileId " $a X + $b = 0 --->  $res"
		set c [lindex $my_golden $i]
		compare $c $res $res_file
	}
	close $fileId
	close $res_file
}

proc main {} {
	test
}
main
