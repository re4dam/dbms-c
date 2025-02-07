/* Saya Zaki Adam dengan NIM 2304934 mahasiswa Program Studi Ilmu Komputer C2
mengerjakan evaluasi Tugas Masa Depan mata kuliah Algoritma dan Pemrograman 2 untuk keberkahannya
maka saya tidak melakukan kecurangan seperti yang telah ditentukan. Aamiin. */
#include"header.h"

void STARTSIZE(){
    sizeBank = 0;
    sizeSite = 0;
    sizeExec = 0;
}

int EOPKATA(char pita[]){   // lampu/indikator untuk menandakan bahwa pita sudah berakhir/habis
    // jika ditemukan penanda pita ditemukan maka berhentikan mesin
    if(pita[idx] == ';'){
        return 1;
    }
    else if(pita[idx] == '\0'){
        return 2;
    }
    // jika tidak maka lanjutkan mesinnya
    else {
        return 0;
    }
}

void STARTKATA(char pita[]){    // tombol memulai mesin kata
    // mendeklarasi nilai index pita dan kata
    idx = 0;    // index untuk pita keseluruhan
    length = 0; // index untuk kata pertama yang diakses

    // melakukan pergeseran jika karakter itu kosong/spasi
    while(pita[idx] == ' '){
        idx++;
    }

    // memulai mengolah kata pertama menjadi kata diakses
    while(pita[idx] != ' ' && EOPKATA(pita) == 0){
        // menyimpan karakter2 ke dalam string
        ckata[length] = pita[idx];
        idx++; length++;
    }

    // mengubah array of karakter menjadi string dengan whitespace
    ckata[length] = '\0';
}

void RESETKATA(){
    // mengkosongkan kata yang sedang diakses
    length = 0;
    ckata[length] = '\0';
}

void INCWORD(char pita[]){  // lanjut mengakses kata selanjutnya
    // mengreset ukuran panjang kata
    length = 0;
    // lanjut bergeser sampai ketemu karakter non-spasi
    while(pita[idx] == ' '){
        idx++;
    }

    // memulai mengolah kata selanjutnya menjadi kata diakses
    while(pita[idx] != ' ' && EOPKATA(pita) == 0){
        ckata[length] = pita[idx];
        idx++; length++;
    }

    // mengubah array of karakter menjadi string dengan whitespace
    ckata[length] = '\0';
}

char* GETWORD(){
    // mengembalikan kata yang sedang diakses
    return ckata;
}

int GETLENGTH(){
    // mengembalikan panjang kata yang sedang diakses
    return length;
}

// PROSEDUR READ DATA Tabel bank makanan
void readBank(table1 record[], char fileName[])
{
    FILE *fTemp;
    fTemp = fopen(fileName, "r"); //  r untuk operator read file
   
    // untuk scan 3 value pada baris pertama dari isi file
    int returnVal = fscanf(fTemp, "%s %s %s",record[sizeBank].id, record[sizeBank].col1, &record[sizeBank].col2); 


    // cek apakah data yang discan di atas dummy atau tidak              
    if (strcmp(record[sizeBank].id, "####") == 0 || returnVal == EOF) printf("File %s Kosong\n",fileName);
    else // jika bukan dummy/eof
    {
        while (strcmp(record[sizeBank].id, "####") != 0) // selama bukan data dummy/eof
        {
            sizeBank = sizeBank + 1; // maju ke indeks penampung berikutnya
            fscanf(fTemp, "%s %s %s", record[sizeBank].id, record[sizeBank].col1, &record[sizeBank].col2); // scan data berikutnya
        }
    }
 
    fclose(fTemp); // tutup file
}

// PROSEDUR MENULIS DATA Tabel bank makanan
void writeBank(table1 record[], char fileName[])
{
    FILE *fTemp;
    fTemp = fopen(fileName, "w"); //  w untuk operator write file
   
    for(int i = 0; i < sizeBank; i++){ // memasukkan setiap index array ke dalam file menurut urutannya
        fprintf(fTemp,"%s %s %s\n",record[i].id,record[i].col1,record[i].col2);
    }
    fprintf(fTemp,"%s %s %s\n","####","####","####"); // data dummy/eof
 
    fclose(fTemp); // tutup file
}

// PROSEDUR READ DATA Tabel tujuan pembagian makanan
void readSite(table1 record[], char fileName[])
{
    FILE *fTemp;
    fTemp = fopen(fileName, "r"); //  r untuk operator read file
   
    // untuk scan 3 value pada baris pertama dari isi file
    int returnVal = fscanf(fTemp, "%s %s %s",record[sizeSite].id, record[sizeSite].col1, &record[sizeSite].col2); 


    // cek apakah data yang discan di atas dummy atau tidak              
    if (strcmp(record[sizeSite].id, "####") == 0 || returnVal == EOF) printf("File %s Kosong\n",fileName);
    else // jika bukan dummy/eof
    {
        while (strcmp(record[sizeSite].id, "####") != 0) // selama bukan data dummy/eof
        {
            sizeSite = sizeSite + 1; // maju ke indeks penampung berikutnya
            fscanf(fTemp, "%s %s %s", record[sizeSite].id, record[sizeSite].col1, &record[sizeSite].col2); // scan data berikutnya
        }
    }
 
    fclose(fTemp); // tutup file
}

// PROSEDUR MENULIS DATA Tabel tujuan pembagian makanan
void writeSite(table1 record[], char fileName[])
{
    FILE *fTemp;
    fTemp = fopen(fileName, "w"); //  w untuk operator write file
   
    for(int i = 0; i < sizeSite; i++){ // memasukkan setiap index array ke dalam file menurut urutannya
        fprintf(fTemp,"%s %s %s\n",record[i].id,record[i].col1,record[i].col2);
    }
    fprintf(fTemp,"%s %s %s\n","####","####","####"); // data dummy/eof
 
    fclose(fTemp); // tutup file
}
  
// PROSEDUR READ DATA Tabel dengan 4 kolom
void readExec(tableForeign record[], char fileName[])
{
    FILE *fTemp;
    fTemp = fopen(fileName, "r"); //  r untuk operator read file
   
    // untuk scan 3 value pada baris pertama dari isi file
    int returnVal = fscanf(fTemp, "%s %s %s %s",record[sizeExec].id, record[sizeExec].col1, &record[sizeExec].col2, &record[sizeExec].col3); 


    // cek apakah data yang discan di atas dummy atau tidak              
    if (strcmp(record[sizeExec].id, "####") == 0 || returnVal == EOF) printf("File %s Kosong\n",fileName);
    else // jika bukan dummy/eof
    {
        while (strcmp(record[sizeExec].id, "####") != 0) // selama bukan data dummy/eof
        {
            sizeExec = sizeExec + 1; // maju ke indeks penampung berikutnya
            fscanf(fTemp, "%s %s %s %s", record[sizeExec].id, record[sizeExec].col1, &record[sizeExec].col2, &record[sizeExec].col3); // scan data berikutnya
        }
    }
 
    fclose(fTemp); // tutup file
}

