#include<stdio.h>

struct node
{
 int pr;
 int x;
 struct node *next;
}*temp,*rear=NULL,*front=NULL,*temp2=NULL,*temp3=NULL;


void insert()
{
 char ch;
 do
 {
   temp=(struct node*)malloc(sizeof(struct node));
   printf("\n\nEnter priority and element to be insterted : ");
   scanf("%d%d",&temp->pr,&temp->x);
   temp->next=NULL;
     if(rear==NULL)
     {
     rear=temp;
     front=temp;
     temp2=front->next;
     temp3=front;
     }
     else
     {
     temp2=front->next;
     temp3=front;
     priority();
     if(temp->next==NULL)
     {
     rear->next=temp;
     rear=temp;
     }
     }
   fflush(stdin);
   printf("\nDo you want to continue Insertion?  Y/N : ");
   ch=getch();
 }while((ch=='y')||(ch=='Y'));
}


void delete()
{
 temp=front->next;
 temp3=front;
 char ch;
 int k;
 do
 {
  if(rear==NULL)
  printf("Queue is empty");
  else
  {
  printf("Enter the priority of the element which you want to delete :  ");
  scanf("%d",&k);
  if(front->pr==k)
  {
  front=front->next;
  temp3->next=NULL;
  temp3=front;
  }
  else
  while(temp!=NULL)
  {if(temp->pr==k)
  {
  temp3->next=temp->next;
  printf("Deleted element is :  %d",temp->x);
  temp->next=NULL;
  }
  temp=temp->next;
  }
  }
 fflush(stdin);
 printf("\nDo you want to continue Deletion?  Y/N : ");
 ch=getch();
 }while((ch=='y')||(ch=='Y'));
}


int priority()
{
if(temp->pr<front->pr)
{
    temp->next=front;
    front=temp;
    return;
}

else

if(temp->pr==front->pr)
{
temp->next=front->next;
front->next=temp;
}

else

while(temp2!=NULL)
{

if(temp2->pr==temp->pr)
{
    temp->next=temp2->next;
    temp2->next=temp;
    return;
}
else
    if(temp->pr<temp2->pr)
{
    temp3->next=temp;
    temp->next=temp2;
    return;
}
temp2=temp->next;
temp3=temp3->next;
}
return;
}





void display()
{
 if(rear==NULL)
 printf("Queue is empty.\n");
 else
 {
 temp=front;
 printf("Entered Queue is : ");
   while(temp!=NULL)
   {
   printf("%d : %d     ",temp->pr,temp->x);
   temp=temp->next;
   }
 }
}



int main()
{
 char ch;
 int p;
  do
  {
   printf("\n\nEnter you choice below :-\n1.Insert.\n2.Delete.\n3.Display.\n\n");
   scanf("%d",&p);
    switch (p)
    {
    case 1:
    insert();
    break;
    case 2:
    delete();
    break;
    case 3:
    display();
    break;
    default:
    printf("Wrong Choice Entered");
    break;
    }
  fflush(stdin);
  printf("\n\nDo you want to do any more Operetion?  Y/N : ");
  ch=getch();
 }while((ch=='y')||(ch=='Y'));
 return 0;
}
