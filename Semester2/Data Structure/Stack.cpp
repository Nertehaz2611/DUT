#include<stdio.h>
#include<stdlib.h>

struct ElementType{
	double c;
	int e;
};

typedef struct ElementType Element;

struct Node{
	Element value;
	Node* next;
};

typedef struct Node* node_ptr;
typedef node_ptr Stack;

Stack create_stack(void){
	Stack S;
	S = (Stack)malloc(sizeof(struct Node));
	if (S == NULL){
		printf("Out of space!");
	}
	S->next = NULL;
	return S;
}

int isEmpty(Stack S){
	return (S->next == NULL);
}

void push(Stack S, Element e){
	node_ptr node = (node_ptr)malloc(sizeof(struct Node));
	node->value = e;
	node->next = S->next;
	S->next = node;
}

void pop(Stack S){
	S->next = S->next->next;
}

Element top(Stack S){
	Element x = S->next->value;
	return x;
}

int main(){
	Stack S = create_stack();
	for (int i = 0; i <= 10; i++){
		Element x;
		x.e = i;
		push(S, x);
		if (i % 2 == 0){
			pop(S);
		}
	}
	node_ptr p = S->next;
	while (p != NULL){
		printf("%d ", p->value.e);
		p = p->next;
	}
	printf("\n%d", top(S).e);
	return 0;
}


