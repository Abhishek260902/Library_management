
#include"issuebook.c"
#include"delete.c"
#include"addbook.c"
#include"display.c"
#include"search.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "library.h"

int is_valid_number(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char choice_str[10];
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Book Information\n");
        printf("3. Issue Book \n");
        printf("4. Search Book Status\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", choice_str);

        if (!is_valid_number(choice_str)) {
            printf("Invalid choice. Please enter a valid number.\n");
            continue;
        }

        choice = atoi(choice_str);

        switch (choice) {
            case 1:
                addbook();
                break;
            case 2:
                displaybookinfo();
                break;
            case 3:
                issuebook();
                break;
            case 4:
                searchbookstatus();
                break;
            case 5:
                deletebook();
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid number.\n");
        }
    }

    return 0;
}
