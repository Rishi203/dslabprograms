#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insertbeginning(int data){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->prev = NULL;

    if(head==NULL){
        head = new;
        new->next = NULL;

    }
    else{
        new->next = head;
        head->prev = new;
        head = new;
    }
}

void insertend(int data){
    struct node *curr = head;
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next = NULL;
    if(curr==NULL){
        head = new; 
    }
    else{
        while(curr->next!=NULL){
            curr= curr->next;
        }
        curr->next=new;
        new->prev=curr;
    }    

}

void insertany(int data,int pos){
    struct node *curr = head;
    
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data=data;
    int count = 1;
    while(curr->next!=NULL && count!=pos){
    
        curr = curr->next;
        count = count+1;
    }

    if(curr==NULL){
        printf("enter correct position");
    }
    else{
        struct node *temp = curr->next;
        curr->next = new;
        new->prev = curr;
        new->next = temp;
        temp->prev = new;
    }   
}

void delete(int data){
    struct node* temp = NULL;
    struct node* curr = head;
    if(curr== NULL){
        printf("empty");
    }
    else{
        while(curr->next!=NULL && curr->data!=data){
            temp = curr;
            curr = curr->next;
        }
        if(curr->data!= data){
            printf("Element not found");
        }
        else{
            if(temp == NULL){
                head = curr->next;
                head->prev = NULL;
                curr->next = NULL;
            }
            else if(curr->next==NULL){
                temp->next = NULL;
                curr->prev = NULL;
                free(curr);
            }
            else{
                temp->next = curr->next;
                curr->next->prev = temp;
                free(curr);
            }
        }
    }
}

void display(){
    struct node *curr = head;
    if(curr==NULL){
        printf("list empty");

    }
    else{
        while(curr!=NULL){
            printf("%d-->",curr->data);
            curr=curr->next;
        }
    }
}




int main(){
    int ch,item,position;
    do{
        printf("\nEnter choice \n1.insert at beginning \n 2. insert at end \n3. insert at any position \n4. delete an element\n 5.display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            
                printf("enter the item to be inserted at beginning \n");
                scanf("%d",&item);
                insertbeginning(item);
                break;

            case 2:
                printf("enter the item to be inserted at end \n");
                scanf("%d",&item);
                insertend(item);

                break;

            case 3:
                printf("enter the item to be inserted at any position \n");
                scanf("%d",&item);
                printf("enter the position \n");
                scanf("%d",&position);
                insertany(item,position);
                break;

            case 4:
                printf("enter the item to be deleted \n");
                scanf("%d",&item);
                delete(item);
                break;
            case 5:
                display();
                break;
        }
    }while(ch<6);    
}


