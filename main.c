#include <stdio.h>
#include <unistd.h>

// Function declaration
int print_frame(int width);

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
            d = 1 + d % 31;
        }
        if (mo == 13) {
            y += mo / 13;
            mo = 1 + mo % 13;
        }

        printf("\033[2J\033[1;1H"); // ANSI escape sequence to clear the screen
        print_frame(47);
        printf("|    The current date and time is: %d-%d-%d |\n", y, mo, d);
        printf("|                                    %02d:%02d:%02d |\n", h, m, s);
        print_frame(47);
        sleep(1);
    }

    return 0;
}

// Function definition
int print_frame(int width) {
    printf("+");
    for (int i = 0; i < width - 2; ++i) {
        printf("-");
    }
    printf("+\n");
    return 0;
}
