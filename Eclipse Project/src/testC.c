#define FI(n) for(int i=0;i<n;++i)
#define N 3
#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"
#include "linkedList/linked_list_t.h"

float (*arr[3])(int a);

float a(int a) {
	return 1.1;
}

typedef struct employee {
//	u16 salary;
//	u16 bonus;
//	u16 tax;
//	u8 id;
//	u32 sal;
	u64 a;
	u16 b;
	u32 c;
	u16 d;
	u64 x;
//	u8 aa;
//	u64 a;
//	u32 b;
} Employee;

typedef union {
//	u8 aa;
//	u16 a;
//	u32 b;
	u8 byte;
	struct {
		u8 b0 :1;
		u8 b1 :1;
		u8 b2 :1;
		u8 b3 :1;
		u8 b4 :1;
		u8 b5 :1;
		u8 b6 :1;
		u8 b7 :1;
	};
} reg;
//Employee Emp_A = { 1000, 50, 200 }, Emp_B = { 2000, 80, 300 }, Emp_C = { 3000,
//		100, 400 };
//u32 tot = 0;
//u32 calcSal(Employee * emp) {
////	return emp->bonus + emp->salary - emp->tax;
//}
Employee Emps[10];

typedef struct {
	enum {
		xxA, xxB, xxC,
	};
} stenum;
#define set_bit(x,i) {x|=(1<<i);}
#define clear_bit(x,i) {x&=~(1<<i);}
#define toggle_bit(x,i) {x^=(1<<i);}

//#define car bmw
//
//#if (car==0)
//
//#elif (car==1)
//
//#else
//#warning "POS wrong car"
//#endif
//

void* calloc_t(u8 n, u8 sz) {
	u8 * t = malloc(n * sz);
	for (u8 i = 0; i < n * sz; i++) {
		t[i] = 0;
	}
	return (void *) t;
}

int main() {
	linked_list_append();
	linked_list_append();
	linked_list_append();
	linked_list_delete(2);
	linked_list_get_size();
	linked_list_print();

//	u8 * carr = (u8 *) calloc_t(5, 1);
//
//	for (u8 i = 0; i < 4; ++i)
//		scanf("\n%c", carr + i);
//
//	for (u8 i = 0; i < 5; ++i)
//		printf("%c\n", *(carr + i));

//	int x = 4;
//	clear_bit(x, 2);
//	printf("%d", x);

//	define include warning error if else
//	char c;
//	Employee e;
//	printf("%x\n", &e.a);
//	printf("%x\n", &e.b);
//	printf("%x\n", &e.c);
//	printf("%x\n", &e.d);
//	printf("%x\n", &c);
//	printf("%d", sizeof(e));
//	char c[] = "1234";
//	printf("%d", sizeof(c));

//	reg r;
//	r.byte = 7;
//	r.b0 = 1;
//	r.b1 = 0;
//	r.b2 = 1;
//	r.b3 = 0;
//	r.b4 = 1;
//	r.b5 = 0;
//	r.b6 = 1;
//	r.b7 = 0;
////	printf("%d",r.b0);
//	printf("%d", r.byte);
//	Employee e;
//	int x;
//	printf("%d\n", sizeof(e));
//	printf("%x\n",(u32*) &e.b -(u32*) &e.a);
//	printf("%x\n", (u32*)&e.c - (u32*)&e.b);
//	printf("%x\n", (u32*)&e.d - (u32*)&e.c);
//	printf("%x\n", (u32*)&x -(u32*) &e.d);
//	FI(10)
//	{
//		Emps[i].id=i;
//		Emps[i].sal=i*1000;
//		printf("ID:%d, sal: %d \n",Emps[i].id,Emps[i].sal);
//	}

//	printf("%d \n", calcSal(&Emp_A));
//	printf("%d \n", calcSal(&Emp_B));
//	printf("%d \n", calcSal(&Emp_C));
//	tot += calcSal(&Emp_A);
//	tot += calcSal(&Emp_B);
//	tot += calcSal(&Emp_C);
//	Emp_A = Emp_B;
//	printf("%d \n", tot);

//	printf("%x \n", Emp_A);
//	printf("%x \n", Emp_A.salary);
//	printf("%x \n", Emp_A.bonus);
//	printf("%x \n", Emp_B);
//	printf("%x \n", Emp_B.salary);
//	printf("%x \n", Emp_B.bonus);
//	printf("%x \n", Emp_C);
//	printf("%x \n", Emp_C.salary);
//	printf("%x \n", Emp_C.bonus);

	return 0;
}
