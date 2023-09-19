#include<stdio.h>
int linears(int a[],int n,int num)
{
  int i;
  for(i=0;i<n;i++)
  {
    if(a[i]==num)
    {
        return 1;
        
    } 
  }
  return -1;
}
int main()
{
    int i,n,num,a[20],ans;
    printf("enter limit::");
    scanf("%d",&n);
    printf("\nenter array elements:");
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    printf("\n array elements are:");
    for(i=0;i<n;i++)
    {
       printf("%d\t",a[i]);
    }
    printf("\n enter number to search:");
    scanf("%d",&num);
    ans=linears(a,n,num);
    if(ans==1)
    printf("\n number found");
    else
    printf("\n not found");
}
