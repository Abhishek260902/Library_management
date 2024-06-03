#include "library.h"
#include <stdio.h>
#include <stdlib.h>

// Function to display book information
void displaybookinfo() {
    FILE *fp;
    int category;
    Book book;

    printf("Choose the category:\n\n");
    printf("1. Computer\n");
    printf("2. Electronics\n");
    printf("Choose a category: ");
    scanf("%d", &category);

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

    printf("Book Information:\n\n");
    printf("Book ID\tBook Name\tAuthor Name\tPrice\n");
    while (fscanf(fp, "%d,%[^,],%[^,],%d\n", &book.book_id, book.book_name,  book.author_name, & book.price) != EOF) {
        printf("%d\t%s\t\t%s\t\t%d\n", book.book_id, book.book_name, book.author_name, book.price);
    }
    fclose(fp);
}
