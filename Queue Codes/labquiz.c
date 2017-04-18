#include<stdio.h>

int x,a[10],max=9,min=0,top1=-1,top2=10;
void push1()
{
if(top1==max || top2==top1)
printf("Stack 1st is full.\n");
else
{
printf("Enter value :  ");
top1++;
scanf("%d",&a[top1]);
}
}

void push2()
{
if(top1==min || top2==top1)
printf("Stack 2nd is full.\n");
else
{
printf("Enter value :  ");
top2--;
scanf("%d",&a[top2]);
}
}

void delete1()
{
if(top1==-1)
printf("Stack 1st is empty");
else
{
printf("Deleted element is :  %d",a[top1]);
top1--;
}
}




void delete2()
{
if(top2==10)
printf("Stack 2nd is empty");
else
{
printf("Deleted element is :  %d",a[top2]);
top2++;
}
}


void display1()
{
x=top1;
if(top1==-1)
printf("Stack 1st underflow.\n");
else
{
printf("Stack 1 :  ");
while(x>-1)
{
printf("%d\t",a[x]);
x--;
}
}
}


void display2()
{
x=top2;
if(top2==10)
printf("Stack 2nd underflow.\n");
else
{
printf("Stack 2 :  ");
while(x<10)
{
printf("%d\t",a[x]);
x++;
}
}
}






int main()
{
char ch;
int p;
do
{
printf("\nEnter choice. \n1.Push 1st\n2.Push 2nd\n3.Delete 1st\n4.Delete 2nd\n5.Display 1st\n6.Display 2nd\n \n");
scanf("%d",&p);
switch (p)
{
case 1:
push1();
break;
case 2:
push2();
break;
case 3:
delete1();
break;
case 4:
delete2();
break;
case 5:
display1();
break;
case 6:
display2();
break;
default :
printf("Wrong choice entered. ");
break;
}
fflush(stdin);
printf("Continue y/n ?  ");
ch=getch();
}while((ch=='y') || (ch=='Y'));
return 0;
}
