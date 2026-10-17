# Opgaver til IMPR Lektion 5

## Gruppeopgaver
Disse opgaver laves sammen i gruppen. Der er rigeligt med opgaver.
Arbejd grundigt med de opgaver, I kan nå, i den skemalagte tid.

### [Opgave A](src/opgave-a.c): Nye funktioner i gamle opgaver 
Dette er Kurt Nørmark's [opgave 5.7](https://homes.cs.aau.dk/~normark/impr-c/functions-ekstr-opg-slide-exercise-3.html). 
Du kan skrive dit program i filen [`opgave-a.c`](src/opgave-a.c).

> I lektionen om iterative kontrolstrukturer arbejdede vi med to opgaver, som vi nu vil tage op igen med det formål at indføre abstraktion med funktioner.
> 
> I programmeringsopgave 1 side 267 (i Problem Solving and Program Design in C, eighth edition) summerede vi alle heltal fra `1` til `n`, 
> og vi sammenlignede værdien af denne sum med `n * (n + 1) / 2`. Skriv nu følgende to funktioner:
> 
>  - En funktion `sum_iter` med én `int` parameter `n`. Funktionen skal addere alle heltal fra `1` til `n`. Funktionen skal returnere denne sum.
>  - En funktion `sum_formula` med én `int` parameter `n` som indkapsler beregningen af `n * (n + 1) / 2`, og som returnerer værdien af dette udtryk.
> 
> I skal kalde disse to funktioner på passende input og sammenligne deres resultater (ligesom i den oprindelige opgave).
> 
> ---
> 
> I lektionen om iterative kontrolstrukturer arbejdede vi også med opgave 1 side 181 i bogen. 
> Vi har en befolkning på 9870 personer som vokser med 10% per år. 
> Spørgsmålet var hvor mange år der går inden befolkningstallet er mere end 30000.
> 
> Skriv nu en funktion som generaliserer denne opgave. Mere specifikt:
> - En funktion `population_projection` med tre `double` parametre: start-befolkningstallet, vækstprocent pr år, og den øvre grænse af befolkningstallet. Funktionen skal returnere det antal år (af typen `int`) det tager for befolkningen at vokse fra start-befolkningstallet til mere end slut-befolkningstallet.
> 
> Kald derefter funktionen så den løser opgaven fra side 181 i bogen (med de tre givne tal 9870, 10% og 30000).

---
### [Opgave B](src/opgave-b.c): Find de første n primtal
Dette er Kurt Nørmark's [opgave 5.2](https://homes.cs.aau.dk/~normark/impr-c/functions-par-ex-2-slide-exercise-1.html)

