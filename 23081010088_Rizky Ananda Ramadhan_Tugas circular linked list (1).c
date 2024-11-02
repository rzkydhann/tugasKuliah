#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *next;
};
typedef struct node node;


void tambahAwal(node **head);
void tambahTengah(node **head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void jumlahData(node *head);
void jumlahSemuaData(node *head);
void tranverse(node *head);

//========================================================

int main()
{
  node *head;
  int pilih;

  head = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. tambah data di awal\n");
     printf("2. tambah data di tengah linked list\n");
     printf("3. tambah data di akhir linked list\n");
     printf("4. cetak isi list\n");
     printf("5. hapus data di awal\n");
     printf("6. hapus data di tengah\n");
     printf("7. hapus data di akhir\n");
     printf("8. cari data dalam linked list\n");
     printf("9. tampilkan informasi jumlah data di linked list\n");
     printf("10. tampilkan total semua penjumlahan data\n");
     printf("MASUKKAN PILIHAN (tekan 0 untuk keluar) : ");
     fflush(stdin);
     scanf("%d", &pilih);

     switch (pilih) {
         case 1:
             tambahAwal(&head);
             break;
         case 2:
             tambahTengah(&head);
             break;
         case 3:
             tambahAkhir(&head);
             break;
         case 4:
             tranverse(head);
             getch();
             break;
         case 5:
             hapusAwal(&head);
             break;
         case 6:
             hapusTengah(&head);
             break;
         case 7:
             hapusAkhir(&head);
             break;
         case 8:
             cariData(head);
             getch();
             break;
         case 9:
             jumlahData(head);
             getch();
             break;
         case 10:
             jumlahSemuaData(head);
             getch();
             break;


     }
  } while (pilih != 0);

  return 0;
}

//========================================================
void tambahAwal(node **head) {
    int bil;
    node *pNew;

    system("cls");
    printf("masukkan bilangan : ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;

        if (*head == NULL) {
            *head = pNew;
            pNew->next = *head;
        } else {
            node *temp = *head;
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = pNew;
            pNew->next = *head;
            *head = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================
void tambahTengah(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nposisi penyisipan setelah data bernilai : ");
    scanf("%d", &pos);
    printf("\nbilangan : ");
    scanf("%d", &bil);

    pCur = *head;

    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }

    do {
        if (pCur->data == pos) {
            break;
        }
        pCur = pCur->next;
    } while (pCur != *head);

    pNew = (node *)malloc(sizeof(node));

    if (pCur == *head && pCur->data != pos) {
        printf("\nnode tidak ditemukan");
        getch();
    } else if (pNew == NULL) {
        printf("\nalokasi memori gagal");
        getch();
    } else {
        pNew->data = bil;
        pNew->next = pCur->next;
        pCur->next = pNew;
    }
}

//========================================================
void tambahAkhir(node **head) {
    int bil;
    node *pNew;

    system("cls");
    printf("masukkan bilangan : ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;

        if (*head == NULL) {
            *head = pNew;
            pNew->next = *head;
        } else {
            node *temp = *head;
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = pNew;
            pNew->next = *head;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================
void tranverse(node *head) {
    node *pWalker;

    system("cls");
    if (head == NULL) {
        printf("List kosong\n");
        return;
    }

    pWalker = head;
    do {
        printf("%d\t", pWalker->data);
        pWalker = pWalker->next;
    } while (pWalker != head);
    printf("\n");
}

//========================================================

void hapusAwal(node **head) {
    node *pDel;

    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }

    pDel = *head;

    if (pDel->next == *head) {
        *head = NULL;
    } else {
        node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        *head = (*head)->next;
        temp->next = *head;
    }

    free(pDel);
    printf("Data awal berhasil dihapus\n");
    getch();
}


//========================================================
void hapusTengah(node **head) {
    int bil;
    node *pCur, *pPrev;

    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }

    system("cls");
    printf("Masukkan nilai yang ingin dihapus: ");
    scanf("%d", &bil);

    pCur = *head;
    pPrev = NULL;

    do {
        if (pCur->data == bil) {
            break;
        }
        pPrev = pCur;
        pCur = pCur->next;
    } while (pCur != *head);

    if (pCur == *head && pCur->data != bil) {
        printf("Data tidak ditemukan\n");
    } else {
        if (pPrev != NULL) {
            pPrev->next = pCur->next;
        } else {
            *head = pCur->next;
            node *temp = *head;
            while (temp->next != pCur) {
                temp = temp->next;
            }
            temp->next = *head;
        }
        free(pCur);
        printf("Data berhasil dihapus\n");
    }
    getch();
}
//========================================================

void hapusAkhir(node **head) {
    node *pCur, *pPrev;

    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }

    pCur = *head;
    pPrev = NULL;

    while (pCur->next != *head) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (pPrev == NULL) {
        *head = NULL;
    } else {
        pPrev->next = *head;
    }

    free(pCur);
    printf("Data akhir berhasil dihapus\n");
    getch();
}
//========================================================
void cariData(node *head) {
    int bil;
    node *pCur;

    system("cls");
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &bil);

    pCur = head;

    if (head == NULL) {
        printf("List kosong\n");
        return;
    }

    do {
        if (pCur->data == bil) {
            printf("Data %d ditemukan\n", bil);
            return;
        }
        pCur = pCur->next;
    } while (pCur != head);

    printf("Data %d tidak ditemukan\n", bil);
    getch();
}
//========================================================

void jumlahData(node *head) {
    int count = 0;
    node *pWalker;

    if (head == NULL) {
        printf("List kosong\n");
        return;
    }

    pWalker = head;
    do {
        count++;
        pWalker = pWalker->next;
    } while (pWalker != head);

    printf("Jumlah data di list: %d\n", count);
}

//========================================================

void jumlahSemuaData(node *head) {
    int total = 0;
    node *pWalker;

    if (head == NULL) {
        printf("List kosong\n");
        return;
    }

    pWalker = head;
    do {
        total += pWalker->data;
        pWalker = pWalker->next;
    } while (pWalker != head);

    printf("Total penjumlahan data: %d\n", total);
}

