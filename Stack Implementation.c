#include<stdio.h>
#include<stdlib.h>
int top=0;
int stack[];
void traverse();
void peek();
void pop();
void push();
int isFull();
int isEmpty();

void main(){
int i=0,data,n=0;
printf("Enter The Size:\n");
scanf("%d",&n);
while(1){
    printf("1: Push\n2: Pop\n3: Peek\n4: Traverse\n5: Exit\n");
    scanf("%d",&i);
    switch(i){
    case 1: {
            printf("Enter The Data\n");
            scanf("%d",&data);
            push(data,n);
            break;
        }
    case 2: {
            pop();
            break;
        }
    case 3:{
            peek();
            break;
        }
    case 4:{
            traverse();
            break;
        }
    case 5:{
            exit(0);
        }
    default: printf("Come Again!!");
        }
    }
}
void push(int data, int n){
if(isFull(n+1)){
    printf("Stack is Full\n\n");
    }
else{
    stack[++top]=data;
    printf("\n%d is pushed\n\n",data);
    }
}

int isFull(int n){
    return (top==n-1)?1:0;
}

void pop(){
int data;
if(isEmpty()){
    printf("Stack is Empty\n");
    }
else{
        if(top==0){
            printf("Stack is Empty\n");
        }
        else{
            data=stack[top--];
            printf("%d is popped\n",data);
        }
    }
}

int isEmpty(){
    return (top==-1)?1:0;
}

void peek(){
    if(isEmpty()){
        printf("Cannot Peek Further\n");
    }
    else{
        printf("Peek = %d\n",stack[top]);
    }
}

void traverse(){
    int i;
    if(isEmpty()){
        printf("Cannot be Traversed\n");
    }
    else{
        for(i=top;i>0;i--){
            printf("%d ",stack[i]);
        }
        printf("\n\n");
    }
}
