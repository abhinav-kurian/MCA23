#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node{
    char name[50];
    char phone[20];
    int fav;
    struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert(char name[], char phone[])
{
 char n;
    if(head==NULL)
{

    head=(node*)malloc(sizeof(node));
    strcpy(head->name, name);
    strcpy(head->phone, phone);
    head->next=NULL;
    printf("Do you want to make this contact fav [y/n]: ");
    scanf(" %c", &n);
     head->fav = (n == 'y' || n == 'Y') ? 1 : 0;

    
}
else
{
    node *t;
    t=head;
    while(t->next!=NULL){
        t=t->next;
    }
     t->next=(node*)malloc(sizeof(node));
     strcpy(t->next->name,name);
     strcpy(t->next->phone,phone);
    t->next->next=NULL;
    printf("Do you want to make this contact fav [y/n]: ");
    scanf(" %c", &n);
    t->next->fav = (n == 'y' || n == 'Y') ? 1 : 0;
}
}
void display()
{
    node *t, *d;
    char tempName[50], tempPhone[20];
    if(head==NULL)
    {
        printf("Contact book is empty\n");
    }

    else{
        for (t = head; t->next != NULL; t = t->next) {
        for (d = t->next; d != NULL; d = d->next) {
            if (strcmp(t->name, d->name) > 0) {
                // Swap names
                strcpy(tempName, t->name);
                strcpy(t->name, d->name);
                strcpy(d->name, tempName);
                // Swap phone numbers
                strcpy(tempPhone, t->phone);
                strcpy(t->phone, d->phone);
                strcpy(d->phone, tempPhone);
            }
        }
    }
        node *t;
        t=head;
        printf("Contact book:\n");
        while(t!=NULL)
        {
         printf("Name: %s\tPhone: %s\n", t->name, t->phone);
            t=t->next;
        }

    }
}
void dispfav()
{
    if(head==NULL)
    {
        printf("Contact book is empty\n");
    }
    else{
        node *t;
        t=head;
        printf("Contact book:\n");
        while(t!=NULL )
        {
         if (t->fav == 1) {
                printf("Name: %s\tPhone: %s\n", t->name, t->phone);
            }
            t = t->next;

    }
}
}
void delete(char name[])
{
    node *t, *prev;
    if (head == NULL)
    {
        printf("contact book is empty\n");
    }
    else if (strcmp(head->name, name) == 0)
    {
        // If the contact to delete is in the head node
        t = head;
        head = head->next;
        free(t);
    }
    else
    {
       t = head;
        prev = NULL;
       while (t != NULL && strcmp(t->name, name) != 0)
        {
            prev = t;
            t = t->next;
        }
       if (t == NULL)
        {
           printf("Contact not found\n");
        }
        else
        {
            prev->next = t->next;
            free(t);
        }
    }
}
void search(char name[])
{
    node *t;
    t = head;
    while (t != NULL && strcmp(t->name, name) != 0)
        {
            t = t->next;
        }
       if (t == NULL)
        {
           printf("Contact not found\n");
        }
        else
        {
             printf("Name: %s\tPhone: %s\n", t->name, t->phone);
            t=t->next;

        }
    }
void edit(char name[])
{
    int editChoice;
     node *t = head;
    while (t != NULL && strcmp(t->name, name) != 0) {
        t = t->next;
    }
    if (t == NULL) {
        printf("Contact not found\n");
        return;
    }
    printf("Editing contact: %s\n", name);
    printf("Choose what you want to edit:\n");
    printf("1. Edit name\n");
    printf("2. Edit phone number\n");
    printf("Enter your choice: ");
    scanf("%d", &editChoice);
    if (editChoice == 1) {
        printf("Enter the new name: ");
        getchar();
        gets(t->name) ;
    } else if (editChoice == 2) {
         printf("Enter the new phone number: ");
         scanf("%s", t->phone);
     
    } else {
        printf("Invalid choice for editing.\n");
    }

}

int menu ()
{
    int ch;
    printf("\nMenu:\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Delete Contact\n");
    printf("4. Search\n");
    printf("5. Edit\n");
    printf("6. fav\n");
    printf("7. Exit\n");

    printf("Enter your choice: ");
    scanf("%d",&ch);
    return ch;
}
int main()
{
    int ch;
    char name[50];
    char phone[20];
    for(ch=menu();ch!=7;ch=menu())
    {
        switch (ch)
        {
        case 1:
            printf("Enter the contact name: ");
            getchar();
            gets(name) ;
            printf("Enter the phone number: ");
            scanf("%s", phone); 
           
           // validate that the phone number contains exactly 10 digits
           if (strlen(phone)!= 10 ) {
           printf("\nInvalid phone number. Please enter a 10-digit number.\n");
                }
                else{
            insert(name, phone);
            }

            break;
        case 2 :
            display();
            break;
        case 3:
            printf("Enter the contact name to delete: ");
            getchar();
            gets(name) ;
            delete(name);
            break;
        case 4:
            printf("Enter the contact name to search: ");
            getchar();
            gets(name) ;
           search(name);
           break;
        case 5: 
            printf("Enter the contact name to Edit: ");
            getchar();
            gets(name) ;
            edit(name);
            break;
        case 6:
             dispfav();
             break;
         case 7:
            printf("Exiting the program\n");
            break;
        default:
           printf("Invalid choice. Please try again.\n");
           break;
        }

    }
}
