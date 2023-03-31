#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int year;
};

struct Library {
    struct Book books[MAX_BOOKS];
    int count;
};

void addBook(struct Library* lib);
void displayBooks(struct Library* lib);
void listBooksByAuthor(struct Library* lib);
void listBookCount(struct Library* lib);

int main() {
    struct Library lib = {{}, 0};
    int choice;

    do {
        printf("\n1. Add book details\n");
        printf("2. Display book details\n");
        printf("3. List all books of given author\n");
        printf("4. List the count of books in the library\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&lib);
                break;
            case 2:
                displayBooks(&lib);
                break;
            case 3:
                listBooksByAuthor(&lib);
                break;
            case 4:
                listBookCount(&lib);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

void addBook(struct Library* lib) {
    struct Book newBook;

    printf("Enter the book ID: ");
    scanf("%d", &newBook.id);
    printf("Enter the book title: ");
    scanf("%s", newBook.title);
    printf("Enter the book author: ");
    scanf("%s", newBook.author);
    printf("Enter the year of publication: ");
    scanf("%d", &newBook.year);

    lib->books[lib->count] = newBook;
    lib->count++;

    printf("Book details added successfully.\n");
}

void displayBooks(struct Library* lib) {
    if (lib->count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("ID\tTitle\t\tAuthor\t\tYear\n");
    for (int i = 0; i < lib->count; i++) {
        struct Book book = lib->books[i];
        printf("%d\t%s\t\t%s\t\t%d\n", book.id, book.title, book.author, book.year);
    }
}

void listBooksByAuthor(struct Library* lib) {
    char author[50];
    int found = 0;

    printf("Enter the name of the author: ");
    scanf("%s", author);

    printf("Books by author '%s':\n", author);
    for (int i = 0; i < lib->count; i++) {
        struct Book book = lib->books[i];
        if (strcmp(book.author, author) == 0) {
            printf("%d\t%s\t\t%s\t\t%d\n", book.id, book.title, book.author, book.year);
            found = 1;
        }
    }

    if (!found) {
        printf("No books found by author '%s'.\n", author);
    }
}

void
