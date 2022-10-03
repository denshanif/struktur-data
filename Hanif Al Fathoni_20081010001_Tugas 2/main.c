#include <stdio.h>
#include <stdlib.h>

// Membuat struct
struct node
{
  int data;
  struct node *next;
};

// Fungsi untuk menambahkan data di awal list
void tambahDataAwal(struct node **pAwal)
{
  struct node *pBaru;
  pBaru = (struct node *)malloc(sizeof(struct node));

  printf("\nMasukkan data: ");
  scanf("%d", &pBaru->data);
  pBaru->next = (*pAwal);
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
    *pAwal = pBaru;
    return;
  }

  while (pAkhir->next != NULL)
  {
    pAkhir = pAkhir->next;
  }

  pAkhir->next = pBaru;
  return;
}

// Menampilkan seluruh data pada list
void tampilData(struct node *pAwal)
{
  if (pAwal == NULL)
  {
    printf("Data kosong, silahkan tambahkan data: \n");
  }
  else
  {
    printf("\nList data yang ada: \n");
    while (pAwal != NULL)
    {
      printf("%d ", pAwal->data);
      pAwal = pAwal->next;
    }
  }
}

// Menghapus data yang terletak pada awal list
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

// Menghapus data yang terletak pada akhir list
void hapusDataAkhir(struct node **pAwal)
{
  if (*pAwal == NULL)
  {
    printf("\nTidak ada data yang dapat dihapus\n");
    return;
  }

  struct node *pHapus = *pAwal;
  struct node *pSebelumnya = NULL;

  if (pHapus->next == NULL)
  {
    *pAwal = NULL;
    free(pHapus);
    return;
  }

  while (pHapus->next != NULL)
  {
    pSebelumnya = pHapus;
    pHapus = pHapus->next;
  }

  pSebelumnya->next = NULL;
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
    printf("\n\n*** Menu ***\n");
    printf("1. Tambahkan Data di Awal\n");
    printf("2. Tambahkan Data di Akhir\n");
    printf("3. Tampilkan Semua Data\n");
    printf("4. Hapus Data di Awal\n");
    printf("5. Hapus Data di Akhir\n");
    printf("6. Jumlahkan Semua Data\n");
    printf("7. Keluar\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
      tampilData(pAwal);
      tambahDataAwal(&pAwal);
      tampilData(pAwal);
      break;
    case 2:
      tampilData(pAwal);
      tambahDataAkhir(&pAwal);
      tampilData(pAwal);
      break;
    case 3:
      tampilData(pAwal);
      break;
    case 4:
      tampilData(pAwal);
      hapusDataAwal(&pAwal);
      tampilData(pAwal);
      break;
    case 5:
      tampilData(pAwal);
      hapusDataAkhir(&pAwal);
      tampilData(pAwal);
      break;
    case 6:
      tampilData(pAwal);
      jumlahkanData(pAwal);
      break;
    case 7:
      printf("Terima kasih telah menggunakan program ini\n");
      break;
    }
  } while (pilihan != 7);
}