void writeExec(tableForeign record[], char fileName[])
{
    FILE *fTemp;
    fTemp = fopen(fileName, "w"); //  w untuk operator write file
   
    for(int i = 0; i < sizeExec; i++){ // memasukkan setiap index array ke dalam file menurut urutannya
        fprintf(fTemp,"%s %s %s %s\n",record[i].id,record[i].col1,record[i].col2,record[i].col3);
    }
    fprintf(fTemp,"%s %s %s %s\n","####","####","####","####"); // data dummy/eof
 
    fclose(fTemp); // tutup file
}

void wait(float x){
    time_t start;
    time_t current;
    time(&start);

    do
    {
        time(&current);
    } while (difftime(current,start) < x);
    
}
void intro(){
    // pembuatan intro untuk DBMS
    system("cls");

    printf("   _____ _____ ___________ _____  ____  \n");
    wait(1);
    printf("  / ____|_   _|___  /_   _|  __ \\|  _ \\ \n");
    wait(1);
    printf(" | |  __  | |    / /  | | | |  | | |_) |\n");
    wait(1);
    printf(" | | |_ | | |   / /   | | | |  | |  _ < \n");
    wait(1);
    printf(" | |__| |_| |_ / /__ _| |_| |__| | |_) |\n");
    wait(1);
    printf("  \\_____|_____/_____|_____|_____/|____/ \n");
    wait(1);
    printf("\n");
    wait(1);
    printf("Selamat datang di database pembagian makanan dari Food Bank!\n");
    wait(1);
    printf("Gunakan HELP; untuk bantuan!\n");
}
void HELP(){
    printf("DBMS command :\n");
    for(int i = 0; i < 7; i++){
        printf("- ");
        if(i == 0){printf("INSERT   menambah record baru ke dalam tabel\n");}
        if(i == 1){printf("UPDATE   memperbarui record dalam tabel\n");}
        if(i == 2){printf("DELETE   menghapus record dari tabel\n");}
        if(i == 3){printf("SELECT   menampilkan record dari tabel\n");}
        if(i == 4){printf("HELP     menampilkan bantuan QUERY dalam DBMS\n");}
        if(i == 5){printf("INFO     menampilkan struktur tabel-tabel dalam DBMS\n");}
        if(i == 6){printf("quit     keluar dari DBMS\n");}
    }
    printf("\n");

}
void INFO(){
    printf("Struktur Tabel Gizi DBMS\n");

    printf("Tabel Bank Makanan (t_bank) : 3 kolom\n");
    for(int i = 0; i < 3; i++){
        printf("-");
        if(i == 0){printf("id_bank [char][51]\n");}
        if(i == 1){printf("nama_bank [char][51]\n");}
        if(i == 2){printf("kontak_bank [char][51]\n");}
    }
    printf("\n");
    printf("Tabel Tujuan Pembagian (t_site) : 3 kolom\n");
    for(int i = 0; i < 3; i++){
        printf("-");
        if(i == 0){printf("id_site [char][51]\n");}
        if(i == 1){printf("destinasi_site [char][51]\n");}
        if(i == 2){printf("domisili_site [char][51]\n");}
    }
    printf("\n");
    printf("Tabel Jadwal Pelaksanaan (t_exec) : 4 kolom\n");
    for(int i = 0; i < 4; i++){
        printf("-");
        if(i == 0){printf("id_jadwal [char][51]\n");}
        if(i == 1){printf("id_site [char][51]\n");}
        if(i == 2){printf("id_bank [char][51]\n");}
        if(i == 3){printf("tanggal [char][51]\n");}
    }
    printf("\n");
}

int checkID(table1 record[], char ID[], char table[]){
    int found = -1, i = 0;
    int size;

    if(strcmp(table,tbank) == 0){
        size = sizeBank;
    }
    else if(strcmp(table,tsite) == 0){
        size = sizeSite;
    }

    while(i < size && found == -1){
        if(strcmp(record[i].id,ID) == 0){
            found = i;
        }
        i++;
    }

    return found;
}
int checkForeign(table1 record, tableForeign foreign[], char table[]){
    int check = 0, i = 0;

    while(i < sizeExec && check == 0){
        if(strcmp(record.id,foreign[i].col2) == 0 && strcmp(tbank,table) == 0){
            check = 1;
        }
        else if(strcmp(record.id,foreign[i].col1) == 0 && strcmp(tsite,table) == 0){
            check = 1;
        }
        i++;
    }

    return check;
}

int INSERTbank(char str[], table1 record[]){
    table1 temp;
    int i = 0, found = 0;

    // memeriksa apakah id bank ada atau tidak
    if(EOPKATA(str) == 0){
        INCWORD(str);
        strcpy(temp.id,GETWORD());

        // memeriksa apakah kode bank yang diinput sudah ada atau belum
        found = checkID(record,temp.id,tbank);

        // memeriksa apakah nama bank ada atau tidak
        if(EOPKATA(str) == 0 && found == -1){
            INCWORD(str);
            strcpy(temp.col1,GETWORD());

            // memeriksa apakah kontak bank ada atau tidak
            if(EOPKATA(str) == 0){
                INCWORD(str);
                strcpy(temp.col2,GETWORD());

                // memeriksa apakah query sudah berakhir dengan titik koma atau belum
                if(EOPKATA(str) == 1){
                    // melakukan penambahan pada data bank
                    record[sizeBank] = temp;
                    (sizeBank)++;
                    return 1100;    // mengembalikan hasil berhasil
                }
                else if(EOPKATA(str) == 2){return 1105;}    // jika akhir dari query kosong akan memberikan error
                else if(EOPKATA(str) == 0){return 1106;}    // jika query masih berlanjut akan memberikan error
            }
            else if(EOPKATA(str) == 2){ return 1105; }  // jika akhir dari query kosong akan memberikan error
            else { return 1104; }   // jika kolom kontak_bank kosong akan memberikan error
        }
        else if(EOPKATA(str) == 2){ return 1105; }  // jika akhir dari query kosong akan memberikan error
        else if(found >= 0){ return 1101; } // jika id_bank yang dimasukkan sudah ada sebelumnya akan memberikan error
        else { return 1103; }   // jika kolom nama_bank kosong akan memberikan error
    }
    else if(EOPKATA(str) == 2){return 1105;}    // jika akhir dari query kosong akan memberikan error
    else {return 1102;} // jika kolom id_bank kosong akan memberikan error
}
int UPDATEbank(char str[], table1 record[]){
    table1 temp;
    int i = 0, found = -1;

    // memeriksa input untuk id_bank yang akan diupdate
    if(EOPKATA(str) == 0){
        INCWORD(str);
        strcpy(temp.id, GETWORD());

        // melakukan sequential search untuk mencari id_bank yang diminta
        found = checkID(record,temp.id,tbank);

        // memeriksa input untuk nama_bank yang akan diupdate
        if(EOPKATA(str) == 0 && found >= 0){
            INCWORD(str);
            strcpy(temp.col1, GETWORD());

            // memeriksa input untuk kontak_bank yang akan diupdate
            if(EOPKATA(str) == 0){
                INCWORD(str);
                strcpy(temp.col2, GETWORD());

                // memeriksa apakah query diakhiri dengan benar atau tidak
                if(EOPKATA(str) == 1){
                    //  memperbarui data yang dicari
                    record[found] = temp;
                    return 2100;
                }
                else if(EOPKATA(str) == 2){return 2105;}    // jika akhir dari query kosong akan memberikan error
                else if(EOPKATA(str) == 0){return 2106;}    // jika query masih berlanjut akan memberikan error
            }
            else if(EOPKATA(str) == 2){return 2105;}    // jika akhir dari query kosong akan memberikan error
            else {return 2104;} // jika kolom kontak_bank kosong akan memberikan error
        }
        else if(EOPKATA(str) == 2){return 2105;}    // jika akhir dari query kosong akan memberikan error
        else if(found == -1){return 2101;}  // jika id_bank yang dimasukkan tidak ada akan memberikan error
        else {return 2103;} // jika kolom nama_bank kosong akan memberikan
    }
    else if(EOPKATA(str) == 2){return 2105;}    // jika akhir dari query kosong akan memberikan error
    else {return 2102;} // jika kolom id_bank kosong akan memberikan error
}
int DELETEbank(char str[], table1 record[], tableForeign foreign[]){
    table1 temp;
    int i = 0, found = -1;
    int check = 0;

    if(EOPKATA(str) == 0){
        // memilih id_bank yang akan dihapus
        INCWORD(str);
        strcpy(temp.id,GETWORD());

        // mencari secara sequential dalam arraynya
        found = checkID(record,temp.id,tbank);

        // mencari apakah foreign key di tabel lain
        check = checkForeign(record[found],foreign,tbank);

        // jika index dari id_bank dicari ditemukan maka lakukan penghapusan
        if(found >= 0 && check == 0 && EOPKATA(str) == 1){
            // menggeser seluruh array ke kiri jika index berada di awal
            if(found == 0){
                for(i = 0; i < sizeBank; i++){
                    record[i] = record[i+1];
                }

                (sizeBank)--;
            } 
            // menyusutkan ukuran dari array jika index berada di akhir
            else if(found == sizeBank-1){
                (sizeBank)--;
            } 
            // menggeser sebagian array ke kiri dari index id_bank Nya
            else{
                for(i = found; i < sizeBank; i++){
                    record[i] = record[i+1];
                }

                (sizeBank)--;
            } 
            return 3100;
        }
        else if(EOPKATA(str) == 2){return 3104;}    // jika akhir dari query kosong akan memberikan error
        else if(EOPKATA(str) == 0){return 3105;}    // jika query masih berlanjut akan memberikan error
        else if(check == 1){return 3102;} // jika id_bank yang dimasukkan merupakan foreign key di tabel lain akan memberikan error
        else if(found == -1){return 3101;}   // jika id_bank yang dimasukkan tidak ada akan memberikan error
    }
    else if(EOPKATA(str) == 2){return 3104;}    // jika akhir dari query kosong akan memberikan error
    else {return 3103;} // jika id_bank yang dimasukkan kosong akan memberikan error
}

