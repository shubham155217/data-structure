#include <stdio.h>
void selection_sort(int a[], int n)
{
    int i, j,pos,min,t;

    for(i=0;i<n-1;i++)
    {
        min=a[i];
        pos=i;
       for(j=i+1;j<n;j++)
       {
        if(min>a[j])
        {
          min=a[j];
          pos=j;
        }
       }

       t=a[i];
       a[i]=a[pos];
       a[pos]=t;
             
    }
    printf("\n after sort::");

   
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}

int main()
{
    int a[10], i, n;
    printf("enter limit:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nenter value:");
        scanf("%d", &a[i]);
    }
    printf("\n before sort::");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    selection_sort(a, n);
}