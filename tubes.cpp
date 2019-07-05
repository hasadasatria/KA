#include <iostream>

using namespace std;

/**
 * Skema data untuk kereta
 */
struct TrainSchema {
  int price;
  int totalCarriage;
  int totalSeat;
  string trainCode;
  string name;
  string destination;
  string destinationCode;
  string destinationTime;
  string departure;
  string departureCode;
  string departureTime;
  string classType;
};

/**
 * Skema data untuk transaksi
 * dimana pengguna dapat melakukan lebih dari 1 item
 * dalam 1 kali pemesanan
 */
struct TransactionSchema {
  long totalPrice;
  string transactionCode;
  string items[10];
};

/**
 * Deklarasi variabel penting
 */
TrainSchema trn[10];
TransactionSchema trx[10];

int ilastTrain = 0;
int ilastTransaction = 0;
int ilastItem = 0;

/**
 * Fungsi mencetak judul
 */
void fnTitle() {
  cout << " ====================================== " << endl;
  cout << "|            SELAMAT DATANG            |" << endl;
  cout << "|       BOOKING TIKET KERETA API       |" << endl;
  cout << "|--------------------------------------|" << endl;
  cout << "|  For first class, but not expensive  |" << endl;
  cout << " ====================================== " << endl;
  cout << endl;
}

/** Fungsi mencetak menu */
void fnMenu() {
  cout << " ====================================== " << endl;
  cout << "| Menu Pilihan:                        |" << endl;
  cout << "|--------------------------------------|" << endl;
  cout << "| 1. Pesan Tiket                       |" << endl;
  cout << "| 2. Lihat Deskripsi Pesanan           |" << endl;
  cout << "| 3. Batalkan Pesanan                  |" << endl;
  cout << "| 4. Lihat Daftar Kereta               |" << endl;
  cout << "| 5. Lihat Daftar Transaksi            |" << endl;
  cout << "| 6. Keluar                            |" << endl;
  cout << "|--------------------------------------|" << endl;
  cout << " ====================================== " << endl;
}

/**
 * Fungsi membuat data string secara acak
 * menggunakan looping sebagai panjang
 */
void randTransactionCode(char *_s, int _len) {
  char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i = 0; i < _len; ++i) _s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];

  _s[_len] = 0;
}

/**
 * Fungsi untuk menambah data kereta
 */
void tambahKereta(int _price, int _totalCarriage, int _totalSeat,
                  string _trainCode, string _name, string _destination,
                  string _destinationCode, string _destinationTime,
                  string _departure, string _departureCode, string _departureTime,
                  string _classType) {
  trn[ilastTrain].price =_price;
  trn[ilastTrain].totalCarriage = _totalCarriage;
  trn[ilastTrain].totalSeat = _totalSeat;
  trn[ilastTrain].name = _name;
  trn[ilastTrain].trainCode = _trainCode;
  trn[ilastTrain].destination = _destination;
  trn[ilastTrain].destinationCode = _destinationCode;
  trn[ilastTrain].destinationTime = _destinationTime;
  trn[ilastTrain].departure = _departure;
  trn[ilastTrain].departureCode = _departureCode;
  trn[ilastTrain].departureTime = _departureTime;
  trn[ilastTrain].classType = _classType;
  ilastTrain++;
}

/**
 * Fungsi untuk mencari index kereta pada array
 * berdasarkan kode kereta yang ada
 */
int cariKereta(string _code) {
  for (int a = 0; a < ilastTrain; a++) {
    if (_code == trn[a].trainCode) {
      return a;
    }
  }
  return -1;
}

/**
 * Fungsi untuk mencetak list data kereta
 */
void listKereta() {
  for (int a = 0; a < ilastTrain; a++) {
    cout << " =============================================== " << endl;
    cout << "| No." << a + 1 << "\t\t\t\t\t\t|" << endl;
    cout << " =============================================== " << endl;
    cout << "| Kode\t\t\t: " << trn[a].trainCode << "\t\t\t|" << endl;
    cout << "| Nama\t\t\t: " << trn[a].name << "\t\t|" << endl;
    cout << "| Harga\t\t\t: " << trn[a].price << "\t\t|" << endl;
    cout << "| Gerbong\t\t: " << trn[a].totalCarriage << "\t\t\t|" << endl;
    cout << "| Tempat Duduk\t\t: " << trn[a].totalSeat << "\t\t\t|" << endl;
    cout << "| Kelas\t\t\t: " << trn[a].classType << "\t\t|" << endl;
    cout << "| Tujuan Kota\t\t: " << trn[a].destination << " (" << trn[a].destinationCode << ")" << "\t|" << endl;
    cout << "| Keberangkatan Kota\t: " << trn[a].departure << " (" << trn[a].departureCode << ")" << "\t|" << endl;
    if (a == ilastTrain - 1) {
      cout << " =============================================== " << endl;
    }
  }
}

