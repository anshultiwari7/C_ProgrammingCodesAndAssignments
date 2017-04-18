#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct node
{
 int x;
 struct node *next;
}
 struct node *start=NULL,*end,*temp;

int create()
{
 temp=(struct node*)malloc(sizeof(struct node));
 scanf("%d",&temp->x);
 temp->next=NULL;
 if(start==NULL)
{
 start=temp;
 end=temp;
}
else
{
 end->next=temp;
 end=temp;
}
 free(temp);
 return 0;
}

int insertbeg()
{
 temp=(struct node*)malloc(sizeof(struct node));
 scanf("%d",&temp->x);
 if(start==NULL)
{
 start=temp;
 temp->next=NULL;
}
else
{
 temp->next=start;
 start=temp;
}
 free(temp);
 return 0;
}

int insertmid()
{
 int a;
 temp=(struct node*)malloc(sizeof(struct node));
 scanf("%d",&temp->x);
 printf("Enter the number at which you want to place your node in the list");
 scanf("%d",&a);
 if(a==1)
 insertbeg();
 exit(0);
 a=a-2;
 end=start;
 if(start==NULL)
{
 printf("Your list was empty,this became your first node\n");
 start=temp;
 temp->next=NULL;
}

else

 while(a)
{
 end=end->next;
 a--;
}
 temp->next=end->next;
 end->next=temp;
 free(temp);
 return 0;
}

int print()
{
 if(start==NULL)
 printf("List is empty");
 end=start;
 for(;end->next=NULL;end=end->next)
 printf("%d",end->x);
 printf("%d",end->x);
 return 0;
}

int delete()
{
 if(start==NULL)
 printf("List is already empty,create to kar");
 int a;
 printf("Enter which numbered node you want to delete..(like 1 or 2 or..)\n");
 scanf("%d\n",&a);
 if(a==1)
 deletebeg();
 exit(0);
 a=a-2;
 while(a)
 {
 end=end->next;
 a--;
 }
 temp=end->next;
 end->next=temp->next;
 temp->next=NULL;
 free(temp); 
}
int main()
{
 printf("Enter your choice number..\n1.Create\n2.Insert in beginning\n3.Insert in the middle\n4.Insert at the end\n5.Print\n6.Delete\n");
 char c;
 scanf("%c",&c);
switch(c)
 case 1:
 create();
 case 2:
 insertbeg();
 case 3:
 insertmid();
 case 4:
 insertend();
 case 5:
 print();
 case 6:
 delete();
 default:
 printf("Kuchh karo na");
}
return 0;
}