#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to issue a book
void issuebook() {
    FILE *fp;
    int category;
    int issue_id;
    Book book;
    int found = 0;
    char category_str[10];
    char issue_id_str[20];
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
        fp = fopen("computer_books.txt", "r+");
    } else {
        fp = fopen("electronics_books.txt", "r+");
    }
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Get Book ID and validate input
    while (1) {
        printf("Enter Book ID: ");
        scanf("%s", issue_id_str);
        valid = 1;
        for (int i = 0; i < strlen(issue_id_str); i++) {
            if (!isdigit(issue_id_str[i])) {
                valid = 0;
                printf("Invalid Book ID. Please enter a valid integer.\n");
                break;
            }
        }
        if (valid) {
            issue_id = atoi(issue_id_str);
            break;
        }
    }

    // Search for the book by its ID
    while (fscanf(fp, "%d,%[^,],%[^,],%f\n", &book.book_id, book.book_name, book.author_name, &book.price) != EOF) {
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
