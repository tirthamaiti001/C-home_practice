#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
};

// Helper Function: Removes the "Enter" key (\n) that fgets adds
void cleanString(char *str) {
    size_t len = strlen(str);
    if (len>0 && str[len-1]=='\n') str[len-1]='\0';
}

void addBook() {
    struct Book b;
    FILE *fp;
    char temp[10]; // Temporary variable to handle numbers
    fp = fopen("library_data.txt", "a");
    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("\n--- ADD NEW BOOK ---\n");
    printf("Enter Book ID: ");
    fgets(temp, sizeof(temp), stdin);
    b.id = atoi(temp); // Convert string to integer
    printf("Enter Book Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    cleanString(b.title); // Clean the extra newline
    printf("Enter Author Name: ");
    fgets(b.author, sizeof(b.author), stdin);
    cleanString(b.author); 
    fprintf(fp, "%d\n%s\n%s\n", b.id, b.title, b.author);
    printf(">> Book Added Successfully!\n");
    fclose(fp);
}

void viewBooks() {
    struct Book b;
    FILE *fp;
    char line[100]; 
    int count = 1; // Variable to number the books (Book 1, Book 2...)
    fp = fopen("library_data.txt", "r");
    if(fp == NULL) {
        printf("\nNo books found! Add some books first.\n");
        return;
    }
    printf("\n--- LIST OF BOOKS ---\n");
    while(fgets(line, sizeof(line), fp) != NULL) {
        b.id = atoi(line);
        fgets(b.title, sizeof(b.title), fp);
        cleanString(b.title);
        fgets(b.author, sizeof(b.author), fp);
        cleanString(b.author);
        printf("BOOK %d:\n", count);
        printf("TITLE: %s\n", b.title);
        printf("ID: %d\n", b.id);
        printf("AUTHOR: %s\n", b.author);
        count++;
    }
    fclose(fp);
}

int main() {
    int choice;
    char temp[10]; // Buffer for menu input
    while(1) {
        printf("\n==============================");
        printf("\n LIBRARY MANAGEMENT SYSTEM");
        printf("\n==============================");
        printf("\n1. Add New Book");
        printf("\n2. View All Books");
        printf("\n3. Exit");
        printf("\n\nEnter your choice: ");
        fgets(temp, sizeof(temp), stdin);
        choice = atoi(temp);
        switch(choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                printf("Exiting...\nThank you for visiting. :)\n");
                exit(0);
            default:
                printf("Invalid Choice! Try again.\n");
        }
    }
    return 0;
}