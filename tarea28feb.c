#include <stdio.h>
#include <math.h>
#include <time.h>

int main() {
   int tarea;
   printf("Que tarea es? ");
   scanf("%d", &tarea);
   switch (tarea) {
   case 1:
       triangulo();
       break;
   case 2:
       quadratica();
       break;
   case 4:
       cajero();
       break;
   case 5:
       tiempo();
       break;
   case 3:
       tienda();
       break;
   case 6:
       romano();
       break;
   }
   return 0;
}

void triangulo() {
    int lado1, lado2, lado3;
    printf("Dame los 3 lados de tu triangulo!");
    printf("\n 1: ");
    scanf("%d", &lado1);
    printf("\n 2: ");
    scanf("%d", &lado2);
    printf("\n 3: ");
    scanf("%d", &lado3);

    if ((lado1 == lado2) && (lado2 == lado3)) {
        printf("\n Tu triangulo es equilatero");
    } else if ((lado2 == lado1) || (lado3 == lado1) || (lado3 == lado2)) {
        printf("\n Tu triangulo es isoceles");
    } else {
        printf("\n Tu triangulo es escaleano");
    }
}

int cajero(){

    int dinero, dineroEntre50;
    int cambio1000 = 0, cambio500 = 0, cambio200 = 0, cambio100 = 0, cambio50 = 0;

    printf("Cuanto dinero deseas (entre 50 y 6000) y solo multiples de 50 \n");
    scanf("%d", &dinero);
    if (((dinero % 50) != 0) || (dinero > 6000) || (dinero < 50)) {
        printf("Tu cantidad ingresada no es valida\n");
        return 0;
    }
    dineroEntre50 = dinero/50;

    while (dineroEntre50 > 0) {
        switch (dineroEntre50) {

        case 19: case 18: case 17: case 16: case 15: case 14: case 13: case 12: case 11: case 10:
            cambio500++;
            dineroEntre50 -= 10;
            break;

        case 9: case 8: case 7: case 6: case 5: case 4:
            cambio200++;
            dineroEntre50 -=4;
            break;

        case 3: case 2:
            cambio100++;
            dineroEntre50 -= 2;
            break;

        case 1:
            cambio50++;
            dineroEntre50 -=1;
            break;

        default:
            cambio1000++;
            dineroEntre50 -= 20;
            break;
        }

    }
    printf("Tu cambio es de %d de 1000, %d de 500, %d de 200, %d de 100 y %d de 50 \n", cambio1000, cambio500, cambio200, cambio100, cambio50);
    return 0;
}

void tiempo() {
    int num = 0, min = 0, hrs =0;
    printf("Cuantos segundos son? ");
    scanf("%d", &num);

    while (num > 59) {
        if (num > 3601) {
            hrs++;
            num -= 3600;
        } else {
            min++;
            num -= 60;
        }
    }
    printf(" \n Son %d horas, %d minutos y %d segundos", hrs, min, num);
}

int quadratica() {
    int a = 0, b = 0, c = 0, b2 = 0;
    float raiz = 0, x1 = 0, x2 = 0, ac4 = 0;

    printf("Dame los 3 numeros para la quadratica!");
    printf("\n a: ");
    scanf("%d", &a);
    printf("\n b: ");
    scanf("%d", &b);
    printf("\n c: ");
    scanf("%d", &c);

    b2 = b*b;
    ac4 = a*c*4;

    raiz = b2-ac4;
    //printf("\n %d %f %f\n", b2, ac4, raiz);


    if (((a+a) < 0) || (raiz < 0)) {
        printf("\n tus numeros son invalidos");
        return 0;
    }
    raiz = sqrt(raiz);
    x1 = (-b + raiz)/(a+a);
    x2 = (-b - raiz)/(a+a);

    printf("\n x1 = %d", x1);
    printf("\n x2 = %d", x2);
    return 0;
}

