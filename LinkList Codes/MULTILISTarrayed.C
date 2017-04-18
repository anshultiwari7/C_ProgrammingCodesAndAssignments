#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
int x;
struct node *next;
}*temp1,*end1;
struct master
{
int x;
struct node *next;
}s[3];

void create()
{
 char c;
 int i;
 for(i=0;i<=2;i++)
 {
 printf("Enter Data..    ");
 scanf("%d",&s[i].x);
 s[i]->next=NULL;
 printf("Do you want to continue this single link list..?    y/n\t");
 scanf("%c",&c);
 while((c=='y')||(c=='Y'))
  {
  temp1=(struct node*)malloc(sizeof(struct node));
  
  s[i]->next=temp1;
  printf("Enter data..    ");
  temp1->next=NULL;
  scanf("%d",&temp1->x);
  if(start1==NULL)
  {
   temp1=start1;
   end1=start1
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
  }
 }
 

  void print()
  {
  int i;
  for(i=0;i<=2;i++)
  {
  printf("%d",s[i]->x);
  temp1=s[i]->next;
  while(temp1!=NULL)
  {
  printf("%d\t",temp1->x);
  temp1=temp1->next;
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
