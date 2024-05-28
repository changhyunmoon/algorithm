#include "LL_Stack.h"
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int i = 0;
	int cnt = 0;
	Node* Popped;

	LinkedListStack* Stack;
	LLS_CreateStack(&Stack);

	LLS_Push(Stack, LLS_CreateNode("abc"));
	LLS_Push(Stack, LLS_CreateNode("ABC"));
	LLS_Push(Stack, LLS_CreateNode("qwe"));

	return 0;
}