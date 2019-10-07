#include<stdlib.h>
#include<stdio.h>
int arr[10];
int top = -1;
void push(int ele){
	arr[++top] = ele;
}
int top(){
	return arr[top];
}
void pop(){
	top--;
}
int empty(){
	if(top == -1)
		return 1;
	else
		return 0;
}
void span(int price[],int days[], int n){
	push(0);
	days[0] = 1;
	for(int i = 1; i < n; i++){
		while(!empty() && price[top()] <= price[i])
			pop();
    days[i] = empty() ? (i + 1) : (i - top());
    push(i);
    }
}
void print(int days[], int n){
	for(int i = 0; i < n; i++)
		printf("%d\n", days[i]);
}
int main(){
	int price[6] = {10, 4, 5, 90, 120, 80};
	int days[6];
	span(price,days,6);
	print(dats,6);
	return 0;
}