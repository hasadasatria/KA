#include <iostream>
#include <stdlib.h>

using namespace std;

struct TNode {
  float price;
  int total;
  string name;
  string code;

  TNode *next;
  TNode *back;
};

/* MEMASUKKAN DATA PENTING KA
 * dengan jumlah max 20
 * jika lebih dari 20 tidak valid
 */
void insert(TNode *&head, TNode *&tail) {
  // inisialisasi node baru
  TNode *newNode, *getit;
  newNode = new TNode;

  // menerima inputan
  cin.ignore();
  cout << "| Masukkan Nama Kereta : ";
  getline(cin, newNode->name);

  cout << "| Masukkan Kode Kereta : ";
  getline(cin, newNode->code);

  cout << "| Masukkan Harga Tiket : ";
  cin >> newNode->price;

  cout << "| Masukkan Jumlah Tiket (Max 20): ";
  cin >> newNode->total;

  // validasi inputan total tidak lebih dari 20
  if (newNode->total <= 20) {

    // inisialisasi node baru next dan back dengan NULL
    newNode->next = newNode->back = NULL;
    if (tail != NULL) {
      tail->next = newNode;
      newNode->back = tail;
      tail = newNode;
      tail->next = NULL;
    } else {
      tail = head = newNode;
    }
  } else {
    cout << " Sorry.. you have exceeded the maximum limit! Try Again.. " << endl;
    system("read -p 'Press Enter to continue...' var");
  }
}

/* PENCARIAN DATA KA
 * MEMASUKKAN KODE KA
 */
void search(TNode *head) {
  // inisialisasi node baru
  TNode *getit, *newNode;
  newNode = new TNode;

  int ct = 1;

  // menerima inputan
  cin.ignore();
  cout << " Masukkan Kode KA : ";
  getline(cin, newNode->code);

  // inisiaslisasi getit dengan data
  getit = head;

  // check node pertama dengan perbandingan 'code'
  cout << endl;
  cout << " =============== Data KA ============== " << endl;
  if (getit->code == newNode->code) {
    cout << "| #" << ct << endl;
    cout << "| Nama KA\t: " << getit->name << endl;
    cout << "| Harga Tiket\t: " << getit->price << endl;
    cout << "| Jumlah Tiket\t: " << getit->total << endl;
    cout << endl;
    ct++;
  } else {
    // check node selanjutnya
    while (getit != NULL) {
      if (getit->code == newNode->code) {
        cout << "| #" << ct << endl;
        cout << "| Nama KA\t: " << getit->name << endl;
        cout << "| Harga Tiket\t: " << getit->price << endl;
        cout << "| Jumlah Tiket\t: " << getit->total << endl;
        cout << endl;
        ct++;
        break;
      }
      getit = getit->next;
    }
    // check node apabila data kosong
    if (getit == NULL) {
      cout << " Nothing.." << endl;
    }
  }
}

/* PROSEDUR PEMBAYARAN TIKET DENGAN MEMASUKKAN KODE TIKET TERLEBIH DAHULU */
void buy(TNode *&head) {
  // inisialisasi node baru
  TNode *getit, *newNode;
  newNode = new TNode;

  int totalItem;
  int priceItem = 0;
  int status = 0;

  cin.ignore();
  do {
    getit = head;

    // menerima inputan
    cout << "| Masukkan Kode KA\t: ";
    getline(cin, newNode->code);

    // pencarian tiket
    while (getit != NULL) {
      if (getit->code == newNode->code) {
        priceItem = getit->price;
      }
      getit = getit->next;
    }

    if (priceItem != 0) {
      cout << "| Harga Tiket\t\t: " << priceItem << endl;
      cout << "| Jumlah Tiket\t\t: "; cin >> totalItem;
      cout << "| Total Pembayaran\t: " << totalItem * priceItem << endl;
      status = 1;
    } else {
      cout << "| Kode KA tidak tersedia" << endl;
    }
  } while (status == 0);
}

