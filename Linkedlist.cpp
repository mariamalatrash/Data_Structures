#include <stdio.h> 
#include <stdlib.h>  
struct Node {
	int data;
	struct Node* next;
};
struct Node *head;
struct Node *tail;
void Append(int n) {
	struct Node* tmp = new Node;
	tmp->data = n;
	tmp->next = head;
	head = tmp;

}
void InsertAtHead(int x) {
	struct Node* tmp = new Node;
	tmp->data = x;
	if (head == NULL) {
		head = tmp;
		tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tail->next;
	}
}

void InsertAtPosition(int x, int index) {
	struct Node* nod = new Node;
	nod->data = x;
	if (index == 1) {
		nod->next = head;
		head = nod;
	}
	else {
		struct Node* tmp = head;
		for (int i = 0;i < index - 1;i++) {
			tmp = tmp->next;
		}
		nod->next = tmp->next;
		tmp->next = nod;


	}

}
void DeleteAtPosition(int index) {}

void Print() {
	struct Node *temp = head;
	while (temp != NULL) {
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("\n");

}
void Reverse() {}
int main() {
	head = NULL;
	tail = NULL;
	insertAtStart(4);
	insertAtStart(5);
	insertAtStart(46);
	insertAT(6,3);
	printNode();
	getchar();


}