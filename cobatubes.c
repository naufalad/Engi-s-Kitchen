//kemungkinan dari command
#include "cobatubes.h"

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

void GU()//Pemain adalah lokasi dari Pemain saat itu,Time adalah waktu yag telah lewat
//Command ini adalah singkatan dari ‘Go Up’, sehingga posisi Player berpindah ke
//atas
{
    if (Pemain.posisi.X == 1) {
        if (EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P2)||(EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P1))||EQ(Pemain.posisi, Dapur.P1)||EQ(Pemain.posisi, Dapur.P2))
            GantiRuangan();
        else {
            printf("Tidak dapat menembus dinding!\n");
        }
    } else {
        Pemain.posisi.X--;
        int i,j;
        if(Pemain.ruangan!=4){
            for (i = 1; i <= 4; ++i)
                for (j = 1; j <= Ruangan[Pemain.ruangan].TTable[i].kursi; ++j)
                    if (EQ(Pemain.posisi, Ruangan[Pemain.ruangan].TTable[i].TChair[j])||EQ(Pemain.posisi, Ruangan[Pemain.ruangan].TTable[i].posisi)) {
                        Pemain.posisi.X++;
                        printf("Tidak dapat menembus meja dan kursi!\n");
                    }
        } else{
            for (i = 1; i <= 16; ++i)
                if (EQ(Pemain.posisi, Dapur.M[i].posisi)||EQ(Pemain.posisi, Dapur.T.posisi)) {
                    Pemain.posisi.X++;
                    printf("Tidak dapat menembus meja dan tray!\n");
                }
        }
    }
    printf("%d  ", Pemain.ruangan);
    TulisPOINT(Pemain.posisi);
    UpdateTimePatience();
}
void GD()
/*Command ini adalah singkatan dari ‘Go Down’, sehingga posisi Player berpindah
ke bawah*/
{
    if (Pemain.posisi.X == 8) {
        if (EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P2)||EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P1)||EQ(Pemain.posisi, Dapur.P1)||EQ(Pemain.posisi, Dapur.P2))
            GantiRuangan();
        else {
            printf("Tidak dapat menembus!\n");
        }
    } else {
        Pemain.posisi.X++;
        int i,j;
        if(Pemain.ruangan!=4){
            for (i = 1; i <= 4; ++i)
                for (j = 1; j <= Ruangan[Pemain.ruangan].TTable[i].kursi; ++j)
                    if (EQ(Pemain.posisi, Ruangan[Pemain.ruangan].TTable[i].TChair[j])||EQ(Pemain.posisi, Ruangan[Pemain.ruangan].TTable[i].posisi)) {
                        Pemain.posisi.X--;
                        printf("Tidak dapat menembus meja dan kursi!\n");
                    }
        } else{
            for (i = 1; i <= 16; ++i)
                if (EQ(Pemain.posisi, Dapur.M[i].posisi)||EQ(Pemain.posisi, Dapur.T.posisi)) {
                    Pemain.posisi.X--;
                    printf("Tidak dapat menembus meja dan tray!\n");
                }
        }
    }
    printf("%d  ", Pemain.ruangan);
    TulisPOINT(Pemain.posisi);
    UpdateTimePatience();
}

void GL()
/*Command ini adalah singkatan dari ‘Go Left’, sehingga posisi Player berpindah
ke kiri*/
{
    if (Pemain.posisi.Y == 1) {
        if (EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P1)||EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P2)||EQ(Pemain.posisi, Dapur.P1)||EQ(Pemain.posisi, Dapur.P2))
            GantiRuangan();
        else {
            printf("Tidak dapat menembus dinding!\n");
        }
    } else {
        Pemain.posisi.Y--;
        int i,j;
        if(Pemain.ruangan!=4){
            for (i = 1; i <= 4; ++i)
                for (j = 1; j <= Ruangan[Pemain.ruangan].TTable[i].kursi; ++j)
                    if (EQ(Pemain.posisi, Ruangan[Pemain.ruangan].TTable[i].TChair[j])||EQ(Pemain.posisi, Ruangan[Pemain.ruangan].TTable[i].posisi)) {
                        Pemain.posisi.Y++;
                        printf("Tidak dapat menembus meja dan kursi!\n");
                    }
        } else{
            for (i = 1; i <= 16; ++i)
                if (EQ(Pemain.posisi, Dapur.M[i].posisi)||EQ(Pemain.posisi, Dapur.T.posisi)) {
                    Pemain.posisi.Y++;
                    printf("Tidak dapat menembus meja dan kursi!\n");
                }
        }
    }
    printf("%d  ", Pemain.ruangan);
    TulisPOINT(Pemain.posisi);
    UpdateTimePatience();
}
void GR()
/*Command ini adalah singkatan dari ‘Go Right’, sehingga posisi Player berpindah
kekanan.*/
{
    if (Pemain.posisi.Y == 8) {
        if (EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P1)||EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P2)||EQ(Pemain.posisi, Dapur.P1)||EQ(Pemain.posisi, Dapur.P2))
            GantiRuangan();
        else {
            printf("Tidak dapat menembus dinding!\n");
        }
    } else {
        Pemain.posisi.Y++;
        int i,j;
        if(Pemain.ruangan!=4){
            for (i = 1; i <= 4; ++i)
                for (j = 1; j <= Ruangan[Pemain.ruangan].TTable[i].kursi; ++j)
                    if (EQ(Pemain.posisi, Ruangan[Pemain.ruangan].TTable[i].TChair[j])||EQ(Pemain.posisi, Ruangan[Pemain.ruangan].TTable[i].posisi)) {
                        Pemain.posisi.Y--;
                        printf("Tidak dapat menembus meja dan kursi!\n");
                    }
        } else{
            for (i = 1; i <= 16; ++i)
                if (EQ(Pemain.posisi, Dapur.M[i].posisi)||EQ(Pemain.posisi, Dapur.T.posisi)) {
                    Pemain.posisi.Y--;
                    printf("Tidak dapat menembus meja dan tray!\n");
                }
        }
    }
    printf("%d  ", Pemain.ruangan);
    TulisPOINT(Pemain.posisi);
    UpdateTimePatience();
}

