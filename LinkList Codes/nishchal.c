#include<stdio.h>
#include<conio.h>

struct HNODE
{
 char win[5];
 char op[5];
 struct HNODE *next;
}*hstr,*hn,*htemp;

struct VNODE
{
 char tname[8];
 char cap[10];
 struct HNODE *right;
 struct VNODE *down;
}*vstr,*vn,*vtemp;

struct abc
{
 char team[8];
 char tcap[5];
 int p;
}*e,t;

void main()
{
 int i,j,x,y;
 clrscr();
 printf("Enter no. of teams \t");
 scanf("%d",&x);
 e=(struct abc*)malloc(x*sizeof(struct abc));
 printf("Team name \t Captain \n");
 vstr=NULL;
 for(i=0;i<x;i++)
 {
  vtemp=(struct VNODE*)malloc(sizeof(struct VNODE));
  scanf("%s %s",vtemp->tname,vtemp->cap);
  strcpy(e[i].team,vtemp->tname);
  strcpy(e[i].tcap,vtemp->cap);
  vtemp->down=NULL;
  if(vstr==NULL)
  {
   vstr=vtemp;
   vn=vtemp;
  }
  else
  {
   vn->down=vtemp;
   vn=vtemp;
  }
 }

 vtemp=vstr;
 for(i=0;i<x;i++)
 {
  e[i].p=0;
  printf("Enter no. of matches of team %d \t",i+1);
  scanf("%d",&y);
  printf("Opponent team \t Winning team \n");
  hstr=NULL;
  for(j=0;j<y;j++)
  {
   htemp=(struct HNODE*)malloc(sizeof(struct HNODE));
   scanf("%s %s",htemp->op,htemp->win);
   if(strcmp(vtemp->tname,htemp->win)==0)
   e[i].p+=2;
   htemp->next=NULL;
   if(hstr==NULL)
   {
    hstr=htemp;
    hn=htemp;
   }
   else
   {
    hn->next=htemp;
    hn=htemp;
   }
  }
  vtemp->right=hstr;
  vtemp=vtemp->down;
 }

 /*printf("Traversal : \n");
 vtemp=vstr;
 while(vtemp!=NULL)
 {
  printf("\nTeam name \t Cap. \n");
  printf("%s \t %s \n",vtemp->tname,vtemp->cap);
  htemp=vtemp->right;
  printf("Opponent \t Winner\n");
  while(htemp!=NULL)
  {
   printf("%s \t %s \n",htemp->op,htemp->win);
   htemp=htemp->next;
  }
  vtemp=vtemp->down;
 }*/

 for(i=0;i<x-1;i++)
 for(j=0;j<x-i-1;j++)
 if(e[j].p<e[j+1].p)
 {
  strcpy(t.team,e[j].team);
  strcpy(t.tcap,e[j].tcap);
  t.p=e[j].p;

  strcpy(e[j].team,e[j+1].team);
  strcpy(e[j].tcap,e[j+1].tcap);
  e[j].p=e[j+1].p;

  strcpy(e[j+1].team,t.team);
  strcpy(e[j+1].tcap,t.tcap);
  e[j+1].p=t.p;
 }

 printf("\n\n Points Table : \n");
 for(i=0;i<x;i++)
 printf("%d. %s - %d\n",i+1,e[i].team,e[i].p);

 printf("Best Captain : %s",e[0].tcap);
 getch();
}