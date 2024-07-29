#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int book_id;
    char book_name[50];
    char author_name[50];
    float price;
} Book;

void addbook();
void displaybookinfo();
void searchbookstatus();
void issuebook();
void deletebook();

#endif
