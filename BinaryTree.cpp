#include <stdio.h> 
#include <stdlib.h> 
struct node
{
	int key_value;
	node *left;
	node *right;
};

void Insert(int key, node *&leaf)
{
	if (leaf == NULL)
	{
		leaf = new node;
		leaf->key_value = key;
		leaf->left = NULL;
		leaf->right = NULL;
	}
	else
	{
		if (key < leaf->key_value)
		{
			Insert(key, leaf->left);
		}
		else if (key >= leaf->key_value)
		{
			Insert(key, leaf->right);
		}
	}
}
void Destroy_tree(node *&leaf)
{
	if (leaf != NULL)
	{
		Destroy_tree(leaf->left);
		Destroy_tree(leaf->right);
		delete leaf;
	}
}

node *Search(int key, node *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->key_value)
			return leaf;
		if (key < leaf->key_value)
			return Search(key, leaf->left);
		else
			return Search(key, leaf->right);
	}
	else return NULL;
}
node *SearchMin(node* leaf) {
	if (leaf != NULL) {
		if (leaf->left == NULL)
			return leaf;
		return SearchMin(leaf->left);
	}
	return NULL;
}
node *SearchMax(node* leaf) {
	if (leaf != NULL) {
		if (leaf->right == NULL)
			return leaf;
		return SearchMax(leaf->right);
	}
	return NULL;
}
node *GetParent(int x, node* leaf) {
	if (leaf->key_value == x) {
		return NULL;
	}

	if (leaf->left != NULL && leaf->left->key_value == x || leaf->right != NULL && leaf->right->key_value == x)
		return leaf;
	if (leaf->left != NULL && leaf->key_value > x)
		return GetParent(x, leaf->left);
	return GetParent(x, leaf->right);
}
int main()
{
	node *root = NULL;
	Insert(10, root);
	Insert(6, root);
	Insert(14, root);
	Insert(5, root);
	Insert(8, root);
	Insert(11, root);
	Insert(18, root);
	printf("min: %d\n", SearchMin(root)->key_value);
	printf("max: %d\n", SearchMax(root)->key_value);
	printf("parent of 14: %d\n", GetParent(14, root)->key_value);

	getchar();
}


