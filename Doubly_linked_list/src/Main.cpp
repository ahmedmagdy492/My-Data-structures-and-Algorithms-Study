#include <stdio.h>

#include "Double_LinkedList_c.h"

#include <assert.h>

void test_prepend() {
	DLinkedList list;
	
	dlist_init(&list, NULL);

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	dlist_prepend(&list, &value1);
	dlist_prepend(&list, &value2);
	dlist_prepend(&list, &value3);

	std::string expected = "3 2 1";
	std::string actual = dlist_to_string(&list);

	std::cout << "Actual: " << actual << ", expected: " << expected << std::endl;
	assert(expected == actual);

	dlist_ensure_integrity(&list);

	dlist_destroy(&list);
}

void test_dlist_ins_next_with_2_nodes_list() {
	DLinkedList list;

	dlist_init(&list, NULL);

	int value1 = 1;
	int value2 = 2;
	dlist_ins_next(&list, NULL, &value1);
	dlist_ins_next(&list, dlist_head(&list), & value2);

	std::string actual = dlist_to_string(&list);
	std::string expected = "1 2";

	std::cout << "Actual: " << actual << ", expected: " << expected << std::endl;
	assert(expected == actual);

	dlist_ensure_integrity(&list);

	dlist_destroy(&list);
}

void test_dlist_ins_prev_with_3_nodes_list() {
	DLinkedList list;

	dlist_init(&list, NULL);

	int value1 = 1;
	int value2 = 2;
	int value3 = 5;
	dlist_ins_prev(&list, NULL, &value1);
	dlist_ins_prev(&list, dlist_head(&list), &value3);
	dlist_ins_prev(&list, dlist_head(&list)->next, &value2);

	std::string actual = dlist_to_string(&list);
	std::string expected = "5 2 1";

	std::cout << "Actual: " << actual << ", expected: " << expected << std::endl;
	assert(expected == actual);

	dlist_ensure_integrity(&list);

	dlist_destroy(&list);
}

void test_dlist_remove_long_list() {
	DLinkedList list;

	dlist_init(&list, NULL);

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	int value4 = 4;
	int value5 = 5;
	dlist_prepend(&list, &value1);
	dlist_prepend(&list, &value2);
	dlist_prepend(&list, &value3);
	dlist_prepend(&list, &value4);
	dlist_prepend(&list, &value5);

	int* data;
	dlist_remove(&list, dlist_head(&list)->next->next, (void**)& data);

	std::string actual = dlist_to_string(&list);
	std::string expected = "5 4 2 1";

	std::cout << "Actual: " << actual << ", expected: " << expected << std::endl;
	assert(expected == actual);

	dlist_ensure_integrity(&list);

	dlist_destroy(&list);
}

void test_dlist_remove_head_of_list() {
	DLinkedList list;

	dlist_init(&list, NULL);

	int value1 = 1;
	int value2 = 2;
	dlist_prepend(&list, &value1);
	dlist_prepend(&list, &value2);

	int* data;
	dlist_remove(&list, dlist_head(&list), (void**)&data);

	std::string actual = dlist_to_string(&list);
	std::string expected = "1";

	std::cout << "Actual: " << actual << ", expected: " << expected << std::endl;
	assert(expected == actual);

	dlist_ensure_integrity(&list);

	dlist_destroy(&list);
}

void test_dlist_remove_tail_of_list() {
	DLinkedList list;

	dlist_init(&list, NULL);

	int value1 = 1;
	int value2 = 2;
	dlist_prepend(&list, &value1);
	dlist_prepend(&list, &value2);

	int* data;
	dlist_remove(&list, dlist_tail(&list), (void**)&data);

	std::string actual = dlist_to_string(&list);
	std::string expected = "2";

	std::cout << "Actual: " << actual << ", expected: " << expected << std::endl;
	assert(expected == actual);

	dlist_ensure_integrity(&list);

	dlist_destroy(&list);
}

void test_dlist_remove_prev_of_tail() {
	DLinkedList list;

	dlist_init(&list, NULL);

	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	dlist_prepend(&list, &value1);
	dlist_prepend(&list, &value2);
	dlist_prepend(&list, &value3);

	int* data;
	dlist_remove(&list, dlist_tail(&list)->prev, (void**)&data);

	std::string actual = dlist_to_string(&list);
	std::string expected = "3 1";

	std::cout << "Actual: " << actual << ", expected: " << expected << std::endl;
	assert(expected == actual);

	dlist_ensure_integrity(&list);

	dlist_destroy(&list);
}

int main() {
	std::cout << "Test Prepend" << std::endl;
	test_prepend();

	std::cout << "test_dlist_ins_next_with_2_nodes_list" << std::endl;
	test_dlist_ins_next_with_2_nodes_list();

	std::cout << "test_dlist_ins_prev_with_3_nodes_list" << std::endl;
	test_dlist_ins_prev_with_3_nodes_list();

	std::cout << "test_dlist_remove_long_list" << std::endl;
	test_dlist_remove_long_list();

	std::cout << "test_dlist_remove_head_of_list" << std::endl;
	test_dlist_remove_head_of_list();

	std::cout << "test_dlist_remove_tail_of_list" << std::endl;
	test_dlist_remove_tail_of_list();

	std::cout << "test_dlist_remove_prev_of_tail" << std::endl;
	test_dlist_remove_prev_of_tail();
}