#include <stdio.h>
#include <stdlib.h>

#include "linked_List.h"

LinkedList* createList(void){
	LinkedList* list = malloc(sizeof(LinkedList));

	list -> head = NULL;
	list -> tail = NULL;

	list -> number_Of_Elements = 0;
	return list;
}

Node* createNode(void* data){
    Node* node = malloc(sizeof(Node));

    node -> data = data;
    node -> next = NULL;

    return node;
}

int isEmpty(LinkedList* list){
	return (list -> number_Of_Elements == 0);
}

void addToHead(LinkedList* list, void* data){
	Node* node = createNode(data);

	if (list -> number_Of_Elements == 0){
		list -> head = node;
		list -> tail = node;

	}
	else{
		node -> next = list -> head;
		list -> head = node;
	}

	(list -> number_Of_Elements)++;
}

void addToTail(LinkedList* list, void* data){
	Node* node = createNode(data);

	if (list -> number_Of_Elements == 0){
		list -> head = node;
		list -> tail = node;
	}
	else{
		list -> tail -> next = node;
		list -> tail = node;
	}

	(list -> number_Of_Elements)++;
}

void addToIndex(LinkedList* list, int index, void* data){
	if (index == 0){
		addToHead(list, data); 
		return;
	}

	if (index == -1 || index > list -> number_Of_Elements){
		addToTail(list, data); 
		return;
	}


	Node* node = createNode(data);

	Node* temp = list -> head;

	for (int i = 1; i < index; i++){
		temp = temp -> next;
	}

	node -> next = temp -> next;
	temp -> next = node;

	(list -> number_Of_Elements)++;
}

void removeFromHead(LinkedList* list){
	if (isEmpty(list)) return;

	Node* temp = list -> head;

	if (list -> number_Of_Elements == 1){
		free(temp);
	}
	else{
		list -> head = list -> head -> next;
		free(temp);
	}

	(list -> number_Of_Elements)--;
}

void removeFromTail(LinkedList* list){
	if (isEmpty(list)) return;

	Node* temp = list -> tail;

	if (list -> number_Of_Elements == 1){
		free(temp);
	}
	else{
		Node* node;
		for (node = list -> head; node -> next != list -> tail; node = node -> next);

		list -> tail = node;
		free(temp);
	}
	(list -> number_Of_Elements)--;
}

void removeFromIndex(LinkedList* list, int index){
	if (index == 0){
		removeFromHead(list); 
		return;
	}

	if (index == -1 || index > list -> number_Of_Elements){
		removeFromTail(list); 
		return;
	}

	Node* node = list -> head;

	for (int i = 1; i < index; i++){
		node = node -> next;
	}

	Node* temp = node -> next;

	node -> next = temp -> next;
	free(temp);

	(list -> number_Of_Elements)--;
}

void* getElement(LinkedList* list, int index){
	if (index == 0) return list -> head -> data;
	if (index == -1) return list -> tail -> data;

	if (index > list -> number_Of_Elements) return NULL;

	Node* temp = list -> head;

	for (int i = 0; i < index; i++){
		temp = temp -> next;
	}

	return temp -> data;
}

void printList(LinkedList* list){
	if (isEmpty(list)) return;

	Node* temp = list -> head;

	while (1){
		printf("Element %p\n", temp -> data);

		if (temp -> next == NULL) break;

		temp = temp -> next;
	}
}

void emptyList(LinkedList* list){
	Node* current_Node = list -> head;

	while (current_Node != NULL){
		Node* temp = current_Node;
		
		current_Node = current_Node -> next;

		free(temp);
	}
}

void freeList(LinkedList* list){
	emptyList(list);
	free(list);
}
