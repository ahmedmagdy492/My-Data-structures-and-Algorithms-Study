#include <iostream>
#include <cassert>

#include "SLL.hpp"
#include "SLL2.hpp"

using namespace std;


void test1() {
	cout << "\n\ntest1\n";
	LinkedList list;

	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	// some actions
	list.print();

	string expected = "1 2 3";
	string result = list.debug_to_string();
	if (expected != result) {
		cout << "no match:\nExpected: " <<
				expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	list.debug_print_list("********");
}

void test2() {
	cout << "\n\ntest2\n";
	LinkedList list;

	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	// some actions
	list.print();

	string expected = "1 2 3 4";
	string result = list.debug_to_string();
	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	list.debug_print_list("********");
}

void test_insert_front_aganist_empty_list() {
	LinkedList list;

	list.insert_front(-2);

	string actual = list.debug_to_string();
	string expected = "-2";
	
	if (expected != actual) {
		cout << "no match:\nExpected: " << expected << "\nactual: " << actual << "\n";
		assert(false);
	}
	list.debug_print_list("********");
	list.debug_verify_data_integrity();
}

void test_insert_front_aganist_normal_case() {
	LinkedList list;
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(6);
	list.insert_end(8);

	list.insert_front(99);

	string actual = list.debug_to_string();
	string expected = "99 4 5 6 8";

	if (expected != actual) {
		cout << "no match:\nExpected: " << expected << "\nactual: " << actual << "\n";
		assert(false);
	}
	list.debug_print_list("********");
	list.debug_verify_data_integrity();
}

void test_insert_front_aganist_single_element() {
	LinkedList list;
	list.insert_end(218);

	list.insert_front(180);

	string actual = list.debug_to_string();
	string expected = "180 218";

	if (expected != actual) {
		cout << "no match:\nExpected: " << expected << "\nactual: " << actual << "\n";
		assert(false);
	}
	list.debug_print_list("********");
	list.debug_verify_data_integrity();
}

void test_delete_front_for_empty_list() {
	LinkedList list;

	list.delete_front();

	string actual = list.debug_to_string();
	string expected = "";

	if (expected != actual) {
		cout << "no match:\nExpected: " << expected << "\nactual: " << actual << "\n";
		assert(false);
	}
	list.debug_print_list("********");
	list.debug_verify_data_integrity();
}

void test_delete_front_for_single_element_list() {
	LinkedList list;
	list.insert_end(22);

	list.delete_front();

	string actual = list.debug_to_string();
	string expected = "";

	if (expected != actual) {
		cout << "no match:\nExpected: " << expected << "\nactual: " << actual << "\n";
		assert(false);
	}
	list.debug_print_list("********");
	list.debug_verify_data_integrity();
}

void test_delete_front_for_normal_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);

	list.delete_front();

	string actual = list.debug_to_string();
	string expected = "2 3 4";

	if (expected != actual) {
		cout << "no match:\nExpected: " << expected << "\nactual: " << actual << "\n";
		assert(false);
	}
	list.debug_print_list("********");
	list.debug_verify_data_integrity();
}


void test_get_nth_back_aganist_single_element() {
	LinkedList list;
	list.insert_end(22);

	int result = list.get_nth_back(1);
	int expected = 22;

	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nresult: " << result << "\n";
		assert(false);
	}
	list.debug_print_list("********");
	list.debug_verify_data_integrity();
}

void test_get_nth_back_aganist_normal_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(6);

	int result = list.get_nth_back(1);
	int expected = 6;

	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nresult: " << result << "\n";
		assert(false);
	}
	list.debug_print_list("********");
	list.debug_verify_data_integrity();
}

void test_is_same_2_lists_of_different_lengthes() {
	LinkedList list1;
	list1.insert_end(1);
	list1.insert_end(2);
	list1.insert_end(3);
	list1.insert_end(4);

	LinkedList list2;
	list2.insert_end(1);
	list2.insert_end(2);
	list2.insert_end(3);

	bool result = list1.is_same(list2);
	bool expected = false;

	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nresult: " << result << "\n";
		assert(false);
	}
}

void test_is_same_2_lists_of_same_length_but_diff_in_values() {
	LinkedList list1;
	list1.insert_end(1);
	list1.insert_end(2);
	list1.insert_end(3);
	list1.insert_end(4);

	LinkedList list2;
	list2.insert_end(1);
	list2.insert_end(2);
	list2.insert_end(3);
	list1.insert_end(5);

	bool result = list1.is_same(list2);
	bool expected = false;

	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nresult: " << result << "\n";
		assert(false);
	}
}

