//implementasi ADT.h

#include "ADT.h"
#include <stdio.h>

Player Pemain;
JAM RealTime;
TabPesanan Pesanan;
Ruang Ruangan[4];
MATRIKS Tampilan;
RuangDapur Dapur;
Kata command;
Queue Antrian;
Stack Makanan;
Stack Tangan;
Graph Denah;
BinTree Resep;
int IntervalCustomer;

void ExitMessage(boolean SaveGame){
    if (SaveGame) SaveFile();
    printf("Kelas K-1\n\n");
    printf("Credits to : Warteg Bahari\n");
    printf("Bimo Adityarahman Wiraputra/13517004\n");
    printf("Ricky Yuliawan Pohan/13517025\n");
    printf("Ahmad Rizqee Nurhani/13517058\n");
    printf("Naufal Aditya Dirgandhavi/13517064\n");
    printf("Ahmad Rizal Alifio/13517076\n\n");
    printf("Thank you for playing!\n");
}

//ntar bakal dipake di command exit sama exitnya main menu, dia bakal nampilin message kalo keluar game dan bakalan ngesave kalo savegamenya true

void TampilanProgramUtama(){
    printf("\n┌────────────────┬───────────────┬───────────────┬────────────┐\n");
    printf("|");
    OutputKata(Pemain.nama);
    printf("\t         │ Money: %d\t │  Life: %d\t │Time: %d     │\n", Pemain.money, Pemain.life, Pemain.time);
    printf("├────────────────┼───┬───┬───┬───┼───┬───┬───┬───┼────────────┤\n");
    printf("│Waiting Cust    │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │Food Stack  │\n", MatriksToChar(ElmtMatriks(Tampilan, 1,1)), MatriksToChar(ElmtMatriks(Tampilan,1,2)), MatriksToChar(ElmtMatriks(Tampilan,1,3)), MatriksToChar(ElmtMatriks(Tampilan,1,4)), MatriksToChar(ElmtMatriks(Tampilan,1,5)), MatriksToChar(ElmtMatriks(Tampilan,1,6)), MatriksToChar(ElmtMatriks(Tampilan,1,7)), MatriksToChar(ElmtMatriks(Tampilan,1,8)));
    infotypeQueue TempCustomer;
    TempCustomer = NthElmt(&Antrian, 1);
    printf("│ %c %c ", NumToChar(TempCustomer.prio), NumToChar(TempCustomer.info));
    OutputKata(NumToKata(TempCustomer.kesabaran));
    printf("\t\t ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    TempCustomer = NthElmt(&Antrian, 2);
    printf("│ %c %c ", NumToChar(TempCustomer.prio), NumToChar(TempCustomer.info));
    OutputKata(NumToKata(TempCustomer.kesabaran));
    printf("\t\t │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", MatriksToChar(ElmtMatriks(Tampilan, 2,1)), MatriksToChar(ElmtMatriks(Tampilan,2,2)), MatriksToChar(ElmtMatriks(Tampilan,2,3)), MatriksToChar(ElmtMatriks(Tampilan,2,4)), MatriksToChar(ElmtMatriks(Tampilan,2,5)), MatriksToChar(ElmtMatriks(Tampilan,2,6)), MatriksToChar(ElmtMatriks(Tampilan,2,7)), MatriksToChar(ElmtMatriks(Tampilan,2,8)));
    TempCustomer = NthElmt(&Antrian, 3);
    printf("│ %c %c ", NumToChar(TempCustomer.prio), NumToChar(TempCustomer.info));
    OutputKata(NumToKata(TempCustomer.kesabaran));
    printf("\t\t ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    TempCustomer = NthElmt(&Antrian, 4);
    printf("│ %c %c ", NumToChar(TempCustomer.prio), NumToChar(TempCustomer.info));
    OutputKata(NumToKata(TempCustomer.kesabaran));
    printf("\t\t │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", MatriksToChar(ElmtMatriks(Tampilan, 3,1)), MatriksToChar(ElmtMatriks(Tampilan,3,2)), MatriksToChar(ElmtMatriks(Tampilan,3,3)), MatriksToChar(ElmtMatriks(Tampilan,3,4)), MatriksToChar(ElmtMatriks(Tampilan,3,5)), MatriksToChar(ElmtMatriks(Tampilan,3,6)), MatriksToChar(ElmtMatriks(Tampilan,3,7)), MatriksToChar(ElmtMatriks(Tampilan,3,8)));
    TempCustomer = NthElmt(&Antrian, 5);
    printf("│ %c %c ", NumToChar(TempCustomer.prio), NumToChar(TempCustomer.info));
    OutputKata(NumToKata(TempCustomer.kesabaran));
    printf("\t\t ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    TempCustomer = NthElmt(&Antrian, 6);
    printf("│ %c %c ", NumToChar(TempCustomer.prio), NumToChar(TempCustomer.info));
    OutputKata(NumToKata(TempCustomer.kesabaran));
    printf("\t\t │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", MatriksToChar(ElmtMatriks(Tampilan, 4,1)), MatriksToChar(ElmtMatriks(Tampilan,4,2)), MatriksToChar(ElmtMatriks(Tampilan,4,3)), MatriksToChar(ElmtMatriks(Tampilan,4,4)), MatriksToChar(ElmtMatriks(Tampilan,4,5)), MatriksToChar(ElmtMatriks(Tampilan,4,6)), MatriksToChar(ElmtMatriks(Tampilan,4,7)), MatriksToChar(ElmtMatriks(Tampilan,4,8)));
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
    PrintQueue(Antrian);
    TulisIsi(Pesanan);
    TulisStack(Makanan);
    TulisStack(Tangan);
}
//ntar bakal nampilin program utamanya
void SaveFile(){
    int i,j;
    FILE *save;
    char *filename;
    char c;
    scanf("%c", &c);
    printf("Mau disave kemana? ");
    scanf("%m[^\n]%*c", &filename);
    save = fopen(filename, "w");
    fprintf(save, "Waktu Save : ===%d:%d:%d===\n", RealTime.HH, RealTime.MM, RealTime.SS); //Jam real time
    for (i = 1; i <= Pemain.nama.Length; ++i) {
		fprintf(save, "%c", Pemain.nama.TabKata[i]);
	} //nama, Kata
    fprintf(save,"\n");
    fprintf(save, "%d\n", Pemain.life); //<life, int>
    fprintf(save, "%d\n", Pemain.money); //<money, int >
    fprintf(save, "%d\n", Pemain.time); //<time, int >
    fprintf(save, "<%d,%d>\n", Pemain.posisi.X, Pemain.posisi.Y); //<posisi x,y, point(?)>
    //save antrian
    fprintf(save, "QUEUE : \n");
    for(i=Head(Antrian);i<=Tail(Antrian);i++){
        fprintf(save, "<%d,%d,%d>", Info(ElmtQueue(Antrian,i)), Prio(ElmtQueue(Antrian,i)), Kesabaran(ElmtQueue(Antrian,i)));
    }
    fprintf(save,"\n");
    //save food stack
    fprintf(save, "FOOD : \n");
    Kata X;
    while(!IsEmptyStack(Makanan)){
        PopStack(&Makanan, &X);
        fprintf(save, "<");
        for (i = 1; i <= X.Length; ++i) {
	    	fprintf(save, "%c", X.TabKata[i]);
        }
	}
    fprintf(save, "\n");
    fprintf(save, "ORDER : \n");
    //save array pesanan
    for(i=1; i<=GetLastIdx(Pesanan);i++){
        fprintf(save, "%d ", ElmtArray(Pesanan,i).MejaID); //<array order>
        for (j = 1; j <= ElmtArray(Pesanan,i).Menu.Length; ++j) {
	    	fprintf(save, "%c", ElmtArray(Pesanan,i).Menu.TabKata[j]);
        }
        fprintf(save, "\n");
    }
    //save stack tangan 
    fprintf(save, "HAND : \n");
    while(!IsEmptyStack(Tangan)){
        PopStack(&Tangan, &X);
        for (i = 1; i <= X.Length; ++i) {
	    	fprintf(save, "%c", X.TabKata[i]);
        }
    }
    //save ruangan
    for (i = 1; i <= 3; ++i) {
        fprintf(save, "Customer Meja Ruangan %d : \n", i);
        for (j = 1; j <= 4; ++j)
            fprintf(save, "%d\n", Ruangan[i].TTable[j].NCustomer);
    }
    fprintf(save, "#\n");
    fclose(save);
}//bakal ngesave ke file eksternal dgn format yg di tampilan
void LoadFile(){
    char *filename;
    printf("Mau load dari mana? ");
    char c;
    scanf("%c", &c);
    scanf("%m[^\n]%*c", &filename);
    STARTKATA(filename);
    int i=1;
    int x,j;
    
        printf("%d. ", i);
        i++;
        do{
            ADVKATA();
            OutputKata(CKata);
            printf("\n");
            ADV();
        }while(CC!='#');
    printf("Mau di load?[1 untuk Ya] ");
    scanf("%d", &x);

    STARTKATA(filename);
    if(x>1){
        for(j=1;j<=x-1;j++){
            do{
                ADVKATA();
            }while(CC!='#');
        }
    }
    ADVKATA();
    Pemain.nama = CKata;
    ADVInt();
    Pemain.life = CInt;
    ADVInt();
    Pemain.money = CInt;
    ADVInt();
    Pemain.time = CInt;
    ADVKATA();
    ADV();
    ADVInt();
    Pemain.posisi.X = CInt;
    ADV();
    ADVInt();
    Pemain.posisi.Y = CInt;
    ADVKATA();
    ADVKATA();
    ADV();
    i = 1;
    infotypeQueue X;
    while(CC=='<'){
        ADVInt();
        X.info = CInt;
        ADV();
        ADVInt();
        X.prio = CInt;
        ADV();
        ADVInt();
        X.kesabaran = CInt;
        AddQueue(&Antrian, X);
        ADVKATA();
        ADV();
    }
    ADVKATA();
    ADV();
    Kata Y;
    while(CC=='<'){
        ADV();
        ADVKATA();
        Y = CKata;
        PushStack(&Makanan, Y);
        ADV();
    }
    ADVKATA();
    ADV();
    PesananID Z;
    while(CC=='<'){
        ADVInt();
        Z.MejaID = CInt;
        ADV();
        ADVKATA();
        Z.Menu = CKata;
        ADV();
    }
    ADVKATA();
    ADV();
    while(CC=='<'){
        ADV();
        ADVKATA();
        Y = CKata;
        PushStack(&Tangan, Y);
        ADV();
    }
    ADVKATA();
    ADVInt();
    (Ruangan[1]).TTable[1].NCustomer = CInt;
    ADVInt();
    (Ruangan[1]).TTable[2].NCustomer = CInt;
    ADVInt();
    (Ruangan[1]).TTable[3].NCustomer = CInt;
    ADVInt();
    (Ruangan[1]).TTable[4].NCustomer = CInt;
    ADV();
    ADV();
    ADVKATA();
    ADVInt();
    (Ruangan[2]).TTable[1].NCustomer = CInt;
    ADVInt();
    (Ruangan[2]).TTable[2].NCustomer = CInt;
    ADVInt();
    (Ruangan[2]).TTable[3].NCustomer = CInt;
    ADVInt();
    (Ruangan[2]).TTable[4].NCustomer = CInt;
    ADV();
    ADVKATA();
    ADVInt();
    (Ruangan[1]).TTable[1].NCustomer = CInt;
    ADVInt();
    (Ruangan[1]).TTable[2].NCustomer = CInt;
    ADVInt();
    (Ruangan[1]).TTable[3].NCustomer = CInt;
    ADVInt();
    (Ruangan[1]).TTable[4].NCustomer = CInt;
    ADV();
    ADV();
    //nampilin daftar apa aja yg bisa diload, ntar playernya milih terus ngeload statnya dan diassign ke variabel
}
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

void init_Ruangan1 (){
    (Ruangan[1]).P1.X = 5;
    (Ruangan[1]).P1.Y = 8;
    (Ruangan[1]).P2.X = 8;
    (Ruangan[1]).P2.Y = 5;
    (Ruangan[1]).TTable[1].posisi.X = 2;
    (Ruangan[1]).TTable[1].posisi.Y = 2;
    (Ruangan[1]).TTable[1].kursi = 4;
    (Ruangan[1]).TTable[1].NCustomer = 0;
    (Ruangan[1]).TTable[1].TChair[1].X = (Ruangan[1]).TTable[1].posisi.X;
    (Ruangan[1]).TTable[1].TChair[1].Y = (Ruangan[1]).TTable[1].posisi.Y-1;
    (Ruangan[1]).TTable[1].TChair[2].X = (Ruangan[1]).TTable[1].posisi.X;
    (Ruangan[1]).TTable[1].TChair[2].Y = (Ruangan[1]).TTable[1].posisi.Y+1;
    (Ruangan[1]).TTable[1].TChair[3].X = (Ruangan[1]).TTable[1].posisi.X-1;
    (Ruangan[1]).TTable[1].TChair[3].Y = (Ruangan[1]).TTable[1].posisi.Y;
    (Ruangan[1]).TTable[1].TChair[4].X = (Ruangan[1]).TTable[1].posisi.X+1;
    (Ruangan[1]).TTable[1].TChair[4].Y = (Ruangan[1]).TTable[1].posisi.Y;

    (Ruangan[1]).TTable[2].posisi.X = 2;
    (Ruangan[1]).TTable[2].posisi.Y = 7;
    (Ruangan[1]).TTable[2].kursi = 2;
    (Ruangan[1]).TTable[2].NCustomer = 0;
    (Ruangan[1]).TTable[2].TChair[1].X = (Ruangan[1]).TTable[2].posisi.X;
    (Ruangan[1]).TTable[2].TChair[1].Y = (Ruangan[1]).TTable[2].posisi.Y-1;
    (Ruangan[1]).TTable[2].TChair[2].X = (Ruangan[1]).TTable[2].posisi.X;
    (Ruangan[1]).TTable[2].TChair[2].Y = (Ruangan[1]).TTable[2].posisi.Y+1;

    (Ruangan[1]).TTable[3].posisi.X = 7;
    (Ruangan[1]).TTable[3].posisi.Y = 2;
    (Ruangan[1]).TTable[3].kursi = 4;
    (Ruangan[1]).TTable[3].NCustomer = 0;
    (Ruangan[1]).TTable[3].TChair[1].X = (Ruangan[1]).TTable[3].posisi.X;
    (Ruangan[1]).TTable[3].TChair[1].Y = (Ruangan[1]).TTable[3].posisi.Y-1;
    (Ruangan[1]).TTable[3].TChair[2].X = (Ruangan[1]).TTable[3].posisi.X;
    (Ruangan[1]).TTable[3].TChair[2].Y = (Ruangan[1]).TTable[3].posisi.Y+1;
    (Ruangan[1]).TTable[3].TChair[3].X = (Ruangan[1]).TTable[3].posisi.X-1;
    (Ruangan[1]).TTable[3].TChair[3].Y = (Ruangan[1]).TTable[3].posisi.Y;
    (Ruangan[1]).TTable[3].TChair[4].X = (Ruangan[1]).TTable[3].posisi.X+1;
    (Ruangan[1]).TTable[3].TChair[4].Y = (Ruangan[1]).TTable[3].posisi.Y;

    (Ruangan[1]).TTable[4].posisi.X = 7;
    (Ruangan[1]).TTable[4].posisi.Y = 7;
    (Ruangan[1]).TTable[4].kursi = 2;
    (Ruangan[1]).TTable[4].NCustomer = 0;
    (Ruangan[1]).TTable[4].TChair[1].X = (Ruangan[1]).TTable[4].posisi.X;
    (Ruangan[1]).TTable[4].TChair[1].Y = (Ruangan[1]).TTable[4].posisi.Y-1;
    (Ruangan[1]).TTable[4].TChair[2].X = (Ruangan[1]).TTable[4].posisi.X;
    (Ruangan[1]).TTable[4].TChair[2].Y = (Ruangan[1]).TTable[4].posisi.Y+1;
}
void init_Ruangan2 (){
    (Ruangan[2]).P1.X = 4;
    (Ruangan[2]).P1.Y = 1;
    (Ruangan[2]).P2.X = 8;
    (Ruangan[2]).P2.Y = 5;
    (Ruangan[2]).TTable[1].posisi.X = 2;
    (Ruangan[2]).TTable[1].posisi.Y = 2;
    (Ruangan[2]).TTable[1].kursi = 4;
    (Ruangan[2]).TTable[1].NCustomer = 0;
    (Ruangan[2]).TTable[1].TChair[1].X = (Ruangan[2]).TTable[1].posisi.X;
    (Ruangan[2]).TTable[1].TChair[1].Y = (Ruangan[2]).TTable[1].posisi.Y-1;
    (Ruangan[2]).TTable[1].TChair[2].X = (Ruangan[2]).TTable[1].posisi.X;
    (Ruangan[2]).TTable[1].TChair[2].Y = (Ruangan[2]).TTable[1].posisi.Y+1;
    (Ruangan[2]).TTable[1].TChair[3].X = (Ruangan[2]).TTable[1].posisi.X-1;
    (Ruangan[2]).TTable[1].TChair[3].Y = (Ruangan[2]).TTable[1].posisi.Y;
    (Ruangan[2]).TTable[1].TChair[4].X = (Ruangan[2]).TTable[1].posisi.X+1;
    (Ruangan[2]).TTable[1].TChair[4].Y = (Ruangan[2]).TTable[1].posisi.Y;

    (Ruangan[2]).TTable[2].posisi.X = 2;
    (Ruangan[2]).TTable[2].posisi.Y = 7;
    (Ruangan[2]).TTable[2].kursi = 2;
    (Ruangan[2]).TTable[2].NCustomer = 0;
    (Ruangan[2]).TTable[2].TChair[1].X = (Ruangan[2]).TTable[2].posisi.X;
    (Ruangan[2]).TTable[2].TChair[1].Y = (Ruangan[2]).TTable[2].posisi.Y-1;
    (Ruangan[2]).TTable[2].TChair[2].X = (Ruangan[2]).TTable[2].posisi.X;
    (Ruangan[2]).TTable[2].TChair[2].Y = (Ruangan[2]).TTable[2].posisi.Y+1;

    (Ruangan[2]).TTable[3].posisi.X = 7;
    (Ruangan[2]).TTable[3].posisi.Y = 2;
    (Ruangan[2]).TTable[3].kursi = 4;
    (Ruangan[2]).TTable[3].NCustomer = 0;
    (Ruangan[2]).TTable[3].TChair[1].X = (Ruangan[2]).TTable[3].posisi.X;
    (Ruangan[2]).TTable[3].TChair[1].Y = (Ruangan[2]).TTable[3].posisi.Y-1;
    (Ruangan[2]).TTable[3].TChair[2].X = (Ruangan[2]).TTable[3].posisi.X;
    (Ruangan[2]).TTable[3].TChair[2].Y = (Ruangan[2]).TTable[3].posisi.Y+1;
    (Ruangan[2]).TTable[3].TChair[3].X = (Ruangan[2]).TTable[3].posisi.X-1;
    (Ruangan[2]).TTable[3].TChair[3].Y = (Ruangan[2]).TTable[3].posisi.Y;
    (Ruangan[2]).TTable[3].TChair[4].X = (Ruangan[2]).TTable[3].posisi.X+1;
    (Ruangan[2]).TTable[3].TChair[4].Y = (Ruangan[2]).TTable[3].posisi.Y;

    (Ruangan[2]).TTable[4].posisi.X = 7;
    (Ruangan[2]).TTable[4].posisi.Y = 7;
    (Ruangan[2]).TTable[4].kursi = 2;
    (Ruangan[2]).TTable[4].NCustomer = 0;
    (Ruangan[2]).TTable[4].TChair[1].X = (Ruangan[2]).TTable[4].posisi.X;
    (Ruangan[2]).TTable[4].TChair[1].Y = (Ruangan[2]).TTable[4].posisi.Y-1;
    (Ruangan[2]).TTable[4].TChair[2].X = (Ruangan[2]).TTable[4].posisi.X;
    (Ruangan[2]).TTable[4].TChair[2].Y = (Ruangan[2]).TTable[4].posisi.Y+1;
}
void init_Ruangan3 (){
    (Ruangan[3]).P1.X = 4;
    (Ruangan[3]).P1.Y = 1;
    (Ruangan[3]).P2.X = 1;
    (Ruangan[3]).P2.Y = 5;
    (Ruangan[3]).TTable[1].posisi.X = 2;
    (Ruangan[3]).TTable[1].posisi.Y = 2;
    (Ruangan[3]).TTable[1].kursi = 4;
    (Ruangan[3]).TTable[1].NCustomer = 0;
    (Ruangan[3]).TTable[1].TChair[1].X = (Ruangan[3]).TTable[1].posisi.X;
    (Ruangan[3]).TTable[1].TChair[1].Y = (Ruangan[3]).TTable[1].posisi.Y-1;
    (Ruangan[3]).TTable[1].TChair[2].X = (Ruangan[3]).TTable[1].posisi.X;
    (Ruangan[3]).TTable[1].TChair[2].Y = (Ruangan[3]).TTable[1].posisi.Y+1;
    (Ruangan[3]).TTable[1].TChair[3].X = (Ruangan[3]).TTable[1].posisi.X-1;
    (Ruangan[3]).TTable[1].TChair[3].Y = (Ruangan[3]).TTable[1].posisi.Y;
    (Ruangan[3]).TTable[1].TChair[4].X = (Ruangan[3]).TTable[1].posisi.X+1;
    (Ruangan[3]).TTable[1].TChair[4].Y = (Ruangan[3]).TTable[1].posisi.Y;

    (Ruangan[3]).TTable[2].posisi.X = 2;
    (Ruangan[3]).TTable[2].posisi.Y = 7;
    (Ruangan[3]).TTable[2].kursi = 2;
    (Ruangan[3]).TTable[2].NCustomer = 0;
    (Ruangan[3]).TTable[2].TChair[1].X = (Ruangan[3]).TTable[2].posisi.X;
    (Ruangan[3]).TTable[2].TChair[1].Y = (Ruangan[3]).TTable[2].posisi.Y-1;
    (Ruangan[3]).TTable[2].TChair[2].X = (Ruangan[3]).TTable[2].posisi.X;
    (Ruangan[3]).TTable[2].TChair[2].Y = (Ruangan[3]).TTable[2].posisi.Y+1;

    (Ruangan[3]).TTable[2].NCustomer = 0;
    (Ruangan[3]).TTable[3].posisi.X = 7;
    (Ruangan[3]).TTable[3].posisi.Y = 2;
    (Ruangan[3]).TTable[3].kursi = 4;
    (Ruangan[3]).TTable[3].NCustomer = 0;
    (Ruangan[3]).TTable[3].TChair[1].X = (Ruangan[3]).TTable[3].posisi.X;
    (Ruangan[3]).TTable[3].TChair[1].Y = (Ruangan[3]).TTable[3].posisi.Y-1;
    (Ruangan[3]).TTable[3].TChair[2].X = (Ruangan[3]).TTable[3].posisi.X;
    (Ruangan[3]).TTable[3].TChair[2].Y = (Ruangan[3]).TTable[3].posisi.Y+1;
    (Ruangan[3]).TTable[3].TChair[3].X = (Ruangan[3]).TTable[3].posisi.X-1;
    (Ruangan[3]).TTable[3].TChair[3].Y = (Ruangan[3]).TTable[3].posisi.Y;
    (Ruangan[3]).TTable[3].TChair[4].X = (Ruangan[3]).TTable[3].posisi.X+1;
    (Ruangan[3]).TTable[3].TChair[4].Y = (Ruangan[3]).TTable[3].posisi.Y;

    (Ruangan[3]).TTable[3].NCustomer = 0;
    (Ruangan[3]).TTable[4].posisi.X = 7;
    (Ruangan[3]).TTable[4].posisi.Y = 7;
    (Ruangan[3]).TTable[4].kursi = 2;
    (Ruangan[3]).TTable[4].NCustomer = 0;
    (Ruangan[3]).TTable[4].TChair[1].X = (Ruangan[3]).TTable[4].posisi.X;
    (Ruangan[3]).TTable[4].TChair[1].Y = (Ruangan[3]).TTable[4].posisi.Y-1;
    (Ruangan[3]).TTable[4].TChair[2].X = (Ruangan[3]).TTable[4].posisi.X;
    (Ruangan[3]).TTable[4].TChair[2].Y = (Ruangan[3]).TTable[4].posisi.Y+1;
}
void init_dapur(){
    (Dapur).P1.X = 5;
    (Dapur).P1.Y = 8;
    (Dapur).P2.X = 1;
    (Dapur).P2.Y = 5;
    (Dapur).T.posisi.X = 1;
    (Dapur).T.posisi.Y = 8;
    CreateEmptyStack(&(Dapur).T.bahan);
    (Dapur).M[1].posisi.X = 7;
    (Dapur).M[1].posisi.Y = 4;
    (Dapur).M[1].bahan = StringToKata("piring");
    (Dapur).M[2].posisi.X = 7;
    (Dapur).M[2].posisi.Y = 3;
    (Dapur).M[2].bahan = StringToKata("sendok");
    (Dapur).M[3].posisi.X = 7;
    (Dapur).M[3].posisi.Y = 5;
    (Dapur).M[3].bahan = StringToKata("garpu");
    (Dapur).M[4].posisi.X = 4;
    (Dapur).M[4].posisi.Y = 3;
    (Dapur).M[4].bahan = StringToKata("nasi");
    (Dapur).M[5].posisi.X = 4;
    (Dapur).M[5].posisi.Y = 2;
    (Dapur).M[5].bahan = StringToKata("telur");
    (Dapur).M[6].posisi.X = 4;
    (Dapur).M[6].posisi.Y = 1;
    (Dapur).M[6].bahan = StringToKata("ayam");
    (Dapur).M[7].posisi.X = 3;
    (Dapur).M[7].posisi.Y = 3;
    (Dapur).M[7].bahan = StringToKata("es krim");
    (Dapur).M[8].posisi.X = 3;
    (Dapur).M[8].posisi.Y = 2;
    (Dapur).M[8].bahan = StringToKata("pisang");
    (Dapur).M[9].posisi.X = 3;
    (Dapur).M[9].posisi.Y = 1;
    (Dapur).M[9].bahan = StringToKata("stroberi");
    (Dapur).M[10].posisi.X = 3;
    (Dapur).M[10].posisi.Y = 6;
    (Dapur).M[10].bahan = StringToKata("roti");
    (Dapur).M[11].posisi.X = 3;
    (Dapur).M[11].posisi.Y = 7;
    (Dapur).M[11].bahan = StringToKata("patty");
    (Dapur).M[12].posisi.X = 3;
    (Dapur).M[12].posisi.Y = 8;
    (Dapur).M[12].bahan = StringToKata("sosis");
    (Dapur).M[13].posisi.X = 4;
    (Dapur).M[13].posisi.Y = 6;
    (Dapur).M[13].bahan = StringToKata("spaghetti");
    (Dapur).M[14].posisi.X = 4;
    (Dapur).M[14].posisi.Y = 7;
    (Dapur).M[14].bahan = StringToKata("bolognaise");
    (Dapur).M[15].posisi.X = 4;
    (Dapur).M[15].posisi.Y = 8;
    (Dapur).M[15].bahan = StringToKata("keju");
    (Dapur).M[16].posisi.X = 7;
    (Dapur).M[16].posisi.Y = 8;
    (Dapur).M[16].bahan = StringToKata("carbonara");
}
void InitDenah () {
    MakeGraph(4,&Denah);
    CreateEdge(&Denah,1,2,1);
    CreateEdge(&Denah,1,4,2);
    CreateEdge(&Denah,3,4,1);
    CreateEdge(&Denah,2,3,2);
}

void assignMatriks(){
    int i,j;
    i = Pemain.posisi.X;
    j = Pemain.posisi.Y;
    Tampilan.NBrsEff = Tampilan.NKolEff = 8;
    MakeEmptyMatriks(&Tampilan);
    ElmtMatriks(Tampilan,i,j) = 5;
    if(Pemain.ruangan != 4 ){
        Ruang TempRuangan;
        if(Pemain.ruangan == 1) TempRuangan = Ruangan[1];
        else if(Pemain.ruangan == 2) TempRuangan = Ruangan[2];
        else if(Pemain.ruangan == 3) TempRuangan = Ruangan[3];
        i = TempRuangan.P1.X; j = TempRuangan.P1.Y;
        ElmtMatriks(Tampilan, i,j) = 10;
        i = TempRuangan.P2.X; j = TempRuangan.P2.Y;
        ElmtMatriks(Tampilan, i,j) = 10;
        for(int m=1;m<=4;m++){
            i=TempRuangan.TTable[m].posisi.X;j=TempRuangan.TTable[m].posisi.Y;
            ElmtMatriks(Tampilan,i,j) =m; 
            if(TempRuangan.TTable[m].NCustomer == 0){
                i = TempRuangan.TTable[m].TChair[1].X; j = TempRuangan.TTable[m].TChair[1].Y;
                ElmtMatriks(Tampilan, i,j) = 6;
                i = TempRuangan.TTable[m].TChair[2].X; j = TempRuangan.TTable[m].TChair[2].Y;
                ElmtMatriks(Tampilan, i,j) = 6;
                i = TempRuangan.TTable[m].TChair[3].X; j = TempRuangan.TTable[m].TChair[3].Y;
                ElmtMatriks(Tampilan, i,j) = 6;
                i = TempRuangan.TTable[m].TChair[4].X; j = TempRuangan.TTable[m].TChair[4].Y;
                ElmtMatriks(Tampilan, i,j) = 6;
            }else if(TempRuangan.TTable[m].NCustomer == 2){
                i = TempRuangan.TTable[m].TChair[1].X; j = TempRuangan.TTable[m].TChair[1].Y;
                ElmtMatriks(Tampilan, i,j) = 7;
                i = TempRuangan.TTable[m].TChair[2].X; j = TempRuangan.TTable[m].TChair[2].Y;
                ElmtMatriks(Tampilan, i,j) = 7;
                i = TempRuangan.TTable[m].TChair[3].X; j = TempRuangan.TTable[m].TChair[3].Y;
                ElmtMatriks(Tampilan, i,j) = 6;
                i = TempRuangan.TTable[m].TChair[4].X; j = TempRuangan.TTable[m].TChair[4].Y;
                ElmtMatriks(Tampilan, i,j) = 6;
            } else if(TempRuangan.TTable[m].NCustomer == 4){
                i = TempRuangan.TTable[m].TChair[1].X; j = TempRuangan.TTable[m].TChair[1].Y;
                ElmtMatriks(Tampilan, i,j) = 7;
                i = TempRuangan.TTable[m].TChair[2].X; j = TempRuangan.TTable[m].TChair[2].Y;
                ElmtMatriks(Tampilan, i,j) = 7;
                i = TempRuangan.TTable[m].TChair[3].X; j = TempRuangan.TTable[m].TChair[3].Y;
                ElmtMatriks(Tampilan, i,j) = 7;
                i = TempRuangan.TTable[m].TChair[4].X; j = TempRuangan.TTable[m].TChair[4].Y;
                ElmtMatriks(Tampilan, i,j) = 7;
            }
        }
    } else{
        i = Dapur.P1.X; j = Dapur.P1.Y;
        ElmtMatriks(Tampilan, i,j) = 10;
        i = Dapur.P2.X; j = Dapur.P2.Y;
        ElmtMatriks(Tampilan, i,j) = 10;
        i = Dapur.T.posisi.X; j = Dapur.T.posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 9;
        i = Dapur.M[1].posisi.X; j = Dapur.M[1].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M[2].posisi.X; j = Dapur.M[2].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M[3].posisi.X; j = Dapur.M[3].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M[4].posisi.X; j = Dapur.M[4].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M[5].posisi.X; j = Dapur.M[5].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M[6].posisi.X; j = Dapur.M[6].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M[7].posisi.X; j = Dapur.M[7].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M[8].posisi.X; j = Dapur.M[8].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M[9].posisi.X; j = Dapur.M[9].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M[10].posisi.X; j = Dapur.M[10].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M[11].posisi.X; j = Dapur.M[11].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M[12].posisi.X; j = Dapur.M[12].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M[13].posisi.X; j = Dapur.M[13].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M[14].posisi.X; j = Dapur.M[14].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M[15].posisi.X; j = Dapur.M[15].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        i = Dapur.M[16].posisi.X; j = Dapur.M[16].posisi.Y;
        ElmtMatriks(Tampilan, i,j) = 8;
        
    }
}

void init_player(){
    Pemain.money = 500;
    Pemain.life = 3;
    Pemain.time = 0;
    Pemain.posisi.X = 3;
    Pemain.posisi.Y = 5;
    Pemain.ruangan = 1;
}

void init_all(){
    init_dapur();
    init_player();
    init_Ruangan1();
    init_Ruangan2();
    init_Ruangan3();
    InitDenah();
    
    CreateEmptyQueue(&Antrian, MaxEl);
    CreateEmptyStack(&Makanan);
    CreateEmptyStack(&Tangan);
    CreateEmptyStack(&Dapur.T.bahan);
    infotypeQueue X;
    X.info = 4;
    X.prio = 2;
    X.kesabaran =30;
    AddQueue(&Antrian,X);
}

int GetRandomArrival(){ 
    JAM RealTime = CurrentTime();

    srand(RealTime.SS); 
    return (rand() % 27)+15; 
} 
 
int GetRandomNCust(){ 
    JAM RealTime = CurrentTime();

    srand(RealTime.SS); 
    if ((rand() % 2) == 0) { 
        return 2; 
    } else { /* rand() mod 2 == 1 */ 
        return 4; 
    } 
} 
 
int GetRandomPrio(){ 
    JAM RealTime = CurrentTime();

    srand(RealTime.SS); 
    if ((rand() % 3) == 2) { 
        return 1; 
    } else if ((rand() % 3) == 1) { 
        return 2; 
    } else { /* mod 3 == 0 */ 
        return 3; 
    } 
} 

int GetRandomMenu(){
    JAM RealTime = CurrentTime();

    srand(RealTime.SS);
    return ((rand() % 8) + 1 );   
}

Kata GetRandomMenuName(int MenuIdx){
    switch(MenuIdx) {
        case 1  : 
            return StringToKata("banana split"); break;
        case 2  :
            return StringToKata("sundae"); break;
        case 3  :
            return StringToKata("nasi telur dadar"); break;
        case 4  :
            return StringToKata("nasi ayam goreng"); break;
        case 5  :
            return StringToKata("burger"); break;
        case 6  :
            return StringToKata("hot dog"); break;
        case 7  :
            return StringToKata("spaghetti bolognaise"); break;
        case 8  :
            return StringToKata("spaghetti carbonara"); break;
    }
}

void RandomizerQueue(int *Interval){
    /* Kamus Lokal */
    infotypeQueue TamuDatang;
    /* Algoritma */
    if(*Interval == 0){
        TamuDatang.prio = GetRandomPrio();
        TamuDatang.info = GetRandomNCust();
        switch (TamuDatang.prio) {
            case 1  :
                TamuDatang.kesabaran = 30; break;
            case 2  :
                TamuDatang.kesabaran = 25; break;
            case 3  :
                TamuDatang.kesabaran = 20; break;
        }
        AddQueue(&Antrian,TamuDatang);

        (*Interval) = GetRandomArrival();
    } else {
        *Interval--;
    }
}