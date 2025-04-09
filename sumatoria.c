# include <stdio.h>

int main () {
    int x = 0, n = 1, fac = 1;
    float t;
    printf("Dame un numero: ");
    scanf("%d", &x);
    for (n=1; n < x; n++) {
        fac *= n;
        t += (float) n/fac;
    }
    printf("La serie iguala: %f", t);
}
