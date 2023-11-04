#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Hello user\n");
    sleep(1);

    int d, mo, y, h, s, m;

    printf("Input the current year: ");
    scanf("%d", &y);
    printf("Input the current month: ");
    scanf("%d", &mo);
    printf("Input the current day: ");
    scanf("%d", &d);
    printf("Input the current hour: ");
    scanf("%d", &h);
    printf("Input the current minute: ");
    scanf("%d", &m);
    printf("Input the current second: ");
    scanf("%d", &s);

    while (d <= 0 || mo <= 0 || y < 0 || h < 0 || m < 0 || s < 0 || d > 31 || mo > 12 || h > 24 || m > 60 || s > 60)
        {
        system("clear");
        printf("Invalid input. Please enter non-negative and correct values.\n");
        sleep(1);
        printf("Try again.\n");
        printf("Input the current year: ");
        scanf("%d", &y);
        printf("Input the current month: ");
        scanf("%d", &mo);
        printf("Input the current day: ");
        scanf("%d", &d);
        printf("Input the current hour: ");
        scanf("%d", &h);
        printf("Input the current minute: ");
        scanf("%d", &m);
        printf("Input the current second: ");
        scanf("%d", &s);
    }

    switch (mo) {
        case 1://month of 31 days
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            while (d > 31)
                {
                printf("Invalid input. Please enter values less than or equal to 31.\n");
                sleep(1);
                printf("Input the current day: ");
                scanf("%d", &d);
            }
            break;

        case 4://month of 31
        case 6:
        case 9:
        case 11:
            while (d > 30) {
                printf("Invalid input. Please enter values less than or equal to 30.\n");
                sleep(1);
                printf("Input the current day: ");
                scanf("%d", &d);
            }
            break;

        case 2://february
            if (y % 4 == 0)// Leap year logic
                {
                while (d > 29) {
                    printf("Invalid input. Please enter values less than or equal to 29.\n");
                    sleep(1);
                    printf("Input the current day: ");
                    scanf("%d", &d);
                }
            } else {
                while (d > 28) {
                    printf("Invalid input. Please enter values less than or equal to 28.\n");
                    sleep(1);
                    printf("Input the current day: ");
                    scanf("%d", &d);
                }
            }
            break;
    }

    while (1) {
        s++;

        if (s == 60) {
            m += s / 60;
            s %= 60;
        }
        if (m == 60) {
            h += m / 60;
            m %= 60;
        }
        if (h == 24) {
            d += h / 24;
            h %= 24;
        }
        if (d == 31) {
            mo += d / 31;
            d = 1 + d % 31;//because days star from '1' not zero like seconds or hours
        }
        if (mo == 13) {
            y += mo / 13;
            mo = 1 + mo % 13;// the same case of days
        }

        system("clear");
        printf("The current date and time is: %d-%d-%d %02d:%02d:%02d\n", y, mo, d, h, m, s);
        sleep(1);
    }

    return 0;
}
