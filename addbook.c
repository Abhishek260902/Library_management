#include "library.h"
#include <stdio.h>
#include <stdlib.h>

void addbook() {
    FILE *fp;
    int category;
    Book newbook;

    printf("Choose the category:\n\n");
    printf("1. Computer\n");
    printf("2. Electronics\n");
    printf("Choose a category: ");
    scanf("%d", &category);

    if (category == 1) {
        fp = fopen("computer_books.txt", "a");
        if (fp == NULL) {
            printf("Error opening file\n");
            return;
        }
    } else if (category == 2) {
        fp = fopen("electronics_books.txt", "a");
        if (fp == NULL) {
            printf("Error opening file\n");
            return;
        }
    } else {
        printf("Invalid category\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &newbook.book_id);
    printf("Enter Book Name: ");
    scanf("%s", newbook.book_name);
    printf("Enter Author Name: ");
    scanf("%s", newbook.author_name);
    printf("Enter Price: ");
    scanf("%d", &newbook.price);

    fprintf(fp, "%d,%s,%s,%d\n",newbook.book_id,newbook.book_name,newbook.author_name,newbook.price);
    fclose(fp);
    printf("Book added successfully!\n");
}
