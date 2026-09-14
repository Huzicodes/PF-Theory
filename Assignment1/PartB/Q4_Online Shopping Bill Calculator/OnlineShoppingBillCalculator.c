#include<stdio.h>

int main(void) {
    int q, p, s, d, a, t, f;

    printf("Enter quantity of items purchased: ");
    scanf("%d", &q);
    printf("Enter price per item: ");
    scanf("%d", &p);
    printf("Enter the discount percentage: ");
    scanf("%d", &d);
    printf("Enter the tax percentage: ");
    scanf("%d", &t);
    s = q*p;
    a = s - (s*d)/100;
    f = a + (a*t)/100;
    printf("\n\tFINAL BILL");
    printf("\nSubTotal: %d", s);
    printf("\nBill After Discount: %d", a);
    printf("\nBill After Tax: %d", f);

    return 0;
}