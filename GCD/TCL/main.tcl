proc gcd {a b} {
	if {$b==0} {return $a} else {gcd $b [expr {$a%$b}]}
}

proc readData {filename} {
    set result {}
    set f [open $filename r]
    foreach line [split [read $f] \n] {
        lappend result $line
    }
    return $result
}

proc compare {golden_val gcd_val res_file} {
	if {$golden_val == $gcd_val} {puts $res_file "Test passed!"
	} else {puts $res_file "Test FAILED!"}
}

proc call_gcd {} {
	set my_data [readData "input.txt"]
        set my_golden [readData "golden.txt"]
	set fileId [open exit.txt "w+"]
	set res_file [open result.txt "w+"]
	for {set i 0} {$i < [expr [llength $my_data]-1]} {incr i} {
		set a [lindex $my_data $i 0]
		set b [lindex $my_data $i 1]
		puts $fileId "The GCD of $a and $b is : [ gcd $a $b ]"
		set c [lindex $my_golden $i 0]
		compare $c [gcd $a $b] $res_file
	}

	close $fileId
	close $res_file
}

proc main {} {
	call_gcd
}
main

