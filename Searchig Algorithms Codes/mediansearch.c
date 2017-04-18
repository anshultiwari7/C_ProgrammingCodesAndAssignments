#include<stdio.h>
int select(int t[],int n,int k)
{
int b[10],c[10],d[10],i,p=0,q=0,r=0,x;
//for(i=0;i<=n-1;i++)
  //  printf("%d",t[i]);
//printf("\n");
x=t[0];

//b,c,d array filling
for(i=0;i<=n-1;i++)
{


if(x>t[i])
b[q++]=t[i];
else
if(x==t[i])
c[p++]=t[i];
else
d[r++]=t[i];
}

if(q>=k)
return select(b,q,k);
else
if(p+q>=k)
return x;
else
return select(d,r,k-(p+q));
}


int main()
{
int a[10],i,k,n=10;
printf("Enter array elements..\n");
for(i=0;i<=9;i++)
scanf("%d",&a[i]);
printf("Enter value assigning to k..\n");
scanf("%d",&k);
printf("%d",select(a,n,k));
return 0;
}
