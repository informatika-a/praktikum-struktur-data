#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct data{
    char nama[20];
    char alamat[20];
    char status[20];
};

struct perusahaan{
    data data_pegawai;
    int gaji = 0;
    int bonus;
    int jumlah_hari;
    int tunjangan;
    int total;
    int banyak_karyawan;
};

perusahaan kantor[50];
int indeks = 0;

void dataPegawai(){
    cout<<"Masukanh Banyak karyawan yang belum digaji = ";cin>>kantor[49].banyak_karyawan;
    for(int kounter = 0 ; kounter < kantor[49].banyak_karyawan; kounter++){
            cin.ignore();
        cout<<"Masukan Nama Pegawai ke "<<kounter+1<<" = ";cin.getline(kantor[indeks].data_pegawai.nama, 20);
        cout<<"Masukan Alamat Pegawai ke "<<kounter+1<<" = ";cin.getline(kantor[indeks].data_pegawai.alamat, 20);
        cout<<"Masukan Status Pegawai ke "<<kounter+1<<" = ";cin.getline(kantor[indeks].data_pegawai.status, 20);
        cout<<"Masukan Gaji yang belum dibayar = ";cin>>kantor[indeks].gaji;

        if((strcmp(kantor[indeks].data_pegawai.status, "menikah")==0)){
             kantor[indeks].tunjangan = kantor[indeks].tunjangan + (0.20 * kantor[indeks].gaji) ;
        }

        else if((strcmp(kantor[indeks].data_pegawai.status, "belum")==0)){
            kantor[indeks].tunjangan = kantor[indeks].tunjangan + (0.07 * kantor[indeks].gaji) ;
        }

        cout<<"Anda masuk berapa hari = ";cin>>kantor[indeks].jumlah_hari;
               if(kantor[indeks].jumlah_hari >= 25 && kantor[indeks].jumlah_hari <= 30 ){
                kantor[indeks].bonus = kantor[indeks].bonus + (kantor[indeks].tunjangan * 2);
               }
               else if(kantor[indeks].jumlah_hari >= 16 && kantor[indeks].jumlah_hari <= 24 ){
                kantor[indeks].bonus = kantor[indeks].bonus + (kantor[indeks].tunjangan * 1);
               }
        kantor[indeks].total = kantor[indeks].gaji + kantor[indeks].bonus + kantor[indeks].tunjangan;
    indeks++;
    cout<<endl;
    }
}

void tampilPegawai(){
    for(int kounter = 0 ; kounter < indeks; kounter++){
        cout<<"\nNama Pegawai ke "<<kounter+1<<" = "<<kantor[kounter].data_pegawai.nama;
        cout<<"\nAlamat Pegawai ke "<<kounter+1<<" = "<<kantor[kounter].data_pegawai.alamat;
        cout<<"\nStatus Pegawai ke "<<kounter+1<<"= "<<kantor[kounter].data_pegawai.status;
        cout<<"\nMendapatkan Gaji Pokok "<<kounter+1<<" = "<<kantor[kounter].gaji;
        cout<<"\nMendapatkan Tunjangan = "<<kantor[kounter].tunjangan;

         if(kantor[kounter].jumlah_hari < 30 && kantor[kounter].jumlah_hari > 0 ) {
            cout<<"\nMendapatkan Bonus = "<<kantor[kounter].bonus;
         }
         else{
            cout<<"\nMaaf anda input melebihi/Kurang dari jumlah hari";
         }

         cout<<"\nTotal Gaji = "<<kantor[kounter].total;
        cout<<endl;

    }
}



int main()
{
    int pilih;
    char ulang;

    do{
        cout<<"Menu\n";
        cout<<"1. Input data\n";
        cout<<"2. Tampil data\n";
        cout<<"Pilihan anda = ";cin>>pilih;
        switch(pilih){
        case 1:
            dataPegawai();
        break;
        case 2:
            tampilPegawai();
        break;
        }
    cout<<"\nApakah anda ingin mengulang = (y/n) ";cin>>ulang;
    }while(ulang=='y');
    return 0;
}
