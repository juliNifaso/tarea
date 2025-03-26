#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct calificacion {
    char materia[30] ;
    float cali;
};

float promedios();
int main() {
    float total = 0;
    int i=0, foo = 0, x=0;
    printf("cuantas materias son?: ");
    scanf("%d", &i);
    foo = i;

    struct calificacion clase[i];

    for (x=1; x<=i; x++) {
        printf("dime el nombre de la materia %d?: ",x);
        scanf("%s", &clase[x].materia);
        clase[x].cali = promedios();
    }

    for (int foo=0; foo>=1; foo--){
        printf("\n%s: %f, ", clase[foo].materia, clase[foo].cali);
    }
    return 0;
}

float promedios() {
    int count = 1;
    float num = 0, total = 0;

    do{
        printf("dime tu calificacion %d: ", count);
        scanf("%f", &num);
        count++;
        total += num;
    } while(num != 0);
    count-= 2;
    return (total/count);
}
