/*
* File: DLL.h
* Author: Sarah Muhammad Rashad
* Created on 13,August,2024 at 8:30 am
*
*/

#ifndef DLL_H
#define	DLL_H

#define NULL ((void*) 0)

typedef unsigned int u32;
typedef int Data;

typedef struct Node
{
	Data data;
	struct Node *next;
	struct Node *prev;
}Node;

typedef struct List
{
	Node *head;
	u32 size;
}List;

typedef enum
{
	false,
	true
}bool;

void createList(List*);
void insertNode(List*, u32, Data);
void deleteNode(List*, u32);
void printList(List*);
void clearList(List*);
u32 searchNode(List*, Data);

#endif /* DLL_H */
