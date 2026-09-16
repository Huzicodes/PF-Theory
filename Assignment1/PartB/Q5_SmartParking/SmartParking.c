#include <stdio.h>

int main(void)
{
    int N;
    int zoneA = 20;
    int zoneB = 40;
    int zoneC = 15;
    int vehicles_processed = 1;
    int accepted = 0;
    int rejected = 0;
    int bikes = 0;
    int cars = 0;
    int vans = 0;
    int zoneA_occupied = 0;
    int zoneB_occupied = 0;
    int zoneC_occupied = 0;
    int zoneA_remain = 20;
    int zoneB_remain = 40;
    int zoneC_remain = 15;
    char E, P, type, category;
    printf("Enter expected number of vehicles to be processed today: ");
    scanf("%d", &N);
    while (N >= 1)
    {
        printf("\nFor Vehicle %d", vehicles_processed);
        printf("\nIs the vehicle an emergency vehicle? (Y: yes, N: no) ");
        scanf(" %c", &E);
        if (E == 'N')
        {
            printf("Is permit available? (Y: yes, N: no) ");
            scanf(" %c", &P);
            if (P == 'N')
            {
                printf("Rejected\nReason: Permit not available\n");
                N--;
                vehicles_processed++;
                rejected++;
                continue;
            }
            else if (P != 'Y')
            {
                printf("Invalid input\nTry again\n");
                continue;
            }
        }
        else if (E != 'Y')
        {
            printf("Invalid input\nTry again\n");
            continue;
        }
        printf("Enter Vehicle Type (B: Bike, C: Car, V: Van): ");
        scanf(" %c", &type);
        if (type != 'B' && type != 'C' && type != 'V')
        {
            printf("Invalid input\nTry again\n");
            continue;
        }
        printf("Enter User Category (F: Faculty, S: Student, G: Guest): ");
        scanf(" %c", &category);
        if (category != 'F' && category != 'S' && category != 'G')
        {
            printf("Invalid input\nTry again\n");
            continue;
        }
        if (category == 'F')
        {
            if (type == 'B' || type == 'C')
            {
                if (zoneA_remain >= 1)
                {
                    zoneA_occupied++;
                    zoneA_remain = zoneA - zoneA_occupied;
                    printf("Parked in zone A\nRemaining capacity in zone A is %d\n", zoneA_remain);
                    accepted++;
                    if (type == 'B')
                    {
                        bikes++;
                    }
                    else
                    {
                        cars++;
                    }
                }
                else
                {
                    printf("Rejected\nReason: space not available\n");
                    rejected++;
                }
            }
            else
            {
                if (zoneA_remain >= 2)
                {
                    zoneA_occupied += 2;
                    zoneA_remain = zoneA - zoneA_occupied;
                    printf("Parked in zone A\nRemaining capacity in zone A is %d\n", zoneA_remain);
                    accepted++;
                    vans++;
                }
                else
                {
                    printf("Rejected\nReason: space not available\n");
                    rejected++;
                }
            }
        }
        else if (category == 'S')
        {
            if (type == 'B' || type == 'C')
            {
                if (zoneB_remain >= 1)
                {
                    zoneB_occupied++;
                    zoneB_remain = zoneB - zoneB_occupied;
                    printf("Parked in zone B\nRemaining capacity in zone B is %d\n", zoneB_remain);
                    accepted++;
                    if (type == 'B')
                    {
                        bikes++;
                    }
                    else
                    {
                        cars++;
                    }
                }
                else
                {
                    printf("Rejected\nReason: space not available\n");
                    rejected++;
                }
            }
            else
            {
                if (zoneC_remain >= 2)
                {
                    zoneC_occupied += 2;
                    zoneC_remain = zoneC - zoneC_occupied;
                    printf("Parked in zone C\nRemaining capacity in zone C is %d\n", zoneC_remain);
                    accepted++;
                    vans++;
                }
                else
                {
                    printf("Rejected\nReason: space not available\n");
                    rejected++;
                }
            }
        }
        else
            {
                if (type == 'B' || type == 'C')
                {
                    if (zoneC_remain >= 1)
                    {
                        zoneC_occupied++;
                        zoneC_remain = zoneC - zoneC_occupied;
                        printf("Parked in zone C\nRemaining capacity in zone C is %d\n", zoneC_remain);
                        accepted++;
                        if (type == 'B')
                        {
                            bikes++;
                        }
                        else
                        {
                            cars++;
                        }
                    }
                    else
                    {
                        printf("Rejected\nReason: space not available\n");
                        rejected++;
                    }
                }
                else
                {
                    if (zoneC_remain >= 2)
                    {
                        zoneC_occupied += 2;
                        zoneC_remain = zoneC - zoneC_occupied;
                        printf("Parked in zone C\nRemaining capacity in zone C is %d\n", zoneC_remain);
                        accepted++;
                        vans++;
                    }
                    else
                    {
                        printf("Rejected\nReason: space not available\n");
                        rejected++;
                    }
                }
            }
        N--;
        vehicles_processed++;
    }
    printf("\n\n\nTotal vehicles processed: %d", vehicles_processed-1);
    printf("\nTotal accepted vehicles: %d", accepted);
    printf("\nTotal rejected vehicles: %d", rejected);
    printf("\nTotal bikes successfully parked: %d", bikes);
    printf("\nTotal cars successfully parked: %d", cars);
    printf("\nTotal vans successfully parked: %d", vans);
    printf("\n\nFinal Occupancy in Zone A: %d", zoneA_occupied);
    printf("\nRemaining Capacity in Zone A: %d", zoneA_remain);
    printf("\n\nFinal Occupancy in Zone B: %d", zoneB_occupied);
    printf("\nRemaining Capacity in Zone B: %d", zoneB_remain);
    printf("\n\nFinal Occupancy in Zone C: %d", zoneC_occupied);
    printf("\nRemaining Capacity in Zone C: %d", zoneC_remain);

    if (zoneA_occupied > zoneB_occupied && zoneA_occupied > zoneC_occupied)
    {
        printf("\n\nZone A has the highest occupancy");
    }
    else if (zoneB_occupied > zoneA_occupied && zoneB_occupied > zoneC_occupied)
    {
        printf("\n\nZone B has the highest occupancy");
    }
    else if (zoneC_occupied > zoneA_occupied && zoneC_occupied > zoneB_occupied)
    {
        printf("\n\nZone C has the highest occupancy");
    }
    else
    {
        printf("\n\nAll zones have equal occupancy");
    }

    if (zoneA_remain == 0 && zoneB_remain == 0 && zoneC_remain == 0)
    {
        printf("\nEntire campus parking is full");
    }

    return 0;
}
