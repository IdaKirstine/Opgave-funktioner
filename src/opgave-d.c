#include <stdio.h>
#include <math.h>

double my_sqrt(double a);

int main(void) {

    double my_sqr;

    for (int i = 0; i <=25; i++) {
        my_sqr = my_sqrt(i);
        printf("%lf |  %lf  |  %lf  \n", i, my_sqr, sqrt(i));
    }

    return 0;
}

double my_sqrt(double a) {
    int sqrt = pow(a, 0.5);

    return sqrt;
}
