#include <stdio.h>
#include <stdlib.h>

struct ElementType {
	char* name;
	int ID;
};
typedef struct ElementType Student;

struct Node {
	Student Value;
	struct Node *next;
};

typedef struct Node *List;
typedef struct Node *Position;

void Insert(List *pL, Student E, Position P)
{
	Position newItem;
	newItem = (struct Node *)malloc(sizeof(struct Node));
	newItem->Value = E;
	if (pL == NULL || P == NULL) { //insert at head of list
		newItem->next = *pL;
		*pL = newItem; 
	}
	else { // insert newItem after the node pointed to by P
		newItem->next = P->next; 
		P->next = newItem;
	}
}

Position Find(List pL, Student E)
{
	Position nodeP;
	nodeP = pL;
	
	while (nodeP!= NULL && nodeP->Value.ID != E.ID){
    	nodeP = nodeP->next;
	}
	return nodeP;
}

int main(int argc, char* argv[]){
	List pL = NULL;
	Student std1,std2,std3;
	
	std1.name = "Do Mot";
	std1.ID = 1;
	
	std2.name = "Do Hai";
	std2.ID = 2;
	
	std3.name = "Do Ba";
	std3.ID = 3;
	
	Position p = NULL;
	
	Insert(&pL,std1,p);
	
	p = Find(pL,std1);
	Insert(&pL,std2,p);
	
	Position nodeP;
	nodeP = pL;
	
	while (nodeP != NULL) {
    	printf("Name:%s  ----- ID:%i \n",nodeP->Value.name,nodeP->Value.ID);
    	nodeP = nodeP->next;
	}
	return 0;
}
