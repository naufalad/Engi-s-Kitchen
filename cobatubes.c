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
int IntervalCustomer;

void GU()//Pemain adalah lokasi dari Pemain saat itu,Time adalah waktu yag telah lewat
//Command ini adalah singkatan dari ‘Go Up’, sehingga posisi Player berpindah ke
//atas
{
    if (Pemain.posisi.X == 1) {
        if (Pemain.ruangan < 4 && (EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P2)||(EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P1)))){
            GantiRuangan();
        }else if ((Pemain.ruangan==4 && ((EQ(Pemain.posisi, Dapur.P1))||EQ(Pemain.posisi, Dapur.P2)))){
            GantiRuangan();
        }
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
    UpdateTimePatience();
}
void GD()
/*Command ini adalah singkatan dari ‘Go Down’, sehingga posisi Player berpindah
ke bawah*/
{
    if (Pemain.posisi.X == 8) {
        if (Pemain.ruangan<4&&(EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P2)||EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P1)))
            GantiRuangan();
        else if ((Pemain.ruangan==4&&(EQ(Pemain.posisi, Dapur.P1))||EQ(Pemain.posisi, Dapur.P2)))
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
    UpdateTimePatience();
}

void GL()
/*Command ini adalah singkatan dari ‘Go Left’, sehingga posisi Player berpindah
ke kiri*/
{
    if (Pemain.posisi.Y == 1) {
        if (Pemain.ruangan<4&&(EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P1)||EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P2)))
            GantiRuangan();
        else if ((Pemain.ruangan==4&&(EQ(Pemain.posisi, Dapur.P1))||EQ(Pemain.posisi, Dapur.P2)))
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
                    printf("Tidak dapat menembus meja dan tray!\n");
                }
        }
    }
    UpdateTimePatience();
}
void GR()
/*Command ini adalah singkatan dari ‘Go Right’, sehingga posisi Player berpindah
kekanan.*/
{
    if (Pemain.posisi.Y == 8) {
        if (Pemain.ruangan<4&&(EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P1)||EQ(Pemain.posisi, Ruangan[Pemain.ruangan].P2)))
            GantiRuangan();
        else if ((Pemain.ruangan==4&&(EQ(Pemain.posisi, Dapur.P1))||EQ(Pemain.posisi, Dapur.P2)))
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
    UpdateTimePatience();
}

void ORDER()//Pemain bisa ambil brp banyak order?
/*Command ini digunakan untuk mengambil order dari meja yang bersebelahan
dengan Pemain*/
/* follow @amndfkhrns */
{
    /*kamus*/
    int TableNo;
    int orderidx;
    PesananID PengenMakan;
    /*algoritma*/
    TableNo = IsNearTable();

    if ((Ruangan[Pemain.ruangan].TTable[TableNo].NCustomer == 0) || (TableNo == 0) || (Ruangan[Pemain.ruangan].TTable[TableNo].isOrderTaken)) {
        /* Kalau di meja gaada orang, atau ga deket meja, atau mejanya udah diambil orderannya */
        printf("Tidak ada orderan yang bisa diambil!\n");
    } else {
        orderidx = GetRandomMenu();
        PengenMakan.Room = Pemain.ruangan;
        PengenMakan.MejaID = TableNo;
        PengenMakan.Kesabaran = 40;
        PengenMakan.Menu = GetRandomMenuName(orderidx);

        AddAsLastEl(&Pesanan, PengenMakan);
        Ruangan[Pemain.ruangan].TTable[TableNo].isOrderTaken = true;
        printf("Berhasil mengambil orderan!\n");
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
      printf("Berhasil membuat makanan!\n");
    }
  } else printf("Anda sedang tidak berada dekat dengan Tray...\n");
}
void TAKE()
/*Command ini digunakan untuk mengambil bahan yang bersebelahan dengan
Pemain*/
{
  /*kamus*/

  /*Algoritma*/
   Kata M = IsNearKitchenTable();
   if(!IsEqKata(M, StringToKata(" "))) {
       PushStack(&Tangan,M);
       printf("Berhasil mengambil bahan!\n");
   }
   else printf("Anda mencoba mengambil bahan : udara. Anda gagal\n");
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
  printf("Berhasil mengosongkan nampan!\n");
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
    printf("Berhasil menambahkan pelanggan!\n");
}

