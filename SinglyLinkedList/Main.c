#include <stdio.h>
#include <string.h>

#include "SinglyLinkedList.h"
#include "FrameManager.h"

void list_print_node(void* data);

//int main() {
//	List list;
//
//	list_init(&list, NULL);
//
//	int item1 = 12, item2 = 44, item3 = 78, item4 = 200, item5 = 500;
//
//	list_append(&list, &item1, sizeof(int));
//	Node* inMiddleNode = list_append(&list, &item2, sizeof(int));
//	Node* beforeLastNode = list_append(&list, &item3, sizeof(int));
//	Node* lastNode = list_append(&list, &item5, sizeof(int));
//
//	list_insert_next(&list, inMiddleNode, &item4, sizeof(int));
//
//	list_insert_next(&list, list.head, &item1, sizeof(int));
//
//	printf("List Size: %lu\n", list_size((&list)));
//
//	list_traverse(&list, list_print_node);
//	printf("\n");
//
//	list_unshift(&list);
//
//	int* outData = NULL;
//	list_rm_next(&list, beforeLastNode, &outData);
//
//	list_traverse(&list, list_print_node);
//
//	printf("List Size: %lu\n", list_size((&list)));
//
//	Node* head = list_head((&list));
//
//	printf("head value: %d\n", *((int*)head->data));
//
//	printf("%d\n", list_is_head(&list, lastNode));
//
//	int* value = (int*)(list_data(beforeLastNode));
//	printf("Data: %d\n", *(value));
//
//	Node* node = list_next(inMiddleNode);
//	printf("Data: %d\n", *((int*)list_data(node)));
//
//	list_destroy(&list);
//}

void list_print_node(void* data) {
	printf("%d\n", *((int*)data));
}

int main() {
	List frames;
	int frame_number = 122;
	list_insert_next(&frames, NULL, &frame_number, sizeof(frame_number));

	int result = alloc_frame(&frames);

	printf("%d\n", result);

	list_destroy(&frames);
}