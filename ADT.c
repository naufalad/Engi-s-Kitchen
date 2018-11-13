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

//void TampilanProgramUtama(Graf Posisi);
    /*{//masih harus dibenerin, pasti berantakan sih
    Matriks Ruangan;
    if(Posisi==1) Ruangan=Ruangan1;
    else if(Posisi==2) Ruangan=Ruangan2;
    else if(Posisi==3) Ruangan=Ruangan3;
    else if(Posisi==4) Ruangan=Dapur;
    printf("\n---------------------------------------------------------------\n");
    printf("|%s\t\t | Money: %d\t | Life: %d\t |Time: %d     |\n", Pemain.nama, Pemain.money, Pemain.life, Pemain.time);
    printf("|-------------------------------------------------------------|\n");
    printf("|Waiting Cust    | %c | %c | %c | %c | %c | %c | %c | %c |Food Stack  |\n", MatriksToChar(Ruangan[1][1]), MatriksToChar(Ruangan[1][2]), MatriksToChar(Ruangan[1][3]), MatriksToChar(Ruangan[1][4]), MatriksToChar(Ruangan[1][5]), MatriksToChar(Ruangan[1][6]), MatriksToChar(Ruangan[1][7]), MatriksToChar(Ruangan[1][8]))
    printf("|                |-------------------------------|            |\n");
    printf("|2               | %c | %c | %c | %c | %c | %c | %c | %c |            |\n", MatriksToChar(Ruangan[2][1]), MatriksToChar(Ruangan[2][2]), MatriksToChar(Ruangan[2][3]), MatriksToChar(Ruangan[2][4]), MatriksToChar(Ruangan[2][5]), MatriksToChar(Ruangan[2][6]), MatriksToChar(Ruangan[2][7]), MatriksToChar(Ruangan[2][8]))
    printf("|                |-------------------------------|            |\n");
    printf("|                | %c | %c | %c | %c | %c | %c | %c | %c |            |\n", MatriksToChar(Ruangan[3][1]), MatriksToChar(Ruangan[3][2]), MatriksToChar(Ruangan[3][3]), MatriksToChar(Ruangan[3][4]), MatriksToChar(Ruangan[3][5]), MatriksToChar(Ruangan[3][6]), MatriksToChar(Ruangan[3][7]), MatriksToChar(Ruangan[3][8]))
    printf("|                |-------------------------------|            |\n");
    printf("|                | %c | %c | %c | %c | %c | %c | %c | %c |            |\n", MatriksToChar(Ruangan[4][1]), MatriksToChar(Ruangan[4][2]), MatriksToChar(Ruangan[4][3]), MatriksToChar(Ruangan[4][4]), MatriksToChar(Ruangan[4][5]), MatriksToChar(Ruangan[4][6]), MatriksToChar(Ruangan[4][7]), MatriksToChar(Ruangan[4][8]))
    printf("--------------------------------------------------------------|\n");
    printf("|Order           | %c | %c | %c | %c | %c | %c | %c | %c |Hand        |\n", MatriksToChar(Ruangan[5][1]), MatriksToChar(Ruangan[5][2]), MatriksToChar(Ruangan[5][3]), MatriksToChar(Ruangan[5][4]), MatriksToChar(Ruangan[5][5]), MatriksToChar(Ruangan[5][6]), MatriksToChar(Ruangan[5][7]), MatriksToChar(Ruangan[5][8]))
    printf("|                |-------------------------------|            |\n");
    printf("|                | %c | %c | %c | %c | %c | %c | %c | %c |            |\n", MatriksToChar(Ruangan[6][1]), MatriksToChar(Ruangan[6][2]), MatriksToChar(Ruangan[6][3]), MatriksToChar(Ruangan[6][4]), MatriksToChar(Ruangan[6][5]), MatriksToChar(Ruangan[6][6]), MatriksToChar(Ruangan[6][7]), MatriksToChar(Ruangan[6][8]))
    printf("|                |-------------------------------|            |\n");
    printf("|                | %c | %c | %c | %c | %c | %c | %c | %c |            |\n", MatriksToChar(Ruangan[7][1]), MatriksToChar(Ruangan[7][2]), MatriksToChar(Ruangan[7][3]), MatriksToChar(Ruangan[7][4]), MatriksToChar(Ruangan[7][5]), MatriksToChar(Ruangan[7][6]), MatriksToChar(Ruangan[7][7]), MatriksToChar(Ruangan[7][8]))
    printf("|                |-------------------------------|            |\n");
    printf("|                | %c | %c | %c | %c | %c | %c | %c | %c |            |\n", MatriksToChar(Ruangan[8][1]), MatriksToChar(Ruangan[8][2]), MatriksToChar(Ruangan[8][3]), MatriksToChar(Ruangan[8][4]), MatriksToChar(Ruangan[8][5]), MatriksToChar(Ruangan[8][6]), MatriksToChar(Ruangan[8][7]), MatriksToChar(Ruangan[8][8]))
    printf("|-------------------------------------------------------------|\n");
    printf(" Command : ");
    scanf("%s", command);
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