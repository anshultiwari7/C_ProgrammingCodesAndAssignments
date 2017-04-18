#include<stdio.h>
#include<stdlib.h>
struct node
{
int x;
struct node *next;
}*temp1,*end1,*temps;
struct master
{
int x;
struct node *next;
struct master *down;
}*start2=NULL,*temp2,*end2;

void create()
{
 char c;
 do
 {
 temp2=(struct master*)malloc(sizeof(struct master));
 printf("Enter Data..    ");
 scanf("%d",&temp2->x);
 temp2->down=NULL;
 temp2->next=NULL;
 if(start2==NULL)
 {
 start2=temp2;
 end2=temp2;
 }
 else
 {
 end2->down=temp2;
 end2=temp2;
 }
 fflush(stdin);
 printf("Do you want to continue this single link list..?    y/n\t");
 scanf("%c",&c);
 while((c=='y')||(c=='Y'))
  {
  temp1=(struct node*)malloc(sizeof(struct node));
  printf("Enter data..    ");
  temp1->next=NULL;
  scanf("%d",&temp1->x);
  if(end2->next==NULL)
  {
  end1=temp1;
  end2->next=temp1;
  }
  else
  {
  end1->next=temp1;
  end1=temp1;
  }
  fflush(stdin);
  printf("Do you want to continue this single link list..?    y/n\t");
  scanf("%c",&c);
  }
  fflush(stdin);
  printf("Do you want to go for another single link list connected to this list..?    y/n\t");
  scanf("%c",&c);
 }while((c=='y')||(c=='Y'));
}


void sort()
{
 int t;
 for(temp2=start2;temp2!=NULL;temp2=temp2->down)
 {
 for(temp1=temp2->next;temp1!=NULL;temp1=temp1->next)
 for(temps=temp2->next;temps!=NULL;temps=temps->next)
 if((temps->next)->x<temps->x)
 {
 t=(temps->next)->x;
 (temps->next)->x=temps->x; 
 temps->x=t;
 }
 if(temp2->x>(temp2->next)->x)
 {
 t=(temp2->next)->x;
 (temps2->next)->x=temp2->x; 
 temp2->x=t;
 }
 }
}



 void print()
 {
  temp2=start2;
  if(temp2==NULL)
  printf("Here is nothing..create one..  \n");
  else
  while(temp2!=NULL)
  {
  temp1=temp2->next;
  printf("%d\t",temp2->x);
  while(temp1!=NULL)
  {
  printf("%d\t",temp1->x);
  temp1=temp1->next;
  }
  temp2=temp2->down;
  printf("\n");
  }
 }


 void main()
 {
 create();
 print();
 sort();
 print();
 printf("\n      THANK YOU    ");
 }
