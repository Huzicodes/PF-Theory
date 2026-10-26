/* ID: 26k-0022
 * Name: Muhammad Huzaifa
 * Department: AI
 * Section: 1A
 * Batch: Fall 2026 (Karachi)
 * Assignment: 2 Q3
 * Course: Programming Fundamentals (Theory)
 */

#include <stdio.h>
#include <stdlib.h>
void init(float **p_grid, int r, int c);
void display(float **p_grid, int r, int c);
void analysis(float *p_grid, int r, int c, int sensor_number);
float avgs [1000]; // assuming a maxiumum of a thousand sensors
int index = 0;
void max_avg(float avgs[], int r);

int main(void)
{
    int r, c;
    printf("Enter number of sensors: ");
    scanf("%u", &r);
    printf("Enter number of hourly readings: ");
    scanf("%u", &c);

    float *grid = malloc(r * c * sizeof(float));
    float **p_grid = malloc(r * sizeof(float *));
    for (int i = 0; i < r; i++)
    {
        p_grid[i] = &grid[i * c];
    }

    init(p_grid, r, c);    // populating the initial array
    display(p_grid, r, c); // displaying the initial array
    printf("\n");
    for (int i = 0; i < r; i++)
    {
        analysis(p_grid[i], r, c, i);
    }
    printf("\n");
    max_avg(avgs,r);

    free(p_grid);
    free(grid);

    return 0;
}

void init(float **p_grid, int r, int c)
{
    printf("\n\t\tINITIAL SETTING\n");
    for (int i = 0; i < r; i++)
    {
        printf("\n\t\tFOR SENSOR %u\n", i + 1);
        for (int j = 0; j < c; j++)
        {
            printf("Enter temperature reading for hour %u: ", j + 1);
            scanf("%f", &p_grid[i][j]);
        }
    }
}

void display(float **p_grid, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        printf("\nSensor %u:", i + 1);
        for (int j = 0; j < c; j++)
        {
            printf(" %.0f", p_grid[i][j]);
        }
    }
}

void analysis(float *row, int r, int c, int sensor_number)
{
    // for total, max, min, critical, warning and streak
    float tot = 0;
    float max = row[0];
    float min = row[0];
    int critical = 0;
    int warning = 0;
    int streak = 0;
    for (int i = 0; i < c; i++)
    {
        tot += row[i];
        if (row[i] > max)
            max = row[i];
        if (row[i] < min)
            min = row[i];
        if (row[i] >= 40)
        {
            critical++;
        }
        else if(row[i] >= 35 && row[i] < 40)
        {
            warning++;
        }
        if (row[i] >= 35)
        {
            streak++;
        }
        else
        {
            streak = 0;
        }
    }
    float avg = tot / (float)c;
    avgs[index] = avg; // tracking all averages
    index++;

    // displaying info
    printf
        (
        "\nSensor %u: Total=%.0f Avg=%.0f Max=%.0f Min=%.0f\n\t  Critical=%d Warning=%d Longest hot streak=%d", sensor_number+1, tot, avg, max, min, critical, warning, streak
        );
}

void max_avg(float avgs[], int r)
{
    float max = avgs[0];
    int max_index = 0;
    for (int i = 0; i < r; i++)
    {
        if (avgs[i] > max) { // to find the maximum average and corresponding index
            max = avgs[i];
            max_index = i;   
        }
    printf("\nHighest average sensor: Sensor %d (%.2f)",max_index+1,max);
    }
}