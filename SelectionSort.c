#include<stdio.h>
void main()
{
    int n=0,i=0;
    printf("Enter the length of the array:- ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements - ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, n);
    printf("The sorted array is :- ");
    display(a,n);
}
void sort(int *arr, int n)
{
    int t=0,i,j,min,p;
    for(i=0;i<n-1;i++)
    {
        min=arr[i];
        p=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                p=j;
            }
        }
        t=arr[i];
        arr[i]=arr[p];
        arr[p]=t;
        printf("Elements after pass %d:-", i+1);
        display(arr, n);
        printf("\n");
    }
}
void display(int *arr, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d, ", arr[i]);
    }
}