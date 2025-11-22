#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node{
	void* data;
	struct Node* next;

}Node;

typedef struct{
	Node* head;
	Node* tail;

	int number_Of_Elements;
}LinkedList;


LinkedList* createList(void);
Node* createNode(void* data);

int isEmpty(LinkedList* list);

void addToHead(LinkedList* list, void* data);
void addToTail(LinkedList* list, void* data);
void addToIndex(LinkedList* list, int index, void* data);

void removeFromHead(LinkedList* list);
void removeFromTail(LinkedList* list);
void removeFromIndex(LinkedList* list, int index);

void* getElement(LinkedList* list, int index);
void printList(LinkedList* list);
void freeList(LinkedList* list);

#endif
