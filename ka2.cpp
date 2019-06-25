#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;


struct loket{
    string kereta;
    char kode[10];
    int stock;
    int harga;
}lkt;

vector<loket>loket;
int j;

ofstream program;
ifstream file;

void judul(){
    cout<< "===================================="<<endl;
    cout<< "--------------WELCOME---------------"<<endl;
    cout<< "           TICKET COUNTER           "<<endl;
    cout<< "------------------------------------"<<endl;
    cout<< " For first class, but not expensive "<<endl;
    cout<< "===================================="<<endl;
    cout<<endl;
}

void tambahka(){
    cout<< " Masukkan Nama Kereta Api : ";cin>>lkt.kereta;
    cout<< " Masukkan Kode Kereta Api : ";cin>>lkt.kode;
    cout<< " Masukkan Stock Tiket KA  : ";cin>>lkt.stock;
    cout<< " Masukkan Harga Tiket KA  : ";cin>>lkt.harga;

    cout<<endl;
    cout<< " Berhasil ditambah..";
    j++;
    loket.push_back(lkt);
}

void filetiket(){
    program.open("read.txt");
    for( int i=0; i<j; i++){
        program<<loket[i].kereta<<endl;
        program<<loket[i].kode<<endl;
        program<<loket[i].stock<<endl;
        program<<loket[i].harga<<endl;     
    }
    program.close();
}

void openread(){
    program.open("read.txt", ios:: app);
    program.close();
    file.open("read.txt");
    while(!file.eof()){
        file>>lkt.kereta;
        file>>lkt.kode;
        file>>lkt.stock;
        file>>lkt.harga;

        j++;
        loket.push_back(lkt);
    }
    j--;
    loket.pop_back();
}

void listtiket(){
    cout<< " Tiket yg tersedia : "<<endl;
    for(int i=0; i<j; i++){
        cout<< " KA    : "<<loket[i].kereta<<endl;
        cout<< " Kode  : "<<loket[i].kode<<endl;
        cout<< " Stock : "<<loket[i].stock<<endl;
        cout<< " Harga : "<<loket[i].harga<<endl;
        cout<<endl;

    }
}

void buy(){
    string beli;
    int jml,total=0,tottiket;

    cout<< " Masukkan Kode KA : ";cin>>beli;
    for(int i=0; i<j;i++){
        if(beli==loket[i].kode){
            cout<< " Tiket KA yang akan dibeli : "<<loket[i].kereta<<endl<<endl;
            cout<< " Masukkan Jumlah Tiket : ";cin>>jml;
            tottiket=loket[i].stock-jml;
            cout<< " Stock yg Tersedia : "<<tottiket<<endl;
            total=loket[i].harga*jml;
            cout<< " Total Pembelian : "<<total<<endl<<endl;
        }else{
            cout<< " ";
        }
    }
}

void cancel(){
    string kodeka;
    cout<< " Masukkan Kode KA yg Akan dicancel : ";cin>>kodeka;
    for(int i=0; i<j; i++){
        if(kodeka==loket[i].kode){
            cout<< " Jadwal Keberangkatan KA : "<<loket[i].kereta<<" Akan di cancel "<<endl;
            loket[i].stock+=1;
            cout<< " THANKS GAN... STOKNYA JADI : "<<loket[i].stock;
        }else{
            cout<< "";
        }
    }
}



void menu(){
    system("cls");
    char back;
 do{
     int pilih;
     judul();
     cout<< " 1. Tambah Tiket KA "<<endl;
     cout<< " 2. List Tiket Yang Tersedia "<<endl;
     cout<< " 3. Pembelian Tiket "<<endl;
     cout<< " 4. Cancel Keberangkatan"<<endl;
     cout<< " 5. Exit..."<<endl;
     cout<<endl;
     cout<<" Masukkan Pilihan : ";cin>>pilih;
     switch (pilih)
     {
     case 1:
        tambahka();
        cout<< " Back To Menu ? [y/n] ";
        cin>>back;
        if(back=='n'|| back=='N'){
            cout<< " Thanks ..";
        }
         break;
     case 2:
        listtiket();
        cout<< " Back To Menu ? [y/n] ";
        cin>>back;
        if(back=='n'|| back=='N'){
            cout<< " Thanks ..";
        }
        break;
     case 3:
        buy();
        cout<< " Back To Menu ? [y/n] ";
        cin>>back;
        if(back=='n'|| back=='N'){
            cout<< " Thanks ..";
        }
        break;
     case 4:
        cancel();
        cout<< " Back To Menu ? [y/n] ";
        cin>>back;
        if(back=='n'|| back=='N'){
            cout<< " Thanks ..";
        }
        break;
     case 5:
        cout<< " Thanks for coming.. ";
        exit(0);
        break;
     }
 }while( back=='y'|| back=='Y');
}

int main(){
    openread();
    menu();
    filetiket();
}