#include<stdio.h>

void merge(int a[], int low, int mid, int high)
{
int b[10000];
int i = low, j = mid + 1, k = 0;
while (i <= mid && j <= high)
{
if (a[i] <= a[j])
b[k++] = a[i++];
else
b[k++] = a[j++];
}
while (i <= mid)
b[k++] = a[i++];
while (j <= high)
b[k++] = a[j++];
k--;
while (k >= 0)
{
a[low + k] = b[k];
k--;
}
}



void mergesort(int a[ ], int low, int high)
{
if (low < high)
{
int m = (high + low)/2;
mergesort(a, low, m);

mergesort(a, m + 1, high);
merge(a, low, m, high);
}
}

int main()
{
int i,a[10],l=0,h=9;
printf("Enter array elements.\n");
for(i=0;i<=9;i++)
{
printf("%d: ",i+1);
scanf("%d",&a[i]);
}
mergesort(a,l,h);
for(i=0;i<=9;i++)
printf("%d  ",a[i]);
return 0;
}
