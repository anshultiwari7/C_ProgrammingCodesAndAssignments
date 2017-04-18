#include<stdio.h>
#include<conio.h>
 struct node
{int x;
 struct node *next;
};

 struct node *start=NULL,*temp,*end,*z;
 void create()
{
 char e;
 do
 {
 printf("enter the data\n");
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
 fflush(stdin);
 printf("enter more  = y/n \n");
 scanf("%c",&e);
 }while(e=='Y'||e=='y');
 free(temp);
}


 void print()
{
 if(start==NULL)
 {
 printf("kuchh nahi hai idhar..");

 }
 else
 {
  end=start;
  while(end->next!=NULL)
  {
  printf("%d",end->x);
  end=end->next;
  }
  printf("%d",end->x);
 }
}



 void practice()
 {
  int min,i=0;
  temp=start;
  end=start;
  min=temp->x;
  while(temp!=NULL)
  {
  if(min>temp->x)
  min=temp->x;
  temp=temp->next;
  }
  temp=start;
  if(min==start->x)
  {
  start=start->next;
  temp->next=NULL;
  free(temp);
  return 0;
  }
   temp=temp->next;
   while(temp!=NULL)
   {
   if(temp->x==min)
   {
   end->next=(end->next)->next;
   return 0;
   }
   temp=temp->next;
   end=end->next;
   }
   return 0;
 }

/*
void half1st2nd()
{
int n=0,i;
temp=start;
end=start;
do
{
temp=temp->next;
n++;
}while(temp!=NULL);
if(n%2!=0)
{
for(i=1;i<=n/2+1;i++)
end=end->next;
}
else
{
for(i=1;i<=n/2;i++)
end=end->next;
}
temp=start;
for(i=1;i<=n/2;i++)
{
temp->x=temp->x+end->x;
end->x=temp->x-end->x;
temp->x=temp->x-end->x;
temp=temp->next;
end=end->next;
}
}

 void rev()
 {
 z=end=temp=start;
 z=(z->next)->next;
 end=end->next;
 temp->next=NULL;
 end->next=temp;
 while(z!=NULL)
 {
 temp=end;
 end=z;
 z=z->next;
 end->next=temp;
 }
 start=end;
}

void sort()
{
 int n=1,p,i,j;
 end=start;
 while(end->next!=NULL)
 {
 end=end->next;
 n++;
 }
 for(i=0;i<n-1;i++)
{
 z=start;
 end=start->next;
 for(j=0;j<n-i-1;j++)
{ if(z->x>end->x)
 {
 p=z->x;
 z->x=end->x;
 end->x=p;
 }
 z=z->next;
 end=end->next;
}
}
}

 void insertbeg()
{temp=(struct node*)malloc(sizeof(struct node));
 if(start==NULL)
{start=temp;
 temp->next=NULL;
}
 else
{
 temp->next=start;
 start=temp;
}
}



 void insertend()
{temp=(struct node*)malloc(sizeof(struct node));
 if(start==NULL)
 {
 start=temp;
 temp->next=NULL;
 }

 end=start;
 while(end->next!=NULL)
 {
 end=end->next;
 }

 end->next=temp;
 temp->next=NULL;
}


 void insertmid()
{
 int i,pos;
 if(start==NULL)
{
 start=temp;
 temp->next=NULL;
}
 end=start;
 printf("kis positon par enter karna hai batao?");
 scanf("%d",&pos);
 for(i=1;i<=pos-2;i++)
 end=end->next;
 temp->next=end->next;
 end->next=temp;
}



void compress()
{
int n;
end=start;
temp=start;
z=temp->next;
 while(end!=NULL)
 {
 end->x=end->x+(end->next)->x;
 end=(end->next)->next;
 z=temp->next;
 temp->next=end;
 temp=end;
 z->next=NULL;
 free(z);
 }

} */

 void main()
{
 clrscr();
 create();
 print();
 printf("    ");
 practice();
 print();
/*
 half1st2nd();
 inserbeg();
 insertend();
 print();
 insertmid();
 printf("\n");
 compress();*/
 getch();
}