/* List* list_initialize(); Initialize linked list


void list_insert_beginning(List* list, int data); Inserts a new node with data at the beginning 


void list_delete_rear(List* list);  Removes the last node of the linked list 

 
void list_print(List* list);  Print the contents of a list


void list_destroy(List* list);  deallocates resources held by the list 
int main() {
	int choice;
	List *list=list_initialize();
	do {
		scanf("%d", &choice);
		switch(choice) {
			int element;
			case 1:
				 Insert an element at beginning of the list 
					scanf("%d", &element);
					list_insert_beginning(list, element);
					break;
			case 2:
				 Remove rear elements  
					list_delete_rear(list);
					break;
			case 3:
				 Print list contents 
				list_print(list);
				break;
			default: 
				list_destroy(list);
				break;
		}
	} while(choice >= 1 && choice < 4);
	getch();
	return 0;
}
*/




#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Initializing list
//Insertion of node at beginning
//Deletion from rear
//Printing the list

typedef struct Node
{
       int data;
       struct Node* next;
}Node;

typedef struct List
{
        Node* head;
        int no_of_nodes;
}List;
      

List* initlist()
{ List *l=(List*)malloc(sizeof(List));
       l->head=NULL;
       l->no_of_nodes=0;
       return l;
}

void insert(List *l,int ele)
{    Node*temp=(Node*)malloc(sizeof(Node));
     temp->data=ele;
     temp->next=NULL;
     if(l->head==NULL)
     { l->head=temp;
     }
     else
     {
         temp->next=l->head;
         l->head=temp;
     }
}     
 
void deletion(List*l)
{    Node* temp=l->head;;                                               
     if(l->head==NULL)
     printf("Empty\n");
     else
		if(temp->next==NULL)
			{printf("\n Node with data:%d has been removed\n",temp->data);
			free(temp);
			l->head=NULL;}
	else	
     {	
		 Node*p=NULL;
         while(temp->next!=NULL)
		{ p=temp;	
		temp=temp->next;
		}
		Node*t=p->next;
		p->next=NULL;
		printf("\n Node with data:%d has been removed\n",t->data);
		free(t);	
		
		
	}
}

void destroy(List*l)
{
	Node*temp=l->head;
	if(l->head==NULL)
	{free(temp);
	printf("\nNothing to delete\n");
	}
	else
	{
		Node*p=NULL;
		while(temp!=NULL)
		{p=temp;
		 temp=temp->next;
		 free(p);
		}
	printf("Success\n");	
	}
	
	
}

void display(List*l)
{
	if(l->head==NULL)
		printf("Empty");
	else
	{
		Node*temp=l->head;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}printf("\n");
}


int main()
{
	int ch;
	List*l=initlist();
	int element;
	printf("1.Insert\n2.Display\n3.Delete\n4.Clear\n");
	
	
	do{	printf("\nEnter choice:");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1:printf("\nEnter element: ");
				   scanf("%d",&element);
					insert(l,element);
					break;

			case 2:printf("\nList is:\n");
				   display(l);
					break;

			case 3:deletion(l);
					break;
			
			case 4:printf("\nClearing memory...");
				   destroy(l);
					break;	
			default:printf("\nClearing memory...");
				   destroy(l);
					break;
			
		}
	}	while(ch>=1 && ch<=4);
	
	return 0;
	getch();
}
	
																		
                                                                      
     
                 
                           
       
