#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
    int data; // ������
    struct tagNode* NextNode; //���� ��带 ����Ű�� ������
}Node;

Node* SLL_CreateNode(int Data) {//��� ����
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = Data;
    NewNode->NextNode = NULL;
    return NewNode;
}
void SLL_DestroyNode(Node* Node) {//��� �Ҹ�
    free(Node);
}
void SLL_AppendNode(Node** HEAD, Node* NewNode) {//��� �߰�
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
Node* SLL_GetNode(Node* HEAD, int Location) {//Ž���� �����ϴ� �Լ�
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

    NewNode = SLL_CreateNode(10); //���� ����ҿ� ��� ����
    SLL_AppendNode(&List, NewNode); //������ ��带 ����Ʈ�� �߰�

    NewNode = SLL_CreateNode(11); //���� ����ҿ� ��� ����
    SLL_AppendNode(&List, NewNode); //������ ��带 ����Ʈ�� �߰�

    NewNode = SLL_CreateNode(12); //���� ����ҿ� ��� ����
    SLL_AppendNode(&List, NewNode); //������ ��带 ����Ʈ�� �߰�

    show_list(&List);
    return 0;
}
