#define max 15
#include<stdio.h>

struct stack{
    char a[max];
    int top;
}s;

void init(){
    s.top=-1;
}
int isempty(){
    if(s.top==-1)
    {
        return 1;
    }
    else 
    return 0;
}

int isfull(){
    if(s.top==max-1)
    {
        return 1;
    }
    else 
    return 0;
}

void  push(char num){
    if(isfull()){
        printf("\n stack is full dont push");
    }
    else{
         s.top++;
         s.a[s.top]=num;
         printf("\n push successfully.");
    }
}

void  pop(){
    char  val;
    if(isempty())
    {
        printf("\n stack is empty cant pop");
    }
    else{
        val=s.a[s.top];
        s.top--;
        printf("\n pop char =%c",val);
    }
}

void dispstack()
{
    int i;
    for(i=s.top;i>-1;i--)
    {
        printf("%c",s.a[i]);
    }
}

int main()
{
char num;
int ch;
printf("1:push\n 2:pop\n3:dispstack");
do{
printf("\n enter choice:");
scanf("%d",&ch);
getchar();
switch(ch){
    case 1: printf("enter char:");
    scanf("%c",&num);
    push(num);
    break;
    case 2:pop();
    break;
    case 3:dispstack();
    break;
     default:printf("\n invalid choice:");
}
}while(ch<5);

}