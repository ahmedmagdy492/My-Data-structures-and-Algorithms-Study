#include "Double_LinkedList_c.h"

void dlist_init(DLinkedList* list, void(*destroy)(void* data)) {
	list->destroy_function = NULL;
	list->destroy_function = destroy;
	list->head = list->tail = NULL;
}

int dlist_prepend(DLinkedList* list, void* data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL)
		return -1;

	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (!list->head) {
		list->head = list->tail = newNode;
	}
	else {
		newNode->next = list->head;
		list->head->prev = newNode;
		list->head = newNode;
	}

	return 0;
}

int dlist_ins_next(DLinkedList* list, Node* node, void* data) {
	if (!list->head)
		return dlist_prepend(list, data);

	if (node == NULL)
		return -1;

	Node* new_node = (Node*)malloc(sizeof(Node));

	if (new_node == NULL)
		return -1;

	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;

	Node* node_next = node->next;
	node->next = new_node;
	new_node->prev = node;
	new_node->next = node_next;
	
	if (node_next) {
		node_next->prev = new_node;
	}

	if (list->head == list->tail) {
		list->tail = new_node;
	}

	return 0;
}

int dlist_ins_prev(DLinkedList* list, Node* node, void* data) {
	if (!list->head || node == list->head)
		return dlist_prepend(list, data);

	if (node == NULL)
		return -1;

	Node* new_node = (Node*)malloc(sizeof(Node));

	if (new_node == NULL)
		return -1;

	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;

	Node* node_prev = node->prev;
	node->prev = new_node;
	new_node->next = node;
	new_node->prev = node_prev;

	if (node_prev) {
		node_prev->next = new_node;
	}

	return 0;
}

int dlist_remove(DLinkedList* list, Node* node, void** data) {
	if (list->head == NULL)
		return -1;

	if (node == NULL)
		return -1;

	if (node == list->head) {
		list->head = list->head->next;
	}

	if (node == list->tail) {
		list->tail = list->tail->prev;
	}

	Node* node_prev = node->prev;
	Node* node_next = node->next;
	*data = node->data;

	if (node_prev) {
		node_prev->next = node_next;
	}
	if (node_next) {
		node_next->prev = node_prev;
	}

	free(node);
	return 0;
}

size_t dlist_size(DLinkedList* list) {
	Node* ptr = list->head;
	size_t size = 0;

	while (ptr) {
		++size;
		ptr = ptr->next;
	}

	return size;
}

Node* dlist_head(DLinkedList* list) {
	return list->head;
}

Node* dlist_tail(DLinkedList* list) {
	return list->tail;
}

int dlist_is_head(DLinkedList* list, Node* node) {
	return list->head == node;
}

int dlist_is_tail(DLinkedList* list, Node* node) {
	return list->tail == node;
}

void* dlist_data(Node* node) {
	return node->data;
}

Node* dlist_next(Node* node) {
	return node->next;
}

Node* dlist_prev(Node* node) {
	return node->prev;
}

void dlist_destroy(DLinkedList* list) {
	Node* ptr = list->head;

	while (ptr) {
		Node* temp = ptr;
		ptr = ptr->next;
		if (list->destroy_function != NULL) {
			list->destroy_function(temp->data);
		}
		free(temp);
	}

	list->head = list->tail = NULL;
}

std::string dlist_to_string(DLinkedList* list) {

	std::stringstream str;

	for (Node* ptr = list->head; ptr; ptr = ptr->next) {
		int value = *((int*)ptr->data);
		if (ptr->next) {
			str << std::to_string(value) << " ";
		}
		else {
			str << std::to_string(value);
		}
	}

	return str.str();
}

void dlist_ensure_integrity(DLinkedList* list) {
	std::cout << std::endl;
	std::cout << "Integrity Check:" << std::endl;
	std::cout << std::endl;

	if (dlist_size(list) == 0) {
		assert(!list->head);
		assert(!list->tail);
	}

	if (dlist_size(list) == 1) {
		assert(list->head == list->tail);
	}

	if (dlist_size(list) > 1) {
		assert(list->head != list->tail);
	}
}