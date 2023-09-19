#include<stdio.h>
#include<string.h>
void selection(char s1[][20],int n)
{
  int i,j,index1;
  char t[20],max[20];
  for(i=0;i<n;i++)
  {  
    strcpy(max,s1[i]);
    
    for(j=i+1;j<n;j++)
    {
        if(strcmp(max,s1[j])<0)
        {
          strcpy(max,s1[j]);
          index1=j;
        }

    }
    strcpy(t,s1[i]);
    strcpy(s1[i],s1[index1]);
    strcpy(s1[index1],t);
  }
}
int main()
{
int n,i;
char s1[20][20];
printf("enter limit::");
scanf("%d",&n);
printf("enter city names::");
for(i=0;i<n;i++)
{
    scanf("%s",s1[i]);
}
selection(s1,n);
printf("sorted city names::");
for(i=0;i<n;i++)
{
    printf("%s\t",s1[i]);
}

}