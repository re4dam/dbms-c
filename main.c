/* Saya Zaki Adam dengan NIM 2304934 mahasiswa Program Studi Ilmu Komputer C2
mengerjakan evaluasi Tugas Masa Depan mata kuliah Algoritma dan Pemrograman 2 untuk keberkahannya
maka saya tidak melakukan kecurangan seperti yang telah ditentukan. Aamiin. */
#include"header.h"

int main(){
    // mengatur ukuran dari masing-masing tabel menjadi 0
    STARTSIZE();
    table1 bank[51], site[51];
    tableForeign execution[51];

    // membaca sequential file dari data yang udah ada
    readBank(bank,filebank);
    readSite(site,filesite);
    readExec(execution,fileexec);
    // variable untuk string query
    char query[201];
    int status = 0; // status mesin nyala atau tidak
    int result = 0; // hasil pengolahan query

    intro();
    /*
    format result kode
    angka pertama nandain query yang dipanggil
    angka kedua nandain tabel yang dipanggil
    angka ketiga-keempat nandain jenis resultnya
    */

    while(status == 0){
        result = 0;
        printf("Gizi DBMS> ");
        scanf(" %200[^\n]s",query);

        STARTKATA(query);
        if(strcmp(GETWORD(),"INSERT") == 0){
            INCWORD(query);
            if(strcmp(GETWORD(),tbank) == 0){
                result = INSERTbank(query,bank);
                if(result == 1100){writeBank(bank,filebank); printf("[%d]: record inserted\n",result);}
                else if(result == 1101){printf("[%d]: id_bank '%s' already existed\n",result,GETWORD());}
                else if(result == 1102){printf("[%d]: input for column id_bank is empty\n",result);}
                else if(result == 1103){printf("[%d]: input for column nama_bank is empty\n",result);}
                else if(result == 1104){printf("[%d]: input for column kontak_bank is empty\n",result);}
                else if(result == 1105){printf("[%d]: query must ends with ';'\n",result);}
                else if(result == 1106){printf("[%d]: Accessing Unknown Column\n",result);}
            }
            else if(strcmp(GETWORD(),tsite) == 0){
                result = INSERTsite(query,site);
                if(result == 1200){writeSite(site,filesite); printf("[%d]: record inserted\n",result);}
                else if(result == 1201){printf("[%d]: id_site '%s' already existed\n",result,GETWORD());}
                else if(result == 1202){printf("[%d]: input for column id_site is empty\n",result);}
                else if(result == 1203){printf("[%d]: input for column destinasi_site is empty\n",result);}
                else if(result == 1204){printf("[%d]: input for column domisili_site is empty\n",result);}
                else if(result == 1205){printf("[%d]: query must ends with ';'\n",result);}
                else if(result == 1206){printf("[%d]: Accessing Unknown Column\n",result);}
            }
            else if(strcmp(GETWORD(),texec) == 0){
                result = INSERTforeign(query,execution,site,bank);
                if(result == 1300){writeExec(execution,fileexec); printf("[%d] record inserted\n",result);}
                else if(result == 1301){printf("[%d]: id_jadwal '%s' already existed\n",result,GETWORD());}
                else if(result == 1302){printf("[%d]: id_site '%s' does not exist\n",result,GETWORD());}
                else if(result == 1303){printf("[%d]: id_bank '%s' does not exist\n",result,GETWORD());}
                else if(result == 1304){printf("[%d]: input for column id_jadwal is empty\n",result);}
                else if(result == 1305){printf("[%d]: input for column id_site is empty\n",result);}
                else if(result == 1306){printf("[%d]: input for column id_bank is empty\n",result);}
                else if(result == 1307){printf("[%d]: input for column date is empty\n",result);}
                else if(result == 1308){printf("[%d]: query must ends with ';'\n",result);}
                else if(result == 1309){printf("[%d]: Accessing Unknown Column\n",result);}
            }
            else if(EOPKATA(query) == 2){printf("[1002] query must end with ';'\n");}
            else{printf("[1001] Unknown Table request\n");}
        }
        else if(strcmp(GETWORD(),"UPDATE") == 0){
            INCWORD(query);
            if(strcmp(GETWORD(),tbank) == 0){
                result = UPDATEbank(query,bank);
                if(result == 2100){writeBank(bank,filebank); printf("[%d]: record updated\n",result);}
                else if(result == 2101){printf("[%d]: id_bank '%s' does not exist\n",result,GETWORD());}
                else if(result == 2102){printf("[%d]: input for column id_bank is empty\n",result);}
                else if(result == 2103){printf("[%d]: input for column nama_bank is empty\n",result);}
                else if(result == 2104){printf("[%d]: input for column kontak_bank is empty\n",result);}
                else if(result == 2105){printf("[%d]: query must ends with ';'\n",result);}
                else if(result == 2106){printf("[%d]: Accessing Unknown Column\n",result);}
            }
            else if(strcmp(GETWORD(),tsite) == 0){
                result = UPDATEsite(query,site);
                if(result == 2200){writeSite(site,filesite); printf("[%d]: record updated\n",result);}
                else if(result == 2201){printf("[%d]: id_site '%s' does not exist\n",result,GETWORD());}
                else if(result == 2202){printf("[%d]: input for column id_site is empty\n",result);}
                else if(result == 2203){printf("[%d]: input for column nama_site is empty\n",result);}
                else if(result == 2204){printf("[%d]: input for column domisili_site is empty\n",result);}
                else if(result == 2205){printf("[%d]: query must ends with ';'\n",result);}
                else if(result == 2206){printf("[%d]: Accessing Unknown Column\n",result);}
            }
            else if(strcmp(GETWORD(),texec) == 0){
                result = UPDATEforeign(query,execution,site,bank);
                if(result == 2300){writeExec(execution,fileexec); printf("[%d] record inserted\n",result);}
                else if(result == 2301){printf("[%d]: id_jadwal '%s' does not exist\n",result,GETWORD());}
                else if(result == 2302){printf("[%d]: id_site '%s' does not exist\n",result,GETWORD());}
                else if(result == 2303){printf("[%d]: id_bank '%s' does not exist\n",result,GETWORD());}
                else if(result == 2304){printf("[%d]: input for column id_jadwal is empty\n",result);}
                else if(result == 2305){printf("[%d]: input for column id_site is empty\n",result);}
                else if(result == 2306){printf("[%d]: input for column id_bank is empty\n",result);}
                else if(result == 2307){printf("[%d]: input for column date is empty\n",result);}
                else if(result == 2308){printf("[%d]: query must ends with ';'\n",result);}
                else if(result == 2309){printf("[%d]: Accessing Unknown Column\n",result);}
            }
            else if(EOPKATA(query) == 2){printf("[2002] query must end with ';'\n");}
            else{printf("[2001] Unknown Table request\n");}
            
        }
        else if(strcmp(GETWORD(),"DELETE") == 0){
            INCWORD(query);
            if(strcmp(GETWORD(),tbank) == 0){
                result = DELETEbank(query,bank,execution);
                if(result == 3100){writeBank(bank,filebank);printf("[%d]: record deleted\n",result);}
                else if(result == 3101){printf("[%d]: id_bank '%s' does not exist\n",result,GETWORD());}
                else if(result == 3102){printf("[%d]: id_bank '%s' is a foreign key in another table\n",result,GETWORD());}
                else if(result == 3103){printf("[%d]: input for column id_bank is empty\n",result);}
                else if(result == 3104){printf("[%d]: query must end with ';'\n",result);}
                else if(result == 3105){printf("[%d]: Accessing Unknown Column\n",result);}
            }
            else if(strcmp(GETWORD(),tsite) == 0){
                result = DELETEsite(query,site,execution);
                if(result == 3200){writeSite(site,filesite);printf("[%d]: record deleted\n",result);}
                else if(result == 3201){printf("[%d]: id_site '%s' does not exist\n",result,GETWORD());}
                else if(result == 3202){printf("[%d]: id_site '%s' is a foreign key in another table\n",result,GETWORD());}
                else if(result == 3203){printf("[%d]: input for column id_site is empty\n",result);}
                else if(result == 3204){printf("[%d]: query must end with ';'\n",result);}
                else if(result == 3205){printf("[%d]: Accessing Unknown Column\n",result);}

            }
            else if(strcmp(GETWORD(),texec) == 0){
                result = DELETEforeign(query,execution);
                if(result == 3300){writeExec(execution,fileexec);printf("[%d]: record deleted\n",result);}
                else if(result == 3301){printf("[%d]: id_jadwal '%s' does not exist\n",result,GETWORD());}
                else if(result == 3302){printf("[%d]: input for column id_jadwal is empty\n",result);}
                else if(result == 3303){printf("[%d]: query must end with ';'\n",result);}
                else if(result == 3304){printf("[%d]: Accessing Unknown Column\n",result);}
            }
            else if(EOPKATA(query) == 2){printf("[3002] query must end with ';'\n");}
            else{printf("[3001] Unknown Table request\n");}
        }
        else if(strcmp(GETWORD(),"SELECT") == 0){
            INCWORD(query);
            
            if(strcmp(GETWORD(),tbank) == 0 && EOPKATA(query) == 1){
                result = SELECTtable(bank,tbank);printf("%d records shown\n",result);
            }
            else if(strcmp(GETWORD(),tsite) == 0 && EOPKATA(query) == 1){
                result = SELECTtable(site,tsite);printf("%d records shown\n",result);
            }
            else if(strcmp(GETWORD(),texec) == 0){
                if(EOPKATA(query) == 1){result = SELECTforeign(execution);printf("%d records shown\n",result);}
                else{
                    INCWORD(query);
                    if(strcmp(GETWORD(),tbank) == 0){
                        if(EOPKATA(query) == 1){result = SELECTForeignBank(execution,bank);printf("%d records shown\n",result);}
                        else if(EOPKATA(query) == 2){printf("[4301] query must end with ';'\n");}
                        else if(EOPKATA(query) == 0){
                            INCWORD(query);
                            if(strcmp(GETWORD(),tsite) == 0){
                                if(EOPKATA(query) == 1){result = SELECTForeignAll(execution,site,bank);printf("%d records shown\n",result);}
                                else if(EOPKATA(query) == 2){printf("[4301] query must end with ';'\n");}
                                else{printf("[4302] Unknown table to join in %s\n",texec);}
                            }
                            else if(strcmp(GETWORD(),tbank) == 0){printf("[4303] Cannot perform join on an already performed joined table\n");}
                            else if(EOPKATA(query) == 2){printf("[4301] query must end with ';'\n");}
                            else{printf("[4302] Unknown table to join in %s\n",texec);}
                        }
                    }
                    else if(strcmp(GETWORD(),tsite) == 0){
                        if(EOPKATA(query) == 1){result = SELECTForeignSite(execution,site);printf("%d records shown\n",result);}
                        else if(EOPKATA(query) == 2){}
                        else if(EOPKATA(query) == 0){
                            INCWORD(query);
                            if(strcmp(GETWORD(),tbank) == 0){
                                if(EOPKATA(query) == 1){result = SELECTForeignAll(execution,site,bank);printf("%d records shown\n",result);}
                                else if(EOPKATA(query) == 2){printf("[4301] query must end with ';'\n");}
                                else{printf("[4302] Unknown table to join in %s\n",texec);}
                            }
                            else if(strcmp(GETWORD(),tsite) == 0){printf("[4303] Cannot perform join on an already performed joined table\n");}
                            else if(EOPKATA(query) == 2){printf("[4301] query must end with ';'\n");}
                            else{printf("[4302] Unknown table to join in %s\n",texec);}
                        }
                    }
                    else if(EOPKATA(query) == 2){printf("[4301] query must end with ';'\n");}
                    else{printf("[4302] Unknown table to join in %s\n",texec);}
                }
            }
            else if(strcmp(GETWORD(),tsite) == 0 && EOPKATA(query) == 0){printf("[4101] Unknown join request for table %s\n",tsite);}
            else if(strcmp(GETWORD(),tbank) == 0 && EOPKATA(query) == 0){printf("[4201] Unknown join request for table %s\n",tbank);}
            else if(EOPKATA(query) == 2){printf("[4002] query must end with ';'\n");}
            else{printf("[4001] Unknown Table request\n");}
        }
        else if(strcmp(GETWORD(),"HELP") == 0 && EOPKATA(query) == 1){HELP();}
        else if(strcmp(GETWORD(),"INFO") == 0 && EOPKATA(query) == 1){INFO();}
        else if(strcmp(GETWORD(),"quit") == 0 && (EOPKATA(query) == 1 || EOPKATA(query) == 2)){status = 1; printf("Berbahagia abangkuh semoga makanan tersampaikan ke mereka yang membutuhkan!\n");}
        else{printf("[0001] Unknown query '%s' request\n",GETWORD());}
    }
    return 0;
}
