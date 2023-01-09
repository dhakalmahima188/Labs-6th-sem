echo "program for performing KILL operations"
ps
echo "enter the pid of the process"
read pid
kill -9 $pid
#kill -9 is used to kill the process forcefullyS
