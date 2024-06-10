#include "library.h"
#include <stdio.h>
#include <stdlib.h>

void deletebook() {
    FILE *fp, *temp;
    int category;
    int delete_id;
    Book book;
    int found = 0;

    printf("Choose the category:\n\n");
    printf("1. Computer\n");
    printf("2. Electronics\n");
    printf("Choose a category: ");
    scanf("%d", &category);
    printf("\n\n");

    printf("Enter the Book ID to delete: ");
    scanf("%d", &delete_id);
    printf("\n\n");

    if (category == 1) {
        fp = fopen("computer_books.txt", "r");
        if (fp == NULL) {
            printf("Error opening file\n");
            return;
        }
        temp = fopen("temp.txt", "w");
        if (temp == NULL) {
            printf("Error opening temporary file\n");
            fclose(fp);
            return;
        }
    } else if (category == 2) {
        fp = fopen("electronics_books.txt", "r");
        if (fp == NULL) {
            printf("Error opening file\n");
            return;
        }
        temp = fopen("temp.txt", "w");
        if (temp == NULL) {
            printf("Error opening temporary file\n");
            fclose(fp);
            return;
        }
    } else {
        printf("Invalid category\n");
        return;
    }

    while (fscanf(fp, "%d,%[^,],%[^,],%d\n", &book.book_id, book.book_name, book.author_name, &book.price) != EOF) {
        if (delete_id == book.book_id) {
            found = 1;
            printf("Book with ID %d deleted successfully.\n", delete_id);
        } else {
            fprintf(temp, "%d,%s,%s,%d\n", book.book_id, book.book_name, book.author_name, book.price);
        }
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        if (category == 1) {
            remove("computer_books.txt");
            rename("temp.txt", "computer_books.txt");
        } else if (category == 2) {
            remove("electronics_books.txt");
            rename("temp.txt", "electronics_books.txt");
        }
    } else {
        printf("Book not found\n");
        remove("temp.txt");
    }
}