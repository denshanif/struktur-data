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
  struct Bank *pointerRekening1 = &Rekening1;
  
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
        tampilRekening( &Rekening1 );
        break;
      case 2:
        tampilSaldo( &Rekening1 );
        break;
      case 3:
        transfer( &Rekening1 );
        tampilSaldo( &Rekening1 );
        break;
      case 4:
        deposit( &Rekening1 );
        tampilSaldo( &Rekening1 );
        break;
      case 5:
        tarikDana( &Rekening1 );
        tampilSaldo( &Rekening1 );
        break;
      case 6:
        printf("Terima kasih telah menggunakan layanan kami\n");
        break;
      default: printf("Pilihan tidak tersedia\n");
    }
  } while (pilihan != 6);
}

void tampilRekening(struct Bank *pointerRekening1) {
  printf("\n *** Data Rekening ***\n");
  printf("Nama: %s \n", pointerRekening1->nama);
  printf("No Rekening: %d \n", pointerRekening1->no_rek);
}

void tampilSaldo(struct Bank *pointerRekening1) {
  printf("\n *** Saldo Rekening Anda ***\n");
  printf("Saldo: %.2f \n", pointerRekening1->saldo);
}

void transfer(struct Bank *pointerRekening1) {
  int no_rek;
  float jumlah;
  printf("\n *** Transfer Dana ***\n");
  printf("Masukkan No Rekening: ");
  scanf("%d", &no_rek);
  printf("Masukkan Jumlah Dana: ");
  scanf("%f", &jumlah);
  if (jumlah > pointerRekening1->saldo) {
    printf("Saldo Anda tidak mencukupi\n");
  } else {
    pointerRekening1->saldo -= jumlah;
    printf("Transfer berhasil\n");
  }
}

void deposit(struct Bank *pointerRekening1) {
  float jumlah;
  printf("\n *** Deposit ***\n");
  printf("Masukkan jumlah deposit: ");
  scanf("%f", &jumlah);
  pointerRekening1->saldo += jumlah;
  printf("Deposit berhasil\n");
}

void tarikDana(struct Bank *pointerRekening1) {
  float jumlah;
  printf("\n *** Tarik Dana ***\n");
  printf("Masukkan jumlah tarik dana: ");
  scanf("%f", &jumlah);
  if (jumlah > pointerRekening1->saldo) {
    printf("Saldo tidak mencukupi\n");
  } else {
    pointerRekening1->saldo -= jumlah;
    printf("Tarik dana berhasil\n");
  }
}