#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_NAME_LENGTH 50

typedef struct {
    int book_id;
    char book_name[MAX_NAME_LENGTH];
    char author_name[MAX_NAME_LENGTH];
    float price;
    char borrower_name[MAX_NAME_LENGTH];  // New field for the borrower's name
} Book;

void addbook();
void displaybookinfo();
void searchbookstatus();
void issuebook();
void deletebook();

#endif