void test_is_same_2_lists_of_same_length_and_values() {
	LinkedList list1;
	list1.insert_end(1);
	list1.insert_end(2);
	list1.insert_end(3);
	list1.insert_end(4);

	LinkedList list2;
	list2.insert_end(1);
	list2.insert_end(2);
	list2.insert_end(3);
	list2.insert_end(4);

	bool result = list1.is_same(list2);
	bool expected = true;

	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nresult: " << result << "\n";
		assert(false);
	}
}

void test_same_until_with_empty_lists() {
	LinkedList list1;

	LinkedList list2;

	int result = list1.same_until(list2);
	int expected = 0;

	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nresult: " << result << "\n";
		assert(false);
	}
}

void test_same_until_with_diff_lists_lengths() {
	LinkedList list1;
	list1.insert_end(1);
	list1.insert_end(2);
	list1.insert_end(3);
	list1.insert_end(4);

	LinkedList list2;
	list2.insert_end(1);
	list2.insert_end(2);
	list2.insert_end(3);

	int result = list1.same_until(list2);
	int expected = 3;

	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nresult: " << result << "\n";
		assert(false);
	}
}

void test_same_until_with_diff_lists_values() {
	LinkedList list1;
	list1.insert_end(1);
	list1.insert_end(2);
	list1.insert_end(3);
	list1.insert_end(4);

	LinkedList list2;
	list2.insert_end(1);
	list2.insert_end(2);
	list2.insert_end(5);
	list2.insert_end(4);

	int result = list1.same_until(list2);
	int expected = 2;

	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nresult: " << result << "\n";
		assert(false);
	}
}

void test_same_until_with_same_lists_values_and_length() {
	LinkedList list1;
	list1.insert_end(1);
	list1.insert_end(2);
	list1.insert_end(3);
	list1.insert_end(4);

	LinkedList list2;
	list2.insert_end(1);
	list2.insert_end(2);
	list2.insert_end(3);
	list2.insert_end(4);

	int result = list1.same_until(list2);
	int expected = 4;

	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nresult: " << result << "\n";
		assert(false);
	}
}

void test_delete_first_with_normal_list() {
	LinkedList list;

	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);

	int result = list.delete_first();
	int expected = 1;

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	string expectedList = "2 3 4 5";
	string actualList = list.debug_to_string();

	if (expectedList != actualList) {
		cout << "expectedList != actualList: " << expectedList << " != " << actualList << "\n";
		assert(false);
	}
}

void test_delete_first_with_single_element_list() {
	LinkedList list;

	list.insert_end(13);

	int result = list.delete_first();
	int expected = 13;

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	string expectedList = "";
	string actualList = list.debug_to_string();

	if (expectedList != actualList) {
		cout << "expectedList != actualList: " << expectedList << " != " << actualList << "\n";
		assert(false);
	}
}

void test_delete_last_with_normal_list() {
	LinkedList list;

	list.insert_end(2);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(6);

	int result = list.delete_last();
	int expected = 6;

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	string expectedList = "2 4 5";
	string actualList = list.debug_to_string();

	if (expectedList != actualList) {
		cout << "expectedList != actualList: " << expectedList << " != " << actualList << "\n";
		assert(false);
	}
}

void test_delete_last_with_single_element_list() {
	LinkedList list;

	list.insert_end(224);

	int result = list.delete_last();
	int expected = 224;

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	string expectedList = "";
	string actualList = list.debug_to_string();

	if (expectedList != actualList) {
		cout << "expectedList != actualList: " << expectedList << " != " << actualList << "\n";
		assert(false);
	}
}

