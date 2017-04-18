#include<stdio.h>

int getMax(int arr[], int n)
{   int i;
    int m = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > m)
            m = arr[i];
    return m;
}


void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

      for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


void radixsort(int arr[], int n)
{

    int m = getMax(arr, n);
    int exp;
    for (exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}


void print(int arr[], int n)
{   int i;
    for (i = 0; i < n; i++)
        printf("%d\t",arr[i]);
}


int main()
{
    int arr[50],n,i;
    printf("\nEnter the size of array :  ");
    scanf("%d",&n);
    printf("\n\nEnter Elements in the array.\n");
    for(i=0;i<=n-1;i++)
    scanf("%d",&arr[i]);
    radixsort(arr, n);
    print(arr, n);
    return 0;
}
