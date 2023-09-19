#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct emp{
    char name[20];
    int age;
    int sal;
}e1[10],t[10];
void merge(struct emp e1[],int top,int mid,int bottom)
{ 
    int k,i,j;
i=top;
j=mid+1;
k=top;
  while(i<=mid  && j<=bottom)
  {
    if(strcmp(e1[i].name,e1[j].name)<0)
    {
        t[k++]=e1[i++];
    }
    else{
        t[k++]=e1[j++];
    }
  }
  while(i<=mid)
{
    t[k++]=e1[i++];
}
  while(j<=bottom)
{
    t[k++]=e1[j++];
}
for(i=top;i<=bottom;i++)
{
    e1[i]=t[i];
}
}
 void mdivide(struct emp e1[],int top,int bottom)
 {  int mid;
    
    if(top<bottom)
    {   mid=(top+bottom)/2;
        mdivide(e1,top,mid);
        mdivide(e1,mid+1,bottom);
        merge(e1,top,mid,bottom);
    }
 }
 
int main()
{
    FILE *fp1;
    int i,n;
    fp1=fopen("employee.txt","r");
    if(fp1==NULL)
    {
        printf("file not found");
        exit(0);
    }
    i=0;
    while(!feof(fp1))
    {
        fscanf(fp1,"%s%d%d",&e1[i].name,&e1[i].age,&e1[i].sal);
        i++;
    }
    n=i-1;
    fclose(fp1);
    mdivide(e1,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%s\t%d\t%d\n",e1[i].name,e1[i].age,e1[i].sal);
    }
}