void ORDER()//Pemain bisa ambil brp banyak order?
/*Command ini digunakan untuk mengambil order dari meja yang bersebelahan
dengan Pemain*/
{
    /*kamus*/
    int TableNo;
    int orderidx;
    /*algoritma*/
    TableNo = IsNearTable();

    if ((Ruangan[Pemain.ruangan].TTable[TableNo].NCustomer == 0) || (TableNo == 0) || (Ruangan[Pemain.ruangan].TTable[TableNo].isOrderTaken)) {
        /* Kalau di meja gaada orang, atau ga deket meja, atau mejanya udah diambil orderannya */
        printf("Ngambil order siapa goblok\n");
        printf("Ericko Lim aja lebih pinter dari maneh\n");
    } else {
        orderidx = GetRandomMenu();
        Pesanan.TI[Neff(Pesanan)+1].Room = Pemain.ruangan;
        Pesanan.TI[Neff(Pesanan)+1].MejaID = TableNo;
        Pesanan.TI[Neff(Pesanan)+1].Kesabaran = 40;
        Pesanan.TI[Neff(Pesanan)+1].Menu = GetRandomMenuName(orderidx);
    }
}
void PUT()
/*Command ini digunakan untuk menaruh makanan di hand ke nampan*/
/*Command ini digunakan untuk menaruh makanan di hand ke nampan*/
{
  /*kamus*/
  Kata isi;
  BinTree R;
  /*Algoritma*/
  if(Pemain.posisi.X - 1 == Dapur.T.posisi.X || Pemain.posisi.Y + 1 == Dapur.T.posisi.Y)
  {
    R = Resep;
    while(!IsEmptyStack(Tangan))
    {
      PopStack(&Tangan,&isi);
      PushStack(&Dapur.T.bahan,isi);
    }
    PopStack(&Dapur.T.bahan,&isi);
    while(!IsEmptyStack(Dapur.T.bahan))
    {
      PopStack(&Dapur.T.bahan,&isi);
      if(IsEqKata(isi,Akar(Left(R))))
      {
        R = Left(R);
      }
      else if(IsEqKata(isi,Akar(Right(R))))
      {
        R = Right(R);
      }
      else
      {
        CH();
      }
    }
    R = Left(R);
    if(IsTreeOneElmt(R))
    {
      PushStack(&Makanan,Akar(R));
    }
  }
}
void TAKE()
/*Command ini digunakan untuk mengambil bahan yang bersebelahan dengan
Pemain*/
{
  /*kamus*/

  /*Algoritma*/
   MejaDapur M = IsNearKitchenTable();
   Kata bahan;
   if(!compareKata(M.bahan, "")) bahan = M.bahan;
   else printf("Anda sedang tidak dekat dengan meja apapun!");
   PushStack(&Tangan,bahan);
}
void CH()
/*Command ini digunakan untuk membuang seluruh bahan makanan yang
terdapat di tangan Pemain*/
{
  /*kamus*/

  /*Algoritma*/
  CreateEmptyStack(&Tangan);
}
void CT()
/*Command ini digunakan untuk membuang seluruh makanan yang berada di
dalam tray*/
{
  /*kamus*/

  /*Algoritma*/
  CreateEmptyStack(&Makanan);
}

int IsNearTable () {
    if (Pemain.ruangan <= 3) {
        int i,j;
        for (i = 1; i <= 4; ++i) {
            for (j = 1; j <= Ruangan[Pemain.ruangan].TTable[i].kursi; ++j)
                if (AdjPOINT(Pemain.posisi, Ruangan[Pemain.ruangan].TTable[i].TChair[j])) return i;
        }
    }
    return 0;
}

