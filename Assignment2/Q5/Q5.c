/* ID: 26k-0022
 * Name: Muhammad Huzaifa
 * Department: AI
 * Section: 1A
 * Batch: Fall 2026 (Karachi)
 * Assignment: 2 Q5
 * Course: Programming Fundamentals (Theory)
 */

#include <stdio.h>
#include <stdbool.h>
void displayMenu(void);
void registerMember(char *name, int *id, int *type);
void displayBooks(char (*titles)[30], int *bookIDs, int *copies);
void borrowBook(int *bookIDs, int *copies, int *std_id, int *count, int borrowed[3],char (*titles)[30]);
int returnBook(int* count, int *bookIDs, int borrowed[3], int *type, int *copies,char (*titles)[30],int* std_id);
void displayMemberRecord(char name[], int *std_id, int *type, int borrowedBookIDs[], int *count, int* late_fine);

int main(void)
{
    char name[100];
    int studentID = 0; // unregistered
    int memberType;
    int bookIDs[] = {101, 102, 103, 104};
    char bookTitles[][30] = {"Programming in C", "Data Structures", "Database Systems", "Computer Networks"};
    int availableCopies[] = {5, 3, 0, 4};
    int totalBooks = 4;
    int borrowedCount = 0;
    int borrowedBookIDs[3] = {0, 0, 0}; // 0 means empty
    int late_fine = 0;

    int choice;
    do
    { // keeps asking until it gets a valid input
        displayMenu();
        printf("\nWhich menu-option (1-6) do you want to access? ");
        scanf(" %d", &choice);
        if (choice < 1 && choice > 6)
        {
            printf("Invalid menu option, try again");
        }
        else
        {
            switch (choice)
            {
            case 1:
                registerMember(name, &studentID, &memberType);
                break;
            case 2:
                displayBooks(bookTitles, bookIDs, availableCopies);
                break;
            case 3:
                borrowBook(bookIDs, availableCopies, &studentID, &borrowedCount, borrowedBookIDs,bookTitles);
                break;
            case 4:
                late_fine = returnBook(&borrowedCount, bookIDs, borrowedBookIDs, &memberType,availableCopies,bookTitles,&studentID);
                break;
            case 5:
                displayMemberRecord(name, &studentID, &memberType, borrowedBookIDs, &borrowedCount, &late_fine);
                break;
            }
        }
    } while ((choice < 1 && choice > 6) || choice != 6); // 6 means exit
}

void displayMenu(void)
{
    printf("\n\t\t\t\tUNIVERSITY LIBRARY MANAGEMENT SYSTEM\n");
    printf("\n1) Member Registration");
    printf("\n2) Display stock");
    printf("\n3) Borrow a book");
    printf("\n4) Return a book");
    printf("\n5) Display member record");
    printf("\n6) Exit system");
}

void registerMember(char *name, int *id, int *type)
{
    printf("\n\t\t\t\tMEMBER REGISTRATION");
    printf("\nEnter full name: ");
    scanf(" %[^\n]%*c", name); // reads until it comes across an enter press before discarding it
    printf("Enter ID: ");
    scanf(" %d", id);
    do // keeps asking until it gets a valid input
    {
        printf("Enter type (1: Student, 2: Faculty): ");
        scanf(" %d", type);

        if (*type != 1 && *type != 2)
        {
            printf("\nInvalid type, try again\n");
        }
    } while (*type != 1 && *type != 2);

    // display info
    printf("\n\t\t\t\tRegistration Successful!");
    printf("\nName: %s", name);
    printf("\nID: %d", *id);
    printf("\nType: ");
    (*type == 1) ? printf("Student (allowed to keep books for 14 days)\n") : printf("Faculty (allowed to keep books for 30 days)\n");
}

void displayBooks(char (*titles)[30], int *bookIDs, int *copies)
{
    // assuming a tab is four spaces long
    printf("\nID \t|\t%15s%15s\t|\t%16s", "TITLES", "", "AVAILABLE COPIES\n");
    for (int i = 0; i < 4; i++)
    {
        for (int i = 1; i <= 72; i++)
            printf("-");
        printf("\n%d\t|\t%-30s\t|\t%8d\n", bookIDs[i], &titles[i][0], copies[i]);
    }
}

