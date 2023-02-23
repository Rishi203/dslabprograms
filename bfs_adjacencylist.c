#include<stdio.h>
#include<stdlib.h>

# define size 100

struct node{
    int data;
    struct node *next;
};

struct node *vertices[100],*temp, *head;

int queue[size];
int front=-1,rear=-1;


void enqueue(int item){
    if(rear==size-1){
        printf("FULL");
    }
    else{
        if(front==-1 && rear ==-1){
            front=0;
            queue[++rear]=item;
        }
        else{
            queue[++rear]=item;
        }
    }
}
int dequeue(){
    if(front==-1){
        printf("empty");
    }
    else{
        int deleted = queue[front];
        if(rear==front){
            front=-1;
            rear=-1;
        }
        else{
            front=front+1;
        }
        return deleted;
    }
}
void bfs(int u){
    int visited[100]={0};

    visited[u]=1;
    enqueue(u);
    int current;

    while(front!=-1 && rear!=-1){
        current=dequeue();
        printf("%d->",current);
        temp=vertices[current];
        while(temp){
            if(!visited[temp->data]){
                visited[temp->data]=1;
                enqueue(temp->data);
            }
            temp=temp->next;
        }

    }
}

int main(){
    int n;
    printf("enter the total number of nodes");
    scanf("%d",&n);
    int i,c;
    for(i=1;i<=n;i++){
        vertices[i] =(struct node *)malloc(sizeof(struct node));
        vertices[i]->data = i;
        vertices[i]->next = NULL;
        head = vertices[i];
        printf("Enter the adjacent nodes to the vertex %d enter 0 to go to next",i);
        do{
            scanf("%d",&c);
            if(c!=0){
                temp = (struct node *)malloc(sizeof(struct node));
                temp->data = c;
                temp->next = NULL;
                head->next = temp;
                head = temp;
            }
        } while(c!=0);
    }
    int startnode;
    printf("\nEnter the start vertex\n");
    scanf("%d", &startnode);
    printf("\nBreadth first traversal from node %d\n", startnode);
    bfs(startnode);

    printf("\n");

}
