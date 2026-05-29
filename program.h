#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PANJANG_KATA 50
#define JUMLAH_DATA_INT 1000
#define MAX_DATA_STRING 4000

//sorting dasar
void bubble_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);

//sorting advaced
void merge(char arr[][MAX_PANJANG_KATA], int l, int m, int r);
void merge_sort(char arr[][MAX_PANJANG_KATA], int l, int r);
void quick_sort(char arr[][MAX_PANJANG_KATA], int low, int high);
void shell_sort(char arr[][MAX_PANJANG_KATA], int n);

//atur file
int read_file(const char *filename, char data[][MAX_PANJANG_KATA], int max_data);

//menu
void hapus_buffer();
void menu_utama();
void menu_sorting_dasar();
void menu_advance_sorting();
void tampil_int(int arr[], int n, int batas);
void tampil_string(char arr[][MAX_PANJANG_KATA], int n, int batas);
void acak_data_int(int arr[], int n);
void acak_data_string(char arr[][MAX_PANJANG_KATA], int n);
void proses_dasar(int metode);
void proses_advance(int metode, char nama_file[]);
void swap(char a[], char b[]);