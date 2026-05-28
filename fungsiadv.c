#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "program.h"

void merge(char arr[][MAX_PANJANG_KATA], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    char kiri[n1][MAX_PANJANG_KATA];
    char kanan[n2][MAX_PANJANG_KATA];
    for (int i = 0; i < n1; i++){
        strcpy(kiri[i], arr[l + i]);
    }
    for (int j = 0; j < n2; j++){
        strcpy(kanan[j],arr[m + 1 +j]);
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (strcmp(kiri[i], kanan[j]) <= 0) {
            strcpy(arr[k], kiri[i]);
            i++;
        } else {
            strcpy(arr[k], kanan[j]);
            j++;
        }
        k++;
    }
    while(i < n1){
        strcpy(arr[k], kiri[i]);
        i++;
        k++;
    }
    while (j < n2) {
        strcpy(arr[k], kanan[j]);
        j++;
        k++;
    }
}

void merge_sort(char arr[][MAX_PANJANG_KATA], int l, int r){
    if (l < r) {
        int m = l +(r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}