#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
struct Contact {
    char name[50];
    char phone[15];
    struct Contact* next;
};

struct Contact* head;

void addContact();
void deleteContact();
void displayContacts();
void searchContact();
void saveContactsToFile();
void loadContactsFromFile();
void updateContact();

int main() {
    loadContactsFromFile();  // Load contacts from file when the program starts

    int choice = 0;
    while (choice != 6) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Update Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                deleteContact();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                updateContact();
                break;
            case 6:
                saveContactsToFile();  // Save contacts to file when exiting the program
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}
void updateContact() {
    char nameToUpdate[50];
    printf("\nEnter name of the contact to update: ");
    scanf(" %s", nameToUpdate);

    struct Contact* current = head;
    while (current != NULL) {
        if (strcmp(current->name, nameToUpdate) == 0) {
            printf("\nEnter new phone number: ");
            scanf(" %s", current->phone);
            printf("\nContact updated successfully.\n");
            return;
        }
        current = current->next;
    }

    printf("\nContact not found.\n");
}


void saveContactsToFile() {
    FILE* file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    struct Contact* current = head;
    while (current != NULL) {
        fprintf(file, "%s\n%s\n", current->name, current->phone);
        current = current->next;
    }

    fclose(file);
}

void loadContactsFromFile() {
    FILE* file = fopen("contacts.txt", "r");
    if (file == NULL) {
        // File does not exist or cannot be opened; initialize an empty list
        head = NULL;
        return;
    }

    char name[50];
    char phone[15];
    while (fgets(name, sizeof(name), file) && fgets(phone, sizeof(phone), file)) {
        name[strlen(name) - 1] = '\0';  // Remove the newline character
        phone[strlen(phone) - 1] = '\0';  // Remove the newline character

        struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
        if (newContact == NULL) {
            printf("\nMemory allocation failed.\n");
            exit(1);
        }
        strcpy(newContact->name, name);
        strcpy(newContact->phone, phone);
        newContact->next = head;
        head = newContact;
    }

    fclose(file);
}

void addContact() {
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    if (newContact == NULL) {
        printf("\nMemory allocation failed.\n");
        exit(1);
    }

    printf("\nEnter name: ");
    fflush(stdin);  // Clear the input buffer

    // Read the name character by character until a newline is encountered
    int i = 0;
    while (i < sizeof(newContact->name) - 1) {
        char c = getchar();
        if (c == '\n') {
            break;  // Stop reading if a newline is encountered
        }
        newContact->name[i++] = c;
    }
    newContact->name[i] = '\0';  // Null-terminate the name

    char phoneInput[15];
    printf("\nEnter phone: ");
    scanf(" %s", phoneInput);  // Add a space before %s

    // Validate that the phone number contains exactly 10 digits
    if (strlen(phoneInput) != 10 || !isPhoneNumberValid(phoneInput)) {
        printf("\nInvalid phone number. Please enter a 10-digit number.\n");
        free(newContact);
        return;
    }

    strcpy(newContact->phone, phoneInput);

    newContact->next = head;
    head = newContact;
    printf("\nContact added successfully.\n");
}

int isPhoneNumberValid(const char* phone) {
    // Check if all characters in the phone number are digits
    int i;
    for ( i = 0; i < 10; i++) {
        if (!isdigit(phone[i])) {
            return 0;
        }
    }
    return 1;
}

void deleteContact() {
    char nameToDelete[50];
    printf("\nEnter name to delete: ");
    scanf("%s", nameToDelete);
    struct Contact* current = head;
    struct Contact* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, nameToDelete) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("\nContact deleted successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("\nContact not found.\n");
}

void searchContact() {
    char nameToSearch[50];
    printf("\nEnter name to search: ");
    scanf("%s", nameToSearch);
    struct Contact* current = head;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->name, nameToSearch) == 0) {
            printf("\nContact found:\n");
            printf("Name: %s\n", current->name);
            printf("Phone: %s\n", current->phone);
            found = 1;
            break;
        }
        current = current->next;
    }

    if (!found) {
        printf("\nContact not found.\n");
    }
}

void displayContacts() {
    struct Contact* current = head;
    if (current == NULL) {
        printf("\nContact list is empty.\n");
        return;
    }
    printf("\nContacts:\n");
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Phone: %s\n", current->phone);
        printf("\n");
        current = current->next;
    }
}