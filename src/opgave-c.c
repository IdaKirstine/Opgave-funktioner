#include <stdio.h>

#include "Primes.h"
void gold_bachs(int i);

int main(void) {


    for (int i = 7; i <= 2000000; i++) {

        //tjekker om talet er lige
        if (i %2 == 0) {
            gold_bachs(i);
        }
    }



    return 0;
}

void gold_bachs(int i) {
    int p_1, p_2;

    // iterer gennem hvert ulige tal til grænsen
    for (int j = 1; j < i; j+=2) {

        //tjekker hvis i er primtal
        if (is_prime(j) == 1) {
            p_1=j;
            p_2 = i-p_1;

            //tjekker hvis andet tal er primtal
            if (is_prime(p_2) == 1) {
                printf(" %d + %d = %d\n", p_1, p_2, i);
                break;
            }
        }


    }


}