int INSERTsite(char str[], table1 record[]){
    table1 temp;
    int i = 0, found = 0;

    // memeriksa apakah id site ada atau tidak
    if(EOPKATA(str) == 0){
        INCWORD(str);
        strcpy(temp.id,GETWORD());

        // memeriksa apakah kode site yang diinput sudah ada atau belum
        found = checkID(record,temp.id,tsite);

        // memeriksa apakah destinasi site ada atau tidak
        if(EOPKATA(str) == 0 && found == -1){
            INCWORD(str);
            strcpy(temp.col1,GETWORD());

            // memeriksa apakah domisili site ada atau tidak
            if(EOPKATA(str) == 0){
                INCWORD(str);
                strcpy(temp.col2,GETWORD());

                // memeriksa apakah query sudah berakhir dengan titik koma atau belum
                if(EOPKATA(str) == 1){
                    // melakukan penambahan pada data site
                    record[sizeSite] = temp;
                    (sizeSite)++;
                    return 1200;    // mengembalikan hasil berhasil
                }
                else if(EOPKATA(str) == 2){return 1205;}    // jika akhir dari query kosong akan memberikan error
                else if(EOPKATA(str) == 0){return 1206;}    // jika query masih berlanjut akan memberikan error
            }
            else if(EOPKATA(str) == 2){return 1205;}    // jika akhir dari query kosong akan memberikan error
            else {return 1204;} // jika kolom domisili site kosong akan memberikan error
        }
        else if(EOPKATA(str) == 2){return 1205;}    // jika akhir dari query kosong akan memberikan error
        else if(found >= 0){return 1201;}   // jika id_site yang dimasukkan sudah ada sebelumnya akan memberikan error
        else {return 1203;} // jika kolom destinasi site kosong akan memberikan error
    }
    else if(EOPKATA(str) == 2){return 1205;}    // jika akhir dari query kosong akan memberikan error
    else {return 1202;} // jika kolom id_site kosong akan memberikan error
}
int UPDATEsite(char str[], table1 record[]){
    table1 temp;
    int i = 0, found = -1;

    // memeriksa input untuk id_site yang akan diupdate
    if(EOPKATA(str) == 0){
        INCWORD(str);
        strcpy(temp.id, GETWORD());

        // melakukan sequential search untuk mencari id_site yang diminta
        found = checkID(record,temp.id,tsite);

        // memeriksa input untuk destinati site yang akan diupdate
        if(EOPKATA(str) == 0 && found >= 0){
            INCWORD(str);
            strcpy(temp.col1, GETWORD());

            // memeriksa input untuk domisilisi site yang akan diupdate
            if(EOPKATA(str) == 0){
                INCWORD(str);
                strcpy(temp.col2, GETWORD());

                // memeriksa apakah query diakhiri dengan benar atau tidak
                if(EOPKATA(str) == 1){
                    // memperbarui data yang dicari
                    record[found] = temp;
                    return 2200;    // mengembalikan hasil berhasil
                }
                else if(EOPKATA(str) == 2){return 2205;}    // jika akhir dari query kosong akan memberikan error
                else if(EOPKATA(str) == 0){return 2206;}    // jika query masih berlanjut akan memberikan error
            }
            else if(EOPKATA(str) == 2){return 2205;}    // jika akhir dari query kosong akan memberikan error
            else {return 2204;} // jika kolom domisili site kosong akan memberikan error
        }
        else if(EOPKATA(str) == 2){return 2205;}    // jika akhir dari query kosong akan memberikan error
        else if(found == -1){return 2201;}  // jika id_site yang dimasukkan tidak ada akan memberikan error
        else {return 2203;} // jika kolom destinasi site kosong akan memberikan error
    }
    else if(EOPKATA(str) == 2){return 2205;}    // jika akhir dari query kosong akan memberikan error
    else {return 2202;} // jika kolom id_site kosong akan memberikan error
}
int DELETEsite(char str[], table1 record[], tableForeign foreign[]){
    table1 temp;
    int i = 0, found = -1;
    int check = 0;

    if(EOPKATA(str) == 0){
        // memilih NIM yang akan dihapus
        INCWORD(str);
        strcpy(temp.id,GETWORD());

        // mencari secara sequential dalam arraynya
        found = checkID(record,temp.id,tsite);

        // mencari apakah foreign key di tabel lain
        check = checkForeign(record[found],foreign,tsite);

        // jika index dari NIM dicari ditemukan maka lakukan penghapusan
        if(found >= 0 && check == 0 && EOPKATA(str) == 1){
            // menggeser seluruh array ke kiri jika index berada di awal
            if(found == 0){
                for(i = 0; i < sizeSite; i++){
                    record[i] = record[i+1];
                }

                (sizeSite)--;
            } 
            // menyusutkan ukuran dari array jika index berada di akhir
            else if(found == sizeSite-1){
                (sizeSite)--;
            } 
            // menggeser sebagian array ke kiri dari index id_site Nya
            else{
                for(i = found; i < sizeSite; i++){
                    record[i] = record[i+1];
                }

                (sizeSite)--;
            } 
            return 3200;
        }
        else if(EOPKATA(str) == 2){return 3204;}    // jika akhir dari query kosong akan memberikan error
        else if(EOPKATA(str) == 0){return 3205;}    // jika query masih berlanjut akan memberikan error
        else if(check == 1){return 3202;}   // jika tidak ditemukan maka berikan peringatan
        else {return 3201;}   // jika id_site yang dimasukkan tidak ada akan memberikan error
    }
    else if(EOPKATA(str) == 2){return 3204;}    // jika akhir dari query kosong akan memberikan error
    else {return 3203;} // jika id_site yang dimasukkan kosong akan memberikan error
}