void PLACE()
/*Command ini digunakan untuk menaruh pelanggan di meja dan kosong.
Pelanggan yang ditaruh adalah pelanggan pada top of queue*/
{
    if (IsEmptyQueue(Antrian)) {
        printf("Tidak ada tamu yang menunggu\n");
        return;
    }
    int i = IsNearTable();
    if (i == 0) {
        printf("Anda harus berada dekat meja makan\n");
        return;
    }
    if (Ruangan[Pemain.ruangan].TTable[i].kursi < InfoHead(Antrian).info) {
        printf("Banyak kursi tidak memenuhi\n");
        return;
    }
    if (Ruangan[Pemain.ruangan].TTable[i].NCustomer > 0) {
        printf("Tempat sudah ditempati\n");
        return;
    }
    Ruangan[Pemain.ruangan].TTable[i].NCustomer = InfoHead(Antrian).info;
    Ruangan[Pemain.ruangan].TTable[i].isOrderTaken = false;
    infotypeQueue X;
    DelQueue(&Antrian,&X);
}

void GIVE()
/*Memberikan makanan yang berada di paling atas tumpukan ke pengunjung yang
bertetanggaan*/
{
  /*kamus*/
  Kata makanan;
  int M =  IsNearTable();
  /*Algoritma*/
  if(!IsEmptyStack(Makanan)&& Ruangan[Pemain.ruangan].TTable[M].kursi!=0)
  {
    PopStack(&Makanan,&makanan);
    Pemain.money = Pemain.money + (500 * Ruangan[Pemain.ruangan].TTable[M].NCustomer);
    Ruangan[Pemain.ruangan].TTable[M].NCustomer = 0;
  }
}
void RECIPE()
/*Command ini digunakan untuk menampilkan pohon makanan.*/
{
  PrintTree(Resep,2);
}
void SAVE()
/*Command ini digunakan untuk menyimpan state permainan saat ini agar dapat
dilanjutkan kemudian. Metode interaksi bebas*/
{
    SaveFile();
}
void LOAD()
/*Command ini digunakan untuk melanjutkan permainan sesuai dengan state yang
ada pada text file. Metode interaksi bebas*/
{
    LoadFile();
}
void EXIT(boolean *exit)
/*Command ini digunakan untuk keluar dari program.*/
{
    /*kamus*/
    *exit = true;
}


void GantiRuangan () {
    int pintu = 0;
    int i;
    for (i = 1; i <= 3; ++i) {
        if (EQ(Pemain.posisi,Ruangan[i].P1)) {
            pintu = 1;
        } else if (EQ(Pemain.posisi,Ruangan[i].P2)) {
            pintu = 2;
        }
    }

    if (Pemain.ruangan == 4) {
        if (EQ(Pemain.posisi,Dapur.P1)) {
            pintu = 1;
        } else if (EQ(Pemain.posisi,Dapur.P2)) {
            pintu = 2;
        }
    }
    if (pintu != 0) {
        Pemain.ruangan = SearchEdge2(Denah,Pemain.ruangan,pintu);
        if (Pemain.ruangan >= 1 && Pemain.ruangan <= 3) {
            if (pintu == 1) {
                Pemain.posisi = Ruangan[Pemain.ruangan].P1;
            } else if (pintu == 2) {
                Pemain.posisi = Ruangan[Pemain.ruangan].P2;
            }
        } else if (Pemain.ruangan == 4) {
            if (pintu == 1) {
                Pemain.posisi = Dapur.P1;
            } else if (pintu == 2) {
                Pemain.posisi = Dapur.P2;
            }
        }
    }
}

MejaDapur IsNearKitchenTable(){
    
    POINT P;
    boolean f=false;
    int i,j;
    //Algoritma
    P.X = Pemain.posisi.X;
    P.Y = Pemain.posisi.Y;
    P.X = P.X+1;
    while(i<=16 && !f)
    {
      while(j<=16 && !f)
      {
        if(EQ(P,Dapur.M[i].posisi))
        {
          f = true;
        }
        else
          j++;
      }
      i++;
    }
    if(!f)
    {
      P.X -= 2;
      i = 1;
      j = 1;
      while(i<=16 && !f)
      {
        while(j<=16 && !f)
        {
          if(EQ(P,Dapur.M[i].posisi))
          {
            f = true;
          }
          else
            j++;
        }
        i++;
      }
    }
    if(!f)
    {
      P.X += 1;
      P.Y += 1;
      i = 1;
      j = 1;

      while(i<=16 && !f)
      {
        while(j<=16 && !f)
        {
          if(EQ(P,Dapur.M[i].posisi))
          {
            f = true;
          }
          else
            j++;
        }
        i++;
      }
    }
    if(!f)
    {
      P.Y -= 2;
      i = 1;
      i = 1;

      while(i<=16 && !f)
      {
        while(j<=16 && !f)
        {
          if(EQ(P,Dapur.M[i].posisi))
          {
            f = true;
          }
          else
            j++;
        }
        i++;
      }
    }
  if(f)
  {
    return Dapur.M[i];
  }
  Dapur.M[0].bahan = StringToKata(" ");
  return Dapur.M[0];
}    
/* Command ini digunakan untuk menentukan apakah Pemain berada di sebelah meja yang benar */
void UpdateTimePatience() {
/* Mengupdate Kesabaran dan waktu */
    Pemain.time++;
    SubKesabaranArray(&Pesanan,&Pemain.life);
    SubKesabaranQueue(&Antrian,&Pemain.life);
}
