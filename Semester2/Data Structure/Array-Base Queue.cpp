#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

const int MAX = 10000;

struct queue_record {
	int capacity;
	int front;
	int rear;
	int size;
	double buffer[MAX];
};

typedef struct queue_record *Queue;

Queue createQueue(int capacity){
	Queue Q;
	if (capacity <= 0){
		printf("Capacity must be bigger than 0!");
	}
	Q = (Queue)malloc(sizeof(struct queue_record));
	if (Q == NULL){
		printf("Errror: Out of space!");
	}
	Q->capacity = capacity;
	Q->rear = -1;
	Q->front = 0;
	return Q;
}

int isEmpty(Queue Q){
	return (Q->size == 0);
}

int isFull(Queue Q){
	return (Q->size == Q->capacity);
}

int succ(Queue Q, int position){
	if (++position == Q->capacity){
		position = 0;
	}
	return position;
}

void Enqueue(Queue &Q, double x){
	if (isFull(Q)){
		printf("Queue is full!\n");
	}
	else {
		Q->rear = succ(Q, Q->rear);
		Q->buffer[Q->rear] = x;
		Q->size++;
	}
}

void Dequeue(Queue &Q){
	if (isEmpty(Q)){
		printf("Queue is empty!\n");
	}
	else {
		Q->front = succ(Q, Q->front);
		Q->size--;
	}
}

double front(Queue Q){
	if (isEmpty(Q)){
		printf("Queue is empty!\n");
	}
	else {
		return Q->buffer[Q->front];
	}
}

void make_null(Queue &Q){
	Q->front = 0;
	Q->rear = -1;
	Q->size = 0;
}

void showQueue(Queue Q){
	if (isEmpty(Q)){
		printf("Queue is empty!\n");
	}
	else {
		Queue tmp = Q;
		for (int i = 0; i < tmp->size; i++){
			printf("%lf ", tmp->buffer[tmp->front]);
			tmp->front = succ(Q, Q->front);
		}
	}
}

int main(){
	Queue Q = createQueue(5);
	for (int i = 1; i <= 5; i++){
		Enqueue(Q, i);
	}
	for (int i = 1; i <= 3; i++){
		Dequeue(Q);
	}
	make_null(Q);
	for (int i = 1; i <= 3; i++){
		Enqueue(Q, i);
	}
	printf("%lf\n", front(Q));
	showQueue(Q);
	return 0;
}