int INSERTforeign(char str[], tableForeign record[], table1 foreign1[], table1 foreign2[]){
    tableForeign temp;
    int i = 0, found = 0;
    int check1 = 0, check2 = 0;

    // periksa apakah id_jadwal yang diinput ada atau tidak
    if(EOPKATA(str) == 0){
        INCWORD(str);
        strcpy(temp.id,GETWORD());

        // memeriksa apakah ada id_jadwal yang diinput sudah ada atau belum
        while(i < sizeExec && found == 0){
            if(strcmp(record[i].id,temp.id) == 0){
                found = 1;
            }
            i++;
        }

        // periksa apakah foreign key dari id_site ada atau tidak
        if(EOPKATA(str) == 0 && found != 1){
            INCWORD(str);
            strcpy(temp.col1,GETWORD());

            // periksa foreign key dari table SITE
            i = 0;
            while(i < sizeSite && check1 == 0){
                if(strcmp(temp.col1,foreign1[i].id) == 0){ check1 = 1; }
                else{ i++; }
            }

            // periksa apakah foreign key dari id_bank ada atau tidak
            if(EOPKATA(str) == 0 && check1 == 1){
                INCWORD(str);
                strcpy(temp.col2,GETWORD());
                
                // periksa foreign key dari table BANK
                i = 0;
                while(i < sizeBank && check2 == 0){
                    if(strcmp(temp.col2,foreign2[i].id) == 0){ check2 = 1; }
                    else{ i++; }
                }

                // periksa apakah tanggal pelaksanaan ada atau tidak
                if(EOPKATA(str) == 0 && check2 == 1){
                    INCWORD(str);
                    strcpy(temp.col3,GETWORD());

                    // periksa apakah ada tanda ';' di akhir query
                    if(EOPKATA(str) == 1){
                        // melakukan penambahan pada data jadwal
                        record[sizeExec] = temp;
                        (sizeExec)++;
                        return 1300;    // mengembalikan hasil berhasil
                    }
                    else if(EOPKATA(str) == 2){return 1308;}    // jika akhir dari query kosong akan memberikan error
                    else if(EOPKATA(str) == 0){return 1309;}    // jika query masih berlanjut akan memberikan error
                }
                else if(EOPKATA(str) == 2){return 1308;}    // jika akhir dari query kosong akan memberikan error
                else if(check2 == 0){return 1303;}  // jika id_bank yang dimasukkan tidak ada akan memberikan error
                else {return 1307;} // jika kolom tanggal kosong akan memberikan error
            }
            else if(EOPKATA(str) == 2){return 1308;}    // jika akhir dari query kosong akan memberikan error
            else if(check1 == 0){return 1302;}  // jika id_site yang dimasukkan tidak ada akan memberikan error
            else {return 1306;} // jika kolom id_bank kosong akan memberikan error
        }
        else if(EOPKATA(str) == 2){return 1308;}    // jika akhir dari query kosong akan memberikan error
        else if(found == 1){return 1301;}   // jika id_jadwal yang dimasukkan sudah ada sebelumnya akan memberikan error
        else {return 1305;} // jika kolom id_site kosong akan memberikan error
    }
    else if(EOPKATA(str) == 2){return 1308;}    // jika akhir dari query kosong akan memberikan error
    else {return 1304;} // jika kolom id_jadwal kosong akan memberikan error
}
int UPDATEforeign(char str[], tableForeign record[], table1 foreign1[], table1 foreign2[]){
    tableForeign temp;
    int i = 0, found = -1;
    int check1 = 0, check2 = 0;

    // periksa apakah id yang diinput ada atau tidak
    if(EOPKATA(str) == 0){
        INCWORD(str);
        strcpy(temp.id,GETWORD());

        // memeriksa apakah ada kode jadwal yang diinput sudah ada atau belum
        while(i < sizeExec && found == 0){
            if(strcmp(record[i].id,temp.id) == 0){
                found = i;
            }
            i++;
        }

        // periksa apakah foreign key dari id_site ada atau tidak
        if(EOPKATA(str) == 0){
            INCWORD(str);
            strcpy(temp.col1,GETWORD());

            // check foreign key from table SITE
            i = 0;
            while(i < sizeBank && check1 == 0){
                if(strcmp(temp.col2,foreign2[i].id) == 0){ check1 = 1; }
                else{ i++; }
            }

            // periksa apakah foreign key dari id_bank ada atau tidak
            if(EOPKATA(str) == 0 && check1 == 1){
                INCWORD(str);
                strcpy(temp.col2,GETWORD());
                
                // check foreign key from table BANK
                i = 0;
                while(i < sizeSite && check2 == 0){
                    if(strcmp(temp.col1,foreign1[i].id) == 0){ check2 = 1; }
                    else{ i++; }
                }

                // periksa apakah tanggal pelaksanaan ada atau tidak
                if(EOPKATA(str) == 0 && check2 == 1){
                    INCWORD(str);
                    strcpy(temp.col3,GETWORD());

                    // periksa apakah ada tanda ';' di akhir query
                    if(EOPKATA(str) == 1){
                        record[found] = temp;
                        return 2300;    // mengembalikan hasil berhasil
                    }
                    else if(EOPKATA(str) == 2){return 2308;}    // jika akhir dari query kosong akan memberikan error
                    else if(EOPKATA(str) == 0){return 2309;}    // jika query masih berlanjut akan memberikan error
                }
                else if(EOPKATA(str) == 2){return 2308;}    // jika akhir dari query kosong akan memberikan error
                else if(check2 == 0){return 2303;}  // jika id_bank yang dimasukkan tidak ada akan memberikan error
                else {return 2307;} // jika kolom tanggal kosong akan memberikan error
            }
            else if(EOPKATA(str) == 2){return 2308;}    // jika akhir dari query kosong akan memberikan error
            else if(check1 == 0){return 2302;}  // jika id_site yang dimasukkan tidak ada akan memberikan error
            else {return 2306;} // jika kolom id_bank kosong akan memberikan error
        }
        else if(EOPKATA(str) == 2){return 2308;}    // jika akhir dari query kosong akan memberikan error
        else if(found == 0){return 2301;}   // jika id_jadwal yang dimasukkan sudah ada sebelumnya akan memberikan error
        else {return 2305;} // jika kolom id_site kosong akan memberikan error
    }
    else if(EOPKATA(str) == 2){return 2308;}    // jika akhir dari query kosong akan memberikan error
    else {return 2304;} // jika kolom id_jadwal kosong akan memberikan error
    
}
int DELETEforeign(char str[], tableForeign record[]){
    tableForeign temp;
    int i = 0, found = -1;

    if(EOPKATA(str) == 0){
        // memilih NIM yang akan dihapus
        INCWORD(str);
        strcpy(temp.id,GETWORD());

        // mencari secara sequential dalam arraynya
        while(i < sizeExec && found == -1){
            if(strcmp(temp.id,record[i].id) == 0){
                found = i;
            } else {
                i++;
            }
        }

        // jika index dari NIM dicari ditemukan maka lakukan penghapusan
        if(found >= 0 && EOPKATA(str) == 1){
            // menggeser seluruh array ke kiri jika index berada di awal
            if(found == 0){
                for(i = 0; i < sizeExec; i++){
                    record[i] = record[i+1];
                }

                (sizeExec)--;
            } 
            // menyusutkan ukuran dari array jika index berada di akhir
            else if(found == sizeExec-1){
                (sizeExec)--;
            } 
            // menggeser sebagian array ke kiri dari index NIMnya
            else{
                for(i = found; i < sizeExec; i++){
                    record[i] = record[i+1];
                }

                (sizeExec)--;
            }
            return 3300;    // mengembalikan hasil berhasil
        }
        else if(EOPKATA(str) == 2){ return 3303; }  // jika akhir dari query kosong akan memberikan error
        else if(EOPKATA(str) == 0){ return 3304; }  // jika query masih berlanjut akan memberikan error
        else { return 3301; }   // jika id_jadwal yang dimasukkan tidak ada akan memberikan error
    }
    else if(EOPKATA(str) == 2){ return 3303; }  // jika akhir dari query kosong akan memberikan error
    else { return 3302; }   // jika kolom id_jadwal kosong akan memberikan error
}

