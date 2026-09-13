#include<stdio.h>

int main(void) {
    int N, nights, rate, t;
    long T = 0;
    float D;
    char S, R;

    printf("Enter number of guests: ");
    scanf("%d", &N);

    while(N >= 1) {
        printf("\nFOR GUEST %d", N);
        printf("\nEnter season (P: Peak, O: Off-peak): ");
        scanf(" %c", &S);
        printf("Enter Room Type (S: Standard, D: Deluxe, U: Suite): ");
        scanf(" %c", &R);
        printf("Enter number of Night Stays: ");
        scanf(" %d", &nights);

        D = 0.0;
        if(nights > 7) D = 0.15;

        if(S == 'P') {
            if(R == 'S') {
                rate = 5000;
            } else if(R == 'D') {
                rate = 8000;
            } else if(R == 'U') {
                rate = 12000;
            }
        }
        else if (S == 'O') {
            if(R == 'S') {
                rate = 3000;
            } else if(R == 'D') {
                rate = 5000;
            } else if(R == 'U') {
                rate = 8000;
            }
        }

        t = (rate*nights) - D*(rate*nights);

        printf("Final price of Guest %d is %d\n", N, t);
        N--;

        T += t;
    }
    printf("\nTotal Revenue: %ld\n", T);

    return 0;
}