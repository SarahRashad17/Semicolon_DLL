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
		if(ptrList->head != NULL) /* if it's not the first node */
		{
			ptrList->head->prev = newNode;
		}
		else {}
		ptrList->head = newNode;

		(ptrList->size)++;
		printf("Node inserted successfully!\n\n");
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

		(ptrList->size)++;
		printf("Node inserted successfully!\n\n");
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
		printf("Node inserted successfully!\n\n");
	}
	else {}
}

void printList(List *ptrList)
{
	Node *temp = ptrList->head;
	int i = 0;
	while(temp != NULL)
	{
		printf("%i\n", temp->data);
		printf("%p\n", temp->next);
		temp = temp->next;
	}
}

void clearList(List *ptrList)
{
	Node *temp = ptrList->head;
	while(temp != NULL)
	{
		ptrList->head = temp->next;
		free(temp);
		temp=ptrList->head;
		ptrList->size--;
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
		free(ptrList->head);
	}
	else if(index == 0)
	{
		ptrList->head = ptrList->head->next;
		free(ptrList->head->prev);
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
	else if(index > 0 && index < (ptrList->size)-1)
	{
		Node *temp = ptrList->head;
		u32 pos = 0;
		for(pos = 0; pos < index; pos++)
		{
			temp = temp->next;
		}
		(temp->next)->prev = temp->prev;
		(temp->prev)->next = temp->next;
		free(temp);
	}
	else {}
	ptrList->size--;
}

