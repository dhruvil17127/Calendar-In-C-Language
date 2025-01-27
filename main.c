#include <stdio.h>

int getFirstDayOfMonth(int year, int month);
int isLeapYear(int year);
void printCalendar(int year, int month);

int main() {    
    int year, month;

    // Ask user for the year and month
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1 to 12): ");
    scanf("%d", &month);

    // Print the calendar for the given month and year
    printCalendar(year, month);

    return 0;
}

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 400 == 0) {
        return 1;
    }
    if (year % 100 == 0) {
        return 0;
    }
    if (year % 4 == 0) {
        return 1;
    }
    return 0;
}

// Function to get the first day of the month (0 = Sunday, 1 = Monday, ...)
int getFirstDayOfMonth(int year, int month) {
    int day, y, m;
    
    // Zeller's congruence algorithm to calculate the first day of the month
    if (month < 3) {
        month += 12;
        year--;
    }
    y = year % 100;
    m = month;

    day = (1 + (13 * (m + 1)) / 5 + y + y / 4 + (year / 400) - (year / 100)) % 7;

    return day;
}

// Function to print the calendar for a specific month and year
void printCalendar(int year, int month) {
    // Array with the number of days in each month (index 0 = January, 1 = February, etc.)
    int daysInMonth[] = {31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Print month and year
    printf("=====================");
    printf("\n Calendar for %d-%d\n", year, month);
    printf("=====================\n");
    printf("Su Mo Tu We Th Fr Sa\n");

    // Get the first day of the month
    int firstDay = getFirstDayOfMonth(year, month);
    int daysInCurrentMonth = daysInMonth[month - 1];

    // Print leading spaces for the first week
    for (int i = 0; i < firstDay; i++) {
        printf("   ");
    }

    // Print the days of the month
    for (int day = 1; day <= daysInCurrentMonth; day++) {
        printf("%2d ", day);
        
        // If Saturday (end of the week), move to the next line
        if ((firstDay + day) % 7 == 0) {
            printf("\n");
        }
    }

    // If the last day of the month isn't Saturday, print a new line
    if ((firstDay + daysInCurrentMonth) % 7 != 0) {
        printf("\n");
    }
}
