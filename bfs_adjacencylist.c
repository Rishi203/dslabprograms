int size = 100;
int queue[size];
int front=-1;rear=-1;

struct node{
    int data;
    struct node*next;
}

struct node* vertices[100],*temp, *head;





void enqueue(int item){
    if(rear==size-1){
        printf("queue full")
    }
    else{
        if(front==-1){
            front=0;
            queue[++rear]=item;
        }
    }
}
int dequeue(){
    if(front==-1){
        printf("queue empty")
    }
    else{
        return queue[front]
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=front+1;
        }
    }
}

void bfs(int u){
    int visited[100]={0};

    visited[u]=1;
    enqueue[u];
    int current;

    while(front!=-1 && rear!=-1){
        v=dequeue();
        printf("%d->",v);
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
    

}