void test_delete_nth_node_with_normal_list() {
	LinkedList list;

	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(34);
	list.insert_end(55);

	int index = 4;

	int result = list.delete_nth_node(index);
	int expected = 55;

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	string expectedList = "1 2 34";
	string actualList = list.debug_to_string();

	if (expectedList != actualList) {
		cout << "expectedList != actualList: " << expectedList << " != " << actualList << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_delete_nth_node_with_mid_node() {
	LinkedList list;

	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);

	int index = 3;

	int result = list.delete_nth_node(index);
	int expected = 3;

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	string expectedList = "1 2 4 5";
	string actualList = list.debug_to_string();

	if (expectedList != actualList) {
		cout << "expectedList != actualList: " << expectedList << " != " << actualList << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_delete_nth_single_node() {
	LinkedList list;

	list.insert_end(23);

	int index = 1;

	int result = list.delete_nth_node(index);
	int expected = 23;

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	string expectedList = "";
	string actualList = list.debug_to_string();

	if (expectedList != actualList) {
		cout << "expectedList != actualList: " << expectedList << " != " << actualList << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_delete_with_key_normal_case() {
	LinkedList list;

	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(2);
	list.insert_end(6);

	int key = 2;

	list.delete_with_key(key);
	string expected = "1 3 4 2 6";
	string result = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_delete_with_key_not_exist() {
	LinkedList list;

	list.insert_end(1);
	list.insert_end(3);
	list.insert_end(4);

	int key = 5;

	list.delete_with_key(key);
	string expected = "1 3 4";
	string result = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_delete_with_key_2_nodes() {
	LinkedList list;

	list.insert_end(3);
	list.insert_end(2);

	int key = 3;

	list.delete_with_key(key);
	string expected = "2";
	string result = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_delete_with_key_single_node() {
	LinkedList list;

	list.insert_end(4);

	int key = 4;

	list.delete_with_key(key);
	string expected = "";
	string result = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_swap_pairs_with_normal_list() {
	LinkedList list;

	list.insert_end(1);
	list.insert_end(2);

	list.swap_pairs();
	string expected = "2 1";
	string result = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_swap_pairs_with_long_list() {
	LinkedList list;

	list.insert_end(1);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(6);

	list.swap_pairs();
	string expected = "3 1 5 4 6";
	string result = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_swap_pairs_with_single_node() {
	LinkedList list;

	list.insert_end(33);

	list.swap_pairs();
	string expected = "33";
	string result = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_swap_pairs_with_empty_list() {
	LinkedList list;

	list.swap_pairs();
	string expected = "";
	string result = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_get_nth_node() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);

	int result = list.get_nth_node(3)->data;
	int expected = 4;

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_reverse_with_normal_even_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);

	list.reverse();
	string result = "4 3 2 1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_reverse_with_normal_odd_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);

	list.reverse();
	string result = "5 4 3 2 1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_reverse_with_single_node() {
	LinkedList list;
	list.insert_end(1);

	list.reverse();
	string result = "1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_reverse_ll_with_empty_list() {
	LinkedList list;

	list.reverse_sl();
	string result = "";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_reverse_ll_with_single_node() {
	LinkedList list;
	list.insert_end(1);

	list.reverse_sl();
	string result = "1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_reverse_ll_with_2_node() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);

	list.reverse_sl();
	string result = "2 1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_reverse_ll_with_normal_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(6);

	list.reverse_sl();
	string result = "6 5 4 3 2 1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_delete_even_positions_with_empty_list() {
	LinkedList list;

	list.delete_even_positions();
	string result = "";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_delete_even_positions_with_1_node_list() {
	LinkedList list;
	list.insert_end(12);

	list.delete_even_positions();
	string result = "12";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_delete_even_positions_with_2_nodes_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);

	list.delete_even_positions();
	string result = "1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_delete_even_positions_with_normal_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(6);

	list.delete_even_positions();
	string result = "1 3 5";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_insert_ordered_empty_list() {
	LinkedList list;

	list.insert_sorted(1);
	string result = "1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_insert_ordered_single_node_list() {
	LinkedList list;
	list.insert_end(2);

	list.insert_sorted(4);
	string result = "2 4";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_insert_ordered_normal_list_middle_insert() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(5);
	list.insert_end(6);

	list.insert_sorted(4);
	string result = "1 2 3 4 5 6";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_insert_ordered_normal_list_last_insert() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);

	list.insert_sorted(5);
	string result = "1 2 3 4 5";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}


void test_swap_head_and_tail_empty_list() {
	LinkedList list;

	list.swap_head_and_tail();
	string result = "";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_swap_head_and_tail_single_node_list() {
	LinkedList list;
	list.insert_end(1);

	list.swap_head_and_tail();
	string result = "1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_swap_head_and_tail_2_nodes_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);

	const Node* oldHead = list.get_head();
	const Node* oldTail = list.get_tail();

	list.swap_head_and_tail();
	string result = "2 1";
	string expected = list.debug_to_string();

	const Node* newHead = list.get_head();
	const Node* newTail = list.get_tail();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	assert(oldHead == newTail);
	assert(oldTail == newHead);

	list.debug_verify_data_integrity();
}

void test_swap_head_and_tail_normal_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);

	const Node* oldHead = list.get_head();
	const Node* oldTail = list.get_tail();

	list.swap_head_and_tail();
	string result = "5 2 3 4 1";
	string expected = list.debug_to_string();

	const Node* newHead = list.get_head();
	const Node* newTail = list.get_tail();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	assert(oldHead == newTail);
	assert(oldTail == newHead);

	list.debug_verify_data_integrity();
}


void test_rotate_left_with_k_equals_1() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);


	list.left_rotate(1);
	string result = "2 3 4 5 1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_rotate_left_with_k_equals_3() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);


	list.left_rotate(3);
	string result = "4 5 1 2 3";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_rotate_left_with_k_equals_3_and_2_nodes() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);

	list.left_rotate(3);
	string result = "2 1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_rotate_left_with_k_equals_4() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);

	list.left_rotate(4);
	string result = "2 3 1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_remove_duplicates_with_normal_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(1);
	list.insert_end(3);
	list.insert_end(2);
	list.insert_end(4);
	list.insert_end(3);
	list.insert_end(5);
	list.insert_end(2);

	list.remove_duplicates();
	string result = "1 2 3 4 5";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_remove_duplicates_with_repeated_values_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(3);
	list.insert_end(3);
	list.insert_end(3);
	list.insert_end(5);

	list.remove_duplicates();
	string result = "1 2 3 5";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_remove_duplicates_no_duplicates_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);

	list.remove_duplicates();
	string result = "1 2 3 4 5";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_remove_duplicates_empty_list() {
	LinkedList list;

	list.remove_duplicates();
	string result = "";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_remove_duplicates_single_node_list() {
	LinkedList list;
	list.insert_end(1);

	list.remove_duplicates();
	string result = "1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_remove_duplicates_2_duplicate_nodes_list() {
	LinkedList list;
	list.insert_end(2);
	list.insert_end(2);

	list.remove_duplicates();
	string result = "2";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_remove_last_occurance_normal_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);

	list.remove_last_occurance(1);
	string result = "2 3";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_remove_last_occurance_normal_list_2() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(1);
	list.insert_end(4);

	list.remove_last_occurance(1);
	string result = "1 2 3 4";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_remove_last_occurance_last_node_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(1);

	list.remove_last_occurance(1);
	string result = "1 2 3 4";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_remove_last_occurance_non_existing_key() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);

	list.remove_last_occurance(7);
	string result = "1 2 3 4";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_move_key_to_back_small_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(1);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);

	list.move_key_to_back(1);
	string result = "3 4 5 1 1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_move_key_to_back_mid_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(2);
	list.insert_end(4);
	list.insert_end(1);

	list.move_key_to_back(1);
	string result = "2 3 2 4 1 1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_move_key_to_back_long_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(4);
	list.insert_end(1);
	list.insert_end(7);
	list.insert_end(1);
	list.insert_end(8);
	list.insert_end(1);
	list.insert_end(1);

	list.move_key_to_back(1);
	string result = "2 3 2 4 7 8 1 1 1 1 1 1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_move_key_to_back_all_1_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(1);
	list.insert_end(1);
	list.insert_end(1);
	list.insert_end(1);

	list.move_key_to_back(1);
	string result = "1 1 1 1 1";
	string expected = list.debug_to_string();

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_max_value_normal_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);

	int actual = list.max();
	int expected = 5;

	if (actual != expected) {
		cout << "actual != expected: " << actual << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_max_value_single_node() {
	LinkedList list;
	list.insert_end(12);

	int actual = list.max();
	int expected = 12;

	if (actual != expected) {
		cout << "actual != expected: " << actual << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_max_value_large_values_list() {
	LinkedList list;
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(45);
	list.insert_end(2);
	list.insert_end(1);

	int actual = list.max();
	int expected = 45;

	if (actual != expected) {
		cout << "actual != expected: " << actual << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_arrange_odd_and_even_positions_mid_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);

	list.arrange_odd_and_even_positions();
	string result = list.debug_to_string();
	string expected = "1 3 2 4";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_arrange_odd_and_even_positions_small_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);

	list.arrange_odd_and_even_positions();
	string result = list.debug_to_string();
	string expected = "1 3 2";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_arrange_odd_and_even_positions_long_list() {
	LinkedList list;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(6);
	list.insert_end(7);

	list.arrange_odd_and_even_positions();
	string result = list.debug_to_string();
	string expected = "1 3 6 2 4 7";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_arrange_odd_and_even_positions_long_list2() {
	LinkedList list;
	list.insert_end(11);
	list.insert_end(33);
	list.insert_end(55);
	list.insert_end(4);
	list.insert_end(50);
	list.insert_end(17);
	list.insert_end(8);

	list.arrange_odd_and_even_positions();
	string result = list.debug_to_string();
	string expected = "11 55 50 8 33 4 17";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_insert_alternate_single_node_in_newlist() {
	LinkedList list, newList;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);

	newList.insert_end(4);

	list.insert_alternate(&newList);
	string result = list.debug_to_string();
	string expected = "1 4 2 3";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_insert_alternate_newlist_larger_than_original_list() {
	LinkedList list, newList;
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);

	newList.insert_end(4);
	newList.insert_end(5);
	newList.insert_end(6);
	newList.insert_end(7);
	newList.insert_end(8);

	list.insert_alternate(&newList);
	string result = list.debug_to_string();
	string expected = "1 4 2 5 3 6 7 8";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_insert_alternate_empty_original_list() {
	LinkedList list, newList;

	newList.insert_end(4);
	newList.insert_end(5);
	newList.insert_end(6);
	newList.insert_end(7);
	newList.insert_end(8);

	list.insert_alternate(&newList);
	string result = list.debug_to_string();
	string expected = "4 5 6 7 8";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}

	list.debug_verify_data_integrity();
}

void test_add_num_2_digit_lists() {
	LinkedList list, list2;

	// number 12
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);

	// number 23
	list2.insert_end(4);
	list2.insert_end(5);
	list2.insert_end(3);

	list.add_number(&list2);
	string result = list.debug_to_string();
	string expected = "5 7 6";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}
	else {
		cout << "result: " << result << "\n";
		cout << "expected: " << expected << "\n";
	}

	list.debug_verify_data_integrity();
	list2.debug_verify_data_integrity();
}

void test_add_num_2_digit_and_2_digits_lists() {
	LinkedList list, list2;

	// number 70
	list.insert_end(0);
	list.insert_end(7);

	// number 98
	list2.insert_end(8);
	list2.insert_end(9);

	list.add_number(&list2);
	string result = list.debug_to_string();
	string expected = "8 6 1";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}
	else {
		cout << "result: " << result << "\n";
		cout << "expected: " << expected << "\n";
	}

	list.debug_verify_data_integrity();
	list2.debug_verify_data_integrity();
}

void test_add_num_2_digit_and_4_digits_lists() {
	LinkedList list, list2;

	// number 12
	list.insert_end(2);
	list.insert_end(1);

	// number 150
	list2.insert_end(0);
	list2.insert_end(5);
	list2.insert_end(1);

	list.add_number(&list2);
	string result = list.debug_to_string();
	string expected = "2 6 1";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}
	else {
		cout << "result: " << result << "\n";
		cout << "expected: " << expected << "\n";
	}

	list.debug_verify_data_integrity();
	list2.debug_verify_data_integrity();
}

void test_add_num_long_lists() {
	LinkedList list, list2;

	list.insert_end(9);
	list.insert_end(6);
	list.insert_end(5);

	// 98754678
	list2.insert_end(8);
	list2.insert_end(7);
	list2.insert_end(6);
	list2.insert_end(4);
	list2.insert_end(5);
	list2.insert_end(7);
	list2.insert_end(8);
	list2.insert_end(9);

	list.add_number(&list2);
	string result = list.debug_to_string();
	string expected = "7 4 2 5 5 7 8 9";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}
	else {
		cout << "result: " << result << "\n";
		cout << "expected: " << expected << "\n";
	}

	list.debug_verify_data_integrity();
	list2.debug_verify_data_integrity();
}

void test_add_num_long_list_small_list() {
	LinkedList list, list2;

	// 98754678
	list.insert_end(8);
	list.insert_end(7);
	list.insert_end(6);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(7);
	list.insert_end(8);
	list.insert_end(9);

	list2.insert_end(9);
	list2.insert_end(6);
	list2.insert_end(5);

	list.add_number(&list2);
	string result = list.debug_to_string();
	string expected = "7 4 2 5 5 7 8 9";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}
	else {
		cout << "result: " << result << "\n";
		cout << "expected: " << expected << "\n";
	}

	list.debug_verify_data_integrity();
	list2.debug_verify_data_integrity();
}

void test_remove_duplicate_many_repeated_values() {
	LinkedList list;

	list.insert_end(1);
	list.insert_end(1);
	list.insert_end(5);
	list.insert_end(2);
	list.insert_end(2);
	list.insert_end(2);
	list.insert_end(3);

	list.remove_duplicate_bf();
	string result = list.debug_to_string();
	string expected = "5 3";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}
	else {
		cout << "result: " << result << "\n";
		cout << "expected: " << expected << "\n";
	}

	list.debug_verify_data_integrity();
}

void test_remove_duplicate_2_nodes_list() {
	LinkedList list;

	list.insert_end(1);
	list.insert_end(1);

	list.remove_duplicate_bf();
	string result = list.debug_to_string();
	string expected = "";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}
	else {
		cout << "result: " << result << "\n";
		cout << "expected: " << expected << "\n";
	}

	list.debug_verify_data_integrity();
}

void test_remove_duplicate_all_nodes_are_duplicates() {
	LinkedList list;

	list.insert_end(1);
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(2);
	list.insert_end(2);

	list.remove_duplicate_bf();
	string result = list.debug_to_string();
	string expected = "";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}
	else {
		cout << "result: " << result << "\n";
		cout << "expected: " << expected << "\n";
	}

	list.debug_verify_data_integrity();
}

