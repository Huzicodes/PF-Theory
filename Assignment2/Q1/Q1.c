/* ID: 26k-0022
 * Name: Muhammad Huzaifa
 * Department: AI
 * Section: 1A
 * Batch: Fall 2026 (Karachi)
 * Assignment: 2 Q1
 * Course: Programming Fundamentals (Theory)
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int r, c;

    printf("\t\t    CINEMA HALL SIZE\n");
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of seats per row: ");
    scanf("%d", &c);

    int *grid = malloc(r * c * sizeof(int));
    int **p_grid = malloc(r * sizeof(int *));

    for (int i = 0; i < r; i++)
    {
        p_grid[i] = &grid[i * c];
    }

    // populating the initial grid
    printf("\n\t\t    INITIAL GRID SETTING\n\t\t    (0:empty,1:booked)\n");
    for (int i = 0; i < r; i++)
    {
        printf("\n\t\t\tFOR ROW %u\n", i + 1);
        for (int j = 0; j < c; j++)
        {
            printf("Is seat %u available? ", j + 1);
            scanf(" %u", &p_grid[i][j]);
        }
    }

    // printing the initial grid
    printf("\n   ");
    for (int i = 0; i < c; i++) // printing column header
    {
        printf("%u ", i);
    }
    for (int i = 0; i < r; i++)
    {
        printf("\nR%u", i); // row label
        for (int j = 0; j < c; j++)
        {
            if (p_grid[i][j] == 1)
            { // if booked
                printf(" X");
            }
            else
            { // if empty
                printf(" _");
            }
        }
    }

    printf("\n\nFree seats per row:");
    int r_empty;
    int tot_empty = 0;
    for (int i = 0; i < r; i++)
    {
        r_empty = 0;
        // resets to zero in each row
        for (int j = 0; j < c; j++)
        {
            if (p_grid[i][j] == 0)
            { // if empty
                r_empty++;
                tot_empty++;
            }
        }
        printf(" %u", r_empty);
    }
    printf("\tTotal free: %u", tot_empty);

    int k; // for group seatings
    printf("\n\nHow many seats for a group booking? (Note: Maximum is %u) ", c);
    scanf("%u", &k);
    if (k > c)
    {
        printf("The requirement exceeds the maximum capacity");
        return 0;
    }

    int r1, r2;
    int mid = r / 2;
    int free_streak;
    int found = 0;
    for (int d = 0; d < r && found != 1; d++)
    // going outward from the middle along both the vertical directions until requirement is met
    {
        r1 = mid - d; // upper half
        r2 = mid + d; // lower half

        // prioritizing upper half
        free_streak = 0;
        if (r1 >= 0) // ensuring we don't go out of bounds of the grid
        {
            for (int m = 0; m < c; m++) // traversing each seat of r1
            {
                if (p_grid[r1][m] == 0) // if empty
                {
                    free_streak++;
                    if (free_streak == k) // if requirement is met
                    {
                        printf("\nGroup of %u seats in row %u, seats %u to %u", k, r1, (m - k + 1), m);
                        found = 1;
                        for (int l = (m - k + 1); l <= m; l++)
                        {
                            p_grid[r1][l] = 1; // updating booked seat status
                        }
                        break;
                    }
                }
                else
                {
                    free_streak = 0; // reset upon an occurence of a booked seat
                }
            }
        }

        free_streak = 0;
        if (found != 1 && r2<r)
        // if requirement is not met, we continue searching, ensuring we don't go out of bounds of the grid
        {
            for (int m = 0; m < c; m++) // traversing each seat of r2
            {
                if (p_grid[r2][m] == 0) // if empty
                {
                    free_streak++;
                    if (free_streak == k) // if requirement is met
                    {
                        printf("\nGroup of %u seats in row %u, seats %u to %u", k, r2, (m - k + 1), m);
                        found = 1;
                        for (int l = (m - k + 1); l <= m; l++)
                        {
                            p_grid[r2][l] = 1; // updating booked seat status
                        }
                        break;
                    }
                }
                else
                {
                    free_streak = 0; // reset upon an occurence of a booked seat
                }
            }
        }
    }

    if (found != 1)
    {
        printf("\nSpace not found");
        return 0;
    }

    // printing the new grid
    printf("\n\n\t\t\tUPDATED GRID\n   ");
    for (int i = 0; i < c; i++) // printing column header
    {
        printf("%u ", i);
    }
    for (int i = 0; i < r; i++)
    {
        printf("\nR%u", i); // row label
        for (int j = 0; j < c; j++)
        {
            if (p_grid[i][j] == 1)
            { // if booked
                printf(" X");
            }
            else
            { // if empty
                printf(" _");
            }
        }
    }

    printf("\n\nFree seats per row:");
    tot_empty = 0; // resetted
    for (int i = 0; i < r; i++)
    {
        r_empty = 0;
        // resets to zero in each row
        for (int j = 0; j < c; j++)
        {
            if (p_grid[i][j] == 0)
            { // if empty
                r_empty++;
                tot_empty++;
            }
        }
        printf(" %u", r_empty);
    }
    printf("\tTotal free: %u", tot_empty);

    free(p_grid); // free pointer array first otherwise it won't be pointing to anything in the first place
    free(grid);

    return 0;
}