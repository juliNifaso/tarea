#include <stdio.h>
#include <time.h>

//Alfonso bravo esta en mi equipo
int main() {
    srand(time(NULL));
    int modo = 0, r=10, i=0, x,ie,w=0;
    char modos[5] = {'+','+','-','*','/'};

    printf("que modo quieres \n1. suma\n2. resta\n3. multiplicacion\n4. divicion\n");
    scanf("%d", &modo);

    if ((modo > 4) || (modo < 1)) {
        modo = 4;
    }
    r = 10;

    while (r>0) {
        if (modo == 4) {
            ie = (rand() % 49) + 2;
            x = 100/ie;
            x  = (rand() % (x - 1)) + 2;
            x *= ie;
            x *= ie;
        } else {
            x = rand() % 100 + 1;
            ie = rand() % 100 + 1;
        }

        if ((ie > x) && (modo == 2)) {
            ie += x;
            x = ie -x;
            ie = ie-x;
        }

        printf("%d %c %d = ",x,modos[modo],ie);
        scanf("%d", &i);

        if (
            (modos[modo] == '+' && i == x + ie) ||
            (modos[modo] == '-' && i == x - ie) ||
            (modos[modo] == '*' && i == x * ie) ||
            (modos[modo] == '/' && i == x / ie)
        ) {
            printf("Correcto! Te quedan %d\n",r-1);
            r--;
        } else {
            printf("Incorrecto.\n");
            w++;
        }
    }

    if (w > 5) {
        w = 5;
    }

    printf("Incorrectas: %d, Calificacion: %d",w,10-w);
}
