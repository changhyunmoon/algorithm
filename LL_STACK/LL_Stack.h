//#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tafNode {
	char* Data;//���� ����ҿ� ����� ���ڿ� �ּҸ� ����Ų��.
	struct tagNode* NextNode; //�ڱ� ���� �׿��ִ� ����� �ּҸ� ����Ų��.
}Node;
typedef struct tagLinkedListStack {
	Node* List; //������ ����ϰ� �ִ� ��ũ�� ����Ʈ�� ������ �� �ְ� ����� �ּҸ� ������ �ִ�.
	Node* Top; //�ֻ��� ��忡 ���� ������ ����
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