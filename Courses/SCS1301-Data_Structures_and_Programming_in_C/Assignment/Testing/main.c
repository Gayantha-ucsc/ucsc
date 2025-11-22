#include <stdio.h>
#include "linked_List.h"

int main(){
	LinkedList* list = createList();

	int A = 23;
	char B = 'a';
	int C = 9;

	addToHead(list, &A);
	addToHead(list, &B);
	addToHead(list, &C);
	addToTail(list, &A);

	printList(list);
	printf("\n");

	addToIndex(list, 3, &C);
	printList(list);

	printf("Address in index %d is %p\n", 2, getElement(list, 2));
	
	removeFromIndex(list, 2);
	printf("\n");
	printList(list);
	printf("Address in index %d is %p\n", 2, getElement(list, 2));

	return 0;

}
