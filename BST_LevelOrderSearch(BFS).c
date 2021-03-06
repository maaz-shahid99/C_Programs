/* Binary tree - Level Order Traversal */
#include<stdio.h>
#include<stdlib.h>

struct Node {
	char data;
	struct Node *left;
	struct Node *right;
};

// Function to print Nodes in a binary tree in Level order
void LevelOrder(struct Node *root) {
	if(root == NULL) return;
	queue<Node*> Q;
	Q.push(root);  
	//while there is at least one discovered node
	while(!Q.empty()) {
		struct Node* current = Q.front();
		Q.pop(); // removing the element at front
		printf("%d " , current->data);
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}
// Function to Insert Node in a Binary Search Tree
struct Node* Insert(struct Node *root,char data) {
	if(root == NULL) {
		root = malloc(sizeof(struct Node));
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data) root->left = Insert(root->left,data);
	else root->right = Insert(root->right,data);
	return root;
}

int main() {
	/*Code To Test the logic
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
struct	Node* root = NULL;
	root = Insert(root,'M'); root = Insert(root,'B');
	root = Insert(root,'Q'); root = Insert(root,'Z'); 
	root = Insert(root,'A'); root = Insert(root,'C');
	//Print Nodes in Level Order. 
	LevelOrder(root);
}