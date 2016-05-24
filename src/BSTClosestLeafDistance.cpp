/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

void minimumHeightFromTemp(struct node *root, int level, int *minimumDistance)
{
	
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
	{
		if (level < (*minimumDistance))
			*minimumDistance = level;
		return;
	}
	minimumHeightFromTemp(root->left, level + 1, minimumDistance);
	minimumHeightFromTemp(root->right, level + 1, minimumDistance);
}

int minDistOnOtherSideOfParent(struct node * root, struct node *x, int *minimumDistance)
{
	if (root == NULL) return -1;
	if (root == x) return 0;
	int l = minDistOnOtherSideOfParent(root->left, x, minimumDistance);
	if (l != -1)
	{
		minimumHeightFromTemp(root->right, l + 2, minimumDistance);
		return l + 1;
	}
	int r = minDistOnOtherSideOfParent(root->right, x, minimumDistance);
	if (r != -1)
	{
		minimumHeightFromTemp(root->left, r + 2, minimumDistance);
		return r + 1;
	}

	return -1;
}
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (temp == NULL || root == NULL)return -1; 
	int minimumDistance = 1000;
	minimumHeightFromTemp(temp, 0, &minimumDistance);
	minDistOnOtherSideOfParent(root, temp, &minimumDistance);
	return minimumDistance;
}
