#include <stdio.h>
#include <stdlib.h>

#define item int

typedef struct BT
{
	item data;
	struct BT *left;
	struct BT *right;
}tnode;


tnode *getNode()
{
	tnode *temp=NULL;
	temp = (tnode *)malloc(sizeof(tnode));
	return temp;
}


void insert(tnode **root, item z)
{
	if(*root == NULL)
	{
		*root = getNode();
		(*root)->data = z;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	
	else if(z<(*root)->data)
	
		insert(&((*root)->left), z);
		
	else
		insert(&((*root)->right),z);
}


//traversals
void preorder(tnode *root)
{
	if(root == NULL)
		return;
		
	else
	{
		if(root!=NULL)
			printf("%d ", root->data);
		
		if(root->left!=NULL)
			preorder(root->left);
			
		if(root->right!=NULL)
			preorder(root->right);
	}
}


void inorder(tnode *root)
{
	if(root == NULL)
		return;
		
	else
	{
		if(root->left!=NULL)
			inorder(root->left);
			
		if(root!=NULL)			
			printf("%d ", root->data);
			
		if(root->right!=NULL)
			inorder(root->right);
	}
}


void postorder(tnode *root)
{
	if(root == NULL)
		return;
		
	else
	{		
		if(root->left!=NULL)
			postorder(root->left);
			
		if(root->right!=NULL)
			postorder(root->right);
			
		if(root!=NULL)
			printf("%d ", root->data);
	}
}

tnode *FindMin(tnode *root)
{
	while(root->left != NULL)
		root = root->left;
		
	return root;
}


/*tnode *search(tnode *root, item z)
{
	if(root == NULL)
		return NULL;
		
	if(z == root->data)
		return root;
	
	if(z<root->data)
		return search(root->left, z);
		
	if(z>root->data)
		return search(root->right, z);

}*/


void delete(tnode **root, item z)
{
	tnode *temp=NULL;	
	
	if(*root==NULL)
		return;
		
	else if(z<(*root)->data)
		delete(&(*root)->left,z);
		
	else if(z>(*root)->data)
		delete(&(*root)->right,z);
		
	else if(z == (*root)->data)
	{
		//if leaf node
		if(((*root)->left== NULL) && ((*root)->right == NULL))
		{
			free(*root);
			*root = NULL;
		}
		
		//has only left child	
		else if(((*root)->left != NULL) && ((*root)->right == NULL))
		{
			temp=*root;
			*root=(*root)->left;
			free(temp);
		}
		
		//has only right child	
		else if(((*root)->right != NULL) && ((*root)->left == NULL))
		{
			temp=*root;
			*root=(*root)->right;
			free(temp);
		}
		
		//has both left child and right child	
		else if(((*root)->right != NULL) && ((*root)->left != NULL))
		{
			//inorder successor of(*root)->right
			temp = FindMin((*root)->right);
			(*root)->data = temp->data;
			delete(&(*root)->right, temp->data);
		}
		
	}
	
	else //node not found
		return;
	
}


int main()
{
	tnode *root=NULL; tnode *temp1=NULL;

	int ch,num;

	
	do
	{		
	
		printf("1.Traverse the list in PreOrder,InOrder and PostOrder.\n2.Insert element into tree.\n3.Delete element from tree.\n4.Search an element in tree.\n\nPress -1 to exit.\n\n");
		
		printf("Enter your choice:");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
				if(root==NULL)
				{
					printf("The tree is Empty.Cannot traverse.\n\n");
					break;
				}
				
				else //tree is not empty
				{
					//PreOrder
					printf("The PreOrder Traversal is: ");
					preorder(root);
					printf("\n\n");
					
					//InOrder
					printf("The InOrder Traversal is: ");
					inorder(root);
					printf("\n\n");
					
					
					//PostOrder
					printf("The PostOrder Traversal is: ");
					postorder(root);
					printf("\n\n");
					
					break;
				}
				
			case 2:
				printf("Enter the element to insert: ");
				scanf("%d", &num);
				insert(&root, num);
				printf("Element has been inserted.\n\n");
				break;
				
			case 3:
				if(root == NULL)
				{
					printf("Tree Empty.Cannot delete.\n\n");
					break;
				}
				
				else
				{
					printf("Enter the item to delete:");
					scanf("%d", &num);
					temp1 = search(root,num);
					if(temp1 == NULL)
					{
						printf("Element not found.\n\n");
						break;
					}
				
					else //element found
					{
						delete(&root, num);
						printf("Element has been deleted.\n\n");
						break;
					}
				}
				
			case 4:
				if(root == NULL)
				{
					printf("Tree Empty.Cannot Search.\n\n");
					break;
				}
				
				else
				{
					printf("Enter the element to search: ");
					scanf("%d", &num);
					temp1=search(root,num);
					
					if(temp1 == NULL)
					{
						printf("Element not found.\n\n");
						break;
					}
					
					else if(temp1->data == num)
					{
						printf("Element %d found.\n\n",temp1->data);
						break;
					}
					
					
				}
		
		
		
		
		
		}
		
		
		

	}while(ch!=-1);
	
	
	return 0;

}







