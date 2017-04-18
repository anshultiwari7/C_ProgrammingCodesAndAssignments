#include<stdio.h>

char a[20],sym;
char stack[20],postfix[20];
int top=-1;

void push(char sym)
{
top++;
stack[top]=sym;
}

char pop()
{
if(empty())
{
printf("Stack underflow.");
exit(1);
}
return stack[top--];
}



void convert()
{
char ch;
int i=0,p=0;
while(a[i]!='\0')
{
 sym=a[i];
 switch (sym)
 {
 case '(':
 push(sym);
 break;
 case ')':
 while((ch=pop())!='(')
 postfix[p++]=ch;
 break;
 case '*':
 case '/':
 case '+':
 case '-':
 while((pr(sym)<=pr(stack[top])) && !empty())
 postfix[p++]=pop();
 push(sym);
 break;
 default :
 postfix[p++]=sym;
 break;
}
i++;
}
while(!empty())
postfix[p++]=pop();
postfix[p]='\0';
}

int empty()
{
if(top==-1)
    return 1;
return 0;
}


int pr()
{
switch (sym)
{
case '*':
case '/':
return 2;
case '+':
case '-':
return 1;
}
}

int main()
{
printf("Enter the infix expression : ");
gets(a);
convert();
printf("%s",postfix);
return 0;
}
