#include <stdio.h>

int main(void)
{
    char type, memb, D, avl, prt, season;
    int current, target, hrs, t, units, Crate, Prate, Ecost, Pcost, final_amount;
    int Cdiscount = 0;
    int Pdiscount = 0;

    printf("Enter Vehicle Type (E: Electric, H: Hybrid): ");
    scanf(" %c", &type);
    printf("Enter current battery charge level (SOC): ");
    scanf(" %d", &current);
    printf("Is charging station available? (Y: yes, N: no): ");
    scanf(" %c", &avl);

    if (avl == 'N')
    {
        /*If a hybrid vehicle experiences lack of availablity, it is disqualified from the system and the program terminates after displaying the status message*/
        if (type == 'H')
        {
            printf("\nCharging unavailable – Parking only");
            return 0;
        }
        else
        {
            printf("\nNo charging slot available");
            return 0;
        }
    }
    else
    {
        /*If a hybrid vehicle has SOC >= 40%, it is disqualified from the system and the program terminates after displaying the status message*/
        if (type == 'H')
        {
            if (current >= 40)
            {
                printf("Vehicle does not qualify for EV charging");
                return 0;
            }
        }
    }

    printf("Enter required charging level: ");
    scanf(" %d", &target);
    units = target - current;
    if (units == 0 || units < 0)
    {
        printf("\nNo charging required");
        return 0;
    }

    printf("Enter expected parking duration (in hours): ");
    scanf(" %d", &hrs);
    printf("Enter current time (in 24-hr format): ");
    scanf(" %d", &t);
    printf("Is membership available? (Y: yes, N: no): ");
    scanf(" %c", &memb);
    printf("Is the customer disabled? (Y: yes, N: no): ");
    scanf(" %c", &D);

    if (current <= 15 && target >= 80)
    {
        prt = 'E';
    }
    else if (D == 'Y' || (memb == 'Y' && current <= 30))
    {
        prt = 'V';
    }
    else
    {
        prt = 'N';
    }

    if (t >= 17 && t <= 22)
    {
        season = 'P';
        Crate = 50;
        if (memb == 'Y' && prt != 'E')
        {
            Cdiscount = 10;
        }
    }
    else
    {
        season = 'O';
        Crate = 35;
        if (memb == 'Y' && prt != 'E')
        {
            Cdiscount = 20;
        }
    }

    if (D == 'N')
    {
        if (hrs <= 2)
        {
            Prate = 200;
        }
        else if (hrs > 2 && hrs <= 5)
        {
            Prate = 400;
        }
        else if (hrs > 5)
        {
            Prate = 700;
        }
        if (memb == 'Y')
        {
            Pdiscount = 20;
        }
    }
    else
    {
        Prate = 0;
        Pdiscount = 100;
    }
    Ecost = units * Crate - ((units * Crate) * Cdiscount) / 100;
    Pcost = Prate - (Prate * Pdiscount) / 100;

    final_amount = Ecost + Pcost;

    if (type == 'H')
    {
        printf("\n\nVehicle Type: Hybrid");
    }
    else
    {
        printf("\n\nVehicle Type: Electric");
    }

    printf("\nCurrent battery percentage: %d", current);
    printf("\nRequired battery percentage: %d", target);

    if (prt == 'E')
    {
        printf("\nCharging Priority: Emergency");
    }
    else if (prt == 'V')
    {
        printf("\nCharging Priority: Priority Customer");
    }
    else
    {
        printf("\nCharging Priority: Normal");
    }

    if (season == 'P')
    {
        printf("\nSeason: Peak");
    }
    else
    {
        printf("\nSeason: Off-Peak");
    }

    printf("\nCharging Cost: %d", Ecost);
    printf("\nParking Cost: %d", Pcost);
    printf("\nDiscount: Charging Discount (%) = %d \t Parking Discount (%) = %d", Cdiscount, Pdiscount);
    printf("\nFinal payable amount: %d", final_amount);

    if (hrs > 8)
    {
        printf("\nLong-stay warning: Please relocate your vehicle after charging.");
    }
    else
    {
        printf("\nStandard parking duration");
    }
    return 0;
}