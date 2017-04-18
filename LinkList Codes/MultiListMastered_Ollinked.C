#include<stdio.h>
#include<malloc.h>

struct node
{
int x;
struct node *next,*down;
}*start=NULL,*temp,*end1,*end2,*end3;


void create()
{
char c;
do
{
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter data..    ");
scanf("%d",&temp->x);
temp->next=NULL;
temp->down=NULL;
if(start==NULL)
 {
  start=temp;
  end1=temp;
  end2=temp;
  fflush(stdin);
  printf("Contine this row..??  y/n    ");
  scanf("%c",&c);
  while((c=='y')||(c=='Y'))
  {
   temp=(struct node*)malloc(sizeof(struct node));
   printf("Enter data..    ");
   scanf("%d",&temp->x);
   temp->next=NULL;
   temp->down=NULL;
   end1->next=temp;
   end1=temp;
   fflush(stdin);
   printf("do u want to enter more");
   scanf("%c",&c);
  }
 }
 else
 {
 end3=end2;
 end2->down=temp;
 end2=temp;
 fflush(stdin);
 end1=temp;
 printf("Continue this row..??  y/n    ");
 scanf("%c",&c);
 while((c=='y')||(c=='Y'))
  {
  temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter data..    ");
  scanf("%d",&temp->x);
  temp->next=NULL;
  temp->down=NULL;
  end1->next=temp;
  end1=temp;
  end3=end3->next;
  if(end3!=NULL)
   {
   end3->down=temp;
   }
    fflush(stdin);
  printf("do u want to enter more   ");
  scanf("%c",&c);
  }
 }
  fflush(stdin);
printf("Go further for another single link list connected to the last one..??  y/n    ");
scanf("%c",&c);
}while((c=='y')||(c=='Y'));

}



void print()
{
temp=start;
if(start==NULL)
printf("Nothing is here..create one...  ");
while(temp!=NULL)
 {
 printf("%d\t",temp->x);
 end1=temp->next;
 while(end1!=NULL)
 {

 printf("%d\t",end1->x);
 end1=end1->next;
 }
 printf("\n");
 temp=temp->down;
 }
}

int main()
{

create();
print();
return 0;
}
