#include <stdio.h>
int merge(int a[], int top, int bottom, int mid)
{
    int t[20];
    int i, j, k;
    i = top;
    j = mid + 1;
    k = top;
    while (i <= mid && j <= bottom)
    {
        if (a[i] < a[j])
        {
            t[k] = a[i];
            k++;
            i++;
        }
        else
        {
            t[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
        {
            t[k] = a[i];
            i++;
            k++;
        }
        while (j <= bottom)
        {
            t[k] = a[j];
            j++;
            k++;
        }
    for (i = top; i <=bottom; i++)
    {
        a[i] = t[i];
    }
}

void msortdiv(int a[], int top, int bottom)
{
    int mid;
        if(top < bottom)
    {
        mid = (top + bottom) / 2;
        msortdiv(a, top, mid);
        msortdiv(a, mid + 1, bottom);
        merge(a, top, bottom, mid);
    }
}

int main()
{
    int a[20], i, n, top, mid, bottom;
    printf("enter limit:");
    scanf("%d", &n);
    printf("\nenter array elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    msortdiv(a, 0, n-1);
     for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
