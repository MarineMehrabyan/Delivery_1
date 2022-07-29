# Function solves a quadratic  equation and return the root of the equation
proc quadratic {a b c} {
	set discriminant [expr ($b * $b) - (4 * $a * $c)]
	if { $a!=0 } {
		if { $discriminant > 0} {
			set t1 [expr (-$b - sqrt($discriminant))/(2*$a)]
			set t2 [expr (-$b + sqrt($discriminant))/(2*$a)]
			return [list $t1 $t2]
		} elseif { $discriminant == 0 }  {return [expr -$b/2*$a]
		} elseif { $discriminant < 0 } { return "Has no solution"
	} } elseif { $a==0 && $b!=0 } { return "Has no solution"
	} elseif { $a==0 && $b==0 } { return  "The solutions are real numbers"
	} else { return [expr -$b/$a] }
	
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
proc compare {golden_val val res_file size} {
	if { $golden_val == "Solutions are real numbers" || $golden_val =="Has no solution" } {
		if { $golden_val == $val } { puts $res_file "Test passed!" }
	} elseif { $size == 1 } {
		if { [expr [lindex $golden_val 0] - [lindex $val 0]]< 0.001} {puts $res_file "Test passed!"} 
	} elseif { $size == 2 } {
		if { [expr [lindex $golden_val 0 ] - [lindex $val 0]]< 0.001 && [expr [lindex $golden_val 1] - [lindex $val 1]]< 0.001 } {
			puts $res_file "Test passed!"
		} 
	} else { puts $res_file "Test FAILED!"}
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
		set c [lindex $my_data $i 2]
		set res [quadratic $a $b $c]
		puts $fileId " $a X^2 + $b X + $c = 0 --->  $res"
		set size [llength $res]
		compare [lindex $my_golden $i]  $res  $res_file $size
	}
	close $fileId
	close $res_file
}

proc main {} {
	test
}
main
