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

void swap(char a[], char b[]){
    char temp[MAX_PANJANG_KATA];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int partition(char arr[][MAX_PANJANG_KATA], int low, int high){
    char pivot[MAX_PANJANG_KATA];
    strcpy(pivot, arr[high]);
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort(char arr[][MAX_PANJANG_KATA], int low, int high){
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void shell_sort(char arr[][MAX_PANJANG_KATA], int n){
    int j;
    char temp[MAX_PANJANG_KATA];
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i++) {
            strcpy(temp, arr[i]);
            for (j = i; j >= interval && strcmp(arr[j - interval], temp) > 0; j -= interval) {
                strcpy(arr[j], arr[j - interval]);
            }
            strcpy(arr[j], temp);
        }
    }
}

int read_file(const char *filename, char data[][MAX_PANJANG_KATA], int max_data) {
    int count = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "gagal membuka file %s\n", filename);
        return 0;
    }
    while (count < max_data && fscanf(file, "%s", data[count]) == 1) {
        count++;
    }
    fclose(file);
    return count;
}