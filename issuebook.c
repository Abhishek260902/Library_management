#include "library.h"
#include <stdio.h>
#include <stdlib.h>

void issuebook() {
    FILE *fp;
    int category;
    int issue_id; // Variable to hold the book ID to issue
    Book book;
    int found = 0;

    printf("Choose the category:\n\n");
    printf("1. Computer\n");
    printf("2. Electronics\n");
    printf("Choose a category: ");
    scanf("%d", &category);
    printf("\n\n");

    printf("Enter the Book ID to issue: ");
    scanf("%d", &issue_id);
    printf("\n\n");

    if (category == 1) {
        fp = fopen("computer_books.txt", "r+");
        if (fp == NULL) {
            printf("Error opening file\n");
            return;
        }
    } else if (category == 2) {
        fp = fopen("electronics_books.txt", "r+");
        if (fp == NULL) {
            printf("Error opening file\n");
            return;
        }
    } else {
        printf("Invalid category\n");
        return;
    }

    while (fscanf(fp, "%d,%[^,],%[^,],%d\n", &book.book_id, book.book_name, book.author_name, &book.price) != EOF) {


        if (issue_id == book.book_id) {
            found = 1;
            printf("%s is issued successfully.\n", book.book_name);
            break;

        }
    }


    fclose(fp);

    if (!found) {
        printf("Book not found\n");
    }
}