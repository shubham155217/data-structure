#include<stdio.h>
int main()
{
    FILE *fp1;
    int num,x,a[20],top,bottom,mid,flag=0,i=0,n;
    fp1=fopen("numbers.txt","r");
    if(fp1==NULL)
    {
        printf("file not found:");
    }
    printf("\n enter city name to search:");
    scanf("%d",&x);
    while(!feof(fp1))
    {
        fscanf(fp1,"%d",&num);
        a[i++]=num;
    }
    n=i;
    top=0;
    bottom=n-1;
    
   while(top<=bottom)
   {
    mid=top+bottom/2;
    if(a[mid]==x)
    {
        flag=1;
        break;
    }
    if(x>a[mid])
    top=mid+1;
    else 
    bottom=mid-1;
   }
   
  if(flag==1)
   printf("number found:");
   else
   printf("number not found:");
    fclose(fp1);
}
