#pragma once

#include <stdlib.h>

#include <iostream>
#include <sstream>
#include <cassert>

typedef struct _Node {
	void* data;
	struct _Node* next;
	struct _Node* prev;
};

typedef struct _Node Node;

struct _DLinkedList {
	struct _Node* head;
	struct _Node* tail;
	void(*destroy_function)(void* data);
};

typedef struct _DLinkedList DLinkedList;

void dlist_init(DLinkedList* list, void(*destroy)(void* data));

int dlist_prepend(DLinkedList* list, void* data);

int dlist_ins_next(DLinkedList* list, Node* node, void* data);

int dlist_ins_prev(DLinkedList* list, Node* node, void* data);

int dlist_remove(DLinkedList* list, Node* node, void** data);

size_t dlist_size(DLinkedList* list);

Node* dlist_head(DLinkedList* list);

Node* dlist_tail(DLinkedList* list);

int dlist_is_head(DLinkedList* list, Node* node);

int dlist_is_tail(DLinkedList* list, Node* node);

void* dlist_data(Node* node);

Node* dlist_next(Node* node);

Node* dlist_prev(Node* node);

void dlist_destroy(DLinkedList* list);

std::string dlist_to_string(DLinkedList* list);

void dlist_ensure_integrity(DLinkedList* list);