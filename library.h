#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct {
    int book_id;
    char book_name[50];
    char author_name[50];
    int price;
} Book;

void addbook();
void displaybookinfo();
void searchbookstatus();
void issuebook();

#endif