#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "library.h"

void searchbookstatus() {
    FILE *fp;
    int category;
    int search_id;
    Book book;
    char category_str[10];
    char search_id_str[20];
    int found = 0;

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

    while (1) {
        printf("Enter Book ID to search: ");
        scanf("%s", search_id_str);

        if (strlen(search_id_str) > 0 && isdigit(search_id_str[0])) {
            search_id = atoi(search_id_str);
            break;
        } else {
            printf("Invalid input. Please enter a valid integer Book ID.\n");
        }
    }

    while (fscanf(fp, "%d,%49[^,],%49[^,],%f,%49[^\n]\n", &book.book_id, book.book_name, book.author_name, &book.price, book.borrower_name) != EOF) {
        if (book.book_id == search_id) {
            printf("Book found:\n");
            printf("Book ID: %d\n", book.book_id);
            printf("Book name: %s\n", book.book_name);
            printf("Author name: %s\n", book.author_name);
            printf("Price: %.2f\n", book.price);
            printf("Borrower name: %s\n", book.borrower_name[0] ? book.borrower_name : "Not issued");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(fp);
}