/**
 * Fungsi untuk mencetak list data transaksi
 * dengan dua tipe yaitu: berdasarkan kode transaksi
 * dan semua list data transaksi
 */
void listTransaksi(string tp = "none") {
  if (tp == "none") {
    for (int a = 0; a < ilastTransaction; a++) {
      cout << " =============================================== " << endl;
      cout << "| Kode Pesanan\t: " << trx[a].transactionCode << "\t\t\t\t|" << endl;
      cout << "| Total Harga\t: " << trx[a].totalPrice << "\t\t\t|" << endl;
      cout << "| --------------------------------------------- |" << endl;
      cout << "| Tiket\t\t: \t\t\t\t|" << endl;
      cout << "| --------------------------------------------- |" << endl;
      for (int b = 0; b < 10; b++) {
        int checkData = cariKereta(trx[a].items[b]);
        if (checkData != -1) {
          cout << "| No." << b + 1 << "\t\t\t\t\t\t|"<< endl;
          cout << "| Kode\t\t\t: " << trn[checkData].trainCode << "\t\t\t|" << endl;
          cout << "| Nama\t\t\t: " << trn[checkData].name << "\t\t|" << endl;
          cout << "| Harga\t\t\t: " << trn[checkData].price << "\t\t|" << endl;
          cout << "| Gerbong\t\t: " << trn[checkData].totalCarriage << "\t\t\t|" << endl;
          cout << "| Tempat Duduk\t\t: " << trn[checkData].totalSeat << "\t\t\t|" << endl;
          cout << "| Kelas\t\t\t: " << trn[checkData].classType << "\t\t|" << endl;
          cout << "| Tujuan Kota\t\t: " << trn[checkData].destination << " (" << trn[checkData].destinationCode << ")" << "\t|" << endl;
          cout << "| Keberangkatan Kota\t: " << trn[checkData].departure << " (" << trn[checkData].departureCode << ")" << "\t|" << endl;
        }
      }
      cout << " =============================================== " << endl;
      cout << endl;
    }
  } else {
    for (int a = 0; a < ilastTransaction; a++) {
      if (tp == trx[a].transactionCode) {
        cout << " =============================================== " << endl;
        cout << "| Kode Pesanan\t: " << trx[a].transactionCode << "\t\t\t\t|" << endl;
        cout << "| Total Harga\t: " << trx[a].totalPrice << "\t\t\t|" << endl;
        cout << "| --------------------------------------------- |" << endl;
        cout << "| Tiket\t\t: \t\t\t\t|" << endl;
        cout << "| --------------------------------------------- |" << endl;
        for (int b = 0; b < 10; b++) {
          int checkData = cariKereta(trx[a].items[b]);
          if (checkData != -1) {
            cout << "| No." << b + 1 << "\t\t\t\t\t\t|"<< endl;
            cout << "| Kode\t\t\t: " << trn[checkData].trainCode << "\t\t\t|" << endl;
            cout << "| Nama\t\t\t: " << trn[checkData].name << "\t\t|" << endl;
            cout << "| Harga\t\t\t: " << trn[checkData].price << "\t\t|" << endl;
            cout << "| Gerbong\t\t: " << trn[checkData].totalCarriage << "\t\t\t|" << endl;
            cout << "| Tempat Duduk\t\t: " << trn[checkData].totalSeat << "\t\t\t|" << endl;
            cout << "| Kelas\t\t\t: " << trn[checkData].classType << "\t\t|" << endl;
            cout << "| Tujuan Kota\t\t: " << trn[checkData].destination << " (" << trn[checkData].destinationCode << ")" << "\t|" << endl;
            cout << "| Keberangkatan Kota\t: " << trn[checkData].departure << " (" << trn[checkData].departureCode << ")" << "\t|" << endl;
          }
        }
        cout << " =============================================== " << endl;
        cout << endl;
      }
    }
  }
}

/**
 * Fungsi untuk menambah data pada list transaksi
 */
void tambahTransaksi(string _transactionCode, string _item) {
  trx[ilastTransaction].transactionCode = _transactionCode;
  trx[ilastTransaction].items[ilastItem] = _item;

  // Mencari total harga
  int checkedPrice = 0;
  for (int a = 0; a <= ilastItem; a++) {
    int indexKereta = cariKereta(trx[ilastTransaction].items[a]);
    checkedPrice += trn[indexKereta].price;
  }
  trx[ilastTransaction].totalPrice = checkedPrice;
}

/**
 * Fungsi untuk memesan tiket kereta dengan bantuan
 * fungsi lain yang sudah di sediakan
 */
