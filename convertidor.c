#include <stdio.h>
void dToB();
void bToD();
void dToO();

int main() {
    char select = 'NULL';
    printf("Menu!, a, b, c o d: ");
    scanf("%c", &select);
    switch (select) {
    case 'a':
        dToB();
        break;
    case 'b':
        bToD();
        break;
    case 'c':
        dToO();
        break;
    case 'd':
        return 0;
    default:
        printf("Vuelve a intentar, ingresaste mal \n");
        main();
        return 0;
    }
}

void dToB() {
    int num;
    printf("dime un numero: ");
    scanf("%d", &num);
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

void bToD() {
    int num, i = 0, rem, dec = 0;
    printf("dime un numero: ");
    scanf("%d", &num);

    while (num != 0) {
        rem = num % 10;
        dec += rem << i;
        num /= 10;
        i++;
    }
    printf("En decimal es %d", dec);
}

void dToO() {
    int num, i = 0, rem, dec = 0;
    printf("dime un numero: ");
    scanf("%d", &num);
    printf("%o", num);
}
