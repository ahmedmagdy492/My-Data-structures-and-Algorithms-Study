#include <iostream>
#include "DLinkedList.h"

void test_insert_end_with_empty_list() {
	int input = 12;

	DLinkedList list;
	list.insert_end(input);

	std::string actual = list.debug_to_string();
	std::string expected = "12";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_insert_end_with_single_node_list() {

	DLinkedList list;
	list.insert_end(23);
	list.insert_end(44);

	std::string actual = list.debug_to_string();
	std::string expected = "23 44";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_insert_end_with_normal_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(5);
	list.insert_end(6);
	list.insert_end(1);

	std::string actual = list.debug_to_string();
	std::string expected = "1 2 3 5 6 1";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_insert_front_with_empty_list() {
	int input = 56;

	DLinkedList list;
	list.insert_front(input);

	std::string actual = list.debug_to_string();
	std::string expected = "56";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_insert_front_with_single_node_list() {

	DLinkedList list;
	list.insert_front(1);
	list.insert_front(6);

	std::string actual = list.debug_to_string();
	std::string expected = "6 1";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_insert_front_with_normal_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(6);

	list.insert_front(9);

	std::string actual = list.debug_to_string();
	std::string expected = "9 1 2 3 4 5 6";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}


void test_insert_sorted_with_empty_list() {

	DLinkedList list;

	list.insert_sorted(1);

	std::string actual = list.debug_to_string();
	std::string expected = "1";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_insert_sorted_with_small_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);

	list.insert_sorted(4);

	std::string actual = list.debug_to_string();
	std::string expected = "1 2 3 4";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_insert_sorted_with_normal_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(5);
	list.insert_end(9);

	list.insert_sorted(2);

	std::string actual = list.debug_to_string();
	std::string expected = "1 2 5 9";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_insert_sorted_with_equal_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);

	list.insert_sorted(2);

	std::string actual = list.debug_to_string();
	std::string expected = "1 2 2 3";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_front_with_empty_list() {

	DLinkedList list;

	list.delete_front();

	std::string actual = list.debug_to_string();
	std::string expected = "";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_front_with_single_node_list() {

	DLinkedList list;
	list.insert_end(1);

	list.delete_front();

	std::string actual = list.debug_to_string();
	std::string expected = "";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_front_with_normal_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);

	list.delete_front();

	std::string actual = list.debug_to_string();
	std::string expected = "2 3 4 5";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_end_with_empty_list() {

	DLinkedList list;

	list.delete_end();

	std::string actual = list.debug_to_string();
	std::string expected = "";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_end_with_single_node_list() {

	DLinkedList list;
	list.insert_end(1);

	list.delete_end();

	std::string actual = list.debug_to_string();
	std::string expected = "";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_end_with_normal_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);

	list.delete_end();

	std::string actual = list.debug_to_string();
	std::string expected = "1 2 3 4";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_with_key_empty_list() {

	DLinkedList list;

	list.delete_with_key(12);

	std::string actual = list.debug_to_string();
	std::string expected = "";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_with_key_not_exist_key() {

	DLinkedList list;
	list.insert_end(1);

	list.delete_with_key(2);

	std::string actual = list.debug_to_string();
	std::string expected = "1";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_with_single_node_list() {

	DLinkedList list;
	list.insert_end(1);

	list.delete_with_key(1);

	std::string actual = list.debug_to_string();
	std::string expected = "";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_with_key_normal_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);

	list.delete_with_key(3);

	std::string actual = list.debug_to_string();
	std::string expected = "1 2 4";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_all_nodes_with_key_normal_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(5);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(4);
	list.insert_end(4);

	list.delete_all_nodes_with_key(5);

	std::string actual = list.debug_to_string();
	std::string expected = "1 2 4 4 4";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_all_nodes_with_key_normal_list2() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(5);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(4);
	list.insert_end(4);
	list.insert_end(5);

	list.delete_all_nodes_with_key(5);

	std::string actual = list.debug_to_string();
	std::string expected = "1 2 4 4 4";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_all_nodes_with_key_normal_list3() {

	DLinkedList list;
	list.insert_end(5);
	list.insert_end(2);
	list.insert_end(5);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(4);
	list.insert_end(4);
	list.insert_end(5);

	list.delete_all_nodes_with_key(5);

	std::string actual = list.debug_to_string();
	std::string expected = "2 4 4 4";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_all_nodes_with_key_repeated_key_list() {

	DLinkedList list;
	list.insert_end(5);
	list.insert_end(5);
	list.insert_end(5);
	list.insert_end(5);
	list.insert_end(5);
	list.insert_end(5);
	list.insert_end(5);
	list.insert_end(5);

	list.delete_all_nodes_with_key(5);

	std::string actual = list.debug_to_string();
	std::string expected = "";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_even_positions_with_normal_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(10);

	list.delete_even_positions();

	std::string actual = list.debug_to_string();
	std::string expected = "1 3 10";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_even_positions_with_normal_list2() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(6);

	list.delete_even_positions();

	std::string actual = list.debug_to_string();
	std::string expected = "1 3 5";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_odd_positions_with_normal_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(10);

	list.delete_odd_positions();

	std::string actual = list.debug_to_string();
	std::string expected = "2 4";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_odd_positions_with_normal_list2() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(7);

	list.delete_odd_positions();

	std::string actual = list.debug_to_string();
	std::string expected = "2 4 7";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_delete_odd_positions_with_single_node() {

	DLinkedList list;
	list.insert_end(7);

	list.delete_odd_positions();

	std::string actual = list.debug_to_string();
	std::string expected = "";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_is_palindrome_single_node() {

	DLinkedList list;
	list.insert_end(7);

	bool actual = list.is_palindrome();
	bool expected = true;

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_is_palindrome_with_palindromed_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(2);
	list.insert_end(1);

	bool actual = list.is_palindrome();
	bool expected = true;

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_is_palindrome_with_non_palindromed_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);

	bool actual = list.is_palindrome();
	bool expected = false;

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_middle_node_with_odd_len_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);

	int actual = list.middle_node_sl()->data;
	int expected = 3;

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_middle_node_with_even_len_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(6);

	int actual = list.middle_node_sl()->data;
	int expected = 4;

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_middle_node_with_single_node() {

	DLinkedList list;
	list.insert_end(2);

	int actual = list.middle_node_sl()->data;
	int expected = 2;

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_swap_forward_with_backward_normal_list_k_is_1() {

	DLinkedList list;
	list.insert_end(6);
	list.insert_end(10);
	list.insert_end(8);
	list.insert_end(15);
	list.swap_forward_with_backward(1);

	std::string actual = list.debug_to_string();
	std::string expected = "15 10 8 6";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_swap_forward_with_backward_normal_list_k_is_2() {

	DLinkedList list;
	list.insert_end(6);
	list.insert_end(10);
	list.insert_end(40);
	list.insert_end(8);
	list.insert_end(15);
	list.swap_forward_with_backward(2);

	std::string actual = list.debug_to_string();
	std::string expected = "6 8 40 10 15";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_swap_forward_with_backward_even_len_list_k_is_2() {

	DLinkedList list;
	list.insert_end(6);
	list.insert_end(10);
	list.insert_end(8);
	list.insert_end(15);
	list.swap_forward_with_backward(2);

	std::string actual = list.debug_to_string();
	std::string expected = "6 8 10 15";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_swap_forward_with_backward_odd_list_k_in_the_middle() {

	DLinkedList list;
	list.insert_end(6);
	list.insert_end(10);
	list.insert_end(40);
	list.insert_end(8);
	list.insert_end(15);
	list.swap_forward_with_backward(3);

	std::string actual = list.debug_to_string();
	std::string expected = "6 10 40 8 15";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_swap_forward_with_backward_odd_list_k_is_4() {

	DLinkedList list;
	list.insert_end(6);
	list.insert_end(10);
	list.insert_end(40);
	list.insert_end(8);
	list.insert_end(15);
	list.swap_forward_with_backward(4);

	std::string actual = list.debug_to_string();
	std::string expected = "6 8 40 10 15";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_reverse_list_with_odd_len_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);
	list.reverse_list();

	std::string actual = list.debug_to_string();
	std::string expected = "5 4 3 2 1";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_reverse_list_with_even_len_list() {

	DLinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.reverse_list();

	std::string actual = list.debug_to_string();
	std::string expected = "2 1";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_reverse_list_with_single_node() {

	DLinkedList list;
	list.insert_end(1);
	list.reverse_list();

	std::string actual = list.debug_to_string();
	std::string expected = "1";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list.debug_verify_data_integrity();
}

void test_merge_lists_sorted_with_normal_list() {

	DLinkedList list1, list2;
	list1.insert_end(10);
	list1.insert_end(20);
	list1.insert_end(30);
	list1.insert_end(40);
	list1.insert_end(50);

	list2.insert_end(15);
	list2.insert_end(17);
	list2.insert_end(22);
	list2.insert_end(24);
	list2.insert_end(35);

	list1.merge_lists_sorted(list2);

	std::string actual = list1.debug_to_string();
	std::string expected = "10 15 17 20 22 24 30 35 40 50";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list1.debug_verify_data_integrity();
}

void test_merge_lists_sorted_with_list1_less_than_list2() {

	DLinkedList list1, list2;
	list1.insert_end(10);
	list1.insert_end(20);
	list1.insert_end(30);
	list1.insert_end(40);
	list1.insert_end(50);

	list2.insert_end(15);
	list2.insert_end(17);
	list2.insert_end(22);
	list2.insert_end(24);
	list2.insert_end(35);
	list2.insert_end(45);

	list1.merge_lists_sorted(list2);

	std::string actual = list1.debug_to_string();
	std::string expected = "10 15 17 20 22 24 30 35 40 45 50";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list1.debug_verify_data_integrity();
}

void test_merge_lists_sorted_with_list2_less_than_list1() {

	DLinkedList list1, list2;
	list1.insert_end(10);
	list1.insert_end(20);
	list1.insert_end(30);
	list1.insert_end(40);
	list1.insert_end(43);
	list1.insert_end(50);

	list2.insert_end(15);
	list2.insert_end(17);
	list2.insert_end(22);
	list2.insert_end(24);
	list2.insert_end(35);

	list1.merge_lists_sorted(list2);

	std::string actual = list1.debug_to_string();
	std::string expected = "10 15 17 20 22 24 30 35 40 43 50";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list1.debug_verify_data_integrity();
}

void test_merge_lists_sorted_with_normal_list2_and_empty_list1() {

	DLinkedList list1, list2;

	list2.insert_end(15);
	list2.insert_end(17);
	list2.insert_end(22);
	list2.insert_end(24);
	list2.insert_end(35);

	list1.merge_lists_sorted(list2);

	std::string actual = list1.debug_to_string();
	std::string expected = "15 17 22 24 35";

	if (actual != expected) {
		std::cout << "actual: " << actual << " ,expected: " << expected << std::endl;
		assert(actual == expected);
	}

	list1.debug_verify_data_integrity();
}
int main() {
	/*std::cout << "test_insert_end_with_empty_list: " << std::endl;
	test_insert_end_with_empty_list();
	
	std::cout << "test_insert_end_with_single_node_list: " << std::endl;
	test_insert_end_with_single_node_list();
	
	std::cout << "test_insert_end_with_normal_list: " << std::endl;
	test_insert_end_with_normal_list();

	std::cout << "test_insert_front_with_empty_list: " << std::endl;
	test_insert_front_with_empty_list();

	std::cout << "test_insert_front_with_single_node_list: " << std::endl;
	test_insert_front_with_single_node_list();

	std::cout << "test_insert_front_with_normal_list: " << std::endl;
	test_insert_front_with_normal_list();

	std::cout << "test_insert_sorted_with_empty_list: " << std::endl;
	test_insert_sorted_with_empty_list();
	std::cout << "test_insert_sorted_with_small_list: " << std::endl;
	test_insert_sorted_with_small_list();
	std::cout << "test_insert_sorted_with_normal_list: " << std::endl;
	test_insert_sorted_with_normal_list();
	std::cout << "test_insert_sorted_with_equal_list: " << std::endl;
	test_insert_sorted_with_equal_list();

	std::cout << "test_delete_front_with_empty_list: " << std::endl;
	test_delete_front_with_empty_list();
	std::cout << "test_delete_front_with_single_node_list: " << std::endl;
	test_delete_front_with_single_node_list();
	std::cout << "test_delete_front_with_normal_list: " << std::endl;
	test_delete_front_with_normal_list();

	std::cout << "test_delete_end_with_empty_list: " << std::endl;
	test_delete_end_with_empty_list();
	std::cout << "test_delete_end_with_single_node_list: " << std::endl;
	test_delete_end_with_single_node_list();
	std::cout << "test_delete_end_with_normal_list: " << std::endl;
	test_delete_end_with_normal_list();


	std::cout << "test_with_key_empty_list: " << std::endl;
	test_delete_with_key_empty_list();
	std::cout << "test_delete_with_key_not_exist_key: " << std::endl;
	test_delete_with_key_not_exist_key();
	std::cout << "test_delete_with_single_node_list: " << std::endl;
	test_delete_with_single_node_list();
	std::cout << "test_delete_with_key_normal_list: " << std::endl;
	test_delete_with_key_normal_list();*/

	/*std::cout << "test_delete_all_nodes_with_key_normal_list: " << std::endl;
	test_delete_all_nodes_with_key_normal_list();
	std::cout << "test_delete_all_nodes_with_key_normal_list2: " << std::endl;
	test_delete_all_nodes_with_key_normal_list2();
	std::cout << "test_delete_all_nodes_with_key_normal_list3: " << std::endl;
	test_delete_all_nodes_with_key_normal_list3();
	std::cout << "test_delete_all_nodes_with_key_repeated_key_list: " << std::endl;
	test_delete_all_nodes_with_key_repeated_key_list();*/

	/*std::cout << "test_delete_even_positions_with_normal_list: " << std::endl;
	test_delete_even_positions_with_normal_list();
	std::cout << "test_delete_even_positions_with_normal_list2: " << std::endl;
	test_delete_even_positions_with_normal_list2();*/

	/*std::cout << "test_delete_odd_positions_with_normal_list: " << std::endl;
	test_delete_odd_positions_with_normal_list();
	std::cout << "test_delete_odd_positions_with_normal_list2: " << std::endl;
	test_delete_odd_positions_with_normal_list2();
	std::cout << "test_delete_odd_positions_with_single_node: " << std::endl;
	test_delete_odd_positions_with_single_node();*/

	/*std::cout << "test_is_palindrome_single_node: " << std::endl;
	test_is_palindrome_single_node();
	std::cout << "test_is_palindrome_with_palindromed_list: " << std::endl;
	test_is_palindrome_with_palindromed_list();
	std::cout << "test_is_palindrome_with_non_palindromed_list: " << std::endl;
	test_is_palindrome_with_non_palindromed_list();*/

	/*std::cout << "test_middle_node_with_odd_len_list: " << std::endl;
	test_middle_node_with_odd_len_list();
	std::cout << "test_middle_node_with_even_len_list: " << std::endl;
	test_middle_node_with_even_len_list();
	std::cout << "test_middle_node_with_single_node: " << std::endl;
	test_middle_node_with_single_node();*/

	/*std::cout << "test_swap_forward_with_backward_normal_list_k_is_1: " << std::endl;
	test_swap_forward_with_backward_normal_list_k_is_1();
	std::cout << "test_swap_forward_with_backward_normal_list_k_is_2: " << std::endl;
	test_swap_forward_with_backward_normal_list_k_is_2();
	std::cout << "test_swap_forward_with_backward_even_len_list_k_is_2: " << std::endl;
	test_swap_forward_with_backward_even_len_list_k_is_2();
	std::cout << "test_swap_forward_with_backward_odd_list_k_in_the_middle: " << std::endl;
	test_swap_forward_with_backward_odd_list_k_in_the_middle();
	std::cout << "test_swap_forward_with_backward_odd_list_k_is_4: " << std::endl;
	test_swap_forward_with_backward_odd_list_k_is_4();

	std::cout << "test_reverse_list_with_odd_len_list: " << std::endl;
	test_reverse_list_with_odd_len_list();
	std::cout << "test_reverse_list_with_even_len_list: " << std::endl;
	test_reverse_list_with_even_len_list();
	std::cout << "test_reverse_list_with_single_node: " << std::endl;
	test_reverse_list_with_single_node();*/

	/*std::cout << "test_merge_lists_sorted_with_normal_list: " << std::endl;
	test_merge_lists_sorted_with_normal_list();
	std::cout << "test_merge_lists_sorted_with_list1_less_than_list2: " << std::endl;
	test_merge_lists_sorted_with_list1_less_than_list2();
	std::cout << "test_merge_lists_sorted_with_list2_less_than_list1: " << std::endl;
	test_merge_lists_sorted_with_list2_less_than_list1();
	std::cout << "test_merge_lists_sorted_with_normal_list2_and_empty_list1: " << std::endl;
	test_merge_lists_sorted_with_normal_list2_and_empty_list1();*/

	

	std::cout << "No RTE" << std::endl;

	return 0;
}