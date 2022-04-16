// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* GetNewNode(int data){
    struct BstNode* newNode;
    newNode = malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BstNode* Insert(struct BstNode* root, int data){
    if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}

void inorder(struct BstNode* root)
{
    if(root!=NULL) // checking if the root is not null
    {
        inorder(root->left); // visiting left child
        printf(" %d ", root->data); // printing data at root
        inorder(root->right);// visiting right child
    }
}


int main() {
    // Write C code here
    struct BstNode* root = NULL;
    root = Insert(root,33);
    root = Insert(root,6);
    root = Insert(root,53);
    root = Insert(root,14);
    root = Insert(root,27);
    root = Insert(root,10);
    root = Insert(root,45);
    root = Insert(root,65);
    inorder(root);
    return 0;
}