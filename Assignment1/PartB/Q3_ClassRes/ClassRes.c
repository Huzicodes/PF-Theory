#include<stdio.h>

int main(void) {
    int N, sum, avg, sub1, sub2, sub3, sub4, sub5;
    char status;

    printf("Enter number of students: ");
    scanf("%d", &N);

    while(N>=1) {
        printf("\nFOR STUDENT%d", N);
        printf("\nEnter marks of subject 1: ");
        scanf("%d", &sub1);
        printf("Enter marks of subject 2: ");
        scanf(" %d", &sub2);
        printf("Enter marks of subject 3: ");
        scanf(" %d", &sub3);
        printf("Enter marks of subject 4: ");
        scanf(" %d", &sub4);
        printf("Enter marks of subject 5: ");
        scanf(" %d", &sub5);

        if (sub1 < 33 || sub2 < 33 || sub3 < 33 || sub4 < 33 || sub5 < 33) {
            printf("Fail - Subject Deficiency\n");
            N--;
            continue;
        }

        sum = sub1 + sub2 + sub3 + sub4 + sub5;
        avg = sum/5;

        if(avg >= 80) {
            printf("Status: Distinction\n");
        }
        else if(avg>=60) {
            printf("Status: Pass\n");
        }
        else {
            printf("Status: Fail\n");
        }

        N--;
    }
    return 0;
}