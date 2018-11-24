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

void TampilanProgramUtama(){
    Kata command;
    printf("\n┌────────────────┬───────────────┬───────────────┬────────────┐\n");
    printf("|");
    OutputKata(Pemain.nama);
    printf("\t\t │ Money: %d\t │ Life: %d\t │Time: %d     │\n", Pemain.money, Pemain.life, Pemain.time);
    printf("├────────────────┼───┬───┬───┬───┼───┬───┬───┬───┼────────────┤\n");
    printf("│Waiting Cust    │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │Food Stack  │\n", MatriksToChar(ElmtMatriks(Tampilan, 1,1)), MatriksToChar(ElmtMatriks(Tampilan,1,2)), MatriksToChar(ElmtMatriks(Tampilan,1,3)), MatriksToChar(ElmtMatriks(Tampilan,1,4)), MatriksToChar(ElmtMatriks(Tampilan,1,5)), MatriksToChar(ElmtMatriks(Tampilan,1,6)), MatriksToChar(ElmtMatriks(Tampilan,1,7)), MatriksToChar(ElmtMatriks(Tampilan,1,8)));
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│2               │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", MatriksToChar(ElmtMatriks(Tampilan, 2,1)), MatriksToChar(ElmtMatriks(Tampilan,2,2)), MatriksToChar(ElmtMatriks(Tampilan,2,3)), MatriksToChar(ElmtMatriks(Tampilan,2,4)), MatriksToChar(ElmtMatriks(Tampilan,2,5)), MatriksToChar(ElmtMatriks(Tampilan,2,6)), MatriksToChar(ElmtMatriks(Tampilan,2,7)), MatriksToChar(ElmtMatriks(Tampilan,2,8)));
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│                │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", MatriksToChar(ElmtMatriks(Tampilan, 3,1)), MatriksToChar(ElmtMatriks(Tampilan,3,2)), MatriksToChar(ElmtMatriks(Tampilan,3,3)), MatriksToChar(ElmtMatriks(Tampilan,3,4)), MatriksToChar(ElmtMatriks(Tampilan,3,5)), MatriksToChar(ElmtMatriks(Tampilan,3,6)), MatriksToChar(ElmtMatriks(Tampilan,3,7)), MatriksToChar(ElmtMatriks(Tampilan,3,8)));
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│                │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", MatriksToChar(ElmtMatriks(Tampilan, 4,1)), MatriksToChar(ElmtMatriks(Tampilan,4,2)), MatriksToChar(ElmtMatriks(Tampilan,4,3)), MatriksToChar(ElmtMatriks(Tampilan,4,4)), MatriksToChar(ElmtMatriks(Tampilan,4,5)), MatriksToChar(ElmtMatriks(Tampilan,4,6)), MatriksToChar(ElmtMatriks(Tampilan,4,7)), MatriksToChar(ElmtMatriks(Tampilan,4,8)));
    printf("├────────────────┼───┼───┼───┼───┼───┼───┼───┼───┼────────────┤\n");
    printf("│Order           │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │Hand        │\n", MatriksToChar(ElmtMatriks(Tampilan, 5,1)), MatriksToChar(ElmtMatriks(Tampilan,5,2)), MatriksToChar(ElmtMatriks(Tampilan,5,3)), MatriksToChar(ElmtMatriks(Tampilan,5,4)), MatriksToChar(ElmtMatriks(Tampilan,5,5)), MatriksToChar(ElmtMatriks(Tampilan,5,6)), MatriksToChar(ElmtMatriks(Tampilan,5,7)), MatriksToChar(ElmtMatriks(Tampilan,5,8)));
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│                │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", MatriksToChar(ElmtMatriks(Tampilan, 6,1)), MatriksToChar(ElmtMatriks(Tampilan,6,2)), MatriksToChar(ElmtMatriks(Tampilan,6,3)), MatriksToChar(ElmtMatriks(Tampilan,6,4)), MatriksToChar(ElmtMatriks(Tampilan,6,5)), MatriksToChar(ElmtMatriks(Tampilan,6,6)), MatriksToChar(ElmtMatriks(Tampilan,6,7)), MatriksToChar(ElmtMatriks(Tampilan,6,8)));
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│                │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", MatriksToChar(ElmtMatriks(Tampilan, 7,1)), MatriksToChar(ElmtMatriks(Tampilan,7,2)), MatriksToChar(ElmtMatriks(Tampilan,7,3)), MatriksToChar(ElmtMatriks(Tampilan,7,4)), MatriksToChar(ElmtMatriks(Tampilan,7,5)), MatriksToChar(ElmtMatriks(Tampilan,7,6)), MatriksToChar(ElmtMatriks(Tampilan,7,7)), MatriksToChar(ElmtMatriks(Tampilan,7,8)));
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│                │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", MatriksToChar(ElmtMatriks(Tampilan, 8,1)), MatriksToChar(ElmtMatriks(Tampilan,8,2)), MatriksToChar(ElmtMatriks(Tampilan,8,3)), MatriksToChar(ElmtMatriks(Tampilan,8,4)), MatriksToChar(ElmtMatriks(Tampilan,8,5)), MatriksToChar(ElmtMatriks(Tampilan,8,6)), MatriksToChar(ElmtMatriks(Tampilan,8,7)), MatriksToChar(ElmtMatriks(Tampilan,8,8)));
    printf("└────────────────┴───┴───┴───┴───┴───┴───┴───┴───┴────────────┘\n");
    printf(" Command : ");
    command= InputKata();
}
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
        fprintf(save, "<%d %d %d>", ElmtQueue(Antrian,i), Prio(ElmtQueue(Antrian,i)), Kesabaran(ElmtQueue(Antrian,i)));
        i++;
    }
    //save food stack
    Kata X;
    while(!IsEmptyStack(Makanan)){
        PopStack(&Makanan, &X);
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
        case 10 :
        y = 'D';
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

void init_ruangan1(){
    (Ruangan1).P1.X = 5;
    (Ruangan1).P1.Y = 8;
    (Ruangan1).P2.X = 8;
    (Ruangan1).P2.Y = 5;
    (Ruangan1).M1.posisi.X = 2;
    (Ruangan1).M1.posisi.Y = 2;
    (Ruangan1).M1.kursi = 4;
    (Ruangan1).M1.NCustomer = 0;
    (Ruangan1).M1.K1.X = (Ruangan1).M1.posisi.X-1;
    (Ruangan1).M1.K1.Y = (Ruangan1).M1.posisi.Y;
    (Ruangan1).M1.K2.X = (Ruangan1).M1.posisi.X+1;
    (Ruangan1).M1.K2.Y = (Ruangan1).M1.posisi.Y;
    (Ruangan1).M1.K3.X = (Ruangan1).M1.posisi.X;
    (Ruangan1).M1.K3.Y = (Ruangan1).M1.posisi.Y-1;
    (Ruangan1).M1.K4.X = (Ruangan1).M1.posisi.X;
    (Ruangan1).M1.K4.Y = (Ruangan1).M1.posisi.Y+1;

    (Ruangan1).M2.posisi.X = 2;
    (Ruangan1).M2.posisi.Y = 7;
    (Ruangan1).M2.kursi = 2;
    (Ruangan1).M2.NCustomer = 0;
    (Ruangan1).M2.K1.X = (Ruangan1).M2.posisi.X-1;
    (Ruangan1).M2.K1.Y = (Ruangan1).M2.posisi.Y;
    (Ruangan1).M2.K2.X = (Ruangan1).M2.posisi.X+1;
    (Ruangan1).M2.K2.Y = (Ruangan1).M2.posisi.Y;

    (Ruangan1).M3.posisi.X = 7;
    (Ruangan1).M3.posisi.Y = 2;
    (Ruangan1).M3.kursi = 4;
    (Ruangan1).M3.NCustomer = 0;
    (Ruangan1).M3.K1.X = (Ruangan1).M3.posisi.X-1;
    (Ruangan1).M3.K1.Y = (Ruangan1).M3.posisi.Y;
    (Ruangan1).M3.K2.X = (Ruangan1).M3.posisi.X+1;
    (Ruangan1).M3.K2.Y = (Ruangan1).M3.posisi.Y;
    (Ruangan1).M3.K3.X = (Ruangan1).M3.posisi.X;
    (Ruangan1).M3.K3.Y = (Ruangan1).M3.posisi.Y-1;
    (Ruangan1).M3.K4.X = (Ruangan1).M3.posisi.X;
    (Ruangan1).M3.K4.Y = (Ruangan1).M3.posisi.Y+1;

    (Ruangan1).M4.posisi.X = 7;
    (Ruangan1).M4.posisi.Y = 7;
    (Ruangan1).M4.kursi = 2;
    (Ruangan1).M4.NCustomer = 0;
    (Ruangan1).M4.K1.X = (Ruangan1).M4.posisi.X-1;
    (Ruangan1).M4.K1.Y = (Ruangan1).M4.posisi.Y;
    (Ruangan1).M4.K2.X = (Ruangan1).M4.posisi.X+1;
    (Ruangan1).M4.K2.Y = (Ruangan1).M4.posisi.Y;
}
void init_ruangan2(){
    (Ruangan2).P1.X = 2;
    (Ruangan2).P1.Y = 1;
    (Ruangan2).P2.X = 8;
    (Ruangan2).P2.Y = 5;
    (Ruangan2).M1.posisi.X = 2;
    (Ruangan2).M1.posisi.Y = 2;
    (Ruangan1).M1.kursi = 4;
    (Ruangan1).M1.NCustomer = 0;
    (Ruangan1).M1.K1.X = (Ruangan1).M1.posisi.X-1;
    (Ruangan1).M1.K1.Y = (Ruangan1).M1.posisi.Y;
    (Ruangan1).M1.K2.X = (Ruangan1).M1.posisi.X+1;
    (Ruangan1).M1.K2.Y = (Ruangan1).M1.posisi.Y;
    (Ruangan1).M1.K3.X = (Ruangan1).M1.posisi.X;
    (Ruangan1).M1.K3.Y = (Ruangan1).M1.posisi.Y-1;
    (Ruangan1).M1.K4.X = (Ruangan1).M1.posisi.X;
    (Ruangan1).M1.K4.Y = (Ruangan1).M1.posisi.Y+1;

    (Ruangan2).M2.posisi.X = 2;
    (Ruangan2).M2.posisi.Y = 7;
    (Ruangan1).M2.kursi = 2;
    (Ruangan1).M2.NCustomer = 0;
    (Ruangan1).M2.K1.X = (Ruangan1).M2.posisi.X-1;
    (Ruangan1).M2.K1.Y = (Ruangan1).M2.posisi.Y;
    (Ruangan1).M2.K2.X = (Ruangan1).M2.posisi.X+1;
    (Ruangan1).M2.K2.Y = (Ruangan1).M2.posisi.Y;

    (Ruangan2).M3.posisi.X = 7;
    (Ruangan2).M3.posisi.Y = 2;
    (Ruangan1).M3.kursi = 4;
    (Ruangan1).M3.NCustomer = 0;
    (Ruangan1).M3.K1.X = (Ruangan1).M3.posisi.X-1;
    (Ruangan1).M3.K1.Y = (Ruangan1).M3.posisi.Y;
    (Ruangan1).M3.K2.X = (Ruangan1).M3.posisi.X+1;
    (Ruangan1).M3.K2.Y = (Ruangan1).M3.posisi.Y;
    (Ruangan1).M3.K3.X = (Ruangan1).M3.posisi.X;
    (Ruangan1).M3.K3.Y = (Ruangan1).M3.posisi.Y-1;
    (Ruangan1).M3.K4.X = (Ruangan1).M3.posisi.X;
    (Ruangan1).M3.K4.Y = (Ruangan1).M3.posisi.Y+1;


    (Ruangan2).M3.NCustomer = 0;
    (Ruangan2).M4.posisi.X = 7;
    (Ruangan2).M4.posisi.Y = 7;
    (Ruangan2).M4.kursi = 2;
    (Ruangan1).M4.NCustomer = 0;
    (Ruangan1).M4.K1.X = (Ruangan1).M4.posisi.X-1;
    (Ruangan1).M4.K1.Y = (Ruangan1).M4.posisi.Y;
    (Ruangan1).M4.K2.X = (Ruangan1).M4.posisi.X+1;
    (Ruangan1).M4.K2.Y = (Ruangan1).M4.posisi.Y;
}
void init_ruangan3(){
    (Ruangan3).P1.X = 2;
    (Ruangan3).P1.Y = 1;
    (Ruangan3).P2.X = 1;
    (Ruangan3).P2.Y = 5;
    (Ruangan3).M1.posisi.X = 2;
    (Ruangan3).M1.posisi.Y = 2;
    (Ruangan1).M1.kursi = 4;
    (Ruangan1).M1.NCustomer = 0;
    (Ruangan1).M1.K1.X = (Ruangan1).M1.posisi.X-1;
    (Ruangan1).M1.K1.Y = (Ruangan1).M1.posisi.Y;
    (Ruangan1).M1.K2.X = (Ruangan1).M1.posisi.X+1;
    (Ruangan1).M1.K2.Y = (Ruangan1).M1.posisi.Y;
    (Ruangan1).M1.K3.X = (Ruangan1).M1.posisi.X;
    (Ruangan1).M1.K3.Y = (Ruangan1).M1.posisi.Y-1;
    (Ruangan1).M1.K4.X = (Ruangan1).M1.posisi.X;
    (Ruangan1).M1.K4.Y = (Ruangan1).M1.posisi.Y+1;

    (Ruangan3).M2.posisi.X = 2;
    (Ruangan3).M2.posisi.Y = 7;
    (Ruangan1).M2.kursi = 2;
    (Ruangan1).M2.NCustomer = 0;
    (Ruangan1).M2.K1.X = (Ruangan1).M2.posisi.X-1;
    (Ruangan1).M2.K1.Y = (Ruangan1).M2.posisi.Y;
    (Ruangan1).M2.K2.X = (Ruangan1).M2.posisi.X+1;
    (Ruangan1).M2.K2.Y = (Ruangan1).M2.posisi.Y;

    (Ruangan3).M2.NCustomer = 0;
    (Ruangan3).M3.posisi.X = 7;
    (Ruangan3).M3.posisi.Y = 2;
    (Ruangan1).M3.kursi = 4;
    (Ruangan1).M3.NCustomer = 0;
    (Ruangan1).M3.K1.X = (Ruangan1).M3.posisi.X-1;
    (Ruangan1).M3.K1.Y = (Ruangan1).M3.posisi.Y;
    (Ruangan1).M3.K2.X = (Ruangan1).M3.posisi.X+1;
    (Ruangan1).M3.K2.Y = (Ruangan1).M3.posisi.Y;
    (Ruangan1).M3.K3.X = (Ruangan1).M3.posisi.X;
    (Ruangan1).M3.K3.Y = (Ruangan1).M3.posisi.Y-1;
    (Ruangan1).M3.K4.X = (Ruangan1).M3.posisi.X;
    (Ruangan1).M3.K4.Y = (Ruangan1).M3.posisi.Y+1;

    (Ruangan3).M3.NCustomer = 0;
    (Ruangan3).M4.posisi.X = 7;
    (Ruangan3).M4.posisi.Y = 7;
    (Ruangan2).M4.kursi = 2;
    (Ruangan1).M4.NCustomer = 0;
    (Ruangan1).M4.K1.X = (Ruangan1).M4.posisi.X-1;
    (Ruangan1).M4.K1.Y = (Ruangan1).M4.posisi.Y;
    (Ruangan1).M4.K2.X = (Ruangan1).M4.posisi.X+1;
    (Ruangan1).M4.K2.Y = (Ruangan1).M4.posisi.Y;
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
    (Dapur).M5.posisi.X = 4;
    (Dapur).M5.posisi.Y = 2;
    (Dapur).M5.bahan = StringToKata("telur");
    (Dapur).M6.posisi.X = 4;
    (Dapur).M6.posisi.Y = 1;
    (Dapur).M6.bahan = StringToKata("ayam");
    (Dapur).M7.posisi.X = 3;
    (Dapur).M7.posisi.Y = 3;
    (Dapur).M7.bahan = StringToKata("es krim");
    (Dapur).M8.posisi.X = 3;
    (Dapur).M8.posisi.Y = 2;
    (Dapur).M8.bahan = StringToKata("pisang");
    (Dapur).M9.posisi.X = 3;
    (Dapur).M9.posisi.Y = 1;
    (Dapur).M9.bahan = StringToKata("stroberi");
    (Dapur).M10.posisi.X = 3;
    (Dapur).M10.posisi.Y = 6;
    (Dapur).M10.bahan = StringToKata("roti");
    (Dapur).M11.posisi.X = 3;
    (Dapur).M11.posisi.Y = 7;
    (Dapur).M11.bahan = StringToKata("patty");
    (Dapur).M12.posisi.X = 3;
    (Dapur).M12.posisi.Y = 8;
    (Dapur).M12.bahan = StringToKata("sosis");
    (Dapur).M13.posisi.X = 4;
    (Dapur).M13.posisi.Y = 6;
    (Dapur).M13.bahan = StringToKata("spaghetti");
    (Dapur).M14.posisi.X = 4;
    (Dapur).M14.posisi.Y = 7;
    (Dapur).M14.bahan = StringToKata("bolognaise");
    (Dapur).M15.posisi.X = 4;
    (Dapur).M15.posisi.Y = 8;
    (Dapur).M15.bahan = StringToKata("keju");
    (Dapur).M16.posisi.X = 7;
    (Dapur).M16.posisi.Y = 8;
    (Dapur).M16.bahan = StringToKata("carbonara");
}
void InitDenah () {
    MakeGraph(4,&Denah);
    CreateEdge(&Denah,1,2,1);
    CreateEdge(&Denah,1,4,2);
    CreateEdge(&Denah,3,4,1);
    CreateEdge(&Denah,2,3,2);
}

void assignMatriks(){
    MakeEmptyMatriks(&Tampilan);
    int i = Pemain.posisi.X;
    int j = Pemain.posisi.Y;
    ElmtMatriks(Tampilan,i,j) = 5;
    if(Pemain.ruangan != 4 ){
        Ruang Ruangan;
        if(Pemain.ruangan == 1) Ruangan = Ruangan1;
        else if(Pemain.ruangan == 2) Ruangan = Ruangan2;
        else if(Pemain.ruangan == 3) Ruangan = Ruangan3;
        i = Ruangan.P1.X; j = Ruangan.P1.Y;
        ElmtMatriks(Tampilan, i,j) = 10;
        i = Ruangan.P2.X; j = Ruangan.P2.Y;
        ElmtMatriks(Tampilan, i,j) = 10;
        if(Ruangan.M1.NCustomer == 0){
            i = Ruangan.M1.K1.X; j = Ruangan.M1.K1.Y;
            ElmtMatriks(Tampilan, i,j) = 6;
            i = Ruangan.M1.K2.X; j = Ruangan.M1.K2.Y;
            ElmtMatriks(Tampilan, i,j) = 6;
            i = Ruangan.M1.K3.X; j = Ruangan.M1.K3.Y;
            ElmtMatriks(Tampilan, i,j) = 6;
            i = Ruangan.M1.K4.X; j = Ruangan.M1.K4.Y;
            ElmtMatriks(Tampilan, i,j) = 6;
        }else if(Ruangan.M1.NCustomer == 2){
            i = Ruangan.M1.K1.X; j = Ruangan.M1.K1.Y;
            ElmtMatriks(Tampilan, i,j) = 7;
            i = Ruangan.M1.K2.X; j = Ruangan.M1.K2.Y;
            ElmtMatriks(Tampilan, i,j) = 7;
            i = Ruangan.M1.K3.X; j = Ruangan.M1.K3.Y;
            ElmtMatriks(Tampilan, i,j) = 6;
            i = Ruangan.M1.K4.X; j = Ruangan.M1.K4.Y;
            ElmtMatriks(Tampilan, i,j) = 6;
        } else if(Ruangan.M1.NCustomer == 4){
            i = Ruangan.M1.K1.X; j = Ruangan.M1.K1.Y;
            ElmtMatriks(Tampilan, i,j) = 7;
            i = Ruangan.M1.K2.X; j = Ruangan.M1.K2.Y;
            ElmtMatriks(Tampilan, i,j) = 7;
            i = Ruangan.M1.K3.X; j = Ruangan.M1.K3.Y;
            ElmtMatriks(Tampilan, i,j) = 7;
            i = Ruangan.M1.K4.X; j = Ruangan.M1.K4.Y;
            ElmtMatriks(Tampilan, i,j) = 7;
        }
    } else{
        i = Dapur.P1.X; j = Dapur.P1.Y;
        ElmtMatriks(Tampilan, i,j) = 10;
        i = Dapur.P2.X; j = Dapur.P2.Y;
        ElmtMatriks(Tampilan, i,j) = 10;
        i = Dapur.T.posisi.X; j = Dapur.T.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 9;
        i = Dapur.M1.posisi.X; j = Dapur.M1.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M2.posisi.X; j = Dapur.M2.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M3.posisi.X; j = Dapur.M3.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M4.posisi.X; j = Dapur.M4.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M5.posisi.X; j = Dapur.M5.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M6.posisi.X; j = Dapur.M6.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M7.posisi.X; j = Dapur.M7.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M8.posisi.X; j = Dapur.M8.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M9.posisi.X; j = Dapur.M9.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M10.posisi.X; j = Dapur.M10.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M11.posisi.X; j = Dapur.M11.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M12.posisi.X; j = Dapur.M12.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M13.posisi.X; j = Dapur.M13.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M14.posisi.X; j = Dapur.M14.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M15.posisi.X; j = Dapur.M15.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M16.posisi.X; j = Dapur.M16.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
    }
}

void init_player(){
    Pemain.money = 500;
    Pemain.life = 100;
    Pemain.time = 0;
    Pemain.posisi.X = 3;
    Pemain.posisi.Y = 5;
    Pemain.ruangan = 1;
}

void init_all(){
    init_dapur;
    init_player;
    init_ruangan1;
    init_ruangan2;
    init_ruangan3;
    InitDenah;
}