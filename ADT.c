//implementasi ADT.h

#include "ADT.h"
#include <stdio.h>

void ExitMessage(boolean SaveGame){
    if (SaveGame) SaveFile();
    printf("Kelas K-1\n\n");
    printf("Credits to : Warteg Bahari\n");
    printf("Bimo Adityarahman Wiraputra/13517004\n");
    printf("Ricky Yuliawan Pohan/13517025\n");
    printf("Ahmad Rizqee Nurhani/13517058\n");
    printf("Naufal Aditya Dirgandhavi/13517064\n");
    printf("Ahmad Rizal Alifio/13517076\n\n");
    printf("Thank you for playing!");
}

//ntar bakal dipake di command exit sama exitnya main menu, dia bakal nampilin message kalo keluar game dan bakalan ngesave kalo savegamenya true

void TampilanProgramUtama();
    /*{//masih harus dibenerin, pasti berantakan sih
    printf("\n---------------------------------------------------------------\n");
    printf("|%c              |Money: %d  |Life: %d   |Time: %d            |\n", Pemain.nama, Pemain.life, Pemain.money, Pemain.time);
    printf("|-------------------------------------------------------------|\n");
    printf("|Waiting Cust    | %c | %c | %c | %c | %c | %c | %c | %c |Food Stack  |\n", MatriksToChar(Elmt(M,i,j)));
    printf("|                |-------------------------------|            |\n");
    printf("|2               | C | 1 | C |   |   | C | 2 | C |            |\n");
    printf("|                |-------------------------------|            |\n");
    printf("|                |   | C |   |   | P |   |   |   |            |\n");
    printf("|                |-------------------------------|            |\n");
    printf("|                |   |   |   |   |   |   |   |   |            |\n");
    printf("--------------------------------------------------------------|\n");
    printf("|Order           |   |   |   |   |   |   |   |   |Hand        |\n");
    printf("|                |-------------------------------|            |\n");
    printf("|                |   | X |   |   |   |   |   |   |            |\n");
    printf("|                |-------------------------------|            |\n");
    printf("|                | X | 3 | X |   |   | C | 4 | C |            |\n");
    printf("|                |-------------------------------|            |\n");
    printf("|                |   | X |   |   |   |   |   |   |            |\n");
    printf("|-------------------------------------------------------------|\n");
    printf("|Command: GU                                                  |\n");
    printf("---------------------------------------------------------------\n");
}*/
//ntar bakal nampilin program utamanya
void SaveFile();
    /*FILE *save;
    save= fopen("savegame.txt", "a");
    fprintf(savega, "===%d:%d:%d===\n\n", ); //Jam real time
    fprintf(save, "%s\n", Pemain.nama); //<nama, string>
    fprintf(save, "%d\n", Pemain.life); //<life, int>
    fprintf(save, "%d\n", Pemain.money); //<money, int >
    fprintf(save, "%d\n", Pemain.time); //<time, int >
    fprintf(save, "<%d, %d>\n", Pemain.posisi.X, Pemain.posisi.Y); //<posisi x,y, point(?)>
    //mulai dr sini kayaknya bakal make loop
    fprintf(save, "<%d, %d>\n", Pemain.time); //<queue antrian>
    fprintf(save, "<%d, %d>\n", food stack); //<food stack>
    fprintf(save, "<%d, %d>\n", array order); //<array order>
    fprintf(save, "<%d, %d>\n", array order); //<stack hand>
    fprintf(save, "<%d, %d>\n", matriks ruangan 1); //<matriks ruangan 1>
    fprintf(save, "<%d, %d>\n", matriks ruangan 2); //<matriks ruangan 2>
    fprintf(save, "<%d, %d>\n", matriks ruangan 3); //<matriks ruangan 3>
    fprintf(save, "<%d, %d>\n", kitchen); //<matriks kitchen>
    fprintf(save, "#");
    fclose(save);*/
}
//bakal ngesave ke file eksternal dgn format yg di tampilan
void LoadFile();
    /*FILE *save;
    load= fopen("savegame.txt", "r");
    fscanf(load, "%d:%d:%d", &RealTime);//Jam real time
    fscanf(load, "%s", &Pemain.nama);//<nama, string>
    fscanf(load, "%d", &Pemain.life);//<life, int>
    fscanf(load, "%d", &Pemain.money);//<money, int >
    fscanf(load, "%d", &Pemain.time);//<time, int >
    fscanf(load, "%d", &Pemain.posisi.x, Pemain.posisi.y);//<posisi x,y, point(?)>
    //mulai dr sini kayaknya bakal make loop
    fscanf(load, "%d", queue antrian);//<queue antrian>
    fscanf(load, "%d", food stack); //<food stack>
    fscanf(load, "%d", array order);//<array order>
    fscanf(load, "%d", stack hand);//<stack hand>
    fscanf(load, "%d", ruangan 1);//<matriks ruangan 1>
    fscanf(load, "%d", ruangan 2);//<matriks ruangan 2>
    fscanf(load, "%d", ruangan 3);//<matriks ruangan 3>
    fscanf(load, "%d", kitchen);//<matriks kitchen>
    fclose(load);

}*/
//bakal dipake sama main menu yg Load game
char MatriksToChar(int y){
    char y
    switch X{
        case 0 :
        y = ' ';
        break;
        case 1 :
        y = '1'
        break;
        case 2 :
        y = '2';
        break;
        case 3 :
        y = '3';
        break;
        case 4 :
        y = '4';
        break;
        case 5 :
        y = 'P';
        break;
        case 6 :
        y = 'X';
        break;
        case 7 :
        y = 'C';
        break;
        case 8 :
        y = 'M';
        break;
        case 9 :
        y = 'T';
        break;
    }
    return y;
}
//ubah matriks jadi char
//kosong=0, Meja=1-4, Player(P) = 5, Kursi kosong(X) = 6, kursi ada(C) = 7, Meja naroh bahan(M) = 8, 
//Tray(T) = 9