#!/bin/bash

#Create a file with several hard links and find a command that will display the names of all hard links.

echo "How many hard links do you want to create?"
read count
touch myhlinks.txt
ls -l
chmod +x myhlinks.txt
for i in $(seq 1 $count); do 
	echo "What do you want your $i hard link name to be?"
	read name
	ln -v myhlinks.txt $name
done
echo "\nMy hash link names are:\n"
ls -li
