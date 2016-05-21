/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void inOrderTraversal2(struct node *root, int *arr, int *index)
{
	if (root == NULL || arr == NULL) return;
	inOrderTraversal2(root->left, arr, index);
	arr[*index] = root->data;
	printf("%d\n", root->data);
	(*index) = (*index) + 1;
	inOrderTraversal2(root->right, arr, index);

}

struct node *newNode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node_spec(struct node *root, int data){
	if (root == NULL) return newNode(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}
void swap_nodes(struct node *a, struct node *b){
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}
int noOfNodes11(struct node* root)
{
	if (root == NULL)return 0;
	return 1 + noOfNodes11(root->left) + noOfNodes11(root->right);
}
void inOrderTraversal11(struct node *root, struct node *nodeArr, int *index)
{
	if (root == NULL || nodeArr == NULL) return;
	inOrderTraversal11(root->left, nodeArr, index);
	nodeArr[*index] = *root;
	//printf("%d\n", root->data);
	(*index) = (*index) + 1;
	inOrderTraversal11(root->right, nodeArr, index);

}
void fix_bst1(struct node *root){
	if (root != NULL)
	{
		int nodes = noOfNodes11(root);
		struct node *nodeArr = (struct node*)malloc(nodes*sizeof(struct node));
		int index = 0, i;
		inOrderTraversal11(root, nodeArr, &index);

		
		int  index1 = 0;
		int *arr = (int *)malloc(nodes*sizeof(int));
		inOrderTraversal2(root, arr, &index1);


		/*for (i = 0; i < nodes; i++)
			printf("%d\n", nodeArr[i].data);*/
		struct node *first = (struct node*)malloc(sizeof(struct node));
		struct node *second = (struct node *)malloc(sizeof(struct node));
		first->data = NULL; second->data = NULL;
		for (i = 1; i < nodes; i++)
		{
			if (nodeArr[i - 1].data > nodeArr[i].data)
			{
				if (first->data == NULL)
				{
					first->left = nodeArr[i - 1].left;
					first->right = nodeArr[i - 1].right;
					first->data = nodeArr[i - 1].data;
				}
				second->left = nodeArr[i].left;
				second->right = nodeArr[i].right;
				second->data = nodeArr[i].data;
			}
		}
		//printf("%d\n%d\n", first.data, second.data);
		struct node *temp = first;
		first = second;
		second = temp;
	}
}


int main(){

	//Use it for testing ,Creating BST etc
	int nums[10] = { 2, 1, 3 };
	struct node *root = NULL;
	for (int i = 0; i < 3; i++){
		root = add_node_spec(root, nums[i]);
	}
	struct node *swaplist[2];
	int originaldata[2];
	swaplist[0] = root->left;
	swaplist[1] = root->right;
	originaldata[0] = swaplist[0]->data;
	originaldata[1] = swaplist[1]->data;

	swap_nodes(swaplist[0], swaplist[1]);
	fix_bst1(root);
	int nodes = noOfNodes11(root);
	struct node *nodeArr = (struct node*)malloc(nodes*sizeof(struct node));
	int index = 0, i;
	inOrderTraversal11(root, nodeArr, &index);
	for (i = 0; i < nodes; i++)
		printf("%d\n", nodeArr[i].data);
	getchar();
	return 0;
}

