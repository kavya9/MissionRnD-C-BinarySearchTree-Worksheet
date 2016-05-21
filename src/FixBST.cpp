/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
/*void findMisplacedNodes(struct node*root,struct node*previous,struct node*firstElement,struct node*secondElement)
{
	if (root == NULL) return;
	findMisplacedNodes(root->left, previous, firstElement, secondElement);
	if (previous != NULL)
	{
		if (previous->data > root->data)
		{
			if (firstElement == NULL)
			{
				firstElement = previous;
			}
			secondElement = root;
		}
	}
	previous = root;
	findMisplacedNodes(root->right, previous, firstElement, secondElement);

}*/
int noOfNodes1(struct node* root)
{
	if (root == NULL)return 0;
	return 1 + noOfNodes1(root->left) + noOfNodes1(root->right);
}
void inOrderTraversal1(struct node *root, struct node **nodeArr, int *index)
{
	if (root == NULL || nodeArr == NULL) return;
	inOrderTraversal1(root->left, nodeArr, index);
	nodeArr[*index] = root;
	(*index) = (*index) + 1;
	inOrderTraversal1(root->right, nodeArr, index);

}
void fix_bst(struct node *root){
	/*struct node *previous=NULL, *firstElement=NULL, *secondElement=NULL;
	if (root != NULL)
	{
		findMisplacedNodes(root, previous, firstElement, secondElement);
		int temp = firstElement->data;
		firstElement->data = secondElement->data;
		secondElement->data = temp;
	}*/
	if (root != NULL)
	{
		int nodes = noOfNodes1(root),i;
		struct node **nodeArr = (struct node**)malloc(nodes*sizeof(struct node*));
		int index = 0;
		inOrderTraversal1(root, nodeArr, &index);
		struct node *first, *second;
		first = NULL; second = NULL;
		int flag = 0;
		for (i = 1; i < nodes; i++)
		{
			if (nodeArr[i - 1]->data > nodeArr[i]->data)
			{
				if (first == NULL)
				{
					first = nodeArr[i - 1];
				}
				second = nodeArr[i];
			}
		}
		
		int num;
		num = first->data;
		first->data = second->data;
		second->data = num;


	}
}
