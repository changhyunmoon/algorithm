#include "queue.h"

int main()
{
	int i = 100;
	CircularQueue* Q;

	CREATE_QUEUE(&Q, 10);

	ENQUEUE(Q, 10);
	ENQUEUE(Q, 11);
	ENQUEUE(Q, 12);
	ENQUEUE(Q, 13);

	printf("Dequeue: %d, Front : %d, Rear : %d \n", DEQUEUE(Q), Q->front, Q->rear);
	printf("Dequeue: %d, Front : %d, Rear : %d \n", DEQUEUE(Q), Q->front, Q->rear);
	printf("Dequeue: %d, Front : %d, Rear : %d \n", DEQUEUE(Q), Q->front, Q->rear);

	return 0;
}