void space(int length){
    // prosedur membuat spasi
    for(int i = 0; i < length; i++){
        printf(" ");
    }
}

void rowTable1(int length, int line1, int line2){
    // prosedur membuat header dari tabel
    for(int i = 0; i < length; i++){
        if(i == 0 || i == line1 || i == line2 || i == length-1){
            printf("+");
        }
        else {
            printf("-");
        }
    }
    printf("\n");
}
void spaceTable1(table1 record[], int size, int* maxId, int* maxCol1, int* maxCol2){
    // prosedur menghitung panjang terbesar dari setiap kolom
    for(int i = 0; i < size; i++){
        if(*maxId < strlen(record[i].id)){
            *maxId = strlen(record[i].id);
        }
        if(*maxCol1 < strlen(record[i].col1)){
            *maxCol1 = strlen(record[i].col1);
        }
        if(*maxCol2 < strlen(record[i].col2)){
            *maxCol2 = strlen(record[i].col2);
        }
    }
}
int SELECTtable(table1 record[], char table[]){
    // deklarasi panjang setiap kolom tabel bank/site
    int maxId = 0, maxCol1 = 0, maxCol2 = 0;
    int size = 0; // deklarasi ukuran tabel yang diakses
    // deklarasi nama setiap kolom dari tabel
    char id[51], col1[51], col2[51];

    if(strcmp(table,tbank) == 0){
        // jika tabel yang diakses tabel bank
        size = sizeBank;
        strcpy(id,"id_bank");
        strcpy(col1,"nama_bank");
        strcpy(col2,"kontak_bank");
    }
    else if(strcmp(table,tsite) == 0){
        // jika tabel yang diakses tabel site
        size = sizeSite;
        strcpy(id,"id_site");
        strcpy(col1,"destinasi_site");
        strcpy(col2,"domisili_site");
    }

    // mencari panjang terbesar dari setiap kolom tabel
    spaceTable1(record,size,&maxId,&maxCol1,&maxCol2);

    // membandingkan panjang terbesar record dari setiap kolom dengan header kolom
    if(maxId < strlen(id)){ maxId = strlen(id); }
    if(maxCol1 < strlen(col1)){ maxCol1 = strlen(col1); }
    if(maxCol2 < strlen(col2)){ maxCol2 = strlen(col2); }

    // membuat panjang tabel keseluruhan
    int baris = (2 + maxId + 2) + (1 + maxCol1 + 1) + (2 + maxCol2 + 2);

    // pembuatan header tabel
    rowTable1(baris,(3+maxId),(4+maxId+2+maxCol1));
    printf("| "); space(maxId - strlen(id)); printf("%s",id); printf(" |");         // membuat kolom id
    printf(" "); space(maxCol1 - strlen(col1)); printf("%s",col1); printf(" ");     // membuat kolom pertama
    printf("| "); space(maxCol2 - strlen(col2)); printf("%s",col2); printf(" |\n"); // membuat kolom kedua
    rowTable1(baris,(3+maxId),(4+maxId+2+maxCol1));
    
    // menampilkan isi dari seluruh tabel
    for(int i = 0; i < size; i++){
        printf("| "); space(maxId - strlen(record[i].id)); printf("%s",record[i].id); printf(" |");         // menampilkan record id
        printf(" "); space(maxCol1 - strlen(record[i].col1)); printf("%s",record[i].col1); printf(" ");     // menampilkan record kolom 1
        printf("| "); space(maxCol2 - strlen(record[i].col2)); printf("%s",record[i].col2); printf(" |\n"); // menampilkan record kolom 2
    }
    rowTable1(baris,(3+maxId),(4+maxId+2+maxCol1)); // menutup tabel

    return size;
}

