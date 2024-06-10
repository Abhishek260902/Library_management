#include "library.h"
#include <stdio.h>
#include <stdlib.h>


void searchbookstatus() {
    FILE *fp;
    int category;
    int search_id;
    Book book;
    int found = 0;

    printf("Choose the category:\n\n");
    printf("1. Computer\n");
    printf("2. Electronics\n");
    printf("Choose a category: ");
    scanf("%d", &category);
    printf("\n\n");

    printf("Enter the Book ID to search: ");
    scanf("%d", &search_id);


    if (category == 1) {
        fp = fopen("computer_books.txt", "r");
        if (fp == NULL) {
            printf("Error opening file\n");
            return;
        }
    } else if (category == 2) {
        fp = fopen("electronics_books.txt", "r");
        if (fp == NULL) {
            printf("Error opening file\n");
            return;
        }
    } else {
        printf("Invalid category\n");
        return;
    }

    while (fscanf(fp, "%d,%[^,],%[^,],%d\n", &book.book_id, book.book_name, book.author_name, &book.price) != EOF) {
        if (search_id == book.book_id) {
            printf("Book information:\n\n");
            printf("Book ID\tBook name\tAuthor name\tPrice\n");
            printf("%d\t%s\t\t%s\t\t%d\n", book.book_id, book.book_name, book.author_name, book.price);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Book not found\n");
    }
}