void borrowBook(int *bookIDs, int *copies, int *std_id, int *count, int borrowed[3],char (*titles)[30])
{
    int book_id;
    int index;
    bool found = false;

    do
    { // keeps asking until receives a valid book ID
        printf("\n\t\t\t\tBORROW A BOOK");
        printf("\nEnter book ID: ");
        scanf(" %d", &book_id);
        for (int i = 0; i < 4; i++)
        {
            if (book_id == bookIDs[i])
            {
                found = true;
                index = i;
            }
        }
        if (found == false)
            printf("\nInvalid book ID, try again\n");
    } while (found == false);
    // verification checks for registration, limit-check and availablity
    if (std_id == 0)
    // since std_id is initialized to 0 in main, 0 means unregistered
    {
        printf("\nUser has not registered, kindly register first");
        return;
    }
    if (*count == 3)
    {
        printf("\nUser has reached borrowing limit");
        return;
    }
    if (copies[index] == 0)
    {
        printf("\nOut of Stock");
        return;
    }

    copies[index]--;
    borrowed[*count] = book_id;
    printf("Student %d has successfully borrowed %s\n",*std_id,titles[index]);
    (*count)++;
}

int returnBook(int* count, int *bookIDs, int borrowed[3], int *type, int *copies,char (*titles)[30], int* std_id)
{
    if (*count == 0)
    {
        printf("\nUser has not borrowed any books");
        return 0;
    }

    int book_id;
    bool found = false;
    int index;
    do
    { // keeps asking until receives a valid book ID
        printf("\n\t\t\t\tRETURN A BOOK");
        printf("\nEnter book ID: ");
        scanf(" %d", &book_id);
        for (int i = 0; i < 4; i++)
        {
            if (book_id == bookIDs[i])
            {
                found = true;
                index = i;
            }
        }
        if (found == false)
            printf("Invalid book ID, try again\n");
    } while (found == false);

    int days;
    printf("For how many days the book was kept? ");
    scanf("%d", &days);

    int i;
    for (i = index; i < 2; i++)
    {
        borrowed[i] = borrowed[i + 1]; // deleting returned book ID from borrowed book IDs
    }
    borrowed[i] = 0; // 0 means empty

    (*count)--;
    copies[index]++;

    int late_fine = 0;
    int extradays = 0;
    if (*type == 1)
    { // student
        if (days > 14)
        {
            extradays = days - 14;
            late_fine = 20 * extradays;
        }
    }
    else
    { // faculty
        if (days > 30)
        {
            extradays = days - 30;
            late_fine = 10 * extradays;
        }
    }

    char is_code;
    do
    {
        printf("Do you have a membership code? (Y: yes, N: no) ");
        scanf(" %c", &is_code);
    } while (is_code != 'Y' && is_code != 'N');
    if (is_code == 'Y')
    {
        bool iscorrect = true;
        char code[100];
        char correctcode[] = "LIB2026";
        printf("Enter code: ");
        scanf(" %s", code);
        for (int i = 0; correctcode[i] != '\0'; i++)
        {
            if (code[i] != correctcode[i])
            {
                printf("Incorrect code");
                iscorrect = false;
                break;
            }
        }
        if (iscorrect == true)
            late_fine *= 0.5;
    }

    printf("Student %d has successfully returned %s\n",*std_id,titles[index]);

    return late_fine;
}

void displayMemberRecord(char name[], int *std_id, int *type, int borrowedBookIDs[], int *count, int* late_fine)
{
    printf("\n\t\t\t\tMEMBER ACCOUNT RECORD\n");

    if (*std_id == 0)
    {
        printf("Status: No member registered yet.\n");
        return;
    }

    printf("Member Name  : %s\n", name);
    printf("Student ID   : %d\n", *std_id);
    printf("Member Role  : %s\n", (*type == 1) ? "Student" : "Faculty");
    printf("Active Books : %d / 3\n", *count);

    if (*count > 0)
    {
        printf("Borrowed IDs :");
        for (int i = 0; i < *count; i++)
        {
            printf(" [%d]", borrowedBookIDs[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Borrowed IDs : None\n");
    }

    printf("Late Fine: %d\n", *late_fine);
}