#include <stdio.h>
#include <string.h>

int main () {
    int a, c = 0;
    char abc[25];
    for (a = 97; a < 123; a++) {
        abc[c] = a;
        c++;
    }
    printf("%s", abc);
    for (c = 25; c > 0; c--) {
        abc[c] = NULL;
        printf("\n%s", abc);
    }
}
