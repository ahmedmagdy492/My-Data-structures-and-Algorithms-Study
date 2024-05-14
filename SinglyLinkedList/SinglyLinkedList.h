#pragma once

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_ {
	void* data;
	struct Node_* next;
} Node;

typedef struct List_ {
	Node* head;
	size_t count;

	void (*destroy)(void* data);
} List;

void list_init(List* list, void (*destroy)(void* data)) {
	list->count = 0;
	list->head = NULL;

	list->destroy = destroy;
}

void list_destroy(List* list) {
	if (list->head != NULL) {
		 Node* ptr = list->head;
		while (ptr != NULL) {
			 Node* temp = ptr;
			ptr = ptr->next;
			if (list->destroy == NULL) {
				free(temp->data);
			}
			else {
				list->destroy(temp->data);
			}
			free(temp);
		}
		list->head = NULL;
	}
}

Node* list_append(List* list, void* data, size_t dataSizeInBytes) {
	if (list->head == NULL) {
		list->head = (Node*)malloc(sizeof(Node));
		if (list->head == NULL) {
			return NULL;
		}
		list->head->data = malloc(dataSizeInBytes);
		if (list->head->data == NULL) {
			return NULL;
		}
		memcpy(list->head->data, data, dataSizeInBytes);
		++list->count;
		list->head->next = NULL;

		return list->head;
	}
	else {
		Node* ptr = list->head;

		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = ( Node*)malloc(sizeof(Node));
		if (ptr->next == NULL) {
			return NULL;
		}
		ptr->next->data = malloc(dataSizeInBytes);
		if (ptr->next->data == NULL) {
			return NULL;
		}
		memcpy(ptr->next->data, data, dataSizeInBytes);
		++list->count;
		ptr->next->next = NULL;
		return ptr->next;
	}

	return NULL;
}

Node* list_prepend(List* list, void* data, size_t dataSizeInBytes) {
	if (list->head == NULL) {
		list->head = (Node*)malloc(sizeof(Node));
		if (list->head == NULL)
			return NULL;
		list->head->data = malloc(dataSizeInBytes);
		if (list->head->data == NULL)
			return NULL;
		
		memcpy(list->head->data, data, dataSizeInBytes);
		list->head->next = NULL;
		++list->count;
		return list->head;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
		return NULL;
	newNode->data = malloc(dataSizeInBytes);
	if (newNode->data == NULL)
		return NULL;

	memcpy(newNode->data, data, dataSizeInBytes);
	newNode->next = list->head;
	list->head = newNode;
	++list->count;
	return list->head;
}

int list_insert_next(List* list, Node* node, void* data, size_t dataSizeInBytes) {
	if (node == NULL) {
		Node* result = list_prepend(list, data, dataSizeInBytes);
		if (result == NULL) return -1;
		return 0;
	}
		
	Node* newNode = ( Node*)malloc(sizeof( Node));
	if (newNode == NULL)
		return -1;
	newNode->data = malloc(dataSizeInBytes);
	if (newNode->data == NULL)
		return -1;

	memcpy(newNode->data, data, dataSizeInBytes);

	newNode->next = node->next;
	node->next = newNode;
	++list->count;

	return 0;
}

Node* list_unshift(List* list) {
	if (list->head == NULL) 
		return NULL;

	Node* nextOfHead = list->head->next;
	Node* elementToRemove = list->head;
	list->head = nextOfHead;
	--list->count;
	return elementToRemove;
}

int list_rm_next(List* list, Node* node, void** data) {
	if (list->head == NULL)
		return -1;

	if (node == NULL) {
		Node* deletedElement = list_unshift(list);
		if (deletedElement == NULL) {
			return -1;
		}
		*data = deletedElement->data;
		free(deletedElement);
		return 0;
	}

	if (node->next == NULL)
		return -1;

	Node* temp = node->next->next;
	*data = node->next->data;

	if (list->destroy == NULL) {
		free(node->next->data);
	}
	else {
		list->destroy(node->next->data);
	}

	free(node->next);
	node->next = temp;
	--list->count;
	return 0;
}

void list_traverse(List* list, void (*func)(void* data)) {
	 Node* ptr = list->head;

	while (ptr != NULL) {
		func(ptr->data);
		ptr = ptr->next;
	}
}

int list_is_head(List* list, Node* node) {
	return list->head == node;
}

#define list_size(list) (list->count)
#define list_head(list) (list->head)
#define list_data(node) (node->data)
#define list_next(node) (node->next)

#endif