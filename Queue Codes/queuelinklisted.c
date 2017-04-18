#include<stdio.h>

struct node
{
 int x;
 struct node *next;
}*temp,*rear=NULL,*front=NULL;


void insert()
{
 char ch;
 do
 {
   temp=(struct node*)malloc(sizeof(struct node));
   printf("\n\nEnter element to be insterted : ");
   scanf("%d",&temp->x);
   temp->next=NULL;
     if(rear==NULL)
     {
     rear=temp;
     front=temp;
     }
     else
     {
     front->next=temp;
     front=temp;
     }
   fflush(stdin);
   printf("\nDo you want to continue Insertion?  Y/N : ");
   ch=getch();
 }while((ch=='y')||(ch=='Y'));
}


void delete()
{
 char ch;
 do
 {
  if(rear==NULL)
  printf("Queue is empty");
  else
  {
  printf("\n\nDeleted element is : %d\n",rear->x);
  rear=rear->next;
  }
 fflush(stdin);
 printf("Do you want to continue Deletion?  Y/N : ");
 ch=getch();
 }while((ch=='y')||(ch=='Y'));
}


void display()
{
 if(rear==NULL)
 printf("Queue is empty.\n");
 else
 {
 temp=rear;
 printf("Entered Queue is : ");
   while(temp!=NULL)
   {
   printf("%d\t",temp->x);
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
