#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *addBeginning(struct node *);
struct node *addEnd(struct node *);
struct node *addPosition(struct node *);
struct node *deleteBeginning(struct node *);
struct node *deleteEnd(struct node *);
void search(struct node *);
void display(struct node *);

int main()
{
    int n;
    while(1){
        printf("\n1. Insert At Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Particular Position");
        printf("\n4. Delete Beginning");
        printf("\n5. Delete End");
        printf("\n6. Search a Node");
        printf("\n7. Display");
        printf("\n1. Exit");
        printf("\nEnter Choice: ");
        scanf("%d",&n);
        switch(n){
            case 1: 
                start = addBeginning(start);
                break;
            case 2: 
                start = addEnd(start);
                break;
            case 3: 
                start = addPosition(start);
                break;
            case 4: 
                start = deleteBeginning(start);
                break;
            case 5: 
                start = deleteEnd(start);
                break;
            case 6:
                search(start);
                break;
            case 7:
                display(start);
                break;
            case -1:
                exit(0);
            default: printf("\nWrong Choice Entered\n");
        }
    }
    return 0;
}

struct node *addBeginning(struct node *start){
    struct node *ptr;
    int num;
    printf("\nEnter number to be inserted. Enter -1 to exit insertion: ");
    scanf("%d", &num);
    while(num != -1){
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->next=NULL;
        ptr->data=num;
        if(start==NULL)
        {
            start=ptr;
        }
        else{
            ptr->next=start;
            start=ptr;
        }
        printf("\nNumber Inserted\n");
        printf("\nEnter number to be inserted. Enter -1 to exit insertion: ");
        scanf("%d", &num);
    }
    return start;
}

struct node *addEnd(struct node *start){
    struct node *tmp, *new_node;
    int num;
    printf("\nEnter number to be inserted. Enter -1 to exit insertion: ");
    scanf("%d", &num);
    while(num!=-1){
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->next=NULL;
        new_node->data=num;
        if(start==NULL)
        {
            start = new_node;
        }
        else{
            tmp = start;
            while(tmp->next!=NULL){
                tmp = tmp->next;
            }
            tmp->next=new_node;
        }
        printf("\nNumber Inserted\n");
        printf("\nEnter number to be inserted. Enter -1 to exit insertion: ");
        scanf("%d", &num);
    }
    return start;
}

struct node *addPosition(struct node *start){
    struct node *ptr,*new_node;
    int val,pos;
    if(start==NULL){
        printf("\nNo linked list created\n");
        return start;
    }
    printf("\nEnter number to be inserted. Enter -1 to exit insertion: ");
    scanf("%d", &val);
    while(val!=-1){
        printf("\nEnter position of number: ");
        scanf("%d", &pos);
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data=val;
        new_node->next=NULL;
        ptr = start;
        if(pos==1)
        {
            new_node->next=start;
            start = new_node;
        }    
        else{
            pos=pos-2;
            while(pos>0){
                ptr=ptr->next;
                pos--;
            }
            new_node->next=ptr->next;
            ptr->next=new_node;
        }

        printf("\nNumber Inserted\n");
        printf("\nEnter number to be inserted. Enter -1 to exit insertion: ");
        scanf("%d", &val);
    }
    return start;
}

struct node *deleteBeginning(struct node *start){
    if(start==NULL){
        printf("\nLinked List is Empty\n");
        return start;
    }
    struct node *ptr;
    ptr = start;
    start=ptr->next;
    free(ptr);
    printf("\nFirst Node Deleted\n");
    return start;
}

struct node *deleteEnd(struct node *start){
    if(start==NULL){
        printf("\nLinked List is Empty\n");
        return start;
    }
    if(start->next==NULL){
        start=NULL;
        printf("\nLast Node Deleted\n");
        return start;
    }
    struct node *ptr;
    ptr=start;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=NULL;
    printf("\nLast Node Deleted\n");
    return start;
}

void search(struct node *start){
    if(start==NULL){
        printf("\nLinked list is empty\n");
        return;
    }
    int num,pos=1;
    printf("\nEnter number to search: ");
    scanf("%d",&num);
    struct node *ptr;
    ptr = start;
    while(ptr!=NULL){
        if(ptr->data==num){
            printf("\nNumber found at %d position\n",pos);
            return;
        }
        ptr=ptr->next;
        pos++;
    }
    printf("\nNumber not found\n");
    return;
}

void display(struct node *start){
    if(start == NULL)
    {
        printf("No Nodes\n");
        return;
    }
    printf("\nNodes are: ");
    struct node *tmp;
    tmp = start;
    while(tmp!=NULL){
        printf("%d\t",tmp->data);
        tmp=tmp->next;
    }
    free(tmp);
}