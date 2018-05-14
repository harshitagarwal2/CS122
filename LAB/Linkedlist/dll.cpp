#include <stdio.h>
#include <stdlib.h>
#define ERROR -999


typedef struct node *Nodeptr;

typedef struct node
{
    int digit;
    Nodeptr llink;
    Nodeptr rlink;
}NODE;


Nodeptr getnode()
{
    Nodeptr temp;

    temp = (Nodeptr) malloc(sizeof(NODE));
    return temp;
}

void Display()
{
    Nodeptr temp;

    temp = head->llink;
    if (head->llink == head->rlink)
    {
        printf("List is Empty\n");
        return;
    }
    printf("\nContents of List : ");
    for(temp=first;temp;temp=temp->next)
        printf("%d ",temp->data);
}

void InsertRear( int item)
{
    Nodeptr temp,last;

    temp = getnode();
    temp->data = item;
    temp->next = NULL;

    if (first == NULL)
    {
        first = temp;
        return;
    }

    last = first;
    while(last->next)
        last = last->next;

    last->next = temp;
}

void InsertFront(int item)
{
    Nodeptr temp;

    temp = getnode();
    temp->data = item;

    temp->next = first;
    first = temp;

}

int  DeleteFront()
{
    Nodeptr temp;
    int num;

    if (first == NULL)
    {
        printf("Empty List\n");
        return ERROR;
    }

    num = first->data;
    temp = first;
    first = first->next;
    free(temp);
    return(num);
}

int DeleteRear()
{
    Nodeptr prev,cur;
    int num;

    if (first == NULL)
    {
        printf("Empty List\n");
        return ERROR;
    }

    cur = first;
    prev = NULL;
    while(cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    num = cur->data;
    if (prev)// node to be deleted isn't the first node
       prev->next = NULL;
    else
        first = NULL;
    free(cur);
    return(num);

}
Nodeptr Search(int item, Nodeptr *prev)
{
    Nodeptr cur;

    if (first == NULL)
    {
        printf("Empty List\n");
        return NULL;
    }

    cur = first;
    *prev = NULL;
    while(cur)
    {
        if (cur->data ==item)
            return cur;
        *prev = cur;
        cur = cur->next;
    }
    return NULL;

}

void Invert()
{
    Nodeptr p,q,r;
    p=first;
    q=NULL;

    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

int main()
{

    int choice, item;
    Nodeptr temp, prev;

    CreateList();

    while(1)
    {
        printf("Enter: 1. InsertFront 2. InsertRear\n");
        printf("Enter: 3. DeleteFront 4. DeleteRear\n");
        printf("Enter: 5. Display     6. Search\n");
        printf("7. Invert   8. Exit\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                    printf("Enter the item to be inserted: ");
                    scanf("%d",&item);
                    InsertFront(item);
                    break;
            case 2:
                    printf("Enter the item to be inserted: ");
                    scanf("%d",&item);
                    InsertRear(item);
                    break;
            case 3:
                    printf("The item Deleted from front = %d\n",DeleteFront());
                    break;
            case 4:
                    printf("The item Deleted from rear = %d\n",DeleteRear());
                    break;
            case 5:
                    Display();
                    break;
            case 6: printf("Enter the item to be searched: ");
                    scanf("%d",&item);
                    temp = Search(item,&prev);
                    if (temp == NULL)
                       printf("Item Not Found\n");
                    else
                    {
                        printf("Item Found\n");
                        if (prev)
                            printf("Previous item = %d\n",prev->data);
                    }
                    break;
            case 7: Invert();
                    break;
            case 8:
                    exit(0);
        }
    }

}
