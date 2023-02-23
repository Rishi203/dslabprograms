#include<stdio.h>

#define size 100

int stack[size];
int top = -1;
int graph[11][11] = {0};


void push(int data){
    if(top==size-1){
        printf("stack full");
    }
    else{
        stack[++top]=data;
    }
}

int pop(){
    if(top==-1){
        printf("stack empty");
    }
    else{
        return stack[top--];

    }
}

void dfs(int item){
    int visited[11]={0};
    int current;

    push(item);
    
    while(top!=-1){
        current=pop();

        if(visited[current]==0){
            printf("%d->",current);
            visited[current]=1;
        }
        for(int i=0;i<11;i++){
            if(graph[current][i]==1 && visited[i]==0){
                push(i);
            }
        }
    }
}

void addEdge(int u,int v){
    graph[u][v]=1;
    graph[v][u]=1;
}

int main(){
    addEdge(1, 2); 
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(2, 5);
    addEdge(2, 7);
    addEdge(2, 8);
    addEdge(3, 4);
    addEdge(3, 10);
    addEdge(3, 9);
    addEdge(5, 6);
    addEdge(5, 7);
    addEdge(5, 8);
    addEdge(7, 8);
    dfs(1);
}