#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

int compareDates(struct Date d1, struct Date d2) {

    if (d1.year > d2.year) {
        return 1;
    } else if (d1.year < d2.year) {
        return -1;
    }


    if (d1.month > d2.month) {
        return 1;
    } else if (d1.month < d2.month) {
        return -1;
    }


    if (d1.day > d2.day) {
        return 1;
    } else if (d1.day < d2.day) {
        return -1;
    }


    return 0;
}

int main() {
    struct Date d1 = {1, 1, 2020};
    struct Date d2 = {1, 1, 2021};

    int result = compareDates(d1, d2);

printf("Result: %d\n", result);

    return 0;
}