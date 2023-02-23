#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int);
void inorder(struct node *);
struct node *findmin(struct node*);
struct node *delete(struct node*,int);

struct node *insertnode(struct node *root,int data){
    if(root == NULL){
        root = createnode(data);
    }
    else if(data <= root->data){
        root->left = insertnode(root->left,data);
    }
    else{
        root->right = insertnode(root->right,data);
    }
    return root;
}


struct node *createnode(int data){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
struct node *findmin(struct node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct node *delete(struct node *root,int data){
    if (root == NULL){
        printf("NOT FOUND");
    }
    else if (data< root->data){
        root->left = delete(root->left,data);
    }
    else if (data > root->data){
        root->right = delete(root ->right,data);
    }
    else{
        if (root->left == NULL && root->right == NULL){
            free(root);  
            root = NULL; 
        }
        
        else if (root->left == NULL || root->right==NULL) {
            struct node *temp = root;
            if (root->left) 
                root = root->left; 
            else 
                root = root->right; 
            free(temp);
        }
        else{
            struct node *temp = findmin(root->right);  
            root->data = temp->data;                       
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}



int main(){
    struct node *root = NULL;
    int ch,item,n;

    do{
        printf("\n1.insert 2.inorder 3.Delete\n");
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter value to be inserted\n");
                scanf("%d", &item);
                root = insertnode(root, item);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                printf("\nenter the node to be deleted\n");
                scanf("%d",&n);
                delete(root,n);
                break;
        }
    }while(ch<4);
}
