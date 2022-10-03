#include <stdio.h>
#include <stdlib.h>

// Membuat struct
struct node
{
  int data;
  struct node *next;
  struct node *prev;
};

// Fungsi untuk menambahkan data di awal list
void tambahDataAwal(struct node **pAwal)
{
  struct node *pBaru;
  pBaru = (struct node *)malloc(sizeof(struct node));

  printf("\nMasukkan data: ");
  scanf("%d", &pBaru->data);
  pBaru->next = (*pAwal);
  pBaru->prev = NULL;

  if ((*pAwal) != NULL)
  {
    (*pAwal)->prev = pBaru;
  }

  (*pAwal) = pBaru;
}

// Fungsi untuk menambahkan data di akhir list
void tambahDataAkhir(struct node **pAwal)
{
  struct node *pBaru;
  pBaru = (struct node *)malloc(sizeof(struct node));
  struct node *pAkhir = *pAwal;

  printf("\nMasukkan data: ");
  scanf("%d", &pBaru->data);
  pBaru->next = NULL;

  if (*pAwal == NULL)
  {
    pBaru->prev = NULL;
    *pAwal = pBaru;
    return;
  }

  while (pAkhir->next != NULL)
  {
    pAkhir = pAkhir->next;
  }

  pAkhir->next = pBaru;
  pBaru->prev = pAkhir;

  return;
}

// Menampilkan seluruh data pada list
void tampilData(struct node *node)
{
  struct node *pAkhir;
  if (node == NULL)
  {
    printf("Data kosong, silahkan tambahkan data: \n");
  }

  printf("\n\nData yang ada pada list: \n");
  while (node != NULL)
  {
    printf("%d ", node->data);
    pAkhir = node;
    node = node->next;
  }

  printf("\n");

  return;
}

// Menghapus data di awal list
void hapusDataAwal(struct node **pAwal)
{
  if (*pAwal == NULL)
  {
    printf("\nTidak ada data yang dapat dihapus\n");
    return;
  }

  struct node *pHapus = *pAwal;
  *pAwal = (*pAwal)->next;
  free(pHapus);
}

// Menghapus data di akhir list
void hapusDataAkhir(struct node **pAwal)
{
  if (*pAwal == NULL)
  {
    printf("\nTidak ada data yang dapat dihapus\n");
    return;
  }

  struct node *pAkhir = *pAwal;
  struct node *pHapus;

  while (pAkhir->next != NULL)
  {
    pAkhir = pAkhir->next;
  }

  pHapus = pAkhir;
  pAkhir->prev->next = NULL;
  free(pHapus);
}

// Menjumlahkan semua data yang ada pada list
void jumlahkanData(struct node *pAwal)
{
  if (pAwal == NULL)
  {
    printf("\nTidak ada data yang dapat dijumlahkan\n");
    return;
  }

  int jumlah = 0;
  while (pAwal != NULL)
  {
    jumlah += pAwal->data;
    pAwal = pAwal->next;
  }
  printf("\n\nHasil penjumlahan dari semua data: %d\n", jumlah);
}

// Fungsi utama program
void main() {
  struct node *pAwal = NULL;

  int pilihan;
  do
  {
    printf("\n\n*** Menu Doubly Linked List ***\n");
    printf("1. Tambahkan Data di Awal\n");
    printf("2. Tambahkan Data di Akhir\n");
    printf("3. Tampilkan Semua Data\n");
    printf("4. Hapus Data Di Awal List\n");
    printf("5. Hapus Data Di Akhir List\n");
    printf("6. Jumlahkan Semua Data\n");
    printf("7. Keluar\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
      tambahDataAwal(&pAwal);
      break;
    case 2:
      tambahDataAkhir(&pAwal);
      break;
    case 3:
      tampilData(pAwal);
      break;
    case 4:
      hapusDataAwal(&pAwal);
      tampilData(pAwal);
      break;
    case 5:
      hapusDataAkhir(&pAwal);
      tampilData(pAwal);
      break;
    case 6:
      jumlahkanData(pAwal);
      break;
    case 7:
      printf("Terima kasih telah menggunakan program ini\n");
      break;
    }
  } while (pilihan != 7);
}