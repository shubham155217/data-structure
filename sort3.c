#include <stdio.h>
#include <stdlib.h>
struct emp
{
    char name[20];
    int age;
    int sal;
} e1[20], k1[20], t;
void bubble(struct emp e1[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (e1[j].age > e1[j + 1].age)
            {
                t = e1[j];
                e1[j] = e1[j + 1];
                e1[j + 1] = t;
            }
        }
    }
}

void insertion(struct emp e1[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = e1[i].age;
        for (j = i - 1; j >= 0 && key < e1[j].age; j--)
        {
            t = e1[j + 1];
            e1[j + 1] = e1[j];
            e1[j] = t;
        }
    }
}

void selection(struct emp e1[], int n)
{
    int i, j, min, pos;
    for (i = 0; i < n; i++)
    {
        min = e1[i].age;
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (e1[j].age < min)
            {
                min = e1[j].age;
                pos = j;
            }
        }
        t = e1[i];
        e1[i] = e1[pos];
        e1[pos] = t;
    }
}

void concure(struct emp e1[], int top, int mid, int bottom)
{
    int i, j, k;
    j = mid + 1;
    i = top;
    k = top;
    struct emp k1[20];
    while (i <= mid && j <= bottom)
    {
        if (e1[i].age < e1[j].age)
        {
            k1[k] = e1[i];
            i++;
            k++;
        }
        else
        {
            k1[k] = e1[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        k1[k] = e1[i];
        k++;
        i++;
    }
    while (j <= bottom)
    {
        k1[k] = e1[j];
        k++;
        j++;
    }
    for (i = top; i <= bottom; i++)
    {
        e1[i] = k1[i];
    }
}
void mdivide(struct emp e1[], int top, int bottom)
{
    int i, j, mid;
    if (top < bottom)
    {
        mid = (top + bottom) / 2;
        mdivide(e1, top, mid);
        mdivide(e1, mid + 1, bottom);
        concure(e1, top, mid, bottom);
    }
}

int main()
{
    FILE *f1;
    int i = 0, n, ch;
    f1 = fopen("employee.txt", "r");
    if (f1 == NULL)
    {
        printf("file not found");
        exit(0);
    }
    while (!feof(f1))
    {
        fscanf(f1, "%s%d%d", &e1[i].name, &e1[i].age, &e1[i].sal);
        i++;
    }
    n = i;
    fclose(f1);

    do
    {
        printf("1.bubble sort\n2.insertion sort\n3.selection sort\n4.Merge sort");
        printf("\n enter choice:");
        scanf("%d", &ch);
        switch (ch)
        {

        case 1:
            printf("bubble sort");
            bubble(e1, n);
            break;
        case 2:
            printf("insertion sort");
            insertion(e1, n);
            break;
        case 3:
            printf(" selection sort");
            selection(e1, n);
            break;
        case 4:
            printf(" merge sort");
            mdivide(e1, 0, n - 1);
            break;
        default:
            printf("invalid choice");
            printf("\n code remain unchanged");
        }

        for (i = 0; i < n; i++)
        {
            printf("%s\t%d\t%d\n", e1[i].name, e1[i].age, e1[i].sal);
        }
    } while (ch <= 4);
}