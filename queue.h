#pragma once
#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct tagNode {
	ElementType Data;
}Node;
typedef struct tagCircularQueue { //순환큐를 나타내는 구조체
	int capacity;
	int front;
	int rear;
	Node* Nodes; //노드 배열
}CircularQueue;

void CREATE_QUEUE(CircularQueue** Queue, int capacity);
void DESTROY_QUEUE(CircularQueue* Queue);
void ENQUEUE(CircularQueue* Queue, ElementType Data);
ElementType DEQUEUE(CircularQueue* queue);
int GET_SIZE(CircularQueue* queue);
int IS_EMPTY(CircularQueue* queue);

#endif // !CIRCULAR_QUEUE_H
