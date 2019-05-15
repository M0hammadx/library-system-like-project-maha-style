/*
 * library.c
 *
 *  Created on: May 15, 2019
 *      Author: mh-sh
 */
#include "library_t.h"

static Acess_Mode_t acess_mode;
static char Password[] = "123";

typedef void (*fptr)(void);

static void library_print_all_users();
static void library_print_reservations();
static void library_print_availables();
static void library_add_student();
static void library_edit_record();
static void library_reserve_book();
static void library_cancel_reserve();

#define admin_functions_no 7
#define user_functions_no 3

static fptr admin_functions[] = { library_print_all_users,
		library_print_reservations, library_print_availables,
		library_add_student, library_edit_record, library_reserve_book,
		library_cancel_reserve, };

static fptr user_functions[] = { library_print_all_users,
		library_print_reservations, library_print_availables, };

u8 no_of_books = 5;
Book_t books[] = { { 0, 1, "Book 1" }, { 5, 0, "Book 2" }, { 4, 0, "Book 3" }, {
		7, 0, "Book 4" }, { 6, 0, "Book 5" }, };
u8 no_of_students = 3;
//Student_t students[] = { { 0, 18, "ali", &books[0] }, { 5, 15, "alaa", NULL }, {
//		3, 17, "omar", NULL }, };
void library_login() {
	//initial data
	{
		LS_Data_t d;
		d.id = 5;
		d.name = malloc(strlen("aa"));
		strcpy(d.name, "aa");
		d.age = 18;
		d.book = &books[0];
		linked_list_append(d);
		d.id = 6;
		d.name = malloc(strlen("bb"));
		strcpy(d.name, "bb");
		d.age = 15;
		d.book = NULL;
		linked_list_append(d);
		d.id = 7;
		d.name = malloc(strlen("cc"));
		strcpy(d.name, "cc");
		d.age = 17;
		d.book = NULL;
		linked_list_append(d);
	}

	printf("enter Acess_Mode\n");
	fflush(stdout);
	scanf("%i", (int *) &acess_mode);

	if (acess_mode == ADMIN) {
		s8 c = 2;
		char pass[10];
		while (c-- > 0) {
			printf("enter pass\n");
			fflush(stdout);
			scanf("%s", pass);
			if (!strcmp(pass, Password)) {
				break;
			}
		}
		if (c == -1) {
			printf("wrong pass no more tries\n");
			fflush(stdout);
			return;
		}
		int action_code;
		do {
			printf("choose admin action\n");
			fflush(stdout);
			scanf("%i", &action_code);
			if (action_code < admin_functions_no)
				admin_functions[action_code]();
			else {
				printf("out of range\n");
				return;
			}
		} while (1);
	} else {
		int action_code;
		while (1) {
			printf("choose user action\n");
			fflush(stdout);
			scanf("%i", &action_code);
			if (action_code < user_functions_no)
				user_functions[action_code]();
			else {
				printf("out of range\n");
				return;
			}
		}
	}
}

void library_print_all_users() { //0
//	FI(no_of_students)
//	{
//		printf("id: %i, name: %s, age: %i, reserving a book?: %s\n",
//				students[i].id, students[i].name, students[i].age,
//				(students[i].book == NULL ? "NO" : "YES"));
//	}
	linked_list_print();
	fflush(stdout);
}
void library_print_books() {
	FI(no_of_books)
	{
		printf("id: %i, name: %s, reserved?: %s\n", books[i].id, books[i].name,
				(books[i].is_reserved == 0 ? "NO" : "YES"));
	}
	fflush(stdout);
}
void library_print_reservations() { //1
	FI(no_of_books)
	{
		if (books[i].is_reserved)
			printf("id: %i, name: %s\n", books[i].id, books[i].name);
	}
	fflush(stdout);
}
void library_print_availables() { //2
	FI(no_of_books)
	{
		if (!books[i].is_reserved)
			printf("id: %i, name: %s\n", books[i].id, books[i].name);
	}
	fflush(stdout);
}
void library_add_student() { //3
	int id;
	int age;
	char *name = malloc(30);
	do {
		printf("enter id name age\n");
		fflush(stdout);
		scanf("%d %s %d", &id, name, &age);
	} while (valid_id(id));

	name = realloc(name, strlen(name) + 1);

	LS_Data_t d;
	d.id = id;
	d.name = name;
	d.age = age;
	d.book = NULL;
	linked_list_append(d);

}
void library_edit_record() { //4
	int id;
	int age;
	char *name = malloc(30);
	node_t *nptr;
	do {
		printf("enter id\n");
		fflush(stdout);
		scanf("%d", &id);
		nptr = linked_list_get_by_id(id);
	} while (!nptr);
	printf("enter new id name age \n");
	fflush(stdout);
	scanf("%d %s %d", &id, name, &age);
	nptr->data.id = id;
	nptr->data.name = name;
	nptr->data.age = age;
}
void library_reserve_book() { //5
	printf("enter student id and book id\n");
	fflush(stdout);
	int sid;
	int bid;
	node_t *nptr;
	scanf("%d %d", &sid, &bid);
	nptr = linked_list_get_by_id(sid);
	FI(no_of_books)
	{
		if (!books[i].is_reserved)
			nptr->data.book = &books[i], books[i].is_reserved = 1;
	}
}
void library_cancel_reserve() { //6
	printf("enter student id \n");
	fflush(stdout);
	int sid;
	node_t *nptr;
	scanf("%d", &sid);
	nptr = linked_list_get_by_id(sid);
	nptr->data.book->is_reserved = 0;
	nptr->data.book = NULL;
}
