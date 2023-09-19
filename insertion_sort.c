#include <stdio.h>
void insertion_sort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n ; i++)
    {
        key = a[i];
        for (j = i - 1; j >= 0 && a[j] > key; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
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

    insertion_sort(a, n);
}