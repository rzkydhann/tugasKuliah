#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxMahasiswa 20

struct mahasiswa {
    int npm;
    char nama[50];
    char jeniskelamin[2];
    struct mahasiswa *next;
    struct mahasiswa *prev;
};
typedef struct mahasiswa mahasiswa;

void tambahMahasiswa(mahasiswa **head, int *count);
void hapusMahasiswa(mahasiswa **head, int *count);
void tampilkanLingkaran(mahasiswa *head);
void pisahkanLingkaran(mahasiswa *head);
void cariMahasiswa(mahasiswa *head);
void jumlahMahasiswa(mahasiswa *head);
int cekCindy(mahasiswa *head, char *namaBaru, char *jenisKelaminBaru);

int main() {
    mahasiswa *head = NULL;
    int pilih, count = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah mahasiswa di lingkaran\n");
        printf("2. Tampilkan semua mahasiswa di lingkaran\n");
        printf("3. Hapus mahasiswa dari lingkaran\n");
        printf("4. Cari data mahasiswa\n");
        printf("5. Tampilkan jumlah mahasiswa\n");
        printf("0. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilih);
        system("cls");

        switch (pilih) {
            case 1: tambahMahasiswa(&head, &count); break;
            case 2: tampilkanLingkaran(head); break;
            case 3: hapusMahasiswa(&head, &count); break;
            case 4: cariMahasiswa(head); break;
            case 5: jumlahMahasiswa(head); break;
            case 0: printf("Keluar dari program\n"); break;
            default: printf("Pilihan tidak valid\n");
        }
    } while (pilih != 0);

    return 0;
}

void tambahMahasiswa(mahasiswa **head, int *count) {
    if (*count >= maxMahasiswa) {
        printf("Lingkaran sudah penuh, maksimal %d mahasiswa\n", maxMahasiswa);
        return;
    }

    mahasiswa *pNew = (mahasiswa *)malloc(sizeof(mahasiswa));
    if (pNew != NULL) {
        printf("Masukkan NPM mahasiswa: ");
        scanf("%d", &pNew->npm);
        printf("Masukkan nama mahasiswa: ");
        scanf("%s", pNew->nama);
        printf("Masukkan jenis kelamin (L/P): ");
        scanf("%s", pNew->jeniskelamin);

        if (strcmp(pNew->nama, "irsyad") == 0 || strcmp(pNew->nama, "arsyad") == 0) {
            printf("%s tidak boleh dipisahkan\n", pNew->nama);
            return;
        }

        if (strcmp(pNew->nama, "cindy") == 0 && cekCindy(*head, pNew->nama, pNew->jeniskelamin) == 0) {
            printf("Cindy hanya boleh berpegangan tangan dengan mahasiswa perempuan\n");
            free(pNew);
            return;
        }

        pNew->next = *head;
        pNew->prev = NULL;

        if (*head != NULL) {
            (*head)->prev = pNew;
        }
        *head = pNew;
        (*count)++;

        if (*count > maxMahasiswa) {
            pisahkanLingkaran(*head);
        }
    } else {
        printf("Alokasi memori gagal\n");
    }
}

int cekCindy(mahasiswa *head, char *namaBaru, char *jenisKelaminBaru) {
    mahasiswa *pCur = head;

    while (pCur != NULL) {
        if (strcmp(pCur->nama, "Cindy") == 0) {
            if (strcmp(jenisKelaminBaru, "P") == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        pCur = pCur->next;
    }
    return 1;
}

void hapusMahasiswa(mahasiswa **head, int *count) {
    if (*head == NULL) {
        printf("Lingkaran kosong\n");
        return;
    }

    mahasiswa *pDel = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(pDel);
    (*count)--;
    printf("Mahasiswa berhasil keluar dari lingkaran\n");
}

void tampilkanLingkaran(mahasiswa *head) {
    if (head == NULL) {
        printf("Lingkaran kosong\n");
        return;
    }

    mahasiswa *pCur = head;
    while (pCur != NULL) {
        printf("NPM: %d, Nama: %s, Jenis Kelamin: %s\n", pCur->npm, pCur->nama, pCur->jeniskelamin);
        pCur = pCur->next;
    }
}

void pisahkanLingkaran(mahasiswa *head) {
    printf("Lingkaran terlalu besar, dipisahkan menjadi dua lingkaran lebih kecil\n");
}

void cariMahasiswa(mahasiswa *head) {
    int npm;
    printf("Masukkan NPM Mahasiswa yang akan dicari: ");
    scanf("%d", &npm);

    mahasiswa *pCur = head;
    while (pCur != NULL && pCur->npm != npm) {
        pCur = pCur->next;
    }

    if (pCur != NULL) {
        printf("Mahasiswa ditemukan: NPM: %d, Nama: %s, Jenis Kelamin: %s\n", pCur->npm, pCur->nama, pCur->jeniskelamin);
    } else {
        printf("Mahasiswa tidak ditemukan\n");
    }
}

void jumlahMahasiswa(mahasiswa *head) {
    int count = 0;
    mahasiswa *pCur = head;

    while (pCur != NULL) {
        count++;
        pCur = pCur->next;
    }

    printf("Jumlah mahasiswa dalam lingkaran: %d\n", count);
}