void rowForeign(int length, int line1, int line2, int line3){
    // membuat pembatas antar kolom tabel
    for(int i = 0; i < length; i++){
        if(i == 0 || i == line1 || i == line2 || i == line3 || i == length-1){
            printf("+");
        }
        else {
            printf("-");
        }
    }
    printf("\n");
}
void spaceForeign(tableForeign record[],int* maxId, int* maxCol1, int* maxCol2, int* maxCol3){
    // mencari panjang terbesar tiap kolom dari tabel jadwal
    for(int i = 0; i < sizeExec; i++){
        if(*maxId < strlen(record[i].id)){
            *maxId = strlen(record[i].id);
        }
        if(*maxCol1 < strlen(record[i].col1)){
            *maxCol1 = strlen(record[i].col1);
        }
        if(*maxCol2 < strlen(record[i].col2)){
            *maxCol2 = strlen(record[i].col2);
        }
        if(*maxCol3 < strlen(record[i].col3)){
            *maxCol3 = strlen(record[i].col3);
        }
    }
}
int SELECTforeign(tableForeign record[]){
    // deklarasi panjang terbesar setiap kolom
    int maxId = 0, maxCol1 = 0, maxCol2 = 0, maxCol3 = 0;
    // deklarasi tiap kolom dari tabel
    char id[51], col1[51], col2[51], col3[51];

    // mencari panjang terbesar setiap kolom dari record
    spaceForeign(record,&maxId,&maxCol1,&maxCol2,&maxCol3);

    // menamakan setiap header kolom dari tabel
    strcpy(id,"id_jadwal");
    strcpy(col1,"id_site");
    strcpy(col2,"id_bank");
    strcpy(col3,"tanggal");

    // membandingkan panjang terbesar setiap kolom dengan header kolomnya
    if(maxId < strlen(id)){ maxId = strlen(id); }
    if(maxCol1 < strlen(col1)){ maxCol1 = strlen(col1); }
    if(maxCol2 < strlen(col2)){ maxCol2 = strlen(col2); }
    if(maxCol3 < strlen(col3)){ maxCol3 = strlen(col3); }

    // membuat panjang tabel keseluruhan
    int baris = (2 + maxId + 2) + (1 + maxCol1 + 1) + (2 + maxCol2 + 2) + (1 + maxCol3 + 2);

    // membuat header dari tabel
    rowForeign(baris,(3+maxId),(4+maxId+2+maxCol1),(4+maxId+2+maxCol1+3+maxCol2));
    printf("| "); space(maxId - strlen(id)); printf("%s",id); printf(" |");         // header untuk kolom id
    printf(" "); space(maxCol1 - strlen(col1)); printf("%s",col1); printf(" ");     // header untuk kolom id_site
    printf("| "); space(maxCol2 - strlen(col2)); printf("%s",col2); printf(" ");    // header untuk kolom id_bank
    printf("| "); space(maxCol3 - strlen(col3)); printf("%s",col3); printf(" |\n"); // header untuk kolom tanggal
    rowForeign(baris,(3+maxId),(4+maxId+2+maxCol1),(4+maxId+2+maxCol1+3+maxCol2));
    
    // menampilkan setiap record dari tabel
    for(int i = 0; i < sizeExec; i++){
        printf("| "); space(maxId - strlen(record[i].id)); printf("%s",record[i].id); printf(" ");          // record untuk id
        printf("| "); space(maxCol1 - strlen(record[i].col1)); printf("%s",record[i].col1); printf(" ");    // record untuk id_site
        printf("| "); space(maxCol2 - strlen(record[i].col2)); printf("%s",record[i].col2); printf(" ");    // record untuk id_bank
        printf("| "); space(maxCol3 - strlen(record[i].col3)); printf("%s",record[i].col3); printf(" |\n"); // record untuk tanggal
    }
    rowForeign(baris,(3+maxId),(4+maxId+2+maxCol1),(4+maxId+2+maxCol1+3+maxCol2));  // menutup tabel

    return sizeExec;
}

void rowForeignOne(int length, int line1, int line2, int line3, int line4){
    // membuat pembatas antar kolom untuk tabel yang dijoin dengan salah satu tabel
    for(int i = 0; i < length; i++){
        if(i == 0 || i == line1 || i == line2 || i == line3 || i == line4 || i == length-1){
            printf("+");
        }
        else {
            printf("-");
        }
    }
    printf("\n");
}

void spaceForeignBank(int* maxId, int* maxCol1, int* maxCol2, int* maxCol3, int* maxCol4){
    // mencari panjang dari setiap kolom tabel yang dijoin dengan tabel bank
    for(int i = 0; i < sizeExec; i++){
        if(*maxId < strlen(join[i].id)){*maxId = strlen(join[i].id);}
        if(*maxCol1 < strlen(join[i].site_dest)){*maxCol1 = strlen(join[i].site_dest);}         // mencari panjang id_site dari kolom
        if(*maxCol2 < strlen(join[i].bank_name)){*maxCol2 = strlen(join[i].bank_name);}         // mencari panjang nama_bank dari kolom
        if(*maxCol3 < strlen(join[i].bank_contact)){*maxCol3 = strlen(join[i].bank_contact);}   // mencari panjang kontak_bank dari kolom
        if(*maxCol4 < strlen(join[i].date)){*maxCol4 = strlen(join[i].date);}
    }
}
int SELECTForeignBank(tableForeign record1[],table1 record2[]){
    // deklarasi variable untuk perulangan dan pencarian tabel bank
    int i, j, found = 0;
    table1 temp;    // variabel temporary untuk menyimpan record dari bank yang dijoin

    for(i = 0; i < sizeExec; i++){
        strcpy(join[i].id,record1[i].id);           // menampung id_jadwal dalam tabel join
        strcpy(join[i].site_dest,record1[i].col1);  // menampung id_site dalam tabel join

        // perulangan mencari id_bank yang bersangkutan
        j = 0; found = 0;
        while(j < sizeBank && found == 0){
            if(strcmp(record1[i].col2,record2[j].id) == 0){
                temp = record2[j];
                found = 1;
            }
            j++;
        }

        strcpy(join[i].bank_name,temp.col1);    // menampung nama_bank dalam tabel join
        strcpy(join[i].bank_contact,temp.col2); // menampung kontak_bank dalam tabel join
        strcpy(join[i].date,record1[i].col3);   // menampung tanggal jadwal dalam tabel join
    }

    // deklarasi panjang terbesar setiap kolom
    int maxId = 0, maxCol1 = 0, maxCol2 = 0, maxCol3 = 0, maxCol4 = 0;
    // deklarasi header dari setiap kolom tabel
    char id[51], col1[51], col2[51], col3[51], col4[51];
    // mencari panjang terbesar setiap kolom dari record data
    spaceForeignBank(&maxId,&maxCol1,&maxCol2,&maxCol3,&maxCol4);

    // menamai header dari setiap kolom tabel
    strcpy(id,"id_jadwal");
    strcpy(col1,"id_site");
    strcpy(col2,"nama_bank");
    strcpy(col3,"kontak_bank");
    strcpy(col4,"tanggal");

    // membandingkan panjang header setiap kolom dengan panjang terbesar record setiap kolom
    if(maxId < strlen(id)){ maxId = strlen(id); }
    if(maxCol1 < strlen(col1)){ maxCol1 = strlen(col1); }
    if(maxCol2 < strlen(col2)){ maxCol2 = strlen(col2); }
    if(maxCol3 < strlen(col3)){ maxCol3 = strlen(col3); }
    if(maxCol4 < strlen(col4)){ maxCol4 = strlen(col4); }

    // membuat panjang dari tabel
    int baris = (2 + maxId + 2) + (1 + maxCol1 + 1) + (2 + maxCol2 + 2) + (1 + maxCol3 + 1) + (2 + maxCol4 + 2);

    // membuat header dari tabel
    rowForeignOne(baris,(3+maxId),(3+maxId+3+maxCol1),(3+maxId+3+maxCol1+3+maxCol2),(3+maxId+3+maxCol1+3+maxCol2+3+maxCol3));
    printf("| "); space(maxId - strlen(id)); printf("%s",id); printf(" ");          // header untuk kolom id
    printf("| "); space(maxCol1 - strlen(col1)); printf("%s",col1); printf(" ");    // header untuk kolom id_site
    printf("| "); space(maxCol2 - strlen(col2)); printf("%s",col2); printf(" ");    // header untuk kolom nama_bank
    printf("| "); space(maxCol3 - strlen(col3)); printf("%s",col3); printf(" ");    // header untuk kolom kontak_bank
    printf("| "); space(maxCol4 - strlen(col4)); printf("%s",col4); printf(" |\n"); // header untuk kolom tanggal
    rowForeignOne(baris,(3+maxId),(3+maxId+3+maxCol1),(3+maxId+3+maxCol1+3+maxCol2),(3+maxId+3+maxCol1+3+maxCol2+3+maxCol3));

    // mengisi tabel dengan record
    for(i = 0; i < sizeExec; i++){
        printf("| "); space(maxId - strlen(join[i].id)); printf("%s",join[i].id); printf(" ");                          // kolom untuk id_jadwal
        printf("| "); space(maxCol1 - strlen(join[i].site_dest)); printf("%s",join[i].site_dest); printf(" ");          // kolom untuk id_site
        printf("| "); space(maxCol2 - strlen(join[i].bank_name)); printf("%s",join[i].bank_name); printf(" ");          // kolom untuk nama_bank yang dijoin
        printf("| "); space(maxCol3 - strlen(join[i].bank_contact)); printf("%s",join[i].bank_contact); printf(" ");    // kolom untuk kontak_bank tersebut
        printf("| "); space(maxCol4 - strlen(join[i].date)); printf("%s",join[i].date); printf(" |\n");                 // kolom untuk tanggal pelaksanaan
    }
    rowForeignOne(baris,(3+maxId),(3+maxId+3+maxCol1),(3+maxId+3+maxCol1+3+maxCol2),(3+maxId+3+maxCol1+3+maxCol2+3+maxCol3));   // menutup tabel tersebut

    return sizeExec;
}

