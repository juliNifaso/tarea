#include <stdio.h>
void cocienteYReciduo();
void exponente();
void promedio();

int main() {
    char select = 'NULL';
    printf("Menu!, a, b, c o d: ");
    scanf("%c", &select);
    switch (select) {
    case 'a':
        cocienteYReciduo();
        break;
    case 'b':
        exponente();
        break;
    case 'c':
        promedio();
        break;
    case 'd':
        return 0;
    default:
        printf("Vuelve a intentar, ingresaste mal \n");
        main();
        return 0;
    }
}
    void cocienteYReciduo() {
        int a, b, c = 0;
        printf("\nDame el primer numero: ");
        scanf("%d", &a);
        printf("\nDame el segundo numero: ");
        scanf("%d", &b);
        if (b > a) {
            b = b+a;
            a = b-a;
            b = b-a;
        }
        while (a>b) {
            a=a-b;
            c++;
        }
        printf("\nCociente = %d, Residuo = %d", c,a);
    }
    void exponente() {
        int a, b;
        printf("\nDame el primer numero: ");
        scanf("%d", &a);
        printf("\nDame el segundo numero: ");
        scanf("%d", &b);
        if (b > a) {
            b = b+a;
            a = b-a;
            b = b-a;
        }
        while (b>0) {
            a=a*b;
            b--;
        }
        printf("%d",a);
    }
    void promedio() {
        int x = 0, M = 0, m = 0, c = 0;
        float p = 0.0;
        do {
            printf("\nDame numero: ");
            scanf("%d", &x);
            if (x > M) {
                M = x;
            }
            if ((m > x) && (x > 0)) {
                m = x;
            }
            p+= x;
            c++;
        }
        while (x != 0);
        p = (float) p/c;
        printf("\nMayor: %d, Menor: %d, Promedio: %.2f", M, m, p);
    }
