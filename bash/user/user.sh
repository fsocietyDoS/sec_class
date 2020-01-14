echo "calculate the users"
awk -F: '{ print $7}' /etc/passwd >> test.txt
grep $1 test.txt
grep -c $1 test.txt
