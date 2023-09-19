#include <stdio.h>
#include<string.h>
struct cities
{
    char cname[20];
    int stdcode;
} c1[20];

int main()
{
    FILE *fp1;
    int i = 0, n, code, flag = 0, top, bottom, mid;
    char name[20],x[20];
    fp1 = fopen("cities.txt", "r");
    if (fp1 == NULL)
    {
        printf("file not found:");
    }
    while (!feof(fp1))
    {
        fscanf(fp1, "%s%d", name, &code);
        strcpy(c1[i].cname, name);
        c1[i].stdcode = code;
        i++;
    }
    n = i;
    printf("enter city name to search::");
    scanf("%s",x);
    top = 0;
    bottom = n - 1;

    while (top<= bottom)
    {
        mid = (top + bottom) / 2;
        if(strcmp(c1[mid].cname,x)==0)
        {
            flag=1;
            break;
        }
        if(strcmp(x,c1[mid].cname)>0)
        top=mid+1;
        else
        bottom=mid-1;
    }
    if(flag==1)
    {
        printf("\n stdcode=%d",c1[mid].stdcode);
    }
    else
    printf("not found");
    fclose(fp1);
}