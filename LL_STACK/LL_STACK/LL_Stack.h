//#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tafNode {
	char* Data;//자유 저장소에 저장된 문자열 주소를 가리킨다.
	struct tagNode* NextNode; //자기 위에 쌓여있는 노드의 주소를 가리킨다.
}Node;
typedef struct tagLinkedListStack {
	Node* List; //스택이 기반하고 있는 링크드 리스트에 접근할 수 있게 노드의 주소를 가지고 있다.
	Node* Top; //최상위 노드에 대한 정보를 유지
}LinkedListStack;

void LLS_CreateStack(LinkedListStack** Stack);
void LLS_DestroyStack(LinkedListStack* Stack);

Node* LLS_CreateNode(char* NewData);
void LLS_DestroyNode(Node* _Node);

void LLS_Push(LinkedListStack* Stack, Node* NewNode);
Node* LLS_Pop(LinkedListStack* Stack);

Node* LLS_Top(LinkedListStack* Stack);
int LLS_GetSize(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);