void spaceForeignSite(int* maxId, int* maxCol1, int* maxCol2, int* maxCol3, int* maxCol4){
    // mencari panjang dari setiap kolom tabel yang dijoin dengan tabel site
    for(int i = 0; i < sizeExec; i++){
        if(*maxId < strlen(join[i].id)){*maxId = strlen(join[i].id);}
        if(*maxCol1 < strlen(join[i].site_dest)){*maxCol1 = strlen(join[i].site_dest);}     // mencari panjang dari destinasi site
        if(*maxCol2 < strlen(join[i].site_domain)){*maxCol2 = strlen(join[i].site_domain);} // mencari panjang dari domisili site
        if(*maxCol3 < strlen(join[i].bank_name)){*maxCol3 = strlen(join[i].bank_name);}     // mencari panjang dari id_bank
        if(*maxCol4 < strlen(join[i].date)){*maxCol4 = strlen(join[i].date);}
    }
}
int SELECTForeignSite(tableForeign record1[],table1 record2[]){
    // deklarasi variable untuk perulangan dan pencarian tabel bank
    int i, j, found = 0;
    table1 temp;    // variabel temporary untuk menyimpan record dari bank yang dijoin

    for(i = 0; i < sizeExec; i++){
        strcpy(join[i].id,record1[i].id);   // menampung id_jadwal dalam tabel join

        // perulangan mencari id_site yang bersangkutan
        j = 0; found = 0;
        while(j < sizeSite && found == 0){
            if(strcmp(record1[i].col1,record2[j].id) == 0){
                temp = record2[j];
                found = 1;
            }
            j++;
        }

        strcpy(join[i].site_dest,temp.col1);        // menampung destinasi site dalam tabel join
        strcpy(join[i].site_domain,temp.col2);      // menampung domisili site dalam tabel join
        strcpy(join[i].bank_name,record1[i].col2);  // menampung id_bank dalam tabel join
        strcpy(join[i].date,record1[i].col3);       // menampung tanggal dalam tabel join
    }

    // deklarasi panjang terbesar setiap kolom
    int maxId = 0, maxCol1 = 0, maxCol2 = 0, maxCol3 = 0, maxCol4 = 0;
    // deklarasi header dari setiap kolom tabel
    char id[51], col1[51], col2[51], col3[51], col4[51];
    // mencari panjang terbesar setiap kolom dari record data
    spaceForeignSite(&maxId,&maxCol1,&maxCol2,&maxCol3,&maxCol4);

    // menamai header dari setiap kolom tabel
    strcpy(id,"id_jadwal");
    strcpy(col1,"destinasi_site");
    strcpy(col2,"domisili_site");
    strcpy(col3,"id_bank");
    strcpy(col4,"tanggal");

    // membandingkan panjang header setiap kolom dengan panjang terbesar record setiap kolom
    if(maxId < strlen(id)){ maxId = strlen(id); }
    if(maxCol1 < strlen(col1)){ maxCol1 = strlen(col1); }
    if(maxCol2 < strlen(col2)){ maxCol2 = strlen(col2); }
    if(maxCol3 < strlen(col3)){ maxCol3 = strlen(col3); }
    if(maxCol4 < strlen(col4)){ maxCol4 = strlen(col4); }

    // membuat panjang dari tabel
    int baris = (2 + maxId + 2) + (1 + maxCol1 + 1) + (2 + maxCol2 + 2) + (1 + maxCol3 + 1) + (2 + maxCol4 + 2);

    // membuat header dari tabel
    rowForeignOne(baris,(3+maxId),(3+maxId+3+maxCol1),(3+maxId+3+maxCol1+3+maxCol2),(3+maxId+3+maxCol1+3+maxCol2+3+maxCol3));
    printf("| "); space(maxId - strlen(id)); printf("%s",id); printf(" ");          // header untuk kolom id_jadwal
    printf("| "); space(maxCol1 - strlen(col1)); printf("%s",col1); printf(" ");    // header untuk kolom destinasi_site
    printf("| "); space(maxCol2 - strlen(col2)); printf("%s",col2); printf(" ");    // header untuk kolom domisili_site
    printf("| "); space(maxCol3 - strlen(col3)); printf("%s",col3); printf(" ");    // header untuk kolom id_bank
    printf("| "); space(maxCol4 - strlen(col4)); printf("%s",col4); printf(" |\n"); // header untuk tanggal pelaksanaan
    rowForeignOne(baris,(3+maxId),(3+maxId+3+maxCol1),(3+maxId+3+maxCol1+3+maxCol2),(3+maxId+3+maxCol1+3+maxCol2+3+maxCol3));

    // mengisi tabel dengan record
    for(i = 0; i < sizeExec; i++){
        printf("| "); space(maxId - strlen(join[i].id)); printf("%s",join[i].id); printf(" ");                      // kolom untuk id_jadwal
        printf("| "); space(maxCol1 - strlen(join[i].site_dest)); printf("%s",join[i].site_dest); printf(" ");      // kolom untuk destinasi_site
        printf("| "); space(maxCol2 - strlen(join[i].site_domain)); printf("%s",join[i].site_domain); printf(" ");  // kolom untuk domisili_site
        printf("| "); space(maxCol3 - strlen(join[i].bank_name)); printf("%s",join[i].bank_name); printf(" ");      // kolom untuk id_bank
        printf("| "); space(maxCol4 - strlen(join[i].date)); printf("%s",join[i].date); printf(" |\n");             // kolom untuk tanggal pelaksanaan
    }
    rowForeignOne(baris,(3+maxId),(3+maxId+3+maxCol1),(3+maxId+3+maxCol1+3+maxCol2),(3+maxId+3+maxCol1+3+maxCol2+3+maxCol3));

    return sizeExec;
}