/* PROSEDUR DELETE DATA KERETA SESUAI DENGAN KODE
 * MEMASUKKAN KODE KA
 */
void del(TNode *&head) {
  // inisialisasi node dengan data dan node baru
  TNode *getit = head, *newNode;
  newNode = new TNode;

  // menerima inputan
  cin.ignore();
  cout << " Masukkan KA yang akan dihapus (KODE) : ";
  getline(cin, newNode->code);

  // inisialisasi next back node baru dengan nilai NULL
  newNode->next = newNode->back = NULL;

  // check urutan pertama
  if (head->code == newNode->code) {
    head = head->next;
  } else {
    // check urutan selanjutnya node->next
    while (getit->next != NULL) {
      if (getit->next->code == newNode->code) {
        getit->next = getit->next->next;
        break;
      }
      getit = getit->next;
    }
  }
  cout << " CLEAR..." << endl;
}

/* PROSEDUR MENAMPILKAN LIST DATA KA
 */
void view(TNode *head) {
  // inisialisasi node dengan data
  TNode *getit;
  getit = head;

  int ct = 1;

  // pengulangan
  while (getit != NULL) {
    cout << "| #" << ct << endl;
    cout << "| Nama KA\t: " << getit->name << endl;
    cout << "| Kode KA\t: " << getit->code << endl;
    cout << "| Harga Tiket\t: " << getit->price << endl;
    cout << "| Jumlah Tiket\t: " << getit->total << endl;

    if (getit->next != NULL) {
      cout << endl;
    }
    // reassign node dengan data selanjutnya
    getit = getit->next;
    ct++;
  }
}

/* PROSEDURE MENU PEMBELIAN */
void menu() {
  cout << " ====================================== " << endl;
  cout << "|            SELAMAT DATANG            |" << endl;
  cout << "|       BOOKING TIKET KERETA API       |" << endl;
  cout << "|--------------------------------------|" << endl;
  cout << "|  For first class, but not expensive  |" << endl;
  cout << " ====================================== " << endl;
  cout << "| Menu Pilihan:                        |" << endl;
  cout << "|--------------------------------------|" << endl;
  cout << "| 1. Tambah Data Kereta                |" << endl;
  cout << "| 2. Tampilkan Data Kereta             |" << endl;
  cout << "| 3. Pembelian Tiket Kereta            |" << endl;
  cout << "| 4. Cari Data Kereta                  |" << endl;
  cout << "| 5. Hapus Data Kereta                 |" << endl;
  cout << "| 6. Keluar                            |" << endl;
  cout << "|--------------------------------------|" << endl;
  cout << " ====================================== " << endl;

  cout << endl;
  cout << " Masukan Pilihan : ";
}

/* PROGRAM UTAMA */
int main() {
  // deklarasi variable
  int choice, total;

  // inisialisasi node
  TNode *head, *getit, *newNode, *tail;

  // set node awal ke null
  head = tail = newNode = getit = NULL;
  do {
    system("clear");

    menu();
    cin >> choice;

    // pilihan
    switch (choice) {
    case 1:
      system("clear");
      cout << "| Masukkan Jumlah Data : "; cin >> total;
      cout << endl;

      for (int i = 1; i <= total; i++) {
        cout << "| #" << i << endl;
        insert(head, tail);
        cout << endl;
      }
      system("read -p 'Press Enter to continue...' var");
      break;
    case 2:
      system("clear");
      cout << " ======== Data KA yang tersedia ======= " << endl;
      view(head);
      cout << " ====================================== " << endl;
      system("read -p 'Press Enter to continue...' var");
      break;
    case 3:
      system("clear");
      cout << " ========== Pembelian Tiket =========== " << endl;
      buy(head);
      system("read -p 'Press Enter to continue...' var");
      break;
    case 4:
      system("clear");
      search(head);
      system("read -p 'Press Enter to continue...' var");
      break;
    case 5:
      system("clear");
      del(head);
      system("read -p 'Press Enter to continue...' var");
      break;
    }
  } while (choice != 6);
  system("read -p 'Press Enter to continue...' var");
}
