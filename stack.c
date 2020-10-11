#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *start=NULL;

struct node *push(struct node *);
struct node *pop(struct node *);
void display(struct node *);

int main(){
    int choice;
    while(1){
        printf("\n_______________");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\n_______________\n");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: start = push(start);
                    break;
            case 2: start = pop(start);
                    break;
            case 3: display(start);
                    break;
            case 4: exit(0);
            default: printf("\nWrong Choice");
        }
    }
    return 0;
}

struct node *push(struct node *start){
    struct node *new_node,*ptr;
    int val = 0;
    printf("\nEnter value to be inserted (-1 to exit): ");
    scanf("%d",&val);
    while(val != -1){
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data=val;
        new_node->next=NULL;
        ptr = start;
        if(start == NULL){
            start = new_node;
        }
        else{
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=new_node;
        }
        printf("\nNode Inserted\n");
        printf("\nEnter value to be inserted (-1 to exit): ");
        scanf("%d",&val);
    }
    return start;
}

struct node *pop(struct node *start){
    struct node *ptr;
    ptr = start;
    if(start==NULL){
        printf("\nUnderflow\n");
    }
    else if(start->next==NULL){
        printf("\nNode Deleted: %d",ptr->data);
        start=NULL;
    }
    else{
        while(ptr->next->next!=NULL){
            ptr=ptr->next;
        }
        printf("\nNode Deleted: %d",ptr->next->data);
        ptr->next=NULL;
    }
    return start;
}

void display(struct node *start){
    struct node *ptr;
    ptr = start;
    if(start==NULL){
        printf("\nUnderflow\n");
    }
    else{
        printf("\nThe nodes:");
        while(ptr!=NULL){
            printf("\t%d",ptr->data);
            ptr=ptr->next;
        }
    }
}