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

/*void TampilanProgramUtama(Graf Posisi){
    Matriks Ruangan;
    Kata command;
    if(Posisi==1) Ruangan=Ruangan1;
    else if(Posisi==2) Ruangan=Ruangan2;
    else if(Posisi==3) Ruangan=Ruangan3;
    else if(Posisi==4) Ruangan=Dapur;
     printf("\n┌────────────────┬───────────────┬───────────────┬────────────┐\n");
    printf("│%s\t\t │ Money: %d\t │ Life: %d\t │Time: %d     │\n", Pemain.nama, Pemain.money, Pemain.life, Pemain.time);
    printf("├────────────────┼───┬───┬───┬───┼───┬───┬───┬───┼────────────┤\n");
    printf("│Waiting Cust    │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │Food Stack  │\n", MatriksToChar(Ruangan[1][1]), MatriksToChar(Ruangan[1][2]), MatriksToChar(Ruangan[1][3]), MatriksToChar(Ruangan[1][4]), MatriksToChar(Ruangan[1][5]), MatriksToChar(Ruangan[1][6]), MatriksToChar(Ruangan[1][7]), MatriksToChar(Ruangan[1][8]));
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│2               │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", MatriksToChar(Ruangan[2][1]), MatriksToChar(Ruangan[2][2]), MatriksToChar(Ruangan[2][3]), MatriksToChar(Ruangan[2][4]), MatriksToChar(Ruangan[2][5]), MatriksToChar(Ruangan[2][6]), MatriksToChar(Ruangan[2][7]), MatriksToChar(Ruangan[2][8]));
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│                │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", MatriksToChar(Ruangan[3][1]), MatriksToChar(Ruangan[3][2]), MatriksToChar(Ruangan[3][3]), MatriksToChar(Ruangan[3][4]), MatriksToChar(Ruangan[3][5]), MatriksToChar(Ruangan[3][6]), MatriksToChar(Ruangan[3][7]), MatriksToChar(Ruangan[3][8]));
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│                │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", MatriksToChar(Ruangan[4][1]), MatriksToChar(Ruangan[4][2]), MatriksToChar(Ruangan[4][3]), MatriksToChar(Ruangan[4][4]), MatriksToChar(Ruangan[4][5]), MatriksToChar(Ruangan[4][6]), MatriksToChar(Ruangan[4][7]), MatriksToChar(Ruangan[4][8]));
    printf("├────────────────┼───┼───┼───┼───┼───┼───┼───┼───┼────────────┤\n");
    printf("│Order           │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │Hand        │\n", MatriksToChar(Ruangan[5][1]), MatriksToChar(Ruangan[5][2]), MatriksToChar(Ruangan[5][3]), MatriksToChar(Ruangan[5][4]), MatriksToChar(Ruangan[5][5]), MatriksToChar(Ruangan[5][6]), MatriksToChar(Ruangan[5][7]), MatriksToChar(Ruangan[5][8]));
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│                │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", MatriksToChar(Ruangan[6][1]), MatriksToChar(Ruangan[6][2]), MatriksToChar(Ruangan[6][3]), MatriksToChar(Ruangan[6][4]), MatriksToChar(Ruangan[6][5]), MatriksToChar(Ruangan[6][6]), MatriksToChar(Ruangan[6][7]), MatriksToChar(Ruangan[6][8]));
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│                │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", MatriksToChar(Ruangan[7][1]), MatriksToChar(Ruangan[7][2]), MatriksToChar(Ruangan[7][3]), MatriksToChar(Ruangan[7][4]), MatriksToChar(Ruangan[7][5]), MatriksToChar(Ruangan[7][6]), MatriksToChar(Ruangan[7][7]), MatriksToChar(Ruangan[7][8]));
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│                │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", MatriksToChar(Ruangan[8][1]), MatriksToChar(Ruangan[8][2]), MatriksToChar(Ruangan[8][3]), MatriksToChar(Ruangan[8][4]), MatriksToChar(Ruangan[8][5]), MatriksToChar(Ruangan[8][6]), MatriksToChar(Ruangan[8][7]), MatriksToChar(Ruangan[8][8]));
    printf("└────────────────┴───┴───┴───┴───┴───┴───┴───┴───┴────────────┘\n");
    printf(" Command : ");
    command= InputKata();
}*/
//ntar bakal nampilin program utamanya
void SaveFile(){
    FILE *save;
    save= fopen("savegame.txt", "a");
    fprintf(save, "Waktu Save : ===%d:%d:%d===\n", RealTime.HH, RealTime.MM, RealTime.SS); //Jam real time
    for (int i = 1; i <= Pemain.nama.Length; ++i) {
		fprintf(save, "%c", Pemain.nama.TabKata[i]);
	} //nama, Kata
    fprintf(save, "Life : %d", Pemain.life); //<life, int>
    fprintf(save, "Money : %d", Pemain.money); //<money, int >
    fprintf(save, "Time : %d", Pemain.time); //<time, int >
    fprintf(save, " Posisi : <%d, %d>", Pemain.posisi.X, Pemain.posisi.Y); //<posisi x,y, point(?)>
    //save antrian
    fprintf(save, "QUEUE : ");
    int i = Head(Antrian);
    while(i!=Nil){
        fprintf(save, "<%d %d %d>", Elmt(Antrian,i), Prio(Elmt(Antrian,i)), Kesabaran(Elmt(Antrian,i)));
        i++;
    }
    //save food stack
    infotypeStack X;
    while(!IsEmptyStack(Makanan)){
        Pop(Makanan, X);
        for (int i = 1; i <= X.Length; ++i) {
	    	fprintf(save, "%c", X.TabKata[i]);
        }
	}
    //save array pesanan
    /*for(i=1; i<=GetLastIdx(Pesanan);i++){
        fprintf(save, "<"); //<array order>
        for (int j = 1; j <= Elmt(Pesanan,i).Length; ++j) {
	    	fprintf(save, "%c", Elmt(Pesanan,i).TabKata[j]);
        }
    }*/
    //save stack tangan 
    while(!IsEmptyStack(Tangan)){
        Pop(Tangan, X);
        for (int i = 1; i <= X.Length; ++i) {
	    	fprintf(save, "%c", X.TabKata[i]);
        }
    }
    /*save ruangan
    fprintf(save, "<%d, %d>\n", matriks ruangan 1); //<matriks ruangan 1>
    fprintf(save, "<%d, %d>\n", matriks ruangan 2); //<matriks ruangan 2>
    fprintf(save, "<%d, %d>\n", matriks ruangan 3); //<matriks ruangan 3>
    fprintf(save, "<%d, %d>\n", kitchen); //<matriks kitchen>*/
    fprintf(save, "#");
    fclose(save);
}
//bakal ngesave ke file eksternal dgn format yg di tampilan
/*void LoadFile();
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

    //nampilin daftar apa aja yg bisa diload, ntar playernya milih terus ngeload statnya dan diassign ke variabel
}*/
//bakal dipake sama main menu yg Load game
char MatriksToChar(int X){
    char y;
    switch (X){
        case 0 :
        y = ' ';
        break;
        case 1 :
        y = '1';
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
BinTree assignResep(){
    int i;
	BinTree P;
	/* ALGORITMA */
	i = 1;
	START("resep.txt");
	BuildTree(&P,&i);   
    return P;
}

void InitDenah () {
    MakeGraph(4,&Denah);
    CreateEdge(&Denah,1,2,1);
    CreateEdge(&Denah,1,4,2);
    CreateEdge(&Denah,3,4,1);
    CreateEdge(&Denah,2,3,2);
}

void init_ruangan1() {
    (Ruangan1).P1.X = 5;
    (Ruangan1).P1.Y = 8;
    (Ruangan1).P2.X = 8;
    (Ruangan1).P2.Y = 5;
    (Ruangan1).M1.posisi.X = 2;
    (Ruangan1).M1.posisi.Y = 2;
    (Ruangan1).M1.kursi = 4;
    (Ruangan1).M1.NCustomer = 0;
    (Ruangan1).M2.posisi.X = 2;
    (Ruangan1).M2.posisi.Y = 7;
    (Ruangan1).M2.kursi = 2;
    (Ruangan1).M2.NCustomer = 0;
    (Ruangan1).M3.posisi.X = 7;
    (Ruangan1).M3.posisi.Y = 2;
    (Ruangan1).M3.kursi = 4;
    (Ruangan1).M3.NCustomer = 0;
    (Ruangan1).M4.posisi.X = 7;
    (Ruangan1).M4.posisi.Y = 7;
    (Ruangan1).M4.kursi = 2;
    (Ruangan1).M4.NCustomer = 0;
}
void init_ruangan2(){
    (Ruangan2).P1.X = 2;
    (Ruangan2).P1.Y = 1;
    (Ruangan2).P2.X = 8;
    (Ruangan2).P2.Y = 5;
    (Ruangan2).M1.posisi.X = 2;
    (Ruangan2).M1.posisi.Y = 2;
    (Ruangan2).M1.kursi = 4;
    (Ruangan2).M1.NCustomer = 0;
    (Ruangan2).M2.posisi.X = 2;
    (Ruangan2).M2.posisi.Y = 7;
    (Ruangan2).M2.kursi = 2;
    (Ruangan2).M2.NCustomer = 0;
    (Ruangan2).M3.posisi.X = 7;
    (Ruangan2).M3.posisi.Y = 2;
    (Ruangan2).M3.kursi = 4;
    (Ruangan2).M3.NCustomer = 0;
    (Ruangan2).M4.posisi.X = 7;
    (Ruangan2).M4.posisi.Y = 7;
    (Ruangan2).M4.kursi = 2;
    (Ruangan2).M4.NCustomer = 0;
}
void init_ruangan3(){
    (Ruangan3).P1.X = 2;
    (Ruangan3).P1.Y = 1;
    (Ruangan3).P2.X = 1;
    (Ruangan3).P2.Y = 5;
    (Ruangan3).M1.posisi.X = 2;
    (Ruangan3).M1.posisi.Y = 2;
    (Ruangan3).M1.kursi = 4;
    (Ruangan3).M1.NCustomer = 0;
    (Ruangan3).M2.posisi.X = 2;
    (Ruangan3).M2.posisi.Y = 7;
    (Ruangan3).M2.kursi = 2;
    (Ruangan3).M2.NCustomer = 0;
    (Ruangan3).M3.posisi.X = 7;
    (Ruangan3).M3.posisi.Y = 2;
    (Ruangan3).M3.kursi = 4;
    (Ruangan3).M3.NCustomer = 0;
    (Ruangan3).M4.posisi.X = 7;
    (Ruangan3).M4.posisi.Y = 7;
    (Ruangan3).M4.kursi = 2;
    (Ruangan3).M4.NCustomer = 0;
}
void init_dapur(){
    (Dapur).P1.X = 5;
    (Dapur).P1.Y = 8;
    (Dapur).P2.X = 1;
    (Dapur).P2.Y = 5;
    (Dapur).T.posisi.X = 1;
    (Dapur).T.posisi.Y = 8;
    CreateEmptyStack(&(Dapur).T.bahan);
    (Dapur).M1.posisi.X = 7;
    (Dapur).M1.posisi.Y = 4;
    (Dapur).M1.bahan = StringToKata("piring");
    (Dapur).M2.posisi.X = 7;
    (Dapur).M2.posisi.Y = 3;
    (Dapur).M2.bahan = StringToKata("sendok");
    (Dapur).M3.posisi.X = 7;
    (Dapur).M3.posisi.Y = 5;
    (Dapur).M3.bahan = StringToKata("garpu");
    (Dapur).M4.posisi.X = 4;
    (Dapur).M4.posisi.Y = 3;
    (Dapur).M4.bahan = StringToKata("nasi");
    (Dapur).M5.posisi.X = 5;
    (Dapur).M5.posisi.Y = 1;
    (Dapur).M5.bahan = StringToKata("telur");
    (Dapur).M6.posisi.X = 6;
    (Dapur).M6.posisi.Y = 1;
    (Dapur).M6.bahan = 2;
    (Dapur).M7.posisi.X = 7;
    (Dapur).M7.posisi.Y = 1;
    (Dapur).M7.bahan = 2;
    (Dapur).M8.posisi.X = 8;
    (Dapur).M8.posisi.Y = 1;
    (Dapur).M8.bahan = 2;
    (Dapur).M9.posisi.X = 5;
    (Dapur).M9.posisi.Y = 4;
    (Dapur).M9.bahan = 2;
    (Dapur).M10.posisi.X = 5;
    (Dapur).M10.posisi.Y = 5;
    (Dapur).M10.bahan = 2;
    (Dapur).M11.posisi.X = 8;
    (Dapur).M11.posisi.Y = 4;
    (Dapur).M11.bahan = 2;
    (Dapur).M12.posisi.X = 8;
    (Dapur).M12.posisi.Y = 5;
    (Dapur).M12.bahan = 2;
    (Dapur).M13.posisi.X = 8;
    (Dapur).M13.posisi.Y = 6;
    (Dapur).M13.bahan = 2;
    (Dapur).M14.posisi.X = 8;
    (Dapur).M14.posisi.Y = 7;
    (Dapur).M14.bahan = 2;
    (Dapur).M15.posisi.X = 8;
    (Dapur).M15.posisi.Y = 8;
    (Dapur).M15.bahan = 2;


}