void rowForeignAll(int length, int line1, int line2, int line3, int line4, int line5){
    // membuat pembatas antar kolom untuk tabel yang dijoin dengan kedua tabel
    for(int i = 0; i < length; i++){
        if(i == 0 || i == line1 || i == line2 || i == line3 || i == line4 || i == line5 || i == length-1){
            printf("+");
        }
        else {
            printf("-");
        }
    }
    printf("\n");
}
void spaceForeignAll(int* maxId, int* maxCol1, int* maxCol2, int* maxCol3, int* maxCol4, int* maxCol5){
    // mencari panjang terbesar record dari setiap kolom tabel yang sudah dijoin keduanya
    for(int i = 0; i < sizeExec; i++){
        if(*maxId < strlen(join[i].id)){*maxId = strlen(join[i].id);}                           // kolom untuk id_jadwal
        if(*maxCol1 < strlen(join[i].site_dest)){*maxCol1 = strlen(join[i].site_dest);}         // kolom untuk destinasi_site
        if(*maxCol2 < strlen(join[i].site_domain)){*maxCol2 = strlen(join[i].site_domain);}     // kolom untuk domisili_site
        if(*maxCol3 < strlen(join[i].bank_name)){*maxCol3 = strlen(join[i].bank_name);}         // kolom untuk nama_bank
        if(*maxCol4 < strlen(join[i].bank_contact)){*maxCol4 = strlen(join[i].bank_contact);}   // kolom untuk kontak_bank
        if(*maxCol5 < strlen(join[i].date)){*maxCol5 = strlen(join[i].date);}                   // kolom untuk tanggal pelaksanaan
    }
}
int SELECTForeignAll(tableForeign record1[],table1 record2[], table1 record3[]){
    // deklarasi variabel iterasi perulangan dan id yang dicari ditemukan
    int i, j, found = 0;
    table1 temp;    // variabel temporary untuk menampung nilai dari tabel bank/site

    for(i = 0; i < sizeExec; i++){
        strcpy(join[i].id,record1[i].id);   // menampung id_jadwal dalam tabel join

        // mencari id_site dari jadwal pelaksanaan
        j = 0; found = 0;
        while(j < sizeBank && found == 0){
            if(strcmp(record1[i].col1,record2[j].id) == 0){
                temp = record2[j];
                found = 1;
            }
            j++;
        }

        strcpy(join[i].site_dest,temp.col1);    // menampungnya dalam destinasi_site
        strcpy(join[i].site_domain,temp.col2);  // menampungnya dalam domisili_site

        // mencari id_bank dari jadwal pelaksanaan
        j = 0; found = 0;
        while(j < sizeBank && found == 0){
            if(strcmp(record1[i].col2,record3[j].id) == 0){
                temp = record3[j];
                found = 1;
            }
            j++;
        }

        strcpy(join[i].bank_name,temp.col1);    // menampungnya dalam nama_bank
        strcpy(join[i].bank_contact,temp.col2); // menampungnya dalam kontak_bank
        strcpy(join[i].date,record1[i].col3);   // menampung tanggal pelaksanaan dalam join
    }

    // deklarasi variabel untuk panjang terbesar setiap kolom
    int maxId = 0, maxCol1 = 0, maxCol2 = 0, maxCol3 = 0, maxCol4 = 0, maxCol5 = 0;
    // deklarasi variable nama header tiap kolom
    char id[51], col1[51], col2[51], col3[51], col4[51], col5[51];
    // mencari panjang terbesar record setiap kolom
    spaceForeignAll(&maxId,&maxCol1,&maxCol2,&maxCol3,&maxCol4,&maxCol5);

    // mengisi nama header tiap kolom
    strcpy(id,"id_jadwal");
    strcpy(col1,"destinasi_site");
    strcpy(col2,"domisili_site");
    strcpy(col3,"nama_bank");
    strcpy(col4,"kontak_bank");
    strcpy(col5,"tanggal");

    // membandingkan panjang header setiap kolom dengan panjang terbesar record setiap kolom
    if(maxId < strlen(id)){ maxId = strlen(id); }
    if(maxCol1 < strlen(col1)){ maxCol1 = strlen(col1); }
    if(maxCol2 < strlen(col2)){ maxCol2 = strlen(col2); }
    if(maxCol3 < strlen(col3)){ maxCol3 = strlen(col3); }
    if(maxCol4 < strlen(col4)){ maxCol4 = strlen(col4); }
    if(maxCol5 < strlen(col5)){ maxCol5 = strlen(col5); }

    // membuat panjang dari tabel
    int baris = (2 + maxId + 2) + (1 + maxCol1 + 1) + (2 + maxCol2 + 2) + (1 + maxCol3 + 1) + (2 + maxCol4 + 2) + (1 + maxCol5 + 2);

    // membuat header dari tabel
    rowForeignAll(baris,(3+maxId),(3+maxId+3+maxCol1),(3+maxId+3+maxCol1+3+maxCol2),(3+maxId+3+maxCol1+3+maxCol2+3+maxCol3),(3+maxId+3+maxCol1+3+maxCol2+3+maxCol3+3+maxCol4));
    printf("| "); space(maxId - strlen(id)); printf("%s",id); printf(" ");          // kolom untuk header id_jadwal
    printf("| "); space(maxCol1 - strlen(col1)); printf("%s",col1); printf(" ");    // kolom untuk header destinasi_site
    printf("| "); space(maxCol2 - strlen(col2)); printf("%s",col2); printf(" ");    // kolom untuk header domisili_site
    printf("| "); space(maxCol3 - strlen(col3)); printf("%s",col3); printf(" ");    // kolom untuk header nama_bank
    printf("| "); space(maxCol4 - strlen(col4)); printf("%s",col4); printf(" ");    // kolom untuk header kontak_bank
    printf("| "); space(maxCol5 - strlen(col5)); printf("%s",col5); printf(" |\n"); // kolom untuk header tanggal pelaksanaan
    rowForeignAll(baris,(3+maxId),(3+maxId+3+maxCol1),(3+maxId+3+maxCol1+3+maxCol2),(3+maxId+3+maxCol1+3+maxCol2+3+maxCol3),(3+maxId+3+maxCol1+3+maxCol2+3+maxCol3+3+maxCol4));

    // mengisi tabel dengan record join
    for(i = 0; i < sizeExec; i++){
        printf("| "); space(maxId - strlen(join[i].id)); printf("%s",join[i].id); printf(" ");                          // kolom untuk record id_jadwal
        printf("| "); space(maxCol1 - strlen(join[i].site_dest)); printf("%s",join[i].site_dest); printf(" ");          // kolom untuk record destinasi_site
        printf("| "); space(maxCol2 - strlen(join[i].site_domain)); printf("%s",join[i].site_domain); printf(" ");      // kolom untuk record domisili_site
        printf("| "); space(maxCol3 - strlen(join[i].bank_name)); printf("%s",join[i].bank_name); printf(" ");          // kolom untuk record nama_bank
        printf("| "); space(maxCol4 - strlen(join[i].bank_contact)); printf("%s",join[i].bank_contact); printf(" ");    // kolom untuk record kontak_bank
        printf("| "); space(maxCol5 - strlen(join[i].date)); printf("%s",join[i].date); printf(" |\n");                 // kolom untuk record tanggal
    }
    rowForeignAll(baris,(3+maxId),(3+maxId+3+maxCol1),(3+maxId+3+maxCol1+3+maxCol2),(3+maxId+3+maxCol1+3+maxCol2+3+maxCol3),(3+maxId+3+maxCol1+3+maxCol2+3+maxCol3+3+maxCol4));

    return sizeExec;
}