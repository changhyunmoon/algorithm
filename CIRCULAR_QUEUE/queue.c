#include "queue.h"


void CREATE_QUEUE(CircularQueue** Queue, int capacity){//ť ����
	//ť�� ��������ҿ� ����
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
	//�Էµ� capacity+1 ��ŭ�ǳ�带 ���� ����ҿ� ����
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (capacity + 1));

	(*Queue)->capacity = capacity;
	(*Queue)->front = 0;
	(*Queue)->rear = 0;
}
void DESTROY_QUEUE(CircularQueue* Queue) {//ť ����
	free(Queue->Nodes);
	free(Queue);
}

//���� ����
void ENQUEUE(CircularQueue* Queue, ElementType Data) {
	int position = 0;
	if (Queue->rear == Queue->capacity + 1) {
		Queue->rear = 0;
		position = 0;
	}
	else position = Queue->rear++;

	Queue->Nodes[position].Data = Data;
}
//���� ����
ElementType DEQUEUE(CircularQueue* queue) {
	int position = queue->front;
	if (queue->front == queue->capacity) queue->front = 0;
	else queue->front++;
	return queue->Nodes[position].Data;
}

int GET_SIZE(CircularQueue* queue){
	if (queue->front <= queue->rear)
		return queue->rear - queue->front;
	else return queue->rear + (queue->capacity - queue->front) + 1;
}
int IS_EMPTY(CircularQueue* queue) {
	return (queue->front == queue->rear);
}
