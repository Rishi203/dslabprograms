#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;
};

struct node *head = NULL;

void insertbeginning(int data){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->next=head;
    head=new; 
    printf("\nInsertion Successful"); 
}

void insertend(int data){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    struct node *curr = head;
    new->data = data;
    new->next = NULL;
    if(head==NULL){
        head=new;
    }    
    else{
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=new;
    }
    printf("\nInsertion Successful");
}

void insertany(int data, int pos){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    struct node *curr = head;
    int currpos = 1;
    while(curr->next!=NULL && currpos!=pos){
        curr=curr->next;
        currpos+=1;
    }
    if(curr == NULL){
        printf("Enter a valid position");
    }
    else{
        new->next=curr->next;
        curr->next = new;
    }
}

void delete(int data){
    struct node *curr = head;
    struct node *temp = NULL;
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
                curr->next = NULL;
                free(curr);
            }
            else if(curr->next==NULL){
                temp->next = NULL;
                free(curr);
            }
            else{
                temp->next = curr->next;
                curr->next = NULL;
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

void reverse(){
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *after;
    while(curr!=NULL){
        after=curr->next;
        curr->next=prev;
        prev=curr;
        curr=after;
    }
    head=prev;

}
void sort(){
    struct node *curr = head;
    struct node *after = NULL;
    int temp;
    if(head == NULL){
        printf("list empty");

    }
    else{
        while(curr!=NULL){
            after=curr->next;
            while(after!=NULL){
                if(after->data<curr->data){
                    temp = curr->data;
                    curr->data=after->data;
                    after->data = temp;
                }
                after=after->next;
            }
            curr = curr->next;
        }
    }
}


int main(){
    int ch,item,position;
    do{
        printf("\nEnter choice \n1.insert at beginning \n 2. insert at end \n3. insert at any position \n4. delete an element\n 5.display\n6. reverse\n7.sort\n");
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
                printf("enter the item to be deleted\n");
                scanf("%d",&item);
                delete(item);
                break;

            case 5:
                display();
                break;
            case 6:
                reverse();
                break;
            case 7:
                sort();
                break;
        }
    }while(ch<8);    
}

