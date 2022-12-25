#include <iostream>
#include <stdio.h>
#include<math.h>
#include"function.h"
void ADD_BOOK();
void DEL_BOOK();
void FIND_BOOK();
void LIST_BOOK();
using namespace std;

int sum = 0;//Êé×ÜÊý

struct date {
	int year;
	int month;
	int day;
};

struct st {
	char Student_name[20];
	char Student_number[10];
};

struct bk {
	char Book_name[20];
	int Book_number;
};

struct book_st {
	int situation = 0;
	st student;
	bk book;
	date Return_date;
	date Borrowing_date;
}state[100];

int main() {
	char com[15];//´¢´æÃüÁî
	printf("Welcome to the Library Management System (YGY in December 2022)\n");
	while (1) {
		printf("Enter your command(You can enter ""HELP"" to get help):\n");
		printf(">>>");
		scanf_s("%s", com, 15);
		switch (toUnicode(com))
		{
			case U("HELP"):
				printf("1.ADD\n2.DEL\n3.FIND\n4.LIST\n5.CLEAR\n");
				break;
			case U("CLEAR"):
				system("cls");
				break;
			case U("ADD"):
				ADD_BOOK();
				break;
			case U("LIST"):
				LIST_BOOK();
				break;
			default:
				printf("The specified command was not found.\n");
				break;
		}
	}
	return 0;
}

void ADD_BOOK() {
	sum++;
	printf("The number of the book you want to add is: ");
	scanf_s("%d",&state[sum].book.Book_number);
	printf("The name of the book you want to add is: ");
	scanf_s("%s", state[sum].book.Book_name,20);
	printf("Whether the book is loaned?(1/0)");
	scanf_s("%d", &state[sum].situation);
	if (state[sum].situation) {
		printf("The student's name is:");
		scanf_s("%s", state[sum].student.Student_name,20);
		printf("The student's number is:");
		scanf_s("%s", state[sum].student.Student_number,20);
		printf("The borrowing date is (?/?/?) :");
		scanf_s("%d/%d/%d", &state[sum].Borrowing_date.year, &state[sum].Borrowing_date.month, &state[sum].Borrowing_date.day);
		printf("The estimated return date is (?/?/?) :");
		scanf_s("%d/%d/%d", &state[sum].Return_date.year, &state[sum].Return_date.month, &state[sum].Return_date.day);
	}
	printf("The addition of books was successful, and there are currently %d books in the system \n", sum);
}

void LIST_BOOK() {
	printf("There are currently %d books in the system \n", sum);
	if (sum > 0) {
		for (int i = 1; i <= sum; i++) {
			printf("Book:    %d.%s    %d \n", i, &state[i].book.Book_name, state[i].book.Book_number);
		}
	}
}

void FIND_BOOK() {
	
}

void DEL_BOOK() {
	sum--;
	state[sum];
}