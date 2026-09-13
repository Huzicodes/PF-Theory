#include<stdio.h>

int main(void) {
    int C = 0;
    int R, N;

    printf("Enter number of requests: ");
    scanf("%d", &N);

    while (N>=1)
    {
        printf("\nWhich floor do you want to go to? ");
        scanf("%d", &R);

        if (R==C){
            printf("Doors Opening");
        }
        else if (R>C) {
            printf("Moving Up");
        }
        else {
            printf("Moving Down");
        }

        C = R;
        N--;
    }

    return 0;
}