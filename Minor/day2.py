import random
rand_no=random.randint(1,10)
input_no=-100
while(input_no!=rand_no):
    input_no=int(input("Enter number? "))
    print("Not matcheed")
print(input_no,rand_no,"Matched")


input_no=int(input("Enter number? "))
if input_no>3:
    for i in range (2,input_no//2):
        if(input_no%i==0):
            print("Not prime")
        else:
            print("Prime")
elif input_no==1 or input_no==3 or input_no==5:
    print("Not prime")
    
elif input_no==2 or input_no==3:
    print("Prime")
    
    
# multiplication table
input_no=int(input("Enter number? "))
for i in range(1,11):
    print(input_no,"*",i,"=",input_no*i)


for i in range (1,10):
    for j in range(1,11):
        print(i,"*",j,"=",i*j,end='\n')
    print("")

#fibonacii
#Quadrant
x,y=(input("Enter cordinates? ")).split(' ')
x,y=int(x),int(y)
if x>0 and y>0:
    print("1st quadrant")
elif x<0 and y>0:
    print("2nd quadrant")
elif x<0 and y<0:
    print("3rd quadrant")
elif x>0 and y<0:
    print("4th quadrant")
else:
    print("Origin")

#MyVar camel case
# my_var popet case

def fibonaci(n):
    if n<3:
        return 1
    else:
      return fibonaci(n-1)+fibonaci(n-2)
for i in range(1,5):
    print(fibonaci(i))
    
x=int(input("Enter Number: "))
try:
    y=5/x
    print(y)
except Exception as e:
    print(e)
    
string_value="Mahima is my name"
x=int(input("Enter index: "))
try: 
    print(string_value[x])
except Exception as e:
    print(type(e),e)
