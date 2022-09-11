#include <stdio.h>
#include <string.h>

void tampilRekening();
void tampilSaldo();
void transfer();
void deposit();
void tarikDana();

struct Bank {
  char nama[20];
  int no_rek;
  float saldo;
};

void main() {
  struct Bank Rekening1;
  
  /* Rekening Andi */
  strcpy(Rekening1.nama, "Andi");
  Rekening1.no_rek = 123456789;
  Rekening1.saldo = 500000;

  int pilihan;
  do {
    printf("\n*** Simulasi Bank ***\n");
    printf("1. Tampilkan Data Rekening\n");
    printf("2. Tampilkan Saldo\n");
    printf("3. Transfer Dana\n");
    printf("4. Deposit\n");
    printf("5. Tarik Dana\n");
    printf("6. Keluar\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);
    switch (pilihan) {
      case 1:
        tampilRekening( Rekening1 );
        break;
      case 2:
        tampilSaldo( Rekening1 );
        break;
      case 3:
        transfer( &Rekening1 );
        break;
      case 4:
        deposit( &Rekening1 );
        break;
      case 5:
        tarikDana( &Rekening1 );
        break;
      case 6:
        printf("Terima kasih telah menggunakan layanan kami\n");
        break;
      default: printf("Pilihan tidak tersedia\n");
    }
  } while (pilihan != 6);
}

void tampilRekening( struct Bank Rekening1) {
  printf("\n *** Data Rekening ***\n");
  printf("\nNama: %s \n", Rekening1.nama);
  printf("No. Rekening: %d \n", Rekening1.no_rek);
}

void tampilSaldo( struct Bank Rekening1) {
  printf("\n *** Saldo Rekening Anda ***\n");
  printf("Saldo: %.2f \n", Rekening1.saldo);
}

void transfer( struct Bank Rekening1) {
  int no_rek;
  float jumlah;
  printf("\n *** Transfer Dana ***\n");
  printf("Masukkan no. rekening tujuan: ");
  scanf("%d", &no_rek);
  printf("Masukkan jumlah transfer: ");
  scanf("%f", &jumlah);
  if (jumlah > Rekening1.saldo) {
    printf("Saldo tidak mencukupi\n");
  } else {
    Rekening1.saldo -= jumlah;
    printf("Transfer berhasil\n");
  }
}

void deposit( struct Bank Rekening1) {
  float jumlah;
  printf("\n *** Deposit ***\n");
  printf("Masukkan jumlah deposit: ");
  scanf("%f", &jumlah);
  Rekening1.saldo += jumlah;
  printf("Deposit berhasil\n");
}

void tarikDana( struct Bank Rekening1) {
  float jumlah;
  printf("\n *** Tarik Dana ***\n");
  printf("Masukkan jumlah tarik dana: ");
  scanf("%f", &jumlah);
  if (jumlah > Rekening1.saldo) {
    printf("Saldo tidak mencukupi\n");
  } else {
    Rekening1.saldo -= jumlah;
    printf("Tarik dana berhasil\n");
  }
}