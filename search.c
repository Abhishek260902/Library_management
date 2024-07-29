#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to search for a book and display its status
void searchbookstatus() {
    FILE *fp;
    int category;
    int search_id;
    Book book;
    char category_str[10];
    char search_id_str[20];
    int found = 0;
    int valid;

    // Prompt for category and validate input
    while (1) {
        printf("Choose the category:\n\n");
        printf("1. Computer\n");
        printf("2. Electronics\n");
        printf("Choose a category: ");
        scanf("%s", category_str);

        // Check if input is a digit and valid category
        if (strlen(category_str) == 1 && isdigit(category_str[0])) {
            category = atoi(category_str);
            if (category == 1 || category == 2) {
                break;
            }
        }
        printf("Invalid category. Please enter a valid number (1 or 2).\n");
    }

    // Open appropriate file based on category
    if (category == 1) {
        fp = fopen("computer_books.txt", "r");
    } else {
        fp = fopen("electronics_books.txt", "r");
    }
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Get Book ID and validate input
    while (1) {
        printf("Enter Book ID: ");
        scanf("%s", search_id_str);
        valid = 1;
        for (int i = 0; i < strlen(search_id_str); i++) {
            if (!isdigit(search_id_str[i])) {
                valid = 0;
                printf("Invalid Book ID. Please enter a valid integer.\n");
                break;
            }
        }
        if (valid) {
            search_id = atoi(search_id_str);
            break;
        }
    }

    // Search for the book by its ID
    while (fscanf(fp, "%d,%[^,],%[^,],%f\n", &book.book_id, book.book_name, book.author_name, &book.price) != EOF) {
        if (search_id == book.book_id) {
            printf("Book information:\n\n");
            printf("Book ID\tBook name\tAuthor name\tPrice\n");
            printf("%d\t%s\t\t%s\t\t%.2f\n", book.book_id, book.book_name, book.author_name, book.price);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Book not found\n");
    }
}
