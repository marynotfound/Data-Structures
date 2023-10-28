#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    srand(time(NULL));
    int sayilar[100];
    for (int i = 0; i < 100; i++) {
        sayilar[i] = rand() % 1000; 
    }
    qsort(sayilar, 100, sizeof(int), compare);
    for (int i = 0; i < 100; i++) {
        printf("%d ", sayilar[i]);
    }

    return 0;
}