void GIVE()
/*Memberikan makanan yang berada di paling atas tumpukan ke pengunjung yang
bertetanggaan*/
{
  /*kamus*/
  Kata makanan;
  int M =  IsNearTable();
  int i;
  PesananID X;
  /*Algoritma*/
  if(M!=0){
    if(!IsEmptyStack(Makanan)&& Ruangan[Pemain.ruangan].TTable[M].kursi!=0)
    {
        PopStack(&Makanan,&makanan);
        X.Menu = makanan;
        X.MejaID = M;
        X.Room = Pemain.ruangan;
        i = SearchArray(Pesanan,X) ;
        if(i!=0){
            Pemain.money = Pemain.money + (500 * Ruangan[Pemain.ruangan].TTable[M].NCustomer);
            printf("Berhasil membuat makanan! Menerima uang sebesar %d", 500 * Ruangan[Pemain.ruangan].TTable[M].NCustomer);
            Ruangan[Pemain.ruangan].TTable[M].NCustomer = 0;
            DelEli(&Pesanan, i,&X);            
        } else{
            printf("Tidak ada yang memesan makanan itu!\n");
        }
    } else if(Ruangan[Pemain.ruangan].TTable[M].kursi==0)
        printf("Tidak ada pelanggan.");
        else if(IsEmptyStack(Makanan))
        printf("Makanan kosong.");
  } else printf("Sedang tidak berada dekat dengan meja apapun...");
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

Kata IsNearKitchenTable(){
    if (Pemain.ruangan == 4) {
        int i,j;
        for (i = 1; i <= 16; ++i) {
            if (AdjPOINT(Pemain.posisi, Dapur.M[i].posisi))
                return Dapur.M[i].bahan;
        }
    }
    return StringToKata(" ");
}    
/* Command ini digunakan untuk menentukan apakah Pemain berada di sebelah meja yang benar */
void UpdateTimePatience() {
/* Mengupdate Kesabaran dan waktu */
    Pemain.time++;
    SubKesabaranArray(&Pesanan,&Pemain.life);
    SubKesabaranQueue(&Antrian,&Pemain.life);
    //Kalau IntervalCustomer >0 akan decrement
    //Kalau IntervalCustomer =0 akan merandom tamu datang untuk masuk ke antrian sistem
    RandomizerQueue();
    
}
void SubKesabaranArray (TabPesanan* T, int* Life) {
  if (!IsEmptyArray(*T)) {
    int i = 1, j = 1;
    while (true) {
      --ElmtArray(*T,i).Kesabaran;
      if (ElmtArray(*T,i).Kesabaran == 0) {
          --*Life;
          printf("Pelanggan di meja %d, ruang %d lelah menanti, dia meninggalkan meja makannya dan pergi!", (*T).TI[i].MejaID, (*T).TI[i].Room);
          Ruangan[Pemain.ruangan].TTable[(*T).TI[i].MejaID].NCustomer = 0;
      } else {
          ElmtArray(*T,j) = ElmtArray(*T,i);
          j++;
      }
      if (i == Neff(*T)) break;
      i++;
    }
    Neff(*T) = j-1;
  }
}


void help(){
    printf("List Command :\n");
    printf("GU \t-> Bergerak ke atas\n");
    printf("GD \t-> Bergerak ke bawah\n");
    printf("GL \t-> Bergerak ke kiri\n");
    printf("GR \t-> Bergerak ke kanan\n");
    printf("ORDER \t-> Mengambil orderan\n");
    printf("PUT \t-> Menaruh ke tray dan membuat makanan(hanya di dekat tray)\n");
    printf("TAKE \t-> Ambil bahan(hanya bisa di dekat meja bahan)\n");
    printf("CH \t-> Membuang semua bahan makanan dalam hand\n");
    printf("CT \t-> Membuang semua makanan yang dibawa\n");
    printf("PLACE \t-> Menaruh pelanggan yang kelaparan\n");
    printf("GIVE \t-> Memberi makanan kepada pelanggan(hanya di dekat pelanggan)\n");
    printf("RECIPE \t-> Menampilkan daftar resep\n");
    printf("SAVE \t-> Menyimpan data permainan\n");
    printf("LOAD \t-> Mengambil data permainan\n");
    printf("EXIT \t-> Keluar dari permainan\n\n");
    printf("Letak Bahan :\n");
    printf("Piring \t\t-> 7,4\n");
    printf("Sendok \t\t-> 7,3\n");
    printf("Garpu \t\t-> 7,5\n");
    printf("Es krim \t-> 3,3\n");
    printf("Nasi \t\t-> 4,3\n");
    printf("Roti \t\t-> 3,6\n");
    printf("Spaghetti \t-> 4,6\n");
    printf("Pisang \t\t-> 3,2\n");
    printf("Stroberi \t-> 3,1\n");
    printf("Telur \t\t-> 4,2\n");
    printf("Ayam goreng \t-> 4,1\n");
    printf("Patty \t\t-> 3,7\n");
    printf("Sosis \t\t-> 3,8\n");
    printf("Bolognese \t-> 4,7\n");
    printf("Carbonara \t-> 7,8\n");
    printf("Keju \t\t-> 4,8\n");
}
void CHEAT(Kata command){
    if(IsEqKata(command, StringToKata("hesoyam"))){
        Pemain.life+=3;
    } else{
        help();
    }
}