#include<stdio.h>
#include<stdlib.h>
 struct node
{
 int x;
 struct node *next;
};
 struct node *start=NULL,*temp,*end;
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
 {end=start;
  while(end->next!=NULL)
  {
  printf("%d",end->x);
  end=end->next;
  }
  printf("%d",end->x);
 }
}

/*


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

}

 int countrec(struct node *cou,int c)
 {
 if(cou==NULL)
 return c;
 else
 {
 c++;
 cou=cou->next;
 return count(cou,c );
 }
 }


 int maxrec(struct node *max,int m)
 {
 if(max==NULL)
 return m;
 else
 {
 if(m<max->x)
 m=max->x;
 max=max->next;
 return maxrec(max,m);
 }
 }*/

 struct node *revrec(struct node *p,struct node *q,struct node *r)
 {
 if(p==NULL)
 {
 start=q;
 return q;
 }
 else
 {
 r=q;
 q=p;
 p=p->next;
 q->next=r;
 return revrec(p,q,r);
 }
 }


 int main()
{
 struct node *p,*q,*r;
 create();

 p=q=r=start;
 p=(p->next)->next;
 q=q->next;
 r->next=NULL;
 q->next=r;
/* print();
 insertbeg();
 insertend();
 print();
 insertmid();
 printf("\n");
 compress();  */
 print();
 start=revrec(p,q,r);
 print();
 return 0;
 }
