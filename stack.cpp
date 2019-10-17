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


int main()
{
	//use const

	//Define Stack
	char S[10];
	int top = -1;
	int len = 10;

	bool res1 = StackEmpty(S, top);

	Push(S, top, len, 'a');
	Push(S, top, len, 'b');
	char chr = Pop(S, top);
	printf("%c", chr);
	printf("%d", S);

	bool res2 = StackEmpty(S, top);

	if (res1 && !res2)
		printf(" : all is good");
	getchar();
}