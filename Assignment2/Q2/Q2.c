/* ID: 26k-0022
 * Name: Muhammad Huzaifa
 * Department: AI
 * Section: 1A
 * Batch: Fall 2026 (Karachi)
 * Assignment: 2 Q2
 * Course: Programming Fundamentals (Theory)
 */

#include <stdio.h>
#include<stdbool.h>
bool is_amicable(int n1, int n2);

int main(void)
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int sum;
    int pairs = 0;
    printf("\nAmicable Pairs of %d:",n);
    for (int i = 1; i <= n; i++) // selecting a number within range
    {
        sum = 0;
        for (int j = 1; j <= i / 2; j++) // summing factors of any given number
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }
        if(sum<=i || sum>n) continue; // avoiding repeated pairs and unnecessary compute
        if (is_amicable(i, sum) ==  true)
        {
            pairs++;
            printf("\nPair%u: (%d,%d)", pairs,i,sum);
        }
    }
    if(pairs == 0) printf("\nNo amicable pairs found");
    return 0;
}

bool is_amicable(int n1, int n2)
{
    int sum = 0;
    for (int i = 1; i <= n2 / 2; i++) // factorizing the sum of factors of n1
    {
        if (n2 % i == 0)
        {
            sum += i; // accumulating factors into a sum
        }
    }
    if (sum == n1) // if sum of factors of n2 (sum of factors of n1) is equal to n1
    {
        return true;
    }
    else
    {
        return false;
    }
}