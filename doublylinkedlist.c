#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *prev;
};

struct node *create(list)
{
    struct node *newnode, *temp;
    int i, n;
    printf("enter limit:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter value:");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (list == NULL)
        {
            list = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    return list;
}

void display(list)
{
    struct node *temp;
    for (temp = list; temp != NULL; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }
}

struct node *insertbeg(struct node *list)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter value:");
    scanf("%d", &newnode->data);
    if (list == NULL)
    {
        newnode->prev = NULL;
        list = newnode;
    }
    else
    {
        newnode->next = list;
        list->prev = newnode;
        list = newnode;
        return list;
    }
}

struct node *insertend(struct node *list)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter value:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (list == NULL)
    {
        newnode->prev = NULL;
        list = newnode;
    }
    else
    {
        temp = list;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    return list;
}

struct node *insertmid(struct node *list)
{
    struct node *newnode, *temp, *temp1;
    int pos, i;
    printf("\nenter position to insert:");
    scanf("%d", &pos);
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter value:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (pos == 1)
    {
        newnode->prev = NULL;
        newnode->next = list;
        list = newnode;
    }
    else
    {
        temp = list;
        i = 1;
        while (i < pos - 1 && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }

        newnode->next = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
    return list;
}

struct node *deletebeg(struct node *list)
{
    struct node *temp;
    temp = list;
    list = list->next;
    free(temp);
    return list;
}
struct node *deleteend(struct node *list)
{
    struct node *temp, *temp1;
    temp = list;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp1 = temp->next;
    temp->next = NULL;
    free(temp1);
    return list;
}

struct node *deletemid(struct node *list)
{
    struct node *temp, *temp1;
    int pos, i;
    printf("\nenter position to delete:");
    scanf("%d", &pos);
    if (pos == 1)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
    else
    {
        i = 1;
        temp = list;
        while (i < (pos - 1) && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        //   if(temp1->next!=NULL)
        //   {
        temp1->next->prev = temp;

        //   }
        free(temp1);
    }
    return list;
}

struct node *delete_by_value(struct node *list)
{
    struct node *temp, *temp1;
    int value, flag = 0;
    printf("enter value:");
    scanf("%d", &value);
    if (list->data == value)
    {
        temp = list;
        list = list->next;
        free(temp);
    }

    else
    {
        temp = list;
        while (temp->next != NULL)
        {
            if (temp->next->data == value)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag == 1)
        {

            temp1 = temp->next;
            temp->next = temp1->next;
            temp1->next->prev = temp;
            free(temp1);
        }
    }
    return list;
}

struct node *search_by_value(struct node *list)
{

    struct node *temp;
    int value, flag = 0;
    printf("enter value:");
    scanf("%d", &value);
    temp = list;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 1)
    {
        printf("\nnumber is found");
    }
    else
    {
        printf("\nnumber is not found");
    }
}

int main()
{
    int ch;
    struct node *list = NULL;
    do
    {
        printf("\n1:create\n2:display\n3:insertbeg\n4:insertend\n5:insertmid\n6:deletebeg\n7:deleteend\n8:deletemid\n9:delete_by_value\n10: search_by_value");
        printf("\nenter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            list = create(list);
            break;
        case 2:
            display(list);
            break;
        case 3:
            list = insertbeg(list);
            break;
        case 4:
            list = insertend(list);
            break;
        case 5:
            list = insertmid(list);
            break;
        case 6:
            list = deletebeg(list);
            break;
        case 7:
            list = deleteend(list);
            break;
        case 8:
            list = deletemid(list);
            break;
        case 9:
            list = delete_by_value(list);
            break;
        case 10:
            search_by_value(list);
            break;
        default:
            printf("\nenter valid choice");
        }
    } while (ch < 11);
}