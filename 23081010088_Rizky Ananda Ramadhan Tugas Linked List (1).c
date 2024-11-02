#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *next;
};
typedef struct node node;

// Prototype Fungsi
void tambahAwal(node **head);
void tambahData(node **head);
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
             tambahData(&head);
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

void tambahAwal(node **head){
  int bil;
  node *pNew;

  system("cls");
  printf("masukkan bilangan : ");
  scanf("%d", &bil);

  pNew = (node *)malloc(sizeof(node));
  if (pNew != NULL){
      pNew->data = bil;
      pNew->next = *head;
      *head = pNew;
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================

void tambahData(node **head){
  int pos, bil;
  node *pNew, *pCur;

  system("cls");
  tranverse(*head);
  printf("\nposisi penyisipan setelah data bernilai : ");
  scanf("%d", &pos);
  printf("\nbilangan : ");
  scanf("%d", &bil);

  pCur = *head;
  while (pCur != NULL && pCur->data != pos) {
    pCur = pCur->next;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nalokasi memori gagal");
     getch();
  }
  else{
     pNew->data = bil;
     pNew->next = pCur->next;
     pCur->next = pNew;
  }
}

//========================================================

void tambahAkhir(node **head){
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("masukkan bilangan : ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = NULL;

        if (*head == NULL) {
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != NULL) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void hapusAwal(node **head){
    node *pDel;

    if (*head == NULL) {
        printf("List kosong\n");
    } else {
        pDel = *head;
        *head = (*head)->next;
        free(pDel);
        printf("Data awal berhasil dihapus\n");
    }
    getch();
}

//========================================================

void hapusTengah(node **head){
    int bil;
    node *pCur, *pPrev;

    if (*head == NULL) {
        printf("List kosong\n");

    }

    system("cls");
    printf("Masukkan nilai yang ingin dihapus: ");
    scanf("%d", &bil);

    pCur = *head;
    pPrev = NULL;

    while (pCur != NULL && pCur->data != bil) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("Data tidak ditemukan\n");
    } else {
        if (pPrev != NULL) {
            pPrev->next = pCur->next;
        } else {
            *head = pCur->next;
        }
        free(pCur);
        printf("Data berhasil dihapus\n");
    }
    getch();
}

//========================================================

void hapusAkhir(node **head){
    node *pCur, *pPrev;

    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }

    pCur = *head;
    pPrev = NULL;

    while (pCur->next != NULL) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (pPrev == NULL) {
        *head = NULL;
    } else {
        pPrev->next = NULL;
    }

    free(pCur);
    printf("Data akhir berhasil dihapus\n");
    getch();
}

//========================================================

void cariData(node *head){
    int bil;
    node *pCur;

    system("cls");
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &bil);

    pCur = head;
    while (pCur != NULL) {
        if (pCur->data == bil) {
            printf("Data %d ditemukan\n", bil);
            return;
        }
        pCur = pCur->next;
    }
    printf("Data %d tidak ditemukan\n", bil);
}

//========================================================

void jumlahData(node *head){
    int count = 0;
    node *pCur = head;

    while (pCur != NULL) {
        count++;
        pCur = pCur->next;
    }

    printf("Jumlah data dalam linked list: %d\n", count);
}

//========================================================


void jumlahSemuaData(node *head) {
    int sum = 0;
    node *pCur = head;

    if (pCur == NULL) {
        printf("Linked list kosong, total penjumlahan: 0\n");
        return;
    }

    while (pCur != NULL) {
        sum += pCur->data;
        pCur = pCur->next;
    }

    printf("Total semua penjumlahan data: %d\n", sum);  // Output yang memastikan jumlah ditampilkan
    return;
}

//========================================================

void tranverse(node *head){
	node *pWalker;

	system("cls");
	pWalker = head;
	while (pWalker != NULL){
		printf("%d\t", pWalker->data);
		pWalker = pWalker->next;
		printf(" -> ");
	}
	printf("NULL\n");
}
