/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inOrderTraversal(struct node *root, int *arr, int *index)
{
	if (root == NULL || arr==NULL) return;
	inOrderTraversal(root->left, arr, index);
	arr[*index] = root->data;
	(*index) = (*index) + 1;
	inOrderTraversal(root->right,arr, index);

}
void preOrderTraversal(struct node *root, int *arr, int *index)
{
	if (root == NULL || arr==NULL) return;
	arr[*index] = root->data;
	(*index) = (*index) + 1;
	preOrderTraversal(root->left, arr, index);
	preOrderTraversal(root->right, arr, index);

}
void postOrderTraversal(struct node *root, int *arr, int *index)
{
	if (root == NULL || arr==NULL) return;
	postOrderTraversal(root->left, arr, index);
	postOrderTraversal(root->right, arr, index);
	arr[*index] = root->data;
	(*index) = (*index) + 1;
}
void inorder(struct node *root, int *arr){
	int  index = 0;
	inOrderTraversal(root, arr, &index);
}
void preorder(struct node *root, int *arr){
	int  index = 0;
	preOrderTraversal(root, arr, &index);
}
void postorder(struct node *root, int *arr){
	int  index = 0;
	postOrderTraversal(root, arr, &index);
}

