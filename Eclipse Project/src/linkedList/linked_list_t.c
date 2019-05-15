/*
 * linked_list_t.c
 *
 *  Created on: May 1, 2019
 *      Author: mh-sh
 */

#include "linked_list_t.h"

static node_t * head;
static node_t * tail;
static u32 no_of_nodes;

void print_data(LS_Data_t data) {
	printf("id: %i, name: %s, age: %i, reserving a book?: %s\n", data.id,
			data.name, data.age, (data.book == NULL ? "NO" : "YES"));

}
u8 valid_id(u8 id) {
	node_t* ptr = head;
	while (ptr) {
		if (ptr->data.id == id)
			return 1;
		ptr = ptr->next;
	}
	return 0;
}
node_t * linked_list_get_by_id(u8 id) {
	node_t* ptr = head;
	while (ptr) {
		if (ptr->data.id == id)
			return ptr;
		ptr = ptr->next;
	}
	return NULL;
}
void free_data(LS_Data_t data) {
	free(data.name);
}
static void free_node(node_t* node) {
	free_data(node->data);
	free(node);
}

void linked_list_append(LS_Data_t data) {
	node_t* newNode = (node_t *) malloc(sizeof(node_t));
	memcpy(&(newNode->data), &data, sizeof(LS_Data_t));

	if (!head) {
		tail = newNode;
		head = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	} else {
		tail->next = newNode;
		tail = newNode;
		tail->next = NULL;
	}
	no_of_nodes++;
}
void linked_list_get_size() {
	printf("sz %u\n", no_of_nodes);
}
void linked_list_delete_head() {
	node_t *del;
	if (head) {
		del = head;
		head = head->next;
		free_node(del);
		no_of_nodes--;
	}
	if (no_of_nodes == 0)
		tail = NULL;
}
void linked_list_delete_tail() {
	node_t *del;
	if (head == tail) {
		del = head;
		head = head->next;
		free_node(del);
		no_of_nodes--;
	}
}
void linked_list_delete(LS_Data_t val) {
	node_t *ptr = head, *del;
	while (head && !memcmp(&val, &(head->data), sizeof(LS_Data_t))) {
		del = head;
		head = head->next;
		free_node(del);
		no_of_nodes--;
	}
	if (no_of_nodes == 0)
		head = NULL;
	ptr = head;
	while (ptr && ptr->next) {
		if (!memcmp(&val, &(ptr->next->data), sizeof(LS_Data_t))) {
			node_t* del = ptr->next;
			ptr->next = ptr->next->next;
			free_node(del);
			no_of_nodes--;
		} else {
			ptr = ptr->next;
		}
	}
	tail = ptr;
}

void linked_list_print() {
	node_t* ptr = head;
	printf("print ");
	while (ptr) {
//		printf("%d ", ptr->data);
		print_data(ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

