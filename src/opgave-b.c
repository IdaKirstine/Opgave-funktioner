#include <stdio.h>
#include "Primes.h"




int main(void) {

    int n = 1000000000;
    int prime, counter=0;

    for (int i =0; i <=n; i++) {
        prime = is_prime(i);

        if (prime == 1) {
            counter++;
            printf("prime %d: %d \n", counter,i);
        }

        if (counter == 100) {
            break;
        }

    }
    return 0;
}
/* Return if i is a prime number.
   It is assumed as a precondition that the parameter i is non-negative
int is_prime(int i) {
    assert(i >= 0);

    if (i == 1)
        return 0;
    else if (i == 2)
        return 1;
    else if (i % 2 == 0)
        return 0;
    else {
        int k, limit;
        limit = (int)(ceil(sqrt(i)));
        for (k = 3; k <= limit; k += 2)
            if (i % k == 0)
                return 0;
        return 1;
    }
}*/