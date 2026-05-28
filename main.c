#include "program.h"

int main() {
    int pilihan = 0, sub_pilihan = 0;
    char nama_file[100];
    srand((unsigned int)time(NULL));
    do {
        menu_utama();
        if (scanf("%d", &pilihan) != 1) {
            hapus_buffer();
            pilihan = -1;
        }
        if (pilihan == 1) {
            do {
                menu_sorting_dasar();
                if (scanf("%d", &sub_pilihan) != 1) {
                    hapus_buffer();
                    sub_pilihan = -1;
                }
                if (sub_pilihan >= 1 && sub_pilihan <= 3) {
                    proses_dasar(sub_pilihan);
                } else if (sub_pilihan == 4) {
                    printf("Kembali ke Menu Utama...\n");
                } else {
                    printf("Pilihan tidak valid\n");
                }
            } while (sub_pilihan != 4);
        }
        else if (pilihan == 2) {
            printf("\nMasukkan nama file (contoh: dataset.txt): ");
            scanf("%s", nama_file);
            do {
                menu_advance_sorting();
                if (scanf("%d", &sub_pilihan) != 1) {
                    hapus_buffer();
                    sub_pilihan = -1;
                }
                if (sub_pilihan >= 1 && sub_pilihan <= 3) {
                    proses_advance(sub_pilihan, nama_file);
                } else if (sub_pilihan == 4) {
                    printf("Kembali ke Menu Utama...\n");
                } else {
                    printf("Pilihan tidak valid\n");
                }
            } while (sub_pilihan != 4);
        }
        else if (pilihan == 3) {
            printf("Program Keluar.\n");
        }
        else {
            printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 3);
    return 0;
}

void hapus_buffer() {
    while (getchar() != '\n');
}

void menu_utama() {
    printf("\n==== MENU UTAMA =====\n");
    printf("1. Sorting Dasar\n");
    printf("2. Advance Sorting\n");
    printf("3. Keluar\n");
    printf("Pilih Menu : ");
}

void menu_sorting_dasar() {
    printf("\n==== MENU SORTING DASAR =====\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Kembali\n");
    printf("Pilih Metode : ");
}

void menu_advance_sorting() {
    printf("\n==== ADVANCE SORTING ====\n");
    printf("1. Merge Sort\n");
    printf("2. Quick Sort\n");
    printf("3. Shell Sort\n");
    printf("4. Kembali\n");
    printf("Pilih Metode : ");
}

void tampil_int(int arr[],int n, int batas){
    if (n < batas){
        batas = n;
    }
    for (int i = 0; i < batas; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void tampil_string(char arr[][MAX_PANJANG_KATA],int n,int batas){
    if (n < batas){
        batas = n;
    }
    for (int i = 0;i < batas;i++){
        printf("%s ",arr[i]);
    }
    printf("\n");
}

void acak_data_int(int arr[], int n){
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

void acak_data_string(char arr[][MAX_PANJANG_KATA],int n){
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        swap(arr[i], arr[j]);
    }
}

void proses_dasar(int metode) {
    int data[JUMLAH_DATA_INT];
    int tampil = 0;
    acak_data_int(data, JUMLAH_DATA_INT);
    printf("Masukkan jumlah data yang ingin ditampilkan: ");
    if (scanf("%d", &tampil) != 1) {
        hapus_buffer();
        tampil = 10;
        printf("Input tidak valid! Menampilkan 10 data saja.\n");
    }
    printf("\nData sebelum Sorting:\n");
    tampil_int(data, JUMLAH_DATA_INT, tampil);
    clock_t mulai = clock();
    if (metode == 1) {
        bubble_sort(data, JUMLAH_DATA_INT);
    } else if (metode == 2) {
        insertion_sort(data, JUMLAH_DATA_INT);
    } else if (metode == 3) {
        selection_sort(data, JUMLAH_DATA_INT);
    }
    clock_t selesai = clock();
    double waktu = ((double)selesai - (double)mulai) / (double)CLOCKS_PER_SEC;
    printf("\nData setelah sorting:\n");
    tampil_int(data, JUMLAH_DATA_INT, tampil);
    printf("Waktu eksekusi: %f detik\n", waktu);
}

void proses_advance(int metode, char nama_file[]) {
    char data[MAX_DATA_STRING][MAX_PANJANG_KATA];
    int tampil = 0;
    int jumlah_data = read_file(nama_file, data, MAX_DATA_STRING);
    if (jumlah_data == 0) {
        printf("File %s tidak ditemukan!\n", nama_file);
        return;
    }
    acak_data_string(data, jumlah_data);
    printf("Masukkan jumlah data/kata yang ingin ditampilkan: ");
    if (scanf("%d", &tampil) != 1) {
        hapus_buffer();
        tampil = 10;
        printf("Input tidak valid! Menampilkan 10 data saja.\n");
    }
}