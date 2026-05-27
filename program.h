#include <stdio.h>
#define MAX_PANJANG_KATA 50

//sorting dasar
void bubble_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);

//sorting advaced
void merge(char arr[][MAX_PANJANG_KATA], int l, int m, int r);
void mergeSort(char arr[][MAX_PANJANG_KATA], int l, int r);
void quick_sort(int arr[], int low, int high);
void shell_sort(int arr[], int n);

//atur file
void read_file(const char *filename, int arr[], int *n);
