#include<stdio.h>
#include<stdlib.h>
void push();
struct stack* creatstack();
void display();

struct stack
{
  int info;
  struct stack *link;
};
struct stack *start = NULL;
int count=0;

struct stack* creatstack()
{
struct stack *p;
    p=malloc(sizeof(struct stack));
  
return (p);
}

void pop();
void push()
{
struct stack *temp;
	temp = creatstack();
	count++;
	printf("enter a number");
	scanf("%d",&temp->info);
	temp->link = NULL;
	if(start==NULL)
		start = temp;
	else
	{
		temp->link=start;
		start=temp;
	}

}
void pop()
 {
   struct stack *t;
   int n;
   n = start->info;
   t = start->link;
   free(start);
   start = t;
   count--;
   
   printf("%d poped out successfully.\n", n);
}

void display()
{
  struct stack *temp;
  temp=start;
  printf("There are %d element in stack \n",count);
    
  while (temp->link != NULL) 
  {
      printf("%d\n", temp->info);
      temp = temp->link;
   }
   printf("%d\n", temp->info);
}


int main()
{
	int x;

	for(;;)
	{
		printf("\n1. for insert a element \n");
		printf("2. for pop a element\n");
		printf("3. for display\n");
		printf("4. exit\n");
		scanf("%d",&x);
	

    if(x==1)
    	{ 
    	    push();
    }
   else if(x==2)
    pop();
    	
    else if(x==4)
    	break;
    else if(x==3)
    	display();
    else
    	printf("Enter a valid choice");

}

return 0;
}
