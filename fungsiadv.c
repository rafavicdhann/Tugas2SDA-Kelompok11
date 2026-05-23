#include "program.h"

void merge(char arr[][MAX_PANJANG_KATA], int l, int m, int r) {
    int n1 = r - l + 1;
    int n2 = r - m;

    char kiri[n1][MAX_PANJANG_KATA];
    char kanan[n2][MAX_PANJANG_KATA];

    for (int i = 0; i < n1; i++) {
        strcpy(kiri[i], arr[l + i]);
    }

    for (int j = 0; j < n2; j++) {
        strcpy(kanan[j], arr[m + 1 +j]);
    }

    int i = 0;
    int j = 0;
    int k = l;