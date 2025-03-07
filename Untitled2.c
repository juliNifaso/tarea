#include <stdio.h>

int sumas(long long int);
int main() {
    long long int nMayor = 0;
    long long int numero = 1;
    int counter = -1;
    while (numero >= 0) {
        printf("Dame un numero: ");
        scanf("%lld", &numero);
        if (numero > nMayor) {
            nMayor = numero;
        }
        counter++;
    }
    printf("El numero mas grande fue %lld de %d numeros \n", nMayor, counter);

    sumas(nMayor);
}

int sumas(long long int numero) {
    long int sumaPares = 0;
    long int sumaNones = 0;
    long int fSumaPares = 0;
    long int fSumaNones = 0;
    int digitos = 0;
    int d = 0;
    int foo = 0;

    while (numero > 0) {
        d = numero % 10;
        numero = numero / 10;
        digitos++;

        foo = d%2;

        if (foo == 0) {
            printf("\nPares: %ld +",sumaPares);
            sumaPares += d;
            printf(" %d = %ld", d, sumaPares);
        } else {
            printf("\nNones: %ld +",sumaNones);
            sumaNones += d;
            printf(" %d = %ld", d, sumaNones);
        }
        d = 0;
    }

    printf("\n\n Digitos: %d", digitos);
    printf("\n Suma Pares: %ld", sumaPares);
    fSumaPares = factorial(sumaPares);
    printf("\n Factorial Suma Pares: %ld", fSumaPares);
    printf("\n Suma Nones: %ld", sumaNones);
    fSumaNones = factorial(sumaNones);
    printf("\n Factorial Suma Nones: %ld", fSumaNones);

    return 0;
}

int factorial (long int num) {
    long int n = 1;
    printf("%ld", num);
    while (num > 0) {
        n = n * num;
        num--;
    }
    return n;
}
