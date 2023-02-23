#include<stdio.h>
#include<string.h>

int top=-1;
char stack[100];

void push(char data){
    stack[++top]=data;
}

char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}


int precedence(char ch){
    switch (ch){
        case '$':
            return 4;
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
         return 1;    
        default:
            return -1;
    }
}

int isop(char ch){
    return(ch>='0' && ch<='9' || ch>='A'&& ch<='Z' || ch>='a' && ch<='z');
}

int infixtopostfix(char exp[]){

    int len=strlen(exp);
    char postfix[100];
    int i,k=0;

    for(i=0;i<len;i++){
        if(isop(exp[i])){ 
            postfix[k++]=exp[i];
        }
        else if(exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            while(peek()!='('){
                postfix[k++] = pop();
            }
            pop();
        }
        else{
            if(precedence(exp[i])>precedence(peek())){
                push(exp[i]);
            }
            else{
                while(top!=-1 && precedence(peek())>=precedence(exp[i])){
                    postfix[k++] = pop();
                }
            }
        }
    }
    while(top!=-1){
        postfix[k++]=pop();
    }
    for (int i = 0; i < k; i++){
        printf("%c", postfix[i]);
    }
}

void main(){
    char exp[100];
    printf("\nEnter infix expression without any spaces");
    printf("\nFor unary - or +, use $. eg: a*-b must be entered as a*$b\n\n");
    scanf("%s", &exp);
    infixtopostfix(exp);
    
}