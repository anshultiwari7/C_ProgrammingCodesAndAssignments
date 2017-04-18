#include<stdio.h>
int stack[10],top=-1,max=9;
int push()
{
int x;
if(top==max)
printf("Stack is already full.");
else
printf("Enter element to push in the stack.\n");
scanf("%d",&x);
top++;
stack[top]=x;
return 0;
}


int pop()
{
if(top==-1)
printf("Stack is already empty.\n");
else
printf("The poped element is %d  ",stack[top]);
top--;
return 0;
}


int display()
{
int i=0;
while(top>=0)
{
printf("%d\t",stack[top]);
top--;
}
return 0;
}

int main()
{
char c;
int n;


do
{
printf("Choose below -:\n1.Push.\n2.Pop.\n3.Display.\n");
scanf("%d",&n);
switch(n)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
}
fflush(stdin);
printf("\nDo you want to continue..?  \n");
scanf("%c",&c);
}while((c=='y')||(c=='Y'));
return 0;
}
