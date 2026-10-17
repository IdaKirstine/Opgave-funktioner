
#include <stdio.h>

int isLeapYear(int year);
int isLeapYearShort(int year);


int main(void) {

    for (int i = 1900; i < 2100; i++) {
        //isLeapYearShort(i);
        //isLeapYear(i);

        if (isLeapYearShort(i) == 1 && isLeapYear(i) == 1) {
            printf("Leap Year: %d\n",i);
        }
    }

    return 0;
}

int isLeapYearShort(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

}
int isLeapYear(int year) {
    int res;
    if (year % 400 == 0)
        res = 1;
    else if (year % 100 == 0)
        res = 0;
    else if (year % 4 == 0)
        res = 1;
    else res = 0;
    return res;
}