void test_remove_duplicate_all_nodes_are_duplicates_except_one() {
	LinkedList list;

	list.insert_end(1);
	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(2);
	list.insert_end(2);
	list.insert_end(5);

	list.remove_duplicate_bf();
	string result = list.debug_to_string();
	string expected = "5";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}
	else {
		cout << "result: " << result << "\n";
		cout << "expected: " << expected << "\n";
	}

	list.debug_verify_data_integrity();
}

void test_remove_duplicate_all_nodes_are_duplicates_except_2() {
	LinkedList list;

	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(2);
	list.insert_end(2);
	list.insert_end(3);

	list.remove_duplicate_bf();
	string result = list.debug_to_string();
	string expected = "1 3";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}
	else {
		cout << "result: " << result << "\n";
		cout << "expected: " << expected << "\n";
	}

	list.debug_verify_data_integrity();
}

void test_reverse_chains_normal_reverse() {
	LinkedList list;

	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(6);

	int k = 6;
	list.reverse_chains(k);
	string result = list.debug_to_string();
	string expected = "6 5 4 3 2 1";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}
	else {
		cout << "result: " << result << "\n";
		cout << "expected: " << expected << "\n";
	}

	list.debug_verify_data_integrity();
}

void test_reverse_chains_k_equals_3() {
	LinkedList list;

	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(6);

	int k = 3;
	list.reverse_chains(k);
	string result = list.debug_to_string();
	string expected = "3 2 1 6 5 4";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}
	else {
		cout << "result: " << result << "\n";
		cout << "expected: " << expected << "\n";
	}

	list.debug_verify_data_integrity();
}

