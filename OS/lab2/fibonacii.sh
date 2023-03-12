echo "Enter number ?"
read n1
a=0
b=1
i=0

while [ $i -lt $n1 ]
do
	c=`expr $a + $b`
	a=$b
	b=$c
	i=`expr $i + 1`
	echo "$c"
done

