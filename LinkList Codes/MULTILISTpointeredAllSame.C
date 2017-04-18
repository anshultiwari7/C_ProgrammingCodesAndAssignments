#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct master
{
int x;
struct master *next;
struct master *down;
}*start=NULL,*temp,*end;

void create()
{
 char c;
 do
 {
 temp=(struct master*)malloc(sizeof(struct master));
 printf("Enter Data..    ");
 scanf("%d",&temp->x);
 temp->down=NULL;
 temp->next=NULL;
 if(start==NULL)
 {
 start=temp;
 end=temp;
 }
 else
 {
 printf("Do you want continue this row further..?? y/n    ");
 scanf("%c",&c);
 while((c=='y')||(c=='Y'))
 {
 temp=end->next;
 end=temp;
 }
 }
 else
 {
 printf("Do you want to go for another row..?? y/n        ");
 scanf("%c",&c);
 while((c=='y')||(c=='Y'))
 {
 temp=end->down;
 end=temp;
 }
 }
}






 void print()
 {
  temp=start;
  if(temp==NULL)
  printf("Here is nothing..create one..  \n");
  else
  {
  while(temp!=NULL)
  {
  while(temp!=NULL)
  {
  printf("%d\t",temp->x); 
  temp=temp->next;
  }
  end=end->down;
  temp=end;
  }
  }
 }





 int delet()
 {  //1
 int i=1,n;
 printf("Enter the node number you want to delete..   ");
 scanf("%d",&n);
 if(start2==NULL)
 {           //2
 printf("Empty already...!  ");
 }              //3
 else
 {                 //4
 while(temp2!=NULL)
 {                    //5
 end1=temp1=temp2->next;
 if(i==n)
 {                       //6
 temp2->x=temp2->x+temp1->x;
 temp1->x=temp2->x-temp1->x;
 temp2->x=temp2->x-temp1->x;
 temp2->next=temp1->next;
 temp1->next=NULL;
 free(temp1);
 return 0;
 }                       //7
 else
 if(temp1!=NULL)
 {                             //8
 if(++i==n)
 {                                //9
 temp2->next=temp1->next;
 temp1->next=NULL;
 free(temp1);
 }                                   //10
 }                                       //11
 else
 while(temp1!=NULL)
 {                        //12
 if(++i==n)
 {                            //13
 temp1=temp1->next;
 end1->next=temp1->next;
 temp1->next=NULL;
 free(temp1);
 return 0;
 }                              //14
 temp1=temp1->next;
 }                                //15
 temp2=temp2->down;
 }
 }
 return 0;                                  //16
 }                                   //17


 void main()
 {
 clrscr();
 create();
 print();
 delet();
 print();
 printf("\n      THANK YOU    ");
 getch();
 }
