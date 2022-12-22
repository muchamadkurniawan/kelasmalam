#include <iostream>
#include "helper.h"
using namespace std;

//global array variable
int npm [100];
string nama [100];
string prodi [100];
float ipk [100];

int counter = -1; //counter variable

void insert_statis(int tnpm, string tnama, string tprodi, float tipk){
    counter = counter + 1;
    nama[counter] = tnama;
    prodi[counter] = tprodi;
    ipk[counter] = tipk;
    npm[counter]=tnpm;
}

void insert(){
    int tnpm;
    string tnama, tprodi;
    float tipk;
    print("masukkan npm mahasiswa : ");
    cin>>tnpm;
    print("masukkan nama mahasiswa : ");
    cin>>tnama;
    print("masukkan prodi mahasiswa : ");
    cin>>tprodi;
    print("masukkan IPK mahasiswa : ");
    cin>>tipk;

    //update counter
    counter = counter + 1;

    //insert to array
    nama[counter] = tnama;
    prodi[counter] = tprodi;
    ipk[counter] = tipk;
    npm[counter]=tnpm;
}

void cetak(){
    for (int i = 0; i <= counter ; i++){
        cout<<"npm mahasiswa : "<<npm[i]<<endl;
        cout<<"nama mahasiswa : "<<nama[i]<<endl;
        cout<<"prodi mahasiswa : "<<prodi[i]<<endl;
        cout<<"ipk mahasiswa : "<<ipk[i]<<endl;
    }
}

void view_header (){
    println("==================");
    println("PROGRAM MAHASISWA");
    println("==================");
}

void view_menu(){
    println("MENU : ");
    println("1. cetak data ");
    println("2. insert data ");
    println("3. update IPK");
    println("4. Cetak Rata-rata IPK");
    println("5. EXIT");
}

void insert_statis(){
    //insert statis data mahasiswa
    insert_statis(7777,"kurniawan","informatika",3.13);
    insert_statis(7776,"kurni","informatika",3.12);
    insert_statis(7778,"kur","informatika",3.11);
}

int search_by_npm(int tm_npm){
   for (int i = 0 ; i<= counter ; i++){
       if (tm_npm == npm[i]){
           return i;
       }
   }
   return -1;
}

void update_ipk(){
    int tm_npm;
    float tm_ipk;
    cout<<"masukkan npm mahasiswa : ";
    cin>>tm_npm;
    cout<<"masukkan ipk baru : ";
    cin>>tm_ipk;
    int index = search_by_npm(tm_npm);
    if (index == -1){
        println("npm yang dimasukkan tidak ada");
    }else {
        ipk[index] = tm_ipk;
    }
}


int main() {

    insert_statis();
    cout<<search_by_npm(777);
    view_header();

    //menu
    int pilih;
    while(pilih != 5){
        view_menu();
        print("masukkan pilihan anda : ");
        cin>>pilih;
        switch (pilih) {
            case 1:
                println("anda masuk menu 1");
                cetak();
                break;
            case 2:
                println("anda masuk menu insert");
                insert();
                break;
            case 3:
                println("anda masuk menu update ipk");
                update_ipk();
                break;
            case 4:
                println("anda masuk menu 4");
                break;
            case 5:
                println("EXIT - Terimakasih");
                break;
        }
    }
    return 0;
}