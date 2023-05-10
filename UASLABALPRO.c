#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// deklarasi struct buku
struct Buku {
    char judul[100];
    char pengarang[100];
    int tahunTerbit;
    char penerbit[100];
    int status; // 0 = tersedia, 1 = dipinjam
};

// deklarasi variabel global
struct Buku daftarBuku[100];
int jumlahBuku = 0;

// deklarasi fungsi
void tambahBuku();
void tampilkanDaftarBuku();
void cariBuku();
void pinjamBuku();
void kembalikanBuku();
void clearInputBuffer();

int main() {
    int opsi;

    while (1) {
        printf("=========================\n");
        printf("           Menu          \n");
        printf("=========================\n");
        printf("1. Tambah Buku           \n");
        printf("2. Pinjam Buku           \n");
        printf("3. Kembalikan Buku       \n");
        printf("4. Cari Buku             \n");
        printf("5. Tampilkan Daftar Buku \n");
        printf("6. Keluar                \n");
        printf("=========================\n");
        Printf("Pilih opsi : ");
        scanf("%d", &opsi);
        clearInputBuffer();

        switch (opsi) {
            case 1:
                tambahBuku();
                break;
            case 2:
                pinjamBuku();
                break;
            case 3:
                kembalikanBuku();
                break;
            case 4:
                cariBuku();
                break;
            case 5:
                tampilkanDaftarBuku();
                break;
            case 6:
                printf("Terima kasih telah menggunakan program ini.\n");
                exit(0);
            default:
                printf("Opsi yang Anda masukkan tidak valid.\n\n");
                break;
        }
    }

    return 0;
}
