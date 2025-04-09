#include <stdio.h>
#include <time.h>

int main () {
    srand(time(NULL));
    int poop, c, s = 0, a = 0;
    for (c = 0; c < 100; c++) {
        poop = rand();
        if (poop < 16383) {
            s++;
        } else {
            a++;
        }
    }
    printf("sol %d, aguilas %d, ganador: ", s, a);
    if (s > a) {
        printf("sol");
    } else {
        printf("aguilas");
    }
}
