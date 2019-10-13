#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int items[100];
	int rear;
	int front;
};
typedef struct queue que;

void enqueue(que *);
void dequeue(que *);
int isfull(que *);
int isempty(que *);
void traverse(que *);
void create(que *);

int main()
{
	que q;
	int ch;
	int flag=1;
	create(&q);
	
	do
	{
		printf("\n\nMenu:\n");
		printf("\n1. Enqueue");
		printf("\n2. Dequeue");
		printf("\n3. Traverse");
		printf("\n4. Exit");
		printf("\n\nChoice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue(&q);
				break;
			case 2:
				dequeue(&q);
				break;
			case 3:
				traverse(&q);
				break;
			default:
				flag=0;
		}
	}while(flag==1);
	system("pause");
	return 0;
}

void create(que *q)
{
	q->rear=-1;
	q->front=0;
}

int isfull(que *q)
{
	if(q->rear==99)
		return 1;
	else
		return 0;
}

int isempty(que *q)
{
	if(q->rear<q->front)
		return 1;
	else
		return 0;
}

void enqueue(que *q)
{
	int x;
	if(isfull(q))
		printf("Queue is Full!!!");
	else
	{
		q->rear++;
		printf("Enter an element: ");
		scanf("%d",&x);
		q->items[q->rear]=x;
	}
}

void dequeue(que *q)
{
	int x;
	if(isempty(q))
		printf("Queue is Empty!!!");
	else
	{
		x=q->items[q->front];
		q->front++;
		printf("%d is removed.",x);
	}
}

void traverse(que *q)
{
	int i;
	if(isempty(q))
		printf("No elements. Queue Empty");
	else
	{
		for (i=q->front;i<=q->rear;i++)
		{
			printf("%d\t",q->items[i]);
		}
	}
}
