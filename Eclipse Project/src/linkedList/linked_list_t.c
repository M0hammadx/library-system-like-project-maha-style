/*
 * linked_list_t.c
 *
 *  Created on: May 1, 2019
 *      Author: mh-sh
 */

#include "linked_list_t.h"

node_t * head;
node_t * tail;
u32 no_of_nodes;

void linked_list_append() {
	node_t* newNode = (node_t *) malloc(sizeof(node_t));
	scanf("%d", &(newNode->data));
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

void linked_list_delete(u32 val) {
	node_t *ptr = head, *del;
	while (head && head->data == val) {
		del = head;
		head = head->next;
		free(del);
		no_of_nodes--;
	}
	if (no_of_nodes == 0)
		head = NULL;
	ptr = head;
	while (ptr && ptr->next) {
		if (ptr->next->data == val) {
			node_t* del = ptr->next;
			ptr->next = ptr->next->next;
			free(del);
			no_of_nodes--;
		} else {
			ptr = ptr->next;
		}
	}
	tail = ptr;
}

void linked_list_print() {
	node_t* ptr = head;
	printf("print\n");
	while (ptr) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

