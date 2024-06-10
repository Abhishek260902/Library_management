#include "library.h"
#include <stdio.h>

int main() {
    int choice;

    do {
        printf("---------Main Menu--------\n\n");
        printf("1. Add books\n");
        printf("2. Display book information\n");
        printf("3. Searching books status\n");
        printf("4. Issue a book\n");
        printf("5. Delete a book\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n\n");

        switch (choice) {
            case 1:
                addbook();
                break;
            case 2:
                displaybookinfo();
                break;
            case 3:
                searchbookstatus();
                break;
            case 4:
                issuebook();
                break;
            case 5:
                deletebook();
                break;
            case 6:
                printf("The library is closed\n\n");
                printf("Have a nice day\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
