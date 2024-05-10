#include<stdio.h>

void addbook();
void displaybookinfo();
void searchbookstatus();
void issuebook();

int main() {
    int choice;

    do {
        printf("---------Main Menu--------\n\n");

        printf("1. Add Books\n");
        printf("2. Display Book Information\n");
        printf("3. Searching Books Status\n");
        printf("4. Issue the Books\n"); 
        printf("5. Exit\n\n");

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
                printf("The library is closed\n\n");
                printf("Have a nice day\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add book information
void addbook() {
    printf("You can add book information\n\n");

    printf("Choose the category:\n\n");
    printf("1. Computer\n");
    printf("2. Electronics\n");

    int category;
    printf("Choose a category: ");
    scanf("%d", &category);
    printf("\n\n");

    if (category == 1) {
        printf("You have chosen Computer category\n\n");
        
        char book_namea[50];
        char author_namea[50];
        int pricea;

        printf("Book Name : ");
        scanf("%s",book_namea);
        printf("\n\n");

        printf("Author Name : ");
        scanf("%s", author_namea); 
        printf("\n\n");

        printf("Price : ");
        scanf("%d", &pricea);
        printf("\n\n");
    } 
    else if (category == 2) {
        printf("You have chosen Electronics category\n\n");
        
        char book_nameb[50];
        char author_nameb[50];
        int priceb;

        printf("Book Name : ");
        scanf("%s",book_nameb); 
        printf("\n\n");

        printf("Author Name : ");
        scanf("%s", author_nameb); 
        printf("\n\n");

        printf("Price : ");
        scanf("%d", &priceb);
        printf("\n\n");
    } 
    else {
        printf("Invalid category\n");
    }
}

// Function to display book information
void displaybookinfo() {
    printf("You can display book information\n\n");

    printf("Choose the category:\n\n");
    printf("1. Computer\n");
    printf("2. Electronics\n\n");

    int category;
    printf("Choose a category: ");
    scanf("%d", &category);
    printf("\n");

    if (category == 1) {           
        printf("You have chosen Computer category\n\n");
        printf("Book Name : Data structers");
        printf("Author: ABC\n");
        printf("Pages: 203\n");
        printf("Price: 150\n\n");
    } 
    else if (category == 2) {
        printf("You have chosen Electronics category\n\n");
        printf("Book Name :microcontroller");
        printf("Author: BCD\n");
        printf("Pages: 179\n");
        printf("Price: 150\n\n");
    } 
    else {
        printf("Invalid category\n");
    }
}

// Function to search for a book and display its status
void searchbookstatus() {
    printf("You can search for a book\n\n");

    printf("press the code:123 for computer books\n");
    printf("press the code:234 for electronics books\n");

    int code;
    printf("Enter the book code to search: ");
    scanf("%d", &code);
    printf("\n");

    switch(code) {
        case 123:
            printf("Book Name : abc\n\n");
            printf("Book States : 3 copies left\n");
            break;
        case 234:
            printf("Book Name : electronics\n\n");
            printf("Book States : 12 copies left\n");
            break;
        default:
            printf("Invalid code\n");
    }   
}

// Function to issue a book
void issuebook() {
    printf("You can issue a book\n\n");

    printf("Choose the category:\n\n");
    printf("1. Computer\n");
    printf("2. Electronics\n\n");

    int category;
    printf("Choose a category: ");
    scanf("%d", &category);
    printf("\n");

    if (category == 1) {
        printf("You have chosen Computer category\n\n");
        printf("Computer book issued successfully!\n\n");                   
    } 
    else if (category == 2) {
        printf("You have chosen Electronics category\n\n");
        printf("Electronics book issued successfully!\n\n");
    } 
    else {
        printf("Invalid category.\n\n");
    }
}
