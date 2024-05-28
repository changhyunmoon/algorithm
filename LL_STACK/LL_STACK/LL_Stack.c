//��ũ�� ����Ʈ�� ������ ����
//���� : ������ �뷮�� ������ ���� �ʾƵ� �ȴ�. 
//������ �迭 ���ð� �޸� ��ũ�� ����Ʈ ������ �ε����� �����Ϳ� ���� �� �� ����.

#include "LL_Stack.h"
#define _CRT_SECURE_NO_WARNINGS

void LLS_CreateStack(LinkedListStack** Stack)
{
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}
void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_Empty(Stack)) {//������ �� ������ �ݺ�
		Node* Popped = LLS_Pop(Stack); //��带 ���ÿ��� ����
		LLS_DestroyNode(Popped);       //���� ����ҿ��� ����
	}
	free(Stack); //������ ���� ����ҿ��� ����
}

Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node)); //���� ����ҿ� ��� �Ҵ�
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);// �Է¹��� ���ڿ��� ũ�⸸ŭ ���� ����ҿ� �Ҵ�
	strcpy(NewNode->Data, NewData);//���� ����ҿ� ���ڿ� ����
	NewNode->NextNode = NULL;//���� ��忡 ���� ������ �ʱ�ȭ
	return NewNode;
}
void LLS_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == NULL) Stack->List = NewNode;
	else {//�ֻ��� ��带 ã�� NewNode�� �����Ѵ�.
		Node* OldTop = Stack->List;
		while (OldTop->NextNode != NULL) {
			OldTop = OldTop->NextNode;
		}
		OldTop->NextNode = NewNode;
	}
	Stack->Top = NewNode;
}
//Pop������ ����
//1. ���� �ֻ��� ����� �ּҸ� �ٸ� �����Ϳ� ������ �д�
//2. ���ο� �ֻ��� ���, �� ���� �ֻ��� ����� �ٷ� ���� ��带 ã�´�.
//3. LinkedListStack ����ü�� Top �ʵ忡 ���ο� �ֻ��� ����� �ּҸ� ����Ѵ�.
//4. 1���� �����Ϳ� �����ص� �� �ֻ��� ����� �ּҸ� ��ȯ�Ѵ�.
Node* LLS_Pop(LinkedListStack* Stack)
{
	//������ �ֻ��� ����� �ּҸ� �ٸ� �����Ϳ� ������ �д�.
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top) {
		Stack->List == NULL;
		Stack->Top = NULL;
	}
	else {//���ο� �ֻ��� �뵵�� ������ top �ʵ忡 ����Ѵ�.
		Node* CurrentTop = Stack->List;
		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top) {
			CurrentTop = CurrentTop->NextNode;
		}
		Stack->Top = CurrentTop;
		CurrentTop->NextNode = NULL;
	}
	return TopNode;
}
Node* LLS_Top(LinkedListStack* Stack)
{
	return Stack->Top;
}
int LLS_GetSize(LinkedListStack* Stack)
{
	int count = 0;
	Node* current = Stack->List;
	while (current != NULL) {
		current = current->NextNode;
		count++;
	}
	return count;
}
int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}
