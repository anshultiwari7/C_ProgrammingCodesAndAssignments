#include<stdio.h>

int p;

struct node
{
int x;
struct node *next;

}*temp2;




struct master
{
int pr;
struct node *next,*rear;
struct master *down;
}*start,*temp1,*temp3=NULL,*temp4=NULL;


void create()
{
temp1=(struct master*)malloc(sizeof(struct master));
temp1->down=NULL;
temp1->next=NULL;
temp1->pr=p;
temp2=(struct node*)malloc(sizeof(struct node));
temp2->next=NULL;
printf("Enter value :  ");
scanf("%d",&temp2->x);
temp1->rear=temp2;
}



int insertion()
{
printf("Enter the priority of the element to be inserted :  ");
scanf("%d",&p);
  do
  {
     if(start==NULL)
     {create();
     start=temp1;
     return 1;
     }
   else
   {


     temp3=start->down;
     temp4=start;
     if(start->pr==p)
     {
     create();
     start->down=temp1;
     start=temp1;
     return 1;
     }
     while(temp3!=NULL)
     {
        if(temp3->pr>p)
        {
        create();
        temp1->down=temp3;
        temp4->down=temp1;
        return 1;
        }
        else
        if(temp3->pr==p)
        {
        temp2=(struct node*)malloc(sizeof(struct node));
        temp2->next=NULL;
        temp3->rear->next=temp2;
        temp3->rear=temp2;
        printf("Enter value :  ");
        scanf("%d",&temp2->x);
        return 1;
        }
      temp3=temp3->down;
     }
   }
   temp1=temp1->down;
  }while(temp1!=NULL);
return 0;
}




void display()
{
  temp1=start;
  if(temp1==NULL)
  printf("Here is nothing..create one..  \n");
  else
  while(temp1!=NULL)
  {
  temp2=temp1->next;
  printf("%d : ",temp1->pr);
  while(temp2!=NULL)
  {
  printf("%d\t",temp2->x);
  temp2=temp2->next;
  }
  temp1=temp1->down;
  printf("\n");
  }
}


int main()
{
int ch;
printf("Choose below : \n1.Insert.\n2.Delete.\n3.Display.\n\n");
scanf("%d",&ch);
switch (ch)
{
case 1:
if(!insertion());
create();
temp3=start;
while(temp3!=NULL)
{
temp3=temp3->down;
}
temp3->down=temp1;
break;

case 2:
deque();
break;

case 3:
display();

default:
printf("Wrong choice. :(");
}
return 0;
}
