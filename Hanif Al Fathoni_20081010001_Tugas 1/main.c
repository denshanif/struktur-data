#include <stdio.h>

void tampilRekening();
void tampilSaldo();
void transfer();
void deposit();
void tarikDana();

void main() {
  char namaNasabah[20] = "Andi";
  int noRekening = 123456789;
  int saldo = 500000;

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
        tampilRekening( &namaNasabah, &noRekening);
        break;
      case 2:
        tampilSaldo( &saldo);
        break;
      case 3:
        transfer( &saldo);
        tampilSaldo( &saldo);
        break;
      case 4:
        deposit( &saldo);
        tampilSaldo( &saldo);
        break;
      case 5:
        tarikDana( &saldo);
        tampilSaldo( &saldo);
        break;
      case 6:
        printf("Terima kasih telah menggunakan layanan kami\n");
        break;
      default: printf("Pilihan tidak tersedia\n");
    }
  } while (pilihan != 6);
}

void tampilRekening(char *namaNasabah, int *noRekening) {
  char *nama = namaNasabah;
  int *noRek = noRekening;
  printf("\n *** Data Rekening ***\n");
  printf("Nama Nasabah: %s\n", nama);
  printf("No Rekening: %d\n", *noRek);
}

void tampilSaldo(int *saldo) {
  int *sld = saldo;
  printf("\n *** Saldo Rekening Anda ***\n");
  printf("Saldo: %d\n", *sld);
}

void transfer(int *saldo) {
  int rekeningTujuan, jumlahTransfer, *sld = saldo;
  printf("\n *** Transfer Dana ***\n");
  printf("Masukkan no rekening tujuan: ");
  scanf("%d", &rekeningTujuan);
  printf("Masukkan jumlah transfer: ");
  scanf("%d", &jumlahTransfer);
  if (jumlahTransfer > *sld) {
    printf("Saldo tidak mencukupi\n");
  } else {
    *sld -= jumlahTransfer;
    printf("Transfer berhasil\n");
  }
}

void deposit(int *saldo) {
  int jumlahDeposit, *sld = saldo;
  printf("\n *** Deposit ***\n");
  printf("Masukkan jumlah deposit: ");
  scanf("%d", &jumlahDeposit);
  *sld += jumlahDeposit;
}

void tarikDana(int *saldo) {
  int jumlahTarik, *sld = saldo;
  printf("\n *** Tarik Dana ***\n");
  printf("Masukkan jumlah tarik: ");
  scanf("%d", &jumlahTarik);
  if (jumlahTarik > *sld) {
    printf("Saldo tidak mencukupi\n");
  } else {
    *sld -= jumlahTarik;
    printf("Tarik dana berhasil\n");
  }
}