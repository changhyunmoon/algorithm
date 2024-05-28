//링크드 리스트로 구성된 스택
//장점 : 스택의 용량에 제한을 두지 않아도 된다. 
//하지만 배열 스택과 달리 링크드 리스트 스택은 인덱스로 데이터에 접근 할 수 없다.

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
	while (!LLS_Empty(Stack)) {//스택이 빌 때까지 반복
		Node* Popped = LLS_Pop(Stack); //노드를 스택에서 제거
		LLS_DestroyNode(Popped);       //자유 저장소에서 해제
	}
	free(Stack); //스택을 자유 저장소에서 해제
}

Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node)); //자유 저장소에 노드 할당
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);// 입력받은 문자열의 크기만큼 자유 저장소에 할당
	strcpy(NewNode->Data, NewData);//자유 저장소에 문자열 복사
	NewNode->NextNode = NULL;//다음 노드에 대한 포인터 초기화
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
	else {//최상위 노드를 찾아 NewNode를 연결한다.
		Node* OldTop = Stack->List;
		while (OldTop->NextNode != NULL) {
			OldTop = OldTop->NextNode;
		}
		OldTop->NextNode = NewNode;
	}
	Stack->Top = NewNode;
}
//Pop연산의 과정
//1. 현재 최상위 노드의 주소를 다른 포인터에 복사해 둔다
//2. 새로운 최상위 노드, 즉 현재 최상위 노드의 바로 이전 노드를 찾는다.
//3. LinkedListStack 구조체의 Top 필드에 새로운 최상위 노드의 주소를 등록한다.
//4. 1에서 포인터에 저장해둔 옛 최상위 노드의 주소를 반환한다.
Node* LLS_Pop(LinkedListStack* Stack)
{
	//현재의 최상위 노드의 주소를 다른 포인터에 복사해 둔다.
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top) {
		Stack->List == NULL;
		Stack->Top = NULL;
	}
	else {//새로운 최상위 노도를 스택의 top 필드에 등록한다.
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
