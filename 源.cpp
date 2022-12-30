#include <iostream>
#include <stdio.h>
#include<math.h>
#include"function.h"
void ADD_BOOK();
void DEL_BOOK();
void FIND_BOOK();
int findYN = 0;
void LIST_BOOK();
int unlock();
void PASSWORD();
int password=1234;
int lockYN = 0;
void REVISE_BOOK();
void save();
void read();
using namespace std;

int sum = 0;//书总数

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
	char com[15];//储存命令
	read();
	title();
	while (1) {
		printf("Enter your command(You can enter ""HELP"" to get help):\n");
		printf(">>>");
		scanf_s("%s", com, 15);
		switch (toUnicode(com))
		{
			case U("HELP"):
				printf("1.ADD\n2.DEL\n3.FIND\n4.LIST\n5.CLEAR\n6.PASSWORD\n7.REVISE\n8.SAVE\n9.READ\n");
				break;
			case U("CLEAR"):
				system("cls");
				break;
			case U("ADD"):
				if (unlock()) {
					ADD_BOOK();
				}
				else {
					printf("The password is incorrect\n");
				}
			case U("LIST"):
				LIST_BOOK();
				break;
			case U("FIND"):
				FIND_BOOK();
				break;
			case U("DEL"):
				if (unlock()) {
					DEL_BOOK();
				}else{
					printf("The password is incorrect\n");
				}
				break;
			case U("PASSWORD"):
				PASSWORD();
				break;
			case U("REVISE"):
				if (unlock()) {
					REVISE_BOOK();
				}
				else {
					printf("The password is incorrect\n");
				}
				break;
			case U("SAVE"):
				save();
				break;
			case U("READ"):
				save();
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
			printf("Book:%d.%s %d \n", i, state[i].book.Book_name, state[i].book.Book_number);
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

int lock_password;

int unlock() {
	printf("Please enter a four-digit PIN (1234):");
	scanf_s("%d",&lock_password);
	if (lock_password==password) {
		return 1;
	}
	else {
		return 0;
	}
}

void PASSWORD() {
	if (unlock()==1) {
		printf("Please set a new four-digit passcode (****) :");
		scanf_s("%d",&password);
		printf("The password is set successfully, and you need to enter this password for some important operations. \n");
	}
	else {
		printf("The password is incorrect\n");
	}
	
}

int revise_Book_number;
char revise_Book_com[15];
int revise_Book_sum;

void REVISE_BOOK() {
	findYN = 0;
	printf("The serial number of the book for which you want to change information: ");
	scanf_s("%d", &revise_Book_number);
	for (int i = 0; i <= sum;i++) {
		if (revise_Book_number==state[i].book.Book_number) {
			findYN = 1;
			revise_Book_sum = i;
		}
	}
	if (findYN==1) {
		printf("The information you want to modify is: ");
		scanf_s("%s", revise_Book_com,15);
		switch (toUnicode(revise_Book_com))
		{
		case U("bookname"):
			printf("The name of the book you want to change is: ");
			scanf_s("%s", state[revise_Book_sum].book.Book_name, 200);
			break;
		case U("booknumber"):
			printf("The number of the book you want to change is: ");
			scanf_s("%d", &state[revise_Book_sum].book.Book_number);
			break;
		case U("studentname"):
			printf("The student's name is:");
			scanf_s("%s", state[revise_Book_sum].student.Student_name, 200);
			break;
		case U("studentnumber"):
			printf("The student's number is:");
			scanf_s("%s", state[revise_Book_sum].student.Student_number, 200);
			break;
		case U("booksituation"):
			printf("Whether the book is loaned?(1/0)");
			scanf_s("%d", &state[revise_Book_sum].situation);
			break;
		default:
			printf("The specified command was not found.\n");
			break;
		}
		printf("The change is complete.\n ");
	}
	else {
		printf("There is no book in the system. \n");
	}
}


void save() {
	FILE* fp;

	fopen_s(&fp, "information.txt", "w");    //打开文件
	fprintf(fp, "%d\n", sum);
	for (int i = 1; i <= sum; i++)
	{
		fprintf(fp,"Book name:   %s\t", state[i].book.Book_name);
		fprintf(fp,"Book number: %d\t", state[i].book.Book_number);
		fprintf(fp, "situation :%d\t", state[i].situation);
		if (state[i].situation == 1) {
			fprintf(fp,"The book is checked out.\t");
			fprintf(fp,"The borrower's name is: %s\t", state[i].student.Student_name);
			fprintf(fp, "The borrower's student number is: %s\t", state[i].student.Student_number);
			fprintf(fp,"The borrowing date is: %d/%d/%d\t", state[i].Borrowing_date.year, state[i].Borrowing_date.month, state[i].Borrowing_date.day);
			fprintf(fp,"The estimated return date is: %d/%d/%d\n", state[i].Return_date.year, state[i].Return_date.month, state[i].Return_date.day);
		}
		else {
			fprintf(fp,"The book is not checked out.\n");
		}
	}
	fclose(fp);    //关闭文件
}

void read() {
	FILE* fp;

	fopen_s(&fp, "information.txt", "r+");    //打开文件
	fscanf_s(fp, "%d\n", &sum);
	for (int i = 1; i <= sum; i++)
	{
		fscanf_s(fp, "Book name:   %s\t", state[i].book.Book_name,15);
		fscanf_s(fp, "Book number: %d\t", &state[i].book.Book_number);
		fscanf_s(fp, "situation :%d\t", &state[i].situation);
		if (state[i].situation == 1) {
			fscanf_s(fp, "The book is checked out.\t");
			fscanf_s(fp, "The borrower's name is: %s\t", state[i].student.Student_name,20);
			fscanf_s(fp, "The borrower's student number is: %s\t", state[i].student.Student_number,20);
			fscanf_s(fp, "The borrowing date is: %d/%d/%d\t", &state[i].Borrowing_date.year, &state[i].Borrowing_date.month, &state[i].Borrowing_date.day);
			fscanf_s(fp, "The estimated return date is: %d/%d/%d\n", &state[i].Return_date.year, &state[i].Return_date.month, &state[i].Return_date.day);
		}
		else {
			fscanf_s(fp, "The book is not checked out.\n");
		}
	}
	fclose(fp);    //关闭文件
}