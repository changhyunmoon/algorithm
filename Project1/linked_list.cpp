#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
    int data; // 데이터
    struct tagNode* NextNode; //다음 노드를 가리키는 포인터
}Node;

Node* SLL_CreateNode(int Data) {//노드 생성
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = Data;
    NewNode->NextNode = NULL;
    return NewNode;
}
void SLL_DestroyNode(Node* Node) {//노드 소멸
    free(Node);
}
void SLL_AppendNode(Node** HEAD, Node* NewNode) {//노드 추가
    if ((*HEAD) == NULL) {
        *HEAD = NewNode;
    }
    else {
        Node* Tail = (*HEAD);
        while (Tail->NextNode != NULL) {
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
    }
}
Node* SLL_GetNode(Node* HEAD, int Location) {//탐색을 수향하는 함수
    Node* cur_Node = HEAD;
    while (cur_Node != NULL && (--Location) >= 0) {
        cur_Node = cur_Node->NextNode;
    }
    return cur_Node;
}
void SLL_RemoveNode(Node** HEAD, Node* remove_Node) {
    if (*HEAD == NULL) {
        *HEAD = remove_Node->NextNode;
    }
    else {
        Node* cur_Node = *HEAD;
        while (cur_Node != NULL && cur_Node->NextNode != remove_Node) {
            cur_Node = cur_Node->NextNode;
        }
        if (cur_Node != NULL) {
            cur_Node->NextNode = remove_Node->NextNode;
        }
    }

}
void show_list(Node** HEAD) {
    Node* cur_Node = (*HEAD);
    if (*HEAD == NULL) {
        printf("this linked list is empty");
    }
    else {
        while (cur_Node != NULL) {
            printf("%d\n", cur_Node->data);
            cur_Node = cur_Node->NextNode;
        }
            
    }
}

int main() {
    Node* List = NULL;
    Node* NewNode = NULL;

    NewNode = SLL_CreateNode(10); //자유 저장소에 노드 생성
    SLL_AppendNode(&List, NewNode); //생성된 노드를 리스트에 추가

    NewNode = SLL_CreateNode(11); //자유 저장소에 노드 생성
    SLL_AppendNode(&List, NewNode); //생성된 노드를 리스트에 추가

    NewNode = SLL_CreateNode(12); //자유 저장소에 노드 생성
    SLL_AppendNode(&List, NewNode); //생성된 노드를 리스트에 추가

    show_list(&List);
    return 0;
}
