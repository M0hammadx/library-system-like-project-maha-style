/*
 * linked_list_t.h
 *
 *  Created on: May 1, 2019
 *      Author: mh-sh
 */

#ifndef LINKEDLIST_LINKED_LIST_T_H_
#define LINKEDLIST_LINKED_LIST_T_H_
#include "../common.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

typedef struct data {
	u8 id;
	u8 age;
	char *name;
	struct book *book;
} LS_Data_t;
struct node {
	LS_Data_t data;
	node_t *next, *prev;
};

void linked_list_append(LS_Data_t data);
void linked_list_get_size();
void linked_list_delete_head();
void linked_list_delete_tail();
void linked_list_delete(LS_Data_t val);
void linked_list_print();

node_t * linked_list_get_by_id(u8 id);
u8 valid_id(u8 id);
void print_data(LS_Data_t data);
#endif /* LINKEDLIST_LINKED_LIST_T_H_ */
