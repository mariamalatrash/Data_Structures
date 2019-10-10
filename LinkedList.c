#include <stdio.h> 
#include <stdlib.h>  
struct Node {
	int data;
	struct Node* next;
};
struct Node *head;
struct Node* insertNode(int n) {
	struct Node* tmp= new Node;
	tmp->data = n;
	tmp->next = head;
	head=tmp;
	return head;
}
void printNode(){
	struct Node *temp = head;
	while (temp != NULL) {
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("\n");

}
int main() {
		head=NULL;
		insertNode(4);
		insertNode(5);
		insertNode(46);
		printNode();
		getchar();


}