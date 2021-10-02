#include<stdio.h>
void main()
{
    int n=0,i=0;
    printf("Enter the length of the array:- ");
    scanf("%d", &n);
    int a[n];
    printf("Enter Elements - ");
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
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>=arr[j+1])
            {
                arr[j]=arr[j]+arr[j+1];
                arr[j+1]=arr[j]-arr[j+1];
                arr[j]=arr[j]-arr[j+1];
            }
        }
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
