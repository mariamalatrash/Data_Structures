#include <iostream>

using namespace std;

bool StackFull(char S[], int top, int len)
{
	return (top == len - 1);
}

bool StackEmpty(char S[], int top)
{
	return (top == -1);
}

void Push(char S[], int& top, int len, char in_chr)
{
	if (StackFull(S, top, len))
		return; //error - overflow
	top++;
	S[top] = in_chr;
}

char Pop(char S[], int& top)
{
	if (StackEmpty(S, top))
		return ' '; //error - underflow
	char result = S[top];
	top--;
	return result;
}
void Enqueue(char S[], int& top, int len, char c) {
	Push(S, top, len, c);
}
char Dequeue(char S[], int& top, int len, char Q[], int& top2) {
	while (!StackEmpty(S, top)) {
		Push(Q, top2,len, Pop(S, top));
	}
	char result=Pop(Q, top2);
	while (!StackEmpty(Q, top2)) {
		Push(S, top, len, Pop(Q, top2));
	}
	return result;
}
int main()
{
	//use const

	//Define Stack
	char S[3];
	char Q[3];
	int top = -1;
	int top2 = -1;
	int len = 3;


	///bool res1 = StackEmpty(S, top);

	///Push(S, top, len, 'a');
	//Push(S, top, len, 'b');
	//char chr = Pop(S, top);
	//printf("%c", chr);
	//printf("%d", S);

	//bool res2 = StackEmpty(S, top);

	///if (res1 && !res2)
	///	printf(" : all is good");
	Enqueue(S,top,len,'a');
	Enqueue(S, top, len,'b');
	Enqueue(S, top, len,'c');
	printf("%c", Dequeue(S, top, len, Q, top2));
	printf("%c", Dequeue(S, top, len, Q, top2));
	printf("%c", Dequeue(S, top, len, Q, top2));
	getchar();
}