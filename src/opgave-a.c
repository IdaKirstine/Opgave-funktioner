#include <math.h> //mat bib
#include <stdio.h> //til printf og scantf

// deklarer funktionerne
int sum_iter(int n);
int sum_formula(int n);
int population_projection(double start_befolkning, double vaekstProcent, double graense);

int main(void) {

    //variabler
    int n, sum_loop, sum_form;

    //henter n grænsen fra bruger
    printf("Indtast venlingst en n-vardi\n");
    scanf("%d", &n);

    //assigner return-værdien fra funktionerne til en variable
    sum_loop = sum_iter(n);
    sum_form = sum_formula(n);

    int years = population_projection(9870, 0.1, 30000);
    printf("%d år \n", years);
    /* printer værdier for kontrol
    printf("%d \n", sum_loop);
    printf("%d \n", sum_form);*/

    //sammenligner return-værdierne gennem if-statement
    if (sum_loop == sum_form) {
        printf("Værdierne er ens\n");
    }
    else
        printf("Fejl\n");

    return 0;
}
// løkke der lægger alle tal (n-1)+n sammen
int sum_iter(int n) {
    int sum;

    //kører gennem alle værdier fra 1 til n og lægger den nye tal i for hver
    // iteration sammen med den tidligere sum.
    for (int i = 1; i <= n; i++) {
        sum = sum + i;
        //printf("%d \n", sum); kontrol print
    }

    return sum;
}
// anvender formlen
int sum_formula(int n) {
    return (n*(n+1))/2;
}

int population_projection(double start_befolkning, double vaekstProcent, double graense) {

    //tæller til år, samt variable for når befolkningen vokser
    int count_years, growth;

    // do while løkke, fordi den forsætter indtil hvis grænse
    do {
        // udregner hvor stor andel af befolkningen er 10%
        // her er det vigtigt at 10% skrives som decimaltal
        growth = start_befolkning * vaekstProcent;

        //lægger de 10% til den nuværende befolkning
        start_befolkning = start_befolkning + growth;

        // incrementere år tælleren med 1
        count_years++;

    }while (start_befolkning < graense); // stopper løkken når grænsen er nåt

    //returnere antal år det tager at nå grænsen
    return count_years;

}