#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to delete a book
void deletebook() {
    FILE *fp, *temp;
    int category;
    int delete_id;
    Book book;
    char category_str[10];
    char delete_id_str[20];
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

    // Get Book ID and validate input
    while (1) {
        printf("Enter the Book ID to delete: ");
        scanf("%s", delete_id_str);
        valid = 1;
        for (int i = 0; i < strlen(delete_id_str); i++) {
            if (!isdigit(delete_id_str[i])) {
                valid = 0;
                printf("Invalid Book ID. Please enter a valid integer.\n");
                break;
            }
        }
        if (valid) {
            delete_id = atoi(delete_id_str);
            break;
        }
    }

    printf("\n\n");

    const char *filename;
    if (category == 1) {
        filename = "computer_books.txt";
    } else {
        filename = "electronics_books.txt";
    }

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Error opening temporary file\n");
        fclose(fp);
        return;
    }

    while (fscanf(fp, "%d,%[^,],%[^,],%f\n", &book.book_id, book.book_name, book.author_name, &book.price) != EOF) {
        if (delete_id == book.book_id) {
            found = 1;
            printf("Book with ID %d deleted successfully.\n", delete_id);
        } else {
            fprintf(temp, "%d,%s,%s,%.2f\n", book.book_id, book.book_name, book.author_name, book.price);
        }
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        if (remove(filename) != 0) {
            printf("Error deleting the original file %s\n", filename);
        } else if (rename("temp.txt", filename) != 0) {
            printf("Error renaming temporary file\n");
        }
    } else {
        printf("Book not found\n");
        remove("temp.txt");
    }
}