void tienda() {
    float costo = 0, costoEntre50 = 0;
    int iCostoEntre50;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int dia = tm.tm_mday;

    printf("Cual es el total de tu compra? ");
    scanf("%f", &costo);

    costoEntre50 = costo/500;
    costoEntre50 = truncf(costoEntre50);
    iCostoEntre50 = (int)costoEntre50;

    switch (iCostoEntre50) {
    case 0:
        break;
    case 1:
        costo = costo * 0.90;
        break;
    default:
        costo = costo * 0.85;
        break;
    }
    if ((dia == 15) || (dia == 30)) {
        costo = costo * 0.95;
    }
    printf("Debes pagar %f", costo);
}

int romano(){
    int num = 0, foo = 0;
    char nRomano[13];

    printf("Dame tu numero: ");
    scanf("%d", &num);

    if ((num > 3000) || (num < 1)) {
        printf("/n Tu numero es invalido!");
        return 0;
    }

    int millar = ((num - (num%1000))/1000);
    int centenas = (((num-millar) - (num%100))/100);
    int decenas = ((((num-millar)-centenas) - (num%10))/10);
    int unos = ((((num-millar)-centenas)-unos) - (num%1));

    printf("Tu numero es: ");
    printf("%d", millar);
    printf("%d", centenas);
    printf("%d", decenas);
    printf("%d", unos);

    while (millar > 1) {
        printf("%c", 'M');
        foo++;
        millar --;
    }
    switch (centenas) {
    case 9:
        printf("%c", 'C');
        foo++;
        printf("%c", 'M');
        foo++;
        break;
    case 4:
        printf("%c", 'C');
        foo++;
        printf("%c", 'D');
        foo++;
        break;
    case 3:
        printf("%c", 'C');
        foo++;
    case 2:
        printf("%c", 'C');
        foo++;
    case 1:
        printf("%c", 'C');
        foo++;
        break;
    case 0:
        break;
    default:
        printf("%c", 'D');
        foo++;
        centenas -= 5;
        switch (centenas) {
            case 3:
                printf("%c", 'C');
                foo++;
            case 2:
                printf("%c", 'C');
                foo++;
            case 1:
                printf("%c", 'C');
                foo++;
                break;
            default:
                break;
        }

    }
    switch (decenas) {
    case 9:
        printf("%c", 'X');
        foo++;
        printf("%c", 'C');
        foo++;
        break;
    case 4:
        printf("%c", 'X');
        foo++;
        printf("%c", 'L');
        foo++;
        break;
    case 3:
        printf("%c", 'X');
        foo++;
    case 2:
        printf("%c", 'X');
        foo++;
    case 1:
        printf("%c", 'X');
        foo++;
        break;
    case 0:
        break;
    default:
        printf("%c", 'L');
        foo++;
        decenas -= 5;
        switch (decenas) {
            case 3:
                printf("%c", 'X');
                foo++;
            case 2:
                printf("%c", 'X');
                foo++;
            case 1:
                printf("%c", 'X');
                foo++;
                break;
            default:
                break;
        }

    }
    switch (unos) {
    case 9:
        printf("%c", 'I');
        foo++;
        printf("%c", 'X');
        foo++;
        break;
    case 4:
        printf("%c", 'I');
        foo++;
        printf("%c", 'V');
        foo++;
        break;
    case 3:
        printf("%c", 'I');
        foo++;
    case 2:
        printf("%c", 'I');
        foo++;
    case 1:
        printf("%c", 'I');
        foo++;
        break;
    case 0:
        break;
    default:
        printf("%c", 'V');
        foo++;
        centenas -= 5;
        switch (centenas) {
            case 3:
                printf("%c", 'I');
                foo++;
            case 2:
                printf("%c", 'I');
                foo++;
            case 1:
                printf("%c", 'I');
                foo++;
                break;
            default:
                break;
        }

    }
    return 0;
}
