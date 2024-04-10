#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

const int MAX = 100;

struct stack_record {
	int capacity;
	int current;
	double buffer[MAX];
};

typedef struct stack_record *Stack;

Stack createStack(int capacity){
	Stack S;
	if (capacity <= 0){
		printf("Capacity must be bigger than 0!");
	}
	S = (Stack)malloc(sizeof(struct stack_record));
	if (S == NULL){
		printf("Out of space!");
	}
	S->capacity = capacity;
	S->current = -1;
	return S;
}

int isEmpty(Stack S){
	if (S->current == -1) return 1;
	else return 0;
}

int isFull(Stack S){
	if (S->current == S->capacity-1) return 1;
	else return 0;
}

void push(Stack &S, double x){
	if (isFull(S)){
		printf("Stack is full!\n");
	} 
	else {
		S->current++;
		S->buffer[S->current] = x;
	}
}

void pop(Stack &S){
	if (isEmpty(S)){
		printf("Stack is empty!");
	}
	else {
		S->current--;
	}
}

double top(Stack S){
	if (isEmpty(S)){
		printf("Stack is empty!");
	}
	else return S->buffer[S->current];
}

void make_null(Stack &S){
	S->current = -1;
}

void showStack(Stack S){
	while (S->current > -1){
		printf("%lf %d\n", S->buffer[S->current], S->current);
		S->current--;
	}
}

int main(){
	
	return 0;
}

 
