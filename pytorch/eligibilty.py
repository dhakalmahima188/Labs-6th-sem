# Description: This program is used to check the eligibility of the student based on the marks obtained in the subjects
import pandas as pd
df = pd.read_csv('data1.csv')
row_sum = df.iloc[0:].sum(axis=1,numeric_only=True)
z=list()

# print(row_sum) 
for i in range (0,4):
    if(row_sum[i]>0.7*7):
       z.append('eligible')  
    #    print("Eligible")        
    else:
        z.append('not eligible')       
        # print("Not Eligible")
df['eligibility'] = z
# print(df)
# print(z)
name=input("Enter the name of the student: ")
for i in range (0,4):
    if(name==df.iloc[i,0]):
        print(df['eligibility'][i])
          