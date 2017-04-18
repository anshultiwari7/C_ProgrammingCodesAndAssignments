#include<stdio.h>
#define MAXSIZE 4
void pqinsert();
void pqdelete();
void display();
int pqueue[3][MAXSIZE];
int front[3]={0,0,0};
int rear[3]={-1,-1,-1};
int item,pr;
int main()
{
char ch;
int choice;
do
{
printf("\n*************** Queue Operations **************\n");
printf("\t\t 1-> PQInsert\n");
printf("\t\t 2-> PQDelete\n");
printf("\t\t 3-> Display\n");
printf("\t\t 4-> Exit\n");
printf("\t\t Enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("\t\t Enter the priority:");
scanf("%d",&pr);
if(pr>0 && pr<4)
pqinsert(pr-1);
else
printf("\t\t Invalid priority\n");
break;
case 2: pqdelete();
break;
case 3: display();
break;
case 4: exit(0);
break;
default: printf("\t\tInvalid choice\n");
break;
}
printf("\t\tDo you want to continue(type y or n):");
fflush(stdin);
scanf("%c",&ch);

} while(ch!='n');
return 0;
}

void pqinsert(int pr)
{
int item;
if(rear[pr]==MAXSIZE-1)
printf("\t\t PQueue Overflows\n");
else
{
printf("\t\t Enter the element:");
scanf("%d",&item);
rear[pr]++;
pqueue[pr][rear[pr]]=item;
}
}
void pqdelete()
{
static int i=0 ;
if(rear[i]==front[i]-1)
{
printf("\t\t Queue %d Underflows\n",i+1);
i++;
}
else
{
printf("\t\t The deleted element is %d of queue %d:\n",pqueue[i][front[i]],i+1);
front[i]++;
}
}


void display()
{
int i,j;
for(i=0;i<3;i++)
{
if(rear[i]==front[i]-1)
printf("\t\t Queue %d Underflows\n:",i+1);
else
{
printf("\t\tThe elements in Queue %d are\n",i+1);
printf("\t");
for(j=front[i];j<=rear[i];j++)
printf("\t%d",pqueue[i][j]);
printf("\n");
}
}
}
