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

// fungsi untuk membersihkan input buffer
void clearInputBuffer() {
    int c;
    while (( c = getchar()) !='\n' && c != EOF);
}

//fungsi untuk menambahkan buku kedalam daftar buku
void tambahBuku() {
    printf("Masukkan judul buku: ");
    scanf("%[^\n]", daftarBuku[JumlahBuku].judul);
    clearInputBuffer();

    printf("Masukkan nama pengarang: ");
    scanf("%[^\n]", daftarBuku[JumlahBuku].pengarang);
    clearInputBuffer();
    
    printf("Masukkan tahun terbit: ");
    scanf("%d", daftarBuku[JumlahBuku].tahunTerbit);
    clearInputBuffer();

    printf("Masukkan penerbit: ");
    scanf("%[^\n]", daftarBuku[JumlahBuku].penerbit);
    clearInputBuffer();

    daftarBuku[jumlahBuku].status = 0;

    jumlahbuku++;

    printf("Buku berhasil ditambahkan. \n\n");
}


// fungsi untuk menampilkan data semua buku
void tampilkanDaftarBuku() {
    if (jumlahBuku == 0) {
        printf("Belum ada buku yang ditambahkan. \n\n");
    } else {
        printf("Data buku:\n");
        for (int i = 0; i < jumlahBuku; i++) {
            printf("Judul buku: %s\n", daftarBuku[i].judul);
            printf("Pengarang: %s\n", daftarBuku[i].pengarang);
            printf("Tahun terbit: %d\n", daftarBuku[i].tahunterbit);
            printf("Penerbit: %s\n", daftarBuku[i].penerbit);
            if (daftarBuku[i].status == 0) {
                printf("Status: Tersedia\n\n");
            } else {
                printf("Status: Dipinjam\n\n");
            }
        }
    }
}

// fungsi untuk mencari buku berdasarkan judul
void cariBuku() {
    char judulCari[100];
    int found = 0;

    printf("Masukkan judul buku yang ingin dicari: ");
    scanf("%[^\n]", judulCari);
    clearInputBuffer();
    
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(judulCari, daftarBuku[i].judul) == 0) {
            printf("Judul buku: %s\n", daftarBuku[i].judul);
            printf("Pengarang: %s\n", daftarBuku[i].pengarang);
        printf("Tahun terbit: %d\n", daftarBuku[i].tahunTerbit);
        printf("Penerbit:%s\n\n",daftarBuku[i].penerbit);
        found = 1;
        break;
        }
    }
    
    if (!found) {
        printf("Buku tidak ditemukan.\n\n");
    }
}

void pinjamBuku() {
    char judulPinjam[100];
    intfound = 0;
    
    printf("Masukkan judul buku yang ingin dipinjam: ");
    scanf("%[^\n]", judulPinjam);
    clearInputBuffer();
    
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(judulPinjam, daftarBuku[i].judul) == 0) {
            if (daftarBuku[i].status == 0) {
                printf("Buku berhasil dipinjam.\n\n");
                daftarBuku[i].status = 1;
            } else {
                printf("Maaf, buku sedang dipinjam.\n\n");
            }
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Buku tidak ditemukan.\n\n");
    }
}
