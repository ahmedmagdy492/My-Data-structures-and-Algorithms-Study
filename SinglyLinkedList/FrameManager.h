#pragma once

#include "SinglyLinkedList.h"

typedef struct _frame {
	void* start_addr;
	size_t frame_size;
} Frame;

int alloc_frame(List* frames) {

	if (list_size(frames) == 0)
		return -1;

	int* data;

	if (list_rm_next(frames, NULL, (void**)&data) != 0) {
		return -1;
	}

	int frame_number = *data;
	free(data);

	return frame_number;
}

int free_frame(List* frames, int frame_num) {
	if (list_insert_next(frames, NULL, (void*)&frame_num, sizeof(int)) != 0)
		return -1;

	return 0;
}