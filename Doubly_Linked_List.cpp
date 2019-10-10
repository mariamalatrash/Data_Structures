#include <stdio.h> 
#include <stdlib.h>  
struct Node {
	int data;
	struct Node* next;  
	struct Node* prev; 
};
struct Node *head;
struct Node *tail;
struct Node *CreateNewNode(int x){
	struct Node* newNode = new Node;
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
void InsertAtHead(int n) {
	struct Node* tmp = new Node;
	tmp->data = n;
	tmp->prev = NULL;
	tmp->next = head;
	head = tmp;
	

}
void Append(int n) {
	struct Node* tmp = new Node;
	tmp->data = n;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (head == NULL) {
		head = tmp;
		tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tail->next;
	}
}

void Print() {
	struct Node* nod = head;
	while (nod != NULL) {
		printf("%d->", nod->data);
		nod = nod->next;
	}
	printf("\n");
}
bool isEmpty() {
	struct Node* nod = new Node;
	nod->prev = NULL;
	nod->next = NULL;
	if (head == NULL) {
		return true;
		
	}
	return false;

}
int length() {
	struct Node* tmp = head;
	int count = 0;
	while (tmp != NULL) {
		count += 1;
		tmp = tmp->next;
	}
	return count;
}
int main() {
	head = NULL;
	InsertAtHead(4);
	InsertAtHead(5);
	InsertAtHead(6);
	InsertAtHead(7);
	printf("length:""%d""\n",length());
	Print();
	getchar();


}