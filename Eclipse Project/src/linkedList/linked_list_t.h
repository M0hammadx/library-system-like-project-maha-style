/*
 * linked_list_t.h
 *
 *  Created on: May 1, 2019
 *      Author: mh-sh
 */

#ifndef LINKEDLIST_LINKED_LIST_T_H_
#define LINKEDLIST_LINKED_LIST_T_H_
#include "..\datatypes.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node {
	u32 data;
	node_t *next, *prev;
};


#endif /* LINKEDLIST_LINKED_LIST_T_H_ */
