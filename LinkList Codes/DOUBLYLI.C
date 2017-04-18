#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

 struct node
{
 int x;
 struct node *next,*prev;
};

 struct node *temp,*end,*start=NULL;


 void create()
{
 temp=(struct node*)malloc(sizeof(struct node));
 printf("data enter kariye   ");
 scanf("%d",&temp->x);
 temp->next=NULL;
 if(start==NULL)
 {
 start=temp;
 end=temp;
 temp->prev=NULL;
 }
 else
 {
 end->next=temp;
 temp->prev=end;
 end=temp;
 }
 free(temp);
}


 void insertbeg()
{
 temp=(struct node*)malloc(sizeof(struct node));
 print("data enter kariye    ");
 scanf("%d",&temp->x);
 if(start==NULL)
 {
 start=temp;
 temp->prev=NULL;
 temp->next=NULL;
 }
 else
 {
 temp->prev=NULL;
 temp->next=start;
 start->prev=temp;
 start=temp;
 }
}
 insertend()
 {
 temp=(struct node*)malloc(sizeof(struct node));
 print("data enter kariye    ");
 scanf("%d",&temp->x);
 temp->next=NULL;

 if(start==NULL)
 {
 start=temp;
 temp->prev=NULL;
 }
 end=start;
 while(end->next!=NULL)
 {
 end=end->next;
 }
 end->next=temp;
 temp->prev=end;
 end=temp;
}


 void main()
{
 clrscr();
 create();
 insertbeg();
 insertend();
 insertmid();
temp=start;
while(temp!=NULL)
{
printf("%d",temp->x);
temp=temp->next;
}
 getch();
}