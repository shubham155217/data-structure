#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

struct node *create(struct node *head)
{
	struct node *newnode,*temp;
	int i,n;
	printf("\n enter limit:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter value:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
	}	
	return head;
}

void disp(struct node *head)
{
	struct node *temp;
 for(temp=head;temp!=NULL;temp=temp->next)
 printf("%d\t",temp->data);	
}

struct node * insertbeg (struct  node *head,int num)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=head;
	head=newnode;
	return head;
}

struct node *insertend(struct node *head,int num)
{
	struct node *newnode,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=NULL;
	for(temp=head;temp->next!=NULL;temp=temp->next);
	temp->next=newnode;
	return head;	
}

struct node *insertmid(struct node *head,int pos,int num)
{
	struct node *newnode,*temp;
	int i;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	for(i=1,temp=head;i<pos-1&&temp->next!=NULL;temp=temp->next);
	newnode->next=temp->next;
	temp->next=newnode;
	return head;	
}

struct node *delbeg(struct node *head)
{
	struct node *temp;
	temp=head;
	head=head->next;
	free(temp);
	return head;
}

struct node *delend(struct node *head)
{
	struct node *temp,*temp1;
	for(temp=head;temp->next->next!=NULL;temp=temp->next);
	temp1=temp->next;
	temp->next=NULL;
	free(temp1);
	return head;
}

struct node *delmid(struct node *head,int pos)
{ int i;
	struct node *temp,*temp1;
	for(i=1,temp=head;i<(pos-1)&&temp->next!=NULL;i++,temp=temp->next);
	temp1=temp->next;
	temp->next=temp1->next;
	free(temp1);
	return head;
}

int main()
{
	int pos,num,ch;
	struct node *newnode;
	struct node *head=NULL;
do{
	printf("\n1-create");
	printf("\n2-display");
	printf("\n3-insert beg");
	printf("\n4-insert end");
	printf("\n5-insert mid");
	printf("\n6-delete beg");
	printf("\n7-delete end");
	printf("\n8-delete mid");
	printf("\n\n");
	printf("\nenter choice:");
	scanf("%d",&ch);
   	switch(ch)
	   {
	   	case 1:head=create(head);
	   	       break;
	   	case 2:disp(head);
	   	       break;
		case 3:printf("enter number:");
	          	scanf("%d",&num);
	            head=insertbeg(head,num);
		       break;
	    case 4:printf("enter number:");
	          	scanf("%d",&num);
	            head=insertend(head,num);
		       break;
        case 5:printf("enter number:");
	          	scanf("%d",&num);
	          	printf("enter position:");
	          	scanf("%d",&pos);
	            head=insertmid(head,pos,num);
		       break;
		case 6:head=delbeg(head);
		       break;
		case 7:head=delend(head);
		       break;
	    case 8:printf("enter position:");
	          	scanf("%d",&pos);
				head=delmid(head,pos);
		       break;
	    default:printf("\n invalid choice:");
		       
	    }	
   }while(ch<9);
}




