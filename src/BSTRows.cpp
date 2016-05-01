/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int noOfNodes(struct node* root)
{
	if (root == NULL)return 0;
	return 1 + noOfNodes(root->left) + noOfNodes(root->right);
}
int height(struct node* root)
{
	if (root == NULL) return 0;
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	int max = leftHeight > rightHeight ? leftHeight : rightHeight;
	return max + 1;
}
void BSTLevelByLevel(struct node* root, int level,int *arr,int *index)
{
	if (root == NULL) return;
	if (level == 1)
	{
		arr[*index] = root->data;
		(*index) = (*index) + 1;
	}
	else if (level > 1)
	{
		BSTLevelByLevel(root->right, level - 1, arr, index);
		BSTLevelByLevel(root->left, level - 1, arr, index);
	}

}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL) return NULL;
	int BSTheight = height(root);
	int *arr = (int *)malloc(noOfNodes(root)*sizeof(int));
	int i,index=0;
	for (i = 1; i <= BSTheight; i++)
		BSTLevelByLevel(root, i, arr, &index);
	return arr;
}
