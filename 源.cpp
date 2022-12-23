#include <iostream>
#include <stdio.h>
#include<math.h>
#include"function.h"
void ADD_BOOK();
void DEL_BOOK();
void FIND_BOOK();
using namespace std;

int sum = 1;//Êé×ÜÊý

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
			default:
				printf("The specified command was not found.\n");
				break;
		}
	}
	return 0;
}

void ADD_BOOK() {
	printf("The number of the book you want to add is: ");
	scanf_s("%d",&state[sum].book.Book_number);
	printf("The name of the book you want to add is: ");
	scanf_s("%s", state[sum].book.Book_name,20);
	printf("Whether the book is loaned?(1/0)");
	scanf_s("%d", &state[sum].situation);
	if (state[sum].situation) {

	}
	sum++;
}

void DEL_BOOK() {
	sum--;
	state[sum];
}

void FIND_BOOK() {
	sum++;
	state[sum];
}