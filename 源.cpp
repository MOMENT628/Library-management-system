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
	char Student_name[200];
	char Student_number[200];
};

struct bk {
	char Book_name[200];
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
			case U("FIND"):
				FIND_BOOK();
				break;
			case U("DEL"):
				DEL_BOOK();
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
	scanf_s("%s", state[sum].book.Book_name,200);
	printf("Whether the book is loaned?(1/0)");
	scanf_s("%d", &state[sum].situation);
	if (state[sum].situation) {
		printf("The student's name is:");
		scanf_s("%s", state[sum].student.Student_name,200);
		printf("The student's number is:");
		scanf_s("%s", state[sum].student.Student_number,200);
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
			printf("Book:%d.%s %d \n", i, &state[i].book.Book_name, state[i].book.Book_number);
		}
	}
}

int findnumber;
int flag=0;

void FIND_BOOK() {
	flag = 0;
	printf("The number of the book you are looking for is: ");
	scanf_s("%d", &findnumber);
	for (int i = 1; i <= sum; i++) {
		if (findnumber==state[i].book.Book_number) {
			flag = 1;
			printf("--------------------------------------------- \n");
			printf("Book name:   %s\n", state[i].book.Book_name);
			printf("Book number: %d\n", state[i].book.Book_number);
			if (state[i].situation==1) {
				printf("The book is checked out.\n");
				printf("The borrower's name is: %s\n", state[i].student.Student_name);
				printf("The borrower's student number is: %s\n", state[i].student.Student_number);
				printf("The borrowing date is: %d/%d/%d\n", state[i].Borrowing_date.year, state[i].Borrowing_date.month, state[i].Borrowing_date.day);
				printf("The estimated return date is: %d/%d/%d\n", state[i].Return_date.year, state[i].Return_date.month, state[i].Return_date.day);
			}
			else {
				printf("The book is not checked out.\n");
			}
			printf("--------------------------------------------- \n");
		}
	}
	if (flag == 1) {

	}
	else {
		printf("There is no book in the system. \n");
	}
}

int delnumber;
int delsum;
int delYN;
int findYN=0;

void DEL_BOOK() {
	findYN = 0;
	printf("The number of the book you want to delete is: ");
	scanf_s("%d", &delnumber);
	printf("Are you sure you want to delete all the information in this book?(1/0)");
	scanf_s("%d", &delYN);
	if (delYN==1) {
		for (int i = 1; i <= sum; i++) {
			if (delnumber == state[i].book.Book_number) {
				delsum = i;
				findYN = 1;
			}
		}
		if (findYN==1) {
			for (int i = delsum; i <= sum;i++) {
				state[i] = state[i + 1];
			}
			sum--;
			printf("This book has since been deleted. \n");
		}
		else {
			printf("There is no book in the system. \n");
		}
	}
	else {
		printf("Ok, already exited. \n");
	}
}