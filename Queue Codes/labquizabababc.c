#include<stdio.h>
char a[50];

void validity()
{
int i=0;
while(a[i]!='\0')
{
if(a[i]<='c' && a[i]>='a')
{
if(a[i]=='a' && a[i+1]!='b')
{
printf("Invalid1.");
return;
}
else
if(a[i]=='c' && a[i+1]!='b')
{
printf("Invalid2.");
return;
}
}
else
{
printf("Invalid3.");
return;
}
i++;
}
printf("Valid.");
return;
}


int main()
{
printf("Enter a string : ");
gets(a);
validity();
return 0;
}
