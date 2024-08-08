#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "library.h"

void addbook() {
    FILE *fp;
    int category;
    Book newbook;
    char *book_id_str = malloc(20 * sizeof(char));
    char *book_name = malloc(50 * sizeof(char));
    char *author_name = malloc(50 * sizeof(char));
    char *price_str = malloc(20 * sizeof(char));
    char *category_str = malloc(10 * sizeof(char));
    int valid;

    if (book_id_str == NULL || book_name == NULL || author_name == NULL || price_str == NULL || category_str == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

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
        fp = fopen("computer_books.txt", "a+");
    } else {
        fp = fopen("electronics_books.txt", "a+");
    }
    if (fp == NULL) {
        printf("Error opening file\n");
        free(book_id_str);
        free(book_name);
        free(author_name);
        free(price_str);
        free(category_str);
        return;
    }

    // Get Book ID
    while (1) {
        printf("Enter Book ID: ");
        scanf("%s", book_id_str);
        valid = 1;
        for (int i = 0; i < strlen(book_id_str); i++) {
            if (!isdigit(book_id_str[i])) {
                valid = 0;
                printf("Invalid Book ID. Please enter a valid integer.\n");
                break;
            }
        }
        if (valid) {
            newbook.book_id = atoi(book_id_str);
            break;
        }
    }

    // Get Book Name
    while (1) {
        printf("Enter Book Name: ");
        scanf("%s", book_name);
        valid = 1;
        for (int i = 0; i < strlen(book_name); i++) {
            if (isdigit(book_name[i])) {
                valid = 0;
                printf("Invalid Book Name. Please enter a valid name without digits.\n");
                break;
            }
        }
        if (valid) {
            strcpy(newbook.book_name, book_name);
            break;
        }
    }

    // Get Author Name
    while (1) {
        printf("Enter Author Name: ");
        scanf("%s", author_name);
        valid = 1;
        for (int i = 0; i < strlen(author_name); i++) {
            if (isdigit(author_name[i])) {
                valid = 0;
                printf("Invalid Author Name. Please enter a valid name without digits.\n");
                break;
            }
        }
        if (valid) {
            strcpy(newbook.author_name, author_name);
            break;
        }
    }

    // Get Price
    while (1) {
        printf("Enter Price: ");
        scanf("%s", price_str);
        valid = 1;
        for (int i = 0; i < strlen(price_str); i++) {
            if (!isdigit(price_str[i]) && price_str[i] != '.') {
                valid = 0;
                printf("Invalid Price. Please enter a valid float value.\n");
                break;
            }
        }
        if (valid) {
            newbook.price = atof(price_str);
            break;
        }
    }

    // Reset file pointer to beginning
    rewind(fp);

    // Check for duplicate book ID
    Book temp;
    while (fscanf(fp, "%d,%49[^,],%49[^,],%f\n", &temp.book_id, temp.book_name, temp.author_name, &temp.price) != EOF) {
        if (temp.book_id == newbook.book_id) {
            printf("Book ID already exists. Please try again.\n");
            fclose(fp);
            free(book_id_str);
            free(book_name);
            free(author_name);
            free(price_str);
            free(category_str);
            return;
        }
    }

    // Write new book to file
    fprintf(fp, "%d,%s,%s,%f\n", newbook.book_id, newbook.book_name, newbook.author_name, newbook.price);
    fclose(fp);
    printf("Book added successfully!\n");

    free(book_id_str);
    free(book_name);
    free(author_name);
    free(price_str);
    free(category_str);
}
