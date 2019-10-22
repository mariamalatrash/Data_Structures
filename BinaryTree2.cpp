#include <stdio.h> 
#include <stdlib.h> 
struct Node
{
	int data_value;
	Node *left;
	Node *right;
};
struct Node* CreatNewNode(int data){
	struct Node* node = new Node;
	node->data_value = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
struct Node* Insert(Node *&node,int data)
{
	if (node == NULL) {
		return(CreatNewNode(data));
	}
	else
	{
		if (data <= node->data_value)
		{
			node->left = Insert(node->left, data);
		}
		else
		{
			node->right = Insert(node->right, data);
		}
		return node;
	}
}
struct Node* Search(Node *&node, int data) {
	if (node != NULL)
	{
		if (data == node->data_value)
			return node;
		if (data < node->data_value)
			return Search(node->left ,data);
		else
			return Search(node->right, data);
	}
	return NULL;
}
struct Node*  MinValue(Node* node) {
	if (node != NULL) {
		if (node->left == NULL)
			return node;
		return MinValue(node->left);
	}
	return NULL;
}
struct Node* MaxValue(Node* node) {
	if (node != NULL) {
		if (node->right == NULL)
			return node;
		return MaxValue(node->right);
	}
	return NULL;
}
void PrintInorder(struct Node *node) {
	if (node != NULL) {
		PrintInorder(node->left);
		printf("%d ", node->data_value);
		PrintInorder(node->right);
	}

}
void PrintPostorder(struct Node *node) {
	if (node != NULL) {
		PrintInorder(node->left);
		PrintInorder(node->right);
		printf("%d ", node->data_value);
	}

}
void PrintPreorder(struct Node *node) {
	if (node != NULL) {
		printf("%d ", node->data_value);
		PrintInorder(node->left);
		PrintInorder(node->right);
		
	}

}
int MaxDepth(struct Node *node) {
	if (node == NULL || node->left == NULL || node->right == NULL)
		return 0;
	int left = 1 + MaxDepth(node->left);
	int right = 1 + MaxDepth(node->right);
	if (left > right)
		return left;
	else
		return right;
	
}
int main(struct Node *node) {
	Node *root = NULL;
	root=Insert(root,2);
	Insert(root,8);
	Insert(root,1);
	Insert(root, 9);
	Insert(root, 5);
	Insert(root, 4);
	PrintInorder(root);
	PrintPostorder(root);
	PrintPreorder(root);
	printf("Max Depth :%d",MaxDepth(root));
	printf("\nSearch : %d\n",Search(root,8)->data_value);
	printf("Min Value : %d\n", MinValue(root)->data_value);
	printf("Max Value : %d\n", MaxValue(root)->data_value);
	getchar();
}
