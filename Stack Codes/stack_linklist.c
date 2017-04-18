#include<stdio.h>

 struct node
{
 int x;
 struct node *next;
}*start=NULL,*end,*temp,*top;

 void push()
{
 printf("enter the data\n");
 top=(struct node*)malloc(sizeof(struct node));
 scanf("%d",&top->x);
 top->next=NULL;
 if(start==NULL)
 {
 start=top;
 end=top;
 }
 else
 {
 end->next=top;
 end=top;
 }
}


void pop()
{
if(start==NULL)
    printf("Stack is already empty.");
else
    {
    end=start;
    while(end->next!=top)
    end=end->next;
    printf("Poped element is :\t %d",top->x);
    top=end;
    end=top->next;
    top->next=NULL;
    free(end);
}

}



void display()
{
 //doubly banao..or..reverse karke print karo..or..end=start karke...
 if(start==NULL)
 {
 printf("kuchh nahi hai idhar..");
 }

 else

 {
  do
 {
  end=start;

   while(end->next!=top)
    end=end->next;
    printf("%d\t",top->x);
    top=end;


 }while(end!=start);
 printf("%d",top->x);
 }

top=start;
while(top->next!=NULL)
    top=top->next;

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
printf("\nDo you want to continue..?  y/n \n");
scanf("%c",&c);
}while((c=='y')||(c=='Y'));

return 0;

}