void test_reverse_chains_k_equals_2() {
	LinkedList list;

	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);
	list.insert_end(6);
	list.insert_end(7);

	int k = 2;
	list.reverse_chains(k);
	string result = list.debug_to_string();
	string expected = "2 1 4 3 6 5 7";

	if (result != expected) {
		cout << "result != expected: " << result << " != " << expected << "\n";
		assert(false);
	}
	else {
		cout << "result: " << result << "\n";
		cout << "expected: " << expected << "\n";
	}

	list.debug_verify_data_integrity();
}

int main() {
	/*test1();
	test2();*/
	
	/*cout << "\nTest test_insert_front_aganist_empty_list Result: " << "\n";
	test_insert_front_aganist_empty_list();
	cout << "\nTest test_insert_front_aganist_normal_case Result: " << "\n";
	test_insert_front_aganist_normal_case();
	cout << "\nTest test_insert_front_aganist_single_element Result: " << "\n";
	test_insert_front_aganist_single_element();*/

	/*cout << "\nTest test_delete_front_for_empty_list Result: " << "\n";
	test_delete_front_for_empty_list();
	cout << "\nTest test_delete_front_for_single_element_list Result: " << "\n";
	test_delete_front_for_single_element_list();
	cout << "\nTest test_delete_front_for_normal_list Result: " << "\n";
	test_delete_front_for_normal_list();*/

	/*cout << "\nTest test_get_nth_back_aganist_single_element Result: " << "\n";
	test_get_nth_back_aganist_single_element();
	cout << "\nTest test_get_nth_back_aganist_normal_list Result: " << "\n";
	test_get_nth_back_aganist_normal_list();*/

	/*cout << "\nTest test_is_same_2_lists_of_different_lengthes Result: " << "\n";
	test_is_same_2_lists_of_different_lengthes();
	cout << "\nTest test_is_same_2_lists_of_same_length_but_diff_in_values Result: " << "\n";
	test_is_same_2_lists_of_same_length_but_diff_in_values();
	cout << "\nTest test_is_same_2_lists_of_same_length_and_values Result: " << "\n";
	test_is_same_2_lists_of_same_length_and_values();*/

	/*cout << "\nTest test_same_until_with_empty_lists Result: " << "\n";
	test_same_until_with_empty_lists();
	cout << "\nTest test_same_until_with_diff_lists_lengths Result: " << "\n";
	test_same_until_with_diff_lists_lengths();
	cout << "\nTest test_same_until_with_diff_lists_values Result: " << "\n";
	test_same_until_with_diff_lists_values();
	cout << "\nTest test_same_until_with_same_lists_values_and_length Result: " << "\n";
	test_same_until_with_same_lists_values_and_length();*/

	/*cout << "\nTest test_delete_first_with_normal_list Result: " << "\n";
	test_delete_first_with_normal_list();
	cout << "\nTest test_delete_first_with_single_element_list Result: " << "\n";
	test_delete_first_with_single_element_list();*/

	/*cout << "\nTest test_delete_last_with_normal_list Result: " << "\n";
	test_delete_last_with_normal_list();
	cout << "\nTest test_delete_last_with_single_element_list Result: " << "\n";
	test_delete_last_with_single_element_list();*/

	/*cout << "\nTest test_delete_nth_node_with_normal_list Result: " << "\n";
	test_delete_nth_node_with_normal_list();
	cout << "\nTest test_delete_nth_node_with_mid_node Result: " << "\n";
	test_delete_nth_node_with_mid_node();
	cout << "\nTest test_delete_nth_single_node Result: " << "\n";
	test_delete_nth_single_node();*/

	//cout << "\nTest test_delete_with_key Result: " << "\n";
	//test_delete_with_key_normal_case();
	///*cout << "\nTest test_delete_with_key_not_exist Result: " << "\n";
	//test_delete_with_key_not_exist();*/
	//cout << "\nTest test_delete_with_key_2_nodes Result: " << "\n";
	//test_delete_with_key_2_nodes();
	//cout << "\nTest test_delete_with_key_single_node Result: " << "\n";
	//test_delete_with_key_single_node();

	/*cout << "\nTest test_swap_pairs_with_normal_list Result: " << "\n";
	test_swap_pairs_with_normal_list();
	cout << "\nTest test_swap_pairs_with_long_list Result: " << "\n";
	test_swap_pairs_with_long_list();
	cout << "\nTest test_swap_pairs_with_single_node Result: " << "\n";
	test_swap_pairs_with_single_node();
	cout << "\nTest test_swap_pairs_with_empty_list Result: " << "\n";
	test_swap_pairs_with_empty_list();*/

	/*cout << "\nTest test_reverse_with_normal_even_list Result: " << "\n";
	test_reverse_with_normal_even_list();
	cout << "\nTest test_reverse_with_normal_odd_list Result: " << "\n";
	test_reverse_with_normal_odd_list();
	cout << "\nTest test_reverse_with_single_node Result: " << "\n";
	test_reverse_with_single_node();*/

	/*cout << "\nTest test_reverse_ll_with_empty_list Result: " << "\n";
	test_reverse_ll_with_empty_list();
	cout << "\nTest test_reverse_ll_with_single_node Result: " << "\n";
	test_reverse_ll_with_single_node();
	cout << "\nTest test_reverse_ll_with_2_node Result: " << "\n";
	test_reverse_ll_with_2_node();
	cout << "\nTest test_reverse_ll_with_normal_list Result: " << "\n";
	test_reverse_ll_with_normal_list();*/

	/*cout << "\nTest test_delete_even_positions_with_empty_list Result: " << "\n";
	test_delete_even_positions_with_empty_list();
	cout << "\nTest test_delete_even_positions_with_1_node_list Result: " << "\n";
	test_delete_even_positions_with_1_node_list();
	cout << "\nTest test_delete_even_positions_with_2_nodes_list Result: " << "\n";
	test_delete_even_positions_with_2_nodes_list();
	cout << "\nTest test_delete_even_positions_with_normal_list Result: " << "\n";
	test_delete_even_positions_with_normal_list();*/

	/*cout << "\nTest test_insert_ordered_empty_list Result: " << "\n";
	test_insert_ordered_empty_list();
	cout << "\nTest test_insert_ordered_single_node_list Result: " << "\n";
	test_insert_ordered_single_node_list();
	cout << "\nTest test_insert_ordered_normal_list_middle_insert Result: " << "\n";
	test_insert_ordered_normal_list_middle_insert();
	cout << "\nTest test_insert_ordered_normal_list_last_insert Result: " << "\n";
	test_insert_ordered_normal_list_last_insert();*/

	/*cout << "\nTest test_swap_head_and_tail_empty_list Result: " << "\n";
	test_swap_head_and_tail_empty_list();
	cout << "\nTest test_swap_head_and_tail_single_node_list Result: " << "\n";
	test_swap_head_and_tail_single_node_list();
	cout << "\nTest test_swap_head_and_tail_2_nodes_list Result: " << "\n";
	test_swap_head_and_tail_2_nodes_list();
	cout << "\nTest test_swap_head_and_tail_normal_list Result: " << "\n";
	test_swap_head_and_tail_normal_list();*/

	/*cout << "\nTest test_rotate_left_with_k_equals_1 Result: " << "\n";
	test_rotate_left_with_k_equals_1();
	cout << "\nTest test_rotate_left_with_k_equals_3 Result: " << "\n";
	test_rotate_left_with_k_equals_3();
	cout << "\nTest test_rotate_left_with_k_equals_4_and_2_nodes Result: " << "\n";
	test_rotate_left_with_k_equals_3_and_2_nodes();
	cout << "\nTest test_rotate_left_with_k_equals_4 Result: " << "\n";
	test_rotate_left_with_k_equals_4();*/

	/*cout << "\nTest test_remove_duplicates_with_normal_list Result: " << "\n";
	test_remove_duplicates_with_normal_list();
	cout << "\nTest test_remove_duplicates_with_repeated_values_list Result: " << "\n";
	test_remove_duplicates_with_repeated_values_list();
	cout << "\nTest test_remove_duplicates_no_duplicates_list Result: " << "\n";
	test_remove_duplicates_no_duplicates_list();
	cout << "\nTest test_remove_duplicates_empty_list Result: " << "\n";
	test_remove_duplicates_empty_list();
	cout << "\nTest test_remove_duplicates_single_node_list Result: " << "\n";
	test_remove_duplicates_single_node_list();
	cout << "\nTest test_remove_duplicates_2_duplicate_nodes_list Result: " << "\n";
	test_remove_duplicates_2_duplicate_nodes_list();*/

	/*cout << "\nTest test_remove_last_occurance_normal_list Result: " << "\n";
	test_remove_last_occurance_normal_list();
	cout << "\nTest test_remove_last_occurance_last_node_list Result: " << "\n";
	test_remove_last_occurance_last_node_list();
	cout << "\nTest test_remove_last_occurance_non_existing_key Result: " << "\n";
	test_remove_last_occurance_non_existing_key();
	cout << "\nTest test_remove_last_occurance_normal_list_2 Result: " << "\n";
	test_remove_last_occurance_normal_list_2();*/

	/*cout << "\nTest test_move_key_to_back_small_list Result: " << "\n";
	test_move_key_to_back_small_list();
	cout << "\nTest test_move_key_to_back_mid_list Result: " << "\n";
	test_move_key_to_back_mid_list();
	cout << "\nTest test_move_key_to_back_long_list Result: " << "\n";
	test_move_key_to_back_long_list();
	cout << "\nTest test_move_key_to_back_all_1_list Result: " << "\n";
	test_move_key_to_back_all_1_list();*/

	/*cout << "\nTest test_max_value_normal_list Result: " << "\n";
	test_max_value_normal_list();
	cout << "\nTest test_max_value_single_node Result: " << "\n";
	test_max_value_single_node();
	cout << "\nTest test_max_value_large_values_list Result: " << "\n";
	test_max_value_large_values_list();*/

	/*cout << "\nTest test_arrange_odd_and_even_positions_mid_list Result: " << "\n";
	test_arrange_odd_and_even_positions_mid_list();
	cout << "\nTest test_arrange_odd_and_even_positions_small_list Result: " << "\n";
	test_arrange_odd_and_even_positions_small_list();
	cout << "\nTest test_arrange_odd_and_even_positions_long_list Result: " << "\n";
	test_arrange_odd_and_even_positions_long_list();
	cout << "\nTest test_arrange_odd_and_even_positions_long_list2 Result: " << "\n";
	test_arrange_odd_and_even_positions_long_list2();*/

	/*cout << "\nTest test_insert_alternate_single_node_in_newlist Result: " << "\n";
	test_insert_alternate_single_node_in_newlist();
	cout << "\nTest test_insert_alternate_newlist_larger_than_original_list Result: " << "\n";
	test_insert_alternate_newlist_larger_than_original_list();
	cout << "\nTest test_insert_alternate_empty_original_list Result: " << "\n";
	test_insert_alternate_empty_original_list();*/

	/*cout << "\nTest test_add_num_2_digit_lists Result: " << "\n";
	test_add_num_2_digit_lists();
	cout << "\nTest test_add_num_2_digit_and_3_digits_lists Result: " << "\n";
	test_add_num_2_digit_and_2_digits_lists();
	cout << "\nTest test_add_num_2_digit_and_4_digits_lists Result: " << "\n";
	test_add_num_2_digit_and_4_digits_lists();
	cout << "\nTest test_add_num_long_lists Result: " << "\n";
	test_add_num_long_lists();
	cout << "\nTest test_add_num_long_list_small_list Result: " << "\n";
	test_add_num_long_list_small_list();*/

	/*cout << "\nTest test_remove_duplicate_many_repeated_values Result: " << "\n";
	test_remove_duplicate_many_repeated_values();
	cout << "\nTest test_remove_duplicate_2_nodes_list Result: " << "\n";
	test_remove_duplicate_2_nodes_list();
	cout << "\nTest test_remove_duplicate_all_nodes_are_duplicates Result: " << "\n";
	test_remove_duplicate_all_nodes_are_duplicates();
	cout << "\nTest test_remove_duplicate_all_nodes_are_duplicates_except_one Result: " << "\n";
	test_remove_duplicate_all_nodes_are_duplicates_except_one();
	cout << "\nTest test_remove_duplicate_all_nodes_are_duplicates_except_2 Result: " << "\n";
	test_remove_duplicate_all_nodes_are_duplicates_except_2();*/

	cout << "\nTest test_reverse_from_to Result: " << "\n";
	test_reverse_chains_normal_reverse();
	cout << "\nTest test_reverse_from_to_k_equals_3 Result: " << "\n";
	test_reverse_chains_k_equals_3();
	cout << "\nTest test_reverse_chains_k_equals_2 Result: " << "\n";
	test_reverse_chains_k_equals_2();

	// must see it, otherwise RTE
	cout << "\n\nNO RTE\n";

	return 0;
}

