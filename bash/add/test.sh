#!/bin/bash
 
filename="/root/homeworks/file.txt"
x=0
while read line
do
	x=$(($x+$line))
 
    #echo "$line"
done < $filename
echo $x
