#include<stdio.h>
 int main()
{
char
str[100];
FILE *fp;
printf("Enter the string");
gets(str);
fp=fopen("file1.dat","w+"); 
while(!feof(fp))
{
fscanf(fp,"%s",str);
}fprintf(fp,"%s",str);
}