Se gerne videoen [Intro til CMake](https://laml.cs.aau.dk/cgi-bin/video2/get/show-video.cgi?video-id=video-intro-cmake-flere-filer&course-id=impr&lecture-number=5&course-year=2026&video-width=640&lang=dk&video-start-time=00:00&auto-play=0) som introducerer de nødvendige CMake kommandoer til at løse denne opgave.

> Denne opgave giver dig blandt andet træning i programmering af et C program, der anvender en header file (.h fil) og en tilhørende .c fil. 
> I denne opgaven kalder vi en funktion, som allerede er skrevet. I senere opgaver skal du selv i gang med at skrive dine funktioner.
> 
> Du skal skrive et program med en `main` funktion der udskriver de første $n$ primtal. Skriv dit program i filen [opgave-b.c](src/opgave-b.c). 
> Der ønskes følgende output hvis $n$ er 100:
> ```
> prime 1: 2
> prime 2: 3
> prime 3: 5
> prime 4: 7
> prime 5: 11
> prime 6: 13
> prime 7: 17
> prime 8: 19
> prime 9: 23
> prime 10: 29
> ...
> prime 99: 523
> prime 100: 541
> ```
> I din main funktion skal du - ganske enkelt - gennemløbe så mange positive heltal, som det er nødvendigt, for at finde de første _n_ primtal.
>
> For at få alt dette til at virke skal du lave følgende `src/primes.h` fil:
> ```c++
> /* Return if i is a prime number */
> int is_prime(int i);
> ```
> Endvidere skal du placere følgende programlinjer i filen `src/primes.c`, og oversætte denne c fil separat.
> ```c++
> #include "primes.h"
> #include <math.h>
> #include <assert.h>
>
> /* Return if i is a prime number.
>    It is assumed as a precondition that the parameter i is non-negative */
> int is_prime(int i) {
>     assert(i >= 0);
>     
>     if (i == 1) 
>         return 0;
>     else if (i == 2) 
>         return 1;
>     else if (i % 2 == 0) 
>         return 0;
>     else {
>         int k, limit;
>         limit = (int)(ceil(sqrt(i)));
>         for (k = 3; k <= limit; k += 2)
>             if (i % k == 0) 
>                 return 0;
>         return 1;
>     }
> }
> ```
> Compilering af programmet: 
> Tilføj i CMake filen [src/CMakeList.txt](src/CMakeLists.txt) navnet på den nye `primes.c` fil til listen af kildefiler i `add_executable` kommandoen for `opgave-b`, 
> så din `main` funktion har adgang til `is_prime` funktionen.
> Se gerne videoen [Intro til CMake](https://laml.cs.aau.dk/cgi-bin/video2/get/show-video.cgi?video-id=video-intro-cmake-flere-filer&course-id=impr&lecture-number=5&course-year=2026&video-width=640&lang=dk&video-start-time=00:00&auto-play=0) som forklarer hvordan dette gøres.
>
> Læs og forstå også funktionen `is_prime`.

---
### [Opgave C](src/opgave-c.c): Goldbachs formodning
Dette er Kurt Nørmark's [opgave 5.3](https://homes.cs.aau.dk/~normark/impr-c/functions-par-ex-2-slide-exercise-2.html).
Du kan skrive dit program i filen [`opgave-c.c`](src/opgave-c.c).

> Goldbachs formodning udtrykker en påstand om at alle lige heltal større end to er summen af to primtal. 
> Denne formodning er hverken bevist eller modbevist. 
> I denne opgave vil vi beskæftige os med følgende variation af påstanden:
>  - _Ethvert lige heltal større end 6 kan udtrykkes som summen af to ulige primtal._
> 
> Skriv et program der beviser denne formodning for alle lige heltal mellem to givne grænser. 
> Eksempelvis for alle lige heltal mellem 7 og 2.000.000. 
> Hvis du er i stand til at finde et modeksempel, er berømmelsen måske lige om hjørnet...
> 
> Det foreslås, at funktionen `is_prime` fra Opgave B bruges ved løsningen af denne opgave.
> 
> Det er for stor en mundfuld at løse dette problem uden opdeling i mindre delproblemer. 
> Det foreslås derfor, at I skriver en funktion, som undersøger påstanden for et bestemt lige heltal, `n`. 
> Denne funktion kan så kaldes for alle lige heltal `n` mellem f.eks. 7 og 2.000.000.
> 
> _Hint_: Når I skal bevise påstanden for et tal, $n$, anbefales det at gennemløbe alle mulige summer $(n-i) + i$, 
> og dermed undersøge om I kan finde et $i$ så både $n-i$ og $i$ er ulige primtal.
> 
> Hvis I bliver hurtigt færdige med denne opgave bedes I se på den variant, der på Wikipedia beskrives som [Goldbach's weak conjecture](http://en.wikipedia.org/wiki/Goldbach%27s_weak_conjecture).
> 
> Som en anden udfordring, kan det være interessant at se alle mulige summer - ikke kun den første. 
> Eller denne variant: Hvilket af de testede tal har det største antal opløsninger (som en sum af to ulige primtal)?

---
### [Opgave D](src/opgave-d.c): Programmering af en kvadratrodsfunktion
Dette er Kurt Nørmark's [opgave 5.6](https://homes.cs.aau.dk/~normark/impr-c/functions-ekstr-opg-slide-exercise-2.html).
Du kan skrive dit program i filen [`opgave-d.c`](src/opgave-d.c).

> Bibliotektet `math.h` indholder som bekendt funktionen `sqrt`, som beregner kvadratroden af et tal i typen `double`.
> 
> Programmer din egen kvadratrodsfunktion `my_sqrt` med brug af Newtons metode. 
> Newtons metode gør det muligt for os at finde denne rod. 
> Se f.eks. [denne video](https://www.youtube.com/watch?v=E24zUEKqgwQ) (lavet Oscar Veliz) om hvordan dette virker. 
> (Se formlen for rækkeudviklingen ved tid [2:23](https://youtu.be/E24zUEKqgwQ?si=8NoWpkQlPxOMfzDc&t=143). 
> Bemærk at forfatteren af videoen laver en fejl i den nederste formel ved tid 2:26. Den korrekte formel er $x_{n+1} = 1/2(x_n + a/x_n)$. Regn selv efter.)
> Alternativt se [denne video](https://www.youtube.com/watch?v=FpOEx6zFf1o).
> 
> Vær sikker på at du programmerer en funktion, som tager en `double` som parameter, og som returnerer en `double` som resultat.
> 
> Hvordan vil du håndtere en situation, hvor der overføres et negativt input?
> 
> Udskriv en tabel over `a`, `my_sqrt(a)` og `sqrt(a)` for alle heltal `a` mellem 0.0 og 25.0, og tjek dermed om din nye funktion leverer gode resultater.

---
### [Opgave E](src/opgave-e.c): Skudårsfunktionen
Dette er Kurt Nørmark's [opgave 5.5](https://homes.cs.aau.dk/~normark/impr-c/functions-ekstr-opg-slide-exercise-1.html).
Du kan skrive dit program i filen [`opgave-e.c`](src/opgave-e.c).

> Vi har tidligere i denne lektion mødt skudårsfunktionen:
> ```c++
> int isLeapYear(int year) {
>     int res;
>     if (year % 400 == 0)
>         res = 1;
>     else if (year % 100 == 0)
>         res = 0;
>     else if (year % 4 == 0)
>         res = 1;
>     else res = 0;
>     return res;
> }
> ```
> Programmér en ny skudårsfunktion med brug af `&&` og `||`, og uden brug af if-else og uden brug af betingede udtryk.
> 
> Kald begge skudårsfunktioner for alle årstal mellem år 1900 og år 2100. Giver de to funktioner samme resultat på alle årstal?

---
### Opgave F: Test af funktioner
Hvis I er hurtigt færdige med de første fem opgaver, kan I nu arbejde med test af jeres funktioner. 
Se først videoen [Intro til CTest](https://laml.cs.aau.dk/cgi-bin/video2/get/show-video.cgi?video-id=video-ctest&course-id=impr&lecture-number=5&course-year=2026&video-width=640&lang=dk&video-start-time=00:00&auto-play=0).
(Se evt. også videoerne [Programbibliotek i CMake](https://laml.cs.aau.dk/cgi-bin/video2/get/show-video.cgi?video-id=video-cmake-library&course-id=impr&lecture-number=5&course-year=2026&video-width=640&lang=dk&video-start-time=00:00&auto-play=0) 
og [Unit testing frameworks](https://laml.cs.aau.dk/cgi-bin/video2/get/show-video.cgi?video-id=video-cmake-mtest&course-id=impr&lecture-number=5&course-year=2026&video-width=640&lang=dk&video-start-time=00:00&auto-play=0).)

> Følg videoen og lav selv automatiseret test af `is_prime` funktionen fra [Opgave B](src/opgave-b.c). 
> Tilføj flere test-cases end de to i videoen. Overvej hvilke forskellige input-værdier det vil kræve at opdage forskellige fejl i programmet.
> 
> Lav også automatiseret test til funktionerne fra de andre opgaver: `sum_iter`, `sum_formula`, `my_sqrt` og `isLeapYear`:
>  - Flyt funktionerne over i en/flere seperate .c-filer (med prototyper i tilhørende header-filer).
>  - Skriv et antal test-cases til hver funktion.
>  - Automatiser kørsel af test med CTest (og evt. [mtest](https://github.com/MortenSchou/mtest)).

---
## Hjemmeopgaver:
Dette er opgaver, som I kan arbejde med derhjemme. Enten som forberedelse inden lektionen,
eller som afrunding og repetition efter lektionen.

### [Opgave G](src/opgave-g.c): 
Dette er self-check opgave 1 side 143 fra afsnit 3.2 i Problem Solving and Program Design in C, eighth edition.
Du kan skrive dit program i filen [`opgave-g.c`](src/opgave-g.c).

> Rewrite the following mathematical expressions using C functions:
> 1. $\sqrt{u + v} \times w^2$
> 2. $\log_e(x^y)$
> 3. $\sqrt{(x - y)^3}$
> 4. $| xy - w / z |$

Se evt. dokumentation for funktionerne i matematikbiblioteket `math.h` her: [cplusplus.com/reference/cmath](https://cplusplus.com/reference/cmath)

---
### [Opgave H](src/opgave-h.c)
Dette er programmeringsopgave 2 side 166 fra afsnit 3.5 i Problem Solving and Program Design in C, eighth edition.
Du kan skrive dit program i filen [`opgave-h.c`](src/opgave-h.c).

> Write a function that computes the time one must leave in order to reach a certain destination by a designated time. 
> You need to deal only with arrivals occurring later the in the same day as the departure. 
> Function inputs include the arrival time as an integer on a 24-hours clock (20:30 is given as 2030), 
> the distance to the destination in kilometers, and the speed you plan to average in km/hr.
> The function result should be the required departure time (rounded to the nearest minutes) as an 
> integer on a 24-hour clock. Also, write a driver program to test your function. 
