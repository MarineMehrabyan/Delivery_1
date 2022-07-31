#!/bin/bash

#Write a program that will occupy some free inods, then write a program that will delete them
echo "How many files do you want to create?"
read count
mkdir some_inods
cd some_inods
#chmod +x some_inods
for i in $(seq 1 $count); do
        echo "What do you want your $i file  name to be?"
        read name
        touch $name
done
echo "\nNew files are rady\n"

