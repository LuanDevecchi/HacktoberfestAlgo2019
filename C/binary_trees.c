#include<stdio.h>
#include<stdlib.h>

// structure definition for the nodes of the binary tree
typedef struct tnode {
    int rollNo;
    struct tnode *left, *right;
}tnode;

tnode *createNode(int);
tnode* createTree();
void preorder(tnode*);
void inorder(tnode*);
void postorder(tnode*);

int main() {
    printf("\tTo stop creating nodes at a subtree, enter any negative number as the roll number\n");

    for(int i = 0; i < 100; ++i)
        printf("-");
    printf("\n");

    tnode *root = NULL;
    root = createTree();

    // printing the elements of the tree using preorder method
    printf("The elements of the tree, traversed in preorder\n");
    preorder(root);
    printf("\n");

    // printing the elements of the tree using inorder method
    printf("The elements of the tree, traversed in inorder\n");
    inorder(root);
    printf("\n");

    // printing the elements of the tree using postorder method
    printf("The elements of the tree, traversed in postorder\n");
    postorder(root);
    printf("\n");

    printf("Enter any key to exit...\n");
    getchar();
    return 0;
}

tnode *createNode(int rollNo) {
    tnode *temp = malloc(sizeof(tnode));
    temp -> rollNo = rollNo;
    temp -> left = temp -> right = NULL;
    return temp;
}

tnode* createTree() {
    tnode *node = NULL;
    int rollNo;

    printf("Enter roll number:\n");
    scanf("%d", &rollNo);

    //if roll number is negative then there is no node to add
    if(rollNo < 0) {
        printf("\nNo node created...\n");
        return NULL;
    }

    //create a node for the tree
    node = createNode(rollNo);

    // Left sub tree
    printf("\nCreating left sub-tree of %d:\n", rollNo);
    node -> left = createTree();

    // Right sub tree
    printf("\nCreating right sub-tree of %d:\n", rollNo);
    node -> right = createTree();

    // return address in node to previous function call
    return node;
}

void preorder(tnode *node) {
    if(node != NULL) {
        printf("%d ", node -> rollNo);
        preorder(node -> left);
        preorder(node -> right);
    }
}

void inorder(tnode *node) { 
    if(node != NULL) {
        inorder(node -> left);
        printf("%d ", node -> rollNo);
        inorder(node -> right);
    }
}

void postorder(tnode *node) {
        if(node != NULL) {
        postorder(node -> left);
        postorder(node -> right);
        printf("%d ", node -> rollNo);
    }
}