#include <iostream>
#include <stdlib.h>

using namespace std;


struct node{
 float price;
 int jumlah;
 string nama;
 string kode;
 struct node *next; 
 struct node *back;
};

/* MEMASUKKAN DATA PENTING KA
 * dengan jumlah max 20
 * jika lebih dari 20 tidak valid
 */
void insert(struct node *&head, struct node *&tail){
      struct node *nodebaru;
      nodebaru = new struct node;
      cin.ignore();
      cout<<" Masukkan Nama Kereta : ";
      getline(cin,nodebaru->nama);
      cout<<" Masukkan Kode Kereta : ";
      getline(cin,nodebaru->kode);
      cout<<" Masukkan Harga Tiket : ";
      cin>>nodebaru->price;
      cout<<" Masukkan Jumlah Tiket (Max20):";
      cin>>nodebaru->jumlah;
      if (nodebaru->jumlah<=20){
          nodebaru->next=nodebaru->back = NULL;  
        if (tail != NULL){
          tail->next = nodebaru;
          nodebaru->back=tail;
          tail = nodebaru;
          tail->next=NULL;
        }else{
        tail = head = nodebaru;
        }
    }else{
    cout<<" Sorry.. you have exceeded the maximum limit! Try Again.. "<<endl;
    system("pause");
 }
}

/* PENCARIAN DATA KA
 * MEMASUKKAN KODE KA
 */
void search(struct node *head){
    struct node *getit, *newnode;
    newnode= new struct node;
    cin.ignore();
    cout<< " Masukkan Kode KA : ";
    getline(cin, newnode->kode);
    getit=head;
    if(getit->kode == newnode->kode){
        cout<< "==== RAILWAY TICKET ===="<<endl;
        cout<< " Nama KA : "<<getit->nama<<endl;
        cout<< " Harga Tiket : "<<getit->price<<endl;
        cout<< " Jumlah Tiket : "<<getit->jumlah<<endl;
    
    }else{
        while(getit!=NULL){
            if(getit->kode == newnode->kode){
                cout<< "==== RAILWAY TICKET ===="<<endl;
                cout<< " Nama KA : "<<getit->nama<<endl;
                cout<< " Harga Tiket : "<<getit->price<<endl;
                cout<< " Jumlah Tiket : "<<getit->jumlah<<endl;
                break;
            }
            getit=getit->next;
        }
        if(getit==NULL){
            cout<< " Nothing.."<<endl;
        }
    }    
}


void judul(){ //judul menu
    cout<< "===================================="<<endl;
    cout<< "--------------WELCOME---------------"<<endl;
    cout<< "           TICKET COUNTER           "<<endl;
    cout<< "------------------------------------"<<endl;
    cout<< " For first class, but not expensive "<<endl;
    cout<< "===================================="<<endl;
    cout<<endl;
}

/* PROSEDUR DELETE DATA KERETA SESUAI DENGAN KODE 
 * MEMASUKKAN KODE KA 
 */
void del(struct node *&head){
    struct node *getit=head, *newnode;
    newnode= new struct node;
    cin.ignore();
    cout<< " Masukkan KA yang akan dihapus (KODE) : ";
    getline(cin,newnode->kode);
    newnode->next=newnode->back=NULL;
    if(head->kode==newnode->kode){
        head=head->next;
    }else{
        while(getit->next!=NULL){
            if(getit->next->kode==newnode->kode){
                getit->next=getit->next->next;
                break;
            }
            getit=getit->next;
        }
    }
    cout<< " CLEAR..."<<endl;
}

/* PROSEDUR MENAMPILKAN LIST DATA KA
 */

void view(struct node *head)
{
 struct node *getit;
 getit = head;
 while(getit != NULL)
 {
     cout<<"Nama KA      : "<<getit->nama<<endl;
     cout<<"Kode KA      : "<<getit->kode<<endl;
     cout<<"Harga Tiket  : "<<getit->price<<endl;
     cout<<"Jumlah Tiket : "<<getit->jumlah<<endl;
     getit = getit->next;
 }
}


/* PROSEDURE MENU PEMBELIAN */
void menu(){
    judul();
    cout<< " 1. Input DATA KERETA "<<endl;
    cout<< " 2. Tampilkan DATA KERETA "<<endl;
    cout<< " 3. Pembelian TIKET KERETA "<<endl;
    cout<< " 4. Cari Data KERETA "<<endl;
    cout<< " 5. Hapus Data KERETA "<<endl;
    cout<< " 6. Exit.. "<<endl;
    cout<<endl;
    cout<< " MASUKKAN PILIHAN : ";
}

/* PROGRAM UTAMA */
int main(){
    int pilih,jml;
    string x;
    struct node *head,*getit,*newnode,*tail; //DEKLARASI STRUCT
    head=tail=newnode=getit=NULL;
    do{
        system("cls");
        menu();
        cin>>pilih;
        switch (pilih)
        {
        case 1:
            system("cls");
            cout<< " Masukkan Jumlah Data : ";cin>>jml;
            for(int i=1; i<=jml; i++){
            cout<< " ANDA MEMASUKKAN DATA KE - "<<i<<endl;
            insert(head,tail);
            }
            system("pause");
            break;
        case 2:
            system("cls");
            cout<< "====== Data KA yang tersedia ======"<<endl;
            view(head);            
            system("pause");
            break;
        case 3: 
            system("cls");
            //BELUM ADA 
            system("pause");
            break;
        case 4:
            system("cls");
            search(head);
            system("pause");
            break;
        case 5: 
            system("cls");
            del(head);
            system("pause");
            break;
        }
    }while (pilih!=6); system("pause");
}


