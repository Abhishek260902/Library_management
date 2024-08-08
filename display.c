#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "library.h"

void displaybookinfo() {
    FILE *fp;
    int category;
    Book book;
    char category_str[10];

    while (1) {
        printf("Choose the category:\n\n");
        printf("1. Computer\n");
        printf("2. Electronics\n");
        printf("Choose a category: ");
        scanf("%s", category_str);

        if (strlen(category_str) == 1 && isdigit(category_str[0])) {
            category = atoi(category_str);
            if (category == 1 || category == 2) {
                break;
            }
        }
        printf("Invalid category. Please enter a valid number (1 or 2).\n");
    }

    if (category == 1) {
        fp = fopen("computer_books.txt", "r");
    } else {
        fp = fopen("electronics_books.txt", "r");
    }
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    printf("Book information:\n\n");
    printf("Book ID\tBook name\tAuthor name\tPrice\tBorrower name\n");

    int bookFound = 0;
    while (fscanf(fp, "%d,%49[^,],%49[^,],%f,%49[^\n]\n", &book.book_id, book.book_name, book.author_name, &book.price, book.borrower_name) != EOF) {
        printf("%d\t%s\t\t%s\t\t%.2f\t%s\n", book.book_id, book.book_name, book.author_name, book.price, book.borrower_name[0] ? book.borrower_name : "Not issued");
        bookFound = 1;
    }

    if (!bookFound) {
        printf("No books found in this category.\n");
    }

    fclose(fp);
}
