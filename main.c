#include <stdio.h>
#include "DLL.h"

int main()
{
	List L1;
	createList(&L1);
	insertNode(&L1,0,10);
	insertNode(&L1,0,20);
	insertNode(&L1,0,30);
	insertNode(&L1,0,40);
	insertNode(&L1,0,50);
	insertNode(&L1,1,60);

	printList(&L1);
	printf("--------------------");

	deleteNode(&L1,0);
	printList(&L1);
	deleteNode(&L1,4);
	printList(&L1);
    deleteNode(&L1,2);
	printList(&L1);
	printf("%d\n",L1.size);

	clearList(&L1);
	printf("After clear: ");
	printList(&L1);
	printf("%d\n", L1.size);
	return 0;
}
