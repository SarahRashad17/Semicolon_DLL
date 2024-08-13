/*
* File: DLL.c
* Author: Sarah Muhammad Rashad
* Created on 13,August,2024 at 8:30 am
* 
*/
#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"

void createList(List* ptrList)
{
	ptrList->head = NULL;
	ptrList->size = 0;
}

void insertNode(List* ptrList, u32 index, Data data)
{
	/* Step1: Check boundaries */
	if(index > ptrList->size)
	{
		printf("Error: Out Of Boundaries\n");
		return;
	}
	
	/* Step2: Create node */
	Node *newNode = malloc(sizeof(Node));
	if(newNode == NULL)
	{
		printf("No Memory Available\n");
	   return;
	}
	/* Step3: Initialize node */
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	/* Step4: check the index */
	if(index == 0)
	{
		newNode->prev = NULL;
		newNode->next = ptrList->head;
		if(ptrList->size != 0) /* if it's not the first node */
		{
			ptrList->head->prev = newNode;
		}
		else {}
		ptrList->head = newNode;
		printf("Book inserted successfully!\n\n");
	}
	
	else if(index == ptrList->size)
	{
		Node *temp = ptrList->head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = NULL;
		printf("Book inserted successfully!\n\n");
	}
	
	else if(index > 0 && index < ptrList->size)
	{
		Node *temp = ptrList->head;
		u32 pos = 0;
		for(pos = 0; pos < index-1; pos++)
		{
			temp = temp->next;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next = newNode;
		(newNode->next)->prev = newNode;
		(ptrList->size)++;
		printf("Book inserted successfully!\n\n");
	}
	else {}
}

void printList(List *ptrList)
{
	Node *temp = ptrList->head;
	while(temp != NULL)
	{
		printf("%i\n", ptrList->data);
		temp = temp->next;
}

void clearList(List *ptrList)
{
	while(ptrList->head != NULL)
	{
		head = head->next;
		free(head->prev);
	}
}

void deleteNode(List *ptrList, u32 index)
{
	/* Step1: Check boundaries */
	if(index >= ptrList->size)
	{
		printf("Error: Out Of Boundaries\n");
		return;
	}
	
	/* Step2: check the index */
	if(ptrList->size == 1)
	{
		free(ptrList->head)
	}
	else if(index == 0)
	{
		ptrList->head = ptrList->head->next;
		free(ptrList->head->prev)
		ptrList->head->prev = NULL;
	}
	else if(index == (ptrList->size)-1)
	{
		Node *temp = ptrList->head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->prev->next = NULL; /* To be more general: temp->prev->next = temp->next */
        free(temp);
	}
	else if(index > 0 && index < (ptrList->size-1))
	{
		Node *temp1 = ptrList->head;
		Node *temp2 = NULL;
		u32 pos = 0;
		for(pos = 0; pos < index-1; pos++)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		temp1->next = temp2->next;
		temp1->next->prev = temp1;
		free(temp2);
	}
	else {}
	ptrList->size--;
}
	
