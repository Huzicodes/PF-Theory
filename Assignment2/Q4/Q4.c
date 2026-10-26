/* ID: 26k-0022
 * Name: Muhammad Huzaifa
 * Department: AI
 * Section: 1A
 * Batch: Fall 2026 (Karachi)
 * Assignment: 2 Q4
 * Course: Programming Fundamentals (Theory)
 */

#include <stdio.h>
int getValidDays(void);
float calculateDailySales(int dayNumber);
int findHighestSalesDay(float dailySales[], int numberOfDays);
void displayBarChart(float dailySales[], int numberOfDays);

int main(void)
{
    // Get validated festival duration (1 to 7 days)
    int days = getValidDays();
    
    // Array to store daily total sales (max 7 days)
    float dailySales[7]; 
    float totalFestivalSales = 0;

    // Process daily orders
    for (int i = 0; i < days; i++)
    {
        dailySales[i] = calculateDailySales(i + 1);
        totalFestivalSales += dailySales[i];
    }

    // Find day with highest total sales
    int peakDay = findHighestSalesDay(dailySales, days);

    // Display Festival Summary Report
    printf("\n\t\t\tFESTIVAL SUMMARY\n");
    printf("Total festival sales: %.2f\n", totalFestivalSales);
    printf("Day with highest sales: Day %d\n", peakDay);
    printf("Highest daily sales: %.2f\n", dailySales[peakDay - 1]);

    // 5. Display Daily Sales Bar Chart
    displayBarChart(dailySales, days);

    return 0;
}

// Inputs and validates festival days (1-7)
int getValidDays(void)
{
    int days;
    do
    {
        printf("Enter number of festival days (1-7): ");
        scanf("%d", &days);
        if (days < 1 || days > 7)
        {
            printf("Invalid entry! Duration must be between 1 and 7 days.\n");
        }
    } while (days < 1 || days > 7);

    return days;
}

// Processes orders for a given day, validates amounts, prints report
float calculateDailySales(int dayNumber)
{
    int numOrders;
    printf("\n\t\t\tDay %d\n", dayNumber);
    
    do
    {
        printf("Enter number of orders: ");
        scanf("%d", &numOrders);
        if (numOrders < 1)
        {
            printf("Invalid entry! Must have at least 1 order.\n");
        }
    } while (numOrders < 1);

    float totalSales = 0.;
    float highestOrder = 0;
    float amount;

    printf("Enter order amounts for %d orders:\n",numOrders);
    for (int i = 1; i <= numOrders; i++)
    {
        do
        {
            scanf("%f", &amount);
            if (amount <= 0)
            {
                printf("Amount must be greater than zero. Re-enter order %d: ", i);
            }
        } while (amount <= 0);

        totalSales += amount;
        if (i == 1 || amount > highestOrder) 
        // ensures highest order starts tracking from order 1 and updates properly
        {
            highestOrder = amount;
        }
    }

    float avgOrder = totalSales / numOrders;

    printf("\nDay %d Summary:\n", dayNumber);
    printf("Total sales  : %.2f\n", totalSales);
    printf("Average order: %.2f\n", avgOrder);
    printf("Highest order: %.2f\n", highestOrder);

    return totalSales;
}

// Finds 1-based day number with highest sales
int findHighestSalesDay(float dailySales[], int numberOfDays)
{
    int bestDay = 1;

    for (int i = 1; i < numberOfDays; i++)
    {
        if (dailySales[i] > dailySales[bestDay - 1]) // esnures it compares with last best day
        {
            bestDay = i + 1;
        }
    }

    return bestDay;
}

void displayBarChart(float dailySales[], int numberOfDays)
{
    printf("\nDAILY SALES BAR CHART\n");
    for (int i = 0; i < numberOfDays; i++)
    {
        int stars = (int)(dailySales[i] / 100.0);
        printf("Day %d: ", i + 1);
        for (int s = 0; s < stars; s++)
        {
            printf("*");
        }
        printf("\n");
    }
}