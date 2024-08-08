#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "library.h"

int isValidName(const char *name) {
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

void issuebook() {
    FILE *fp, *temp_fp;
    int category;
    int book_id;
    char book_id_str[20];
    Book book;
    int found = 0;
    char category_str[10];
    char borrower_name[MAX_NAME_LENGTH];

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
        temp_fp = fopen("temp_computer_books.txt", "w");
    } else {
        fp = fopen("electronics_books.txt", "r");
        temp_fp = fopen("temp_electronics_books.txt", "w");
    }
    if (fp == NULL || temp_fp == NULL) {
        printf("Error opening file\n");
        if (fp != NULL) fclose(fp);
        if (temp_fp != NULL) fclose(temp_fp);
        return;
    }

    while (1) {
        printf("Enter Book ID to issue: ");
        scanf("%s", book_id_str);

        if (strlen(book_id_str) > 0 && isdigit(book_id_str[0])) {
            book_id = atoi(book_id_str);
            break;
        } else {
            printf("Invalid input. Please enter a valid integer Book ID.\n");
        }
    }

    while (fscanf(fp, "%d,%49[^,],%49[^,],%f,%49[^\n]\n", &book.book_id, book.book_name, book.author_name, &book.price, book.borrower_name) != EOF) {
        if (book.book_id == book_id) {
            printf("Book found:\n");
            printf("Book ID: %d\n", book.book_id);
            printf("Book name: %s\n", book.book_name);
            printf("Author name: %s\n", book.author_name);
            printf("Price: %.2f\n", book.price);

            while (1) {
                printf("Enter Borrower Name: ");
                scanf(" %[^\n]", borrower_name);  // Note: This format string allows spaces in the input
                if (isValidName(borrower_name)) {
                    break;
                } else {
                    printf("Invalid name. Please enter a valid name without digits or symbols.\n");
                }
            }
            strcpy(book.borrower_name, borrower_name);

            fprintf(temp_fp, "%d,%s,%s,%f,%s\n", book.book_id, book.book_name, book.author_name, book.price, book.borrower_name);
            printf("Book issued to %s successfully!\n", book.borrower_name);
            found = 1;
        } else {
            fprintf(temp_fp, "%d,%s,%s,%f,%s\n", book.book_id, book.book_name, book.author_name, book.price, book.borrower_name);
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(fp);
    fclose(temp_fp);

    if (category == 1) {
        remove("computer_books.txt");
        rename("temp_computer_books.txt", "computer_books.txt");
    } else {
        remove("electronics_books.txt");
        rename("temp_electronics_books.txt", "electronics_books.txt");
    }
}
