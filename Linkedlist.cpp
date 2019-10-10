#include <stdio.h> 
#include <stdlib.h>  
struct Node {
	int data;
	struct Node* next;
};
struct Node *head;
struct Node *tail;
void InsertAtHead(int n) {
	struct Node* tmp = new Node;
	tmp->data = n;
	tmp->next = head;
	head = tmp;

}
void Append(int x) {
	struct Node* tmp = new Node;
	tmp->data = x;
	tmp->next = NULL;
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
		for (int i = 1; i < index - 1; i++) {
			tmp = tmp->next;
		}
		nod->next = tmp->next;
		tmp->next = nod;


	}

}
void DeleteAtPosition(int index) {
	struct Node* tmp =head;
	Node *del;
	for (int i = 1; i < index - 1; i++) {
		tmp = tmp->next;
	}
	del = tmp->next;
	tmp->next = del->next;
	free(del);
}

void Print() {
	struct Node *nod = head;
	while (nod != NULL) {
		printf("%d->", nod->data);
		nod = nod->next;
	}
	printf("\n");

}
void Reverse(Node* nod) {
	Node* tmp = nod;
	if (tmp != NULL) {
		Reverse(tmp->next);
		printf("%d->", tmp->data);
	}
}
int main() {
	head = NULL;
	tail = NULL;
	Append(4);
	Append(5);
	Append(6);
	Append(7);
	Append(8);
	Print();
	Reverse(head);
	getchar();


}