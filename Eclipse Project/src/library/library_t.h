/*
 * library.h
 *
 *  Created on: May 15, 2019
 *      Author: mh-sh
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include "../linkedList/linked_list_t.h"
#include "../common.h"

typedef struct student {
	u8 id;
	u8 age;
	char *name;
	struct book *book;
} Student_t;

typedef struct book {
	u8 id;
	u8 is_reserved;
	char name[10];
} Book_t;

typedef enum {
	USER, ADMIN,
} Acess_Mode_t;

void library_login();

#endif /* LIBRARY_H_ */