void pesanTiket() {
  char trxCode[5];
  randTransactionCode(trxCode, 5);

  // Tampil List Kereta
  listKereta();

  // looping
  int status = 1;
  do {
    // Minta Kode Kereta
    string code;
    cout << "Kode kereta yang dipilih: "; cin >> code;

    // Cari Kereta berdasarkan kode
    int indexKereta = cariKereta(code);
    if (indexKereta != -1){
      tambahTransaksi(trxCode, code);

      string pesan;
      cout << "Lagi (y/n)? "; cin >> pesan;
      if (pesan == "n" || pesan == "N") status = 0;

      ilastItem++;
      ilastTransaction++;
    } else {
      cout << "Kode kereta yang dipilih tidak tersedia." << endl;
    }
  } while(status == 1);
  system("clear");
  listTransaksi(trxCode);
}

/**
 * Fungsi untuk melihat deskripsi transaksi
 * berdasarkan kode transaksi yang ada
 */
void lihatDeskripsiPesanan() {
  string code;

  cout << "Masukan kode pesanan : "; cin >> code;
  listTransaksi(code);
}

/**
 * Fungsi untuk membatalkan atau menghapus transaksi
 * dari list transaksi
 */
void batalkanPesanan() {
  string code;

  TransactionSchema bantuTrx[10];
  int indexTrxBantu = 0;

  cout << "Masukan kode pesanan : "; cin >> code;

  // Mindah data utama ke bantu
  for (int a = 0; a < ilastTransaction; a++) {
    if (code != trx[a].transactionCode) {
      bantuTrx[indexTrxBantu].transactionCode = trx[a].transactionCode;
      bantuTrx[indexTrxBantu].totalPrice = trx[a].totalPrice;
      for (int b = 0; b < 10; b++) {
        int checkData = cariKereta(trx[a].items[b]);
        if (checkData != -1) {
          bantuTrx[indexTrxBantu].items[b] = trx[a].items[b];
        }
      }
      indexTrxBantu++;
    }
  }

  ilastTransaction--;

  // Mindah data bantu ke data utama
  for (int b = 0; b < indexTrxBantu; b++) {
    trx[b].transactionCode = bantuTrx[b].transactionCode;
    trx[b].totalPrice = bantuTrx[b].totalPrice;
    for (int c = 0; c < 10; c++) {
      int checkData = cariKereta(bantuTrx[b].items[c]);
      if (checkData != -1) {
        trx[b].items[c] = bantuTrx[indexTrxBantu].items[c];
      }
    }
  }
}

int main() {
  /**
   * Memanggil fungsi untuk mencetak judul aplikasi
   */
  fnTitle();

  /**
   * Memanggil fungsi untuk mencetak menu aplikasi
   */
  fnMenu();

  /**
   * Deklarasi variabel yang dibutuhkan
   */
  int choice;
  int status = 1;

  /**
   * Deklarasi data kereta
   */
  tambahKereta(100000, 5, 120, "ABCD", "Gajah Kencana", "Purwokerto", "PWT", "1 Jan 2019", "Yogyakarta", "YOG", "1 Jan 2019", "Ekonomi");
  tambahKereta(100000, 5, 120, "EFGH", "Joglo Semar", "Yogyakarta", "YOG", "1 Jan 2019", "Purwokerto", "PWT", "1 Jan 2019", "Ekonomi");

  /**
   * Looping menu
   */
  do {
    /**
     * Input pilihan
     */
    cout << "Pilih menu (tampil menu: 7): "; cin >> choice;
    /**
     * Pilihan menu
     */
    switch (choice) {
      /**
       * Pesanan tiket
       * pengguna dapat melakukan reservasi tiket
       * dengan adanya tampilan list tiket.
       */
      case 1:
        system("clear");
        pesanTiket();
        break;

      /**
       * Lihat detail pesanan
       * pengguna dapat melihat detail tiket
       * yang dibooking
       */
      case 2:
        system("clear");
        lihatDeskripsiPesanan();
        break;

      /**
       * Batalkan pesanan
       * akan menghapus transaksi yang dilakukan
       * pengguna
       */
      case 3:
        system("clear");
        batalkanPesanan();
        break;

      /**
       * Lihat list kereta
       * akan menampilkan list kereta yang tersedia
       */
      case 4:
        system("clear");
        listKereta();
        break;

      /**
       * List Transaksi
       * akan menampilkan list transaksi semua pengguna
       */
      case 5:
        system("clear");
        listTransaksi();
        break;

      /**
       * Keluar
       */
      case 6:
        status = 0;
        break;

      /**
       * Default
       */
      default:
        system("clear");
        fnMenu();
        break;
    }
  } while (status == 1);
}
