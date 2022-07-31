#!/bin/sh

#Write a program that will run every 3 hours on weekdays,
#check the size of system partitions and if it is 80% full or more,
#check the 10 largest files among users.

df -h /boot| sed -n '2p' | awk '{print $5 " " $1 }' | while read output;
do
  echo $output
  usep=$(echo $output | awk '{ print $1}' | cut -d'%' -f1  )
  partition=$(echo $output | awk '{ print $2 }' )
  if [ $usep -ge 80];
  then
    echo "Running out of space \n"
  fi 
done

echo "top 10 largest file/directories: \n"
du -a /home | sort -n -r | head -n 10
echo "\nBye!\n"
