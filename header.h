/* Saya Zaki Adam dengan NIM 2304934 mahasiswa Program Studi Ilmu Komputer C2
mengerjakan evaluasi Tugas Masa Depan mata kuliah Algoritma dan Pemrograman 2 untuk keberkahannya
maka saya tidak melakukan kecurangan seperti yang telah ditentukan. Aamiin. */

// library yang digunakan
#include<stdio.h>   // input output
#include<string.h>  // penggunaan string
#include<stdlib.h>  // membersihkan command
#include<time.h>    // pembuatan intro

// pendefinisian nama file dari setiap tabel
#define filebank "t_bank.txt"
#define filesite "t_lokasi.txt"
#define fileexec "t_pelaksanaan.txt"

// pendefinisian nama tabel
#define tbank "t_bank"
#define tsite "t_site"
#define texec "t_exec"

// struktur untuk tabel bank dan site
typedef struct
{
    char id[51];    // primary key tabel
    char col1[51];  // konten untuk kolom 1
    char col2[51];  // konten untuk kolom 2
}table1;

// struktur untuk tabel jadwal
typedef struct
{
    char id[51];    // primary key tabel
    char col1[51];  // foreign key tabel site
    char col2[51];  // foreign key tabel bank
    char col3[51];  // tanggal pelaksanaan
}tableForeign;

// struktur untuk tabel join jadwal
typedef struct
{
    char id[51];

    // table site pertama
    char site_dest[51];
    char site_domain[51];

    // table bank kedua
    char bank_name[51];
    char bank_contact[51];

    // kolom untuk tanggal pelaksanaan
    char date[51];
}tableJoin;

// variable global
extern int idx;            // index untuk pita query
extern int length;         // panjang kata dari kata yang diakses
extern char ckata[51];     // kata yang sedang diakses
extern tableJoin join[51]; // array untuk tabel join jadwal

int EOPKATA(char pita[]);       // Lampu/Indikator bahwa pita sudah diakhir/menemui penanda akhir pita
void STARTKATA(char pita[]);    // Tombol memulai pita dan menerima kata pertama
void RESETKATA();               // Tombol mengkosong kata yang sedang diakses
void INCWORD(char pita[]);      // Tombol lanjut mengakses kata selanjutnya
char* GETWORD();                // Tombol memanggil kata yang diakses
int GETLENGTH();                // Tombol memanggil panjang kata yang diakses

// variable global
int sizeBank, sizeSite, sizeExec;
/*
sizeBank untuk ukuran tabel Bank
sizeSite untuk ukuran tabel Site
sizeExec untuk ukuran tabel Jadwal
*/

void STARTSIZE();   // mengeset semua ukuran tabel menjadi 0

void readBank(table1 record[], char fileName[101]);
void writeBank(table1 record[], char fileName[101]);
void readSite(table1 record[], char fileName[101]);
void writeSite(table1 record[], char fileName[101]);
void readExec(tableForeign record[], char fileName[101]);
void writeExec(tableForeign record[], char fileName[101]);

void wait(float x);
void intro();
void HELP();
void INFO();

int checkID(table1 record[], char ID[], char table[]);
int checkForeign(table1 record, tableForeign foreign[], char table[]);

// melakukan modifikasi untuk tabel BANK
int INSERTbank(char str[], table1 record[]);    // menambahkan data untuk tabel bank
int UPDATEbank(char str[], table1 record[]);    // memperbarui data untuk tabel bank
int DELETEbank(char str[], table1 record[], tableForeign foreign[]);    // menghapus data untuk tabel bank

// melakukan modifikasi untuk tabel SITE
int INSERTsite(char str[], table1 record[]);    // menambahkan data untuk tabel site
int UPDATEsite(char str[], table1 record[]);    // memperbarui data untuk tabel bank
int DELETEsite(char str[], table1 record[], tableForeign foreign[]);    // menghapus data untuk tabel site

// melakukan modifikasi untuk tabel JADWAL
int INSERTforeign(char str[], tableForeign record[], table1 foreign1[], table1 foreign2[]); // menambahkan data untuk tabel jadwal
int UPDATEforeign(char str[], tableForeign record[], table1 foreign1[], table1 foreign2[]); // memperbarui data untuk tabel jadwal
int DELETEforeign(char str[], tableForeign record[]);   // menghapus data untuk tabel jadwal

// prosedur untuk membuat spasi
void space(int length);

// prosedur dan fungsi menampilkan record per tabel
void rowTable1(int length,int line1, int line2);    // membuat tabel header untuk tabel bank/site
void spaceTable1(table1 record[], int size, int* maxId, int* maxCol1, int* maxCol2);    // menghitung spasi terbesar setiap kolom untuk merapikan tabel
int SELECTtable(table1 record[], char table[]);    // pembuatan tabel keseluruhan untuk tabel bank/site

void rowForeign(int length, int line1, int line2, int line3);   // membuat tabel header untuk tabel jadwal
void spaceForeign(tableForeign record[],int* maxId, int* maxCol1, int* maxCol2, int* maxCol3);  // menghitung spasi terbesar setiap kolom untuk merapikan tabel
int SELECTforeign(tableForeign record[]);  //pembuatan tabel keseluruhan untuk tabel jadwal

// prosedur dan fungsi menampilkan join dengan salah satu tabel
void rowForeignOne(int length, int line1, int line2, int line3, int line4); // membuat tabel header untuk tabel jadwal dengan join satu tabel

void spaceForeignBank(int* maxId, int* maxCol1, int* maxCol2, int* maxCol3, int* maxCol4);  // menghitung spasi terbesar setiap kolom ketika tabel yang dijoin adalah tabel bank
int SELECTForeignBank(tableForeign record1[], table1 record2[]);   // pembuatan tabel keseluruhan untuk tabel jadwal join bank

void spaceForeignSite(int* maxId, int* maxCol1, int* maxCol2, int* maxCol3, int* maxCol4);  // menghitung spasi terbesar setiap kolom ketika tabel yang dijoin adalah tabel site
int SELECTForeignSite(tableForeign record1[], table1 record2[]);   // pembuatan tabel keseluruhan untuk tabel jadwal join site

// prosedur dan fungsi menampilkan join dengan kedua tabel
void rowForeignAll(int length, int line1, int line2, int line3, int line4, int line5);  // membuat tabel header untuk tabel jadwal dengan join kedua tabel
void spaceForeignAll(int* maxId, int* maxCol1, int* maxCol2, int* maxCol3, int* maxCol4, int* maxCol5); // menghitung spasi terbesar setiap kolom ketika tabel yang dijoin adalah semua tabel
int SELECTForeignAll(tableForeign record1[], table1 record2[], table1 record3[]);  // pembuatan tabel keseluruhan untuk tabel jadwal join bank & site
