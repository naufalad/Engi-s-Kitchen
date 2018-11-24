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
    /*kamus*/
    POINT P;
    /*algoritma*/
    P.X = (Pemain).posisi.X-1;
    P.Y = (Pemain).posisi.Y;
    Ruang ruangan;
    switch ((Pemain).ruangan){
        case 1 :
        ruangan = Ruangan[1];  
        break;
        case 2 :
        ruangan = Ruangan[2];  
        break;
        case 3 :
        ruangan = Ruangan[3];  
        break;
    }

    if (EQ(P,ruangan.P1)||EQ(P,ruangan.P2)) {
        GantiRuangan(Pemain);
    } else{
        for (int i=1;i<=4;i++){
            if (ruangan.TTable[i].kursi == 2) {
                for (int j=2;j<=3;j++) {
                    if (EQ(P,ruangan.TTable[i].posisi) || EQ(P,ruangan.TTable[i].TChair[j])) {
                        printf("Anda tidak dapat melangkahi Meja/Kursi");
                    } else {
                        (Pemain).posisi = P;
                    }
                }
            }
            else if (ruangan.TTable[i].kursi == 4) {
                for (int j=1;j<=4;j++) {
                    if (EQ(P,ruangan.TTable[i].posisi) || EQ(P,ruangan.TTable[i].TChair[j])) {
                        printf("Anda tidak dapat melangkahi Meja/Kursi");
                    } else {
                        (Pemain).posisi = P;
                    }
                }
            }
        } 
    }
}
void GD(Player Pemain)
/*Command ini adalah singkatan dari ‘Go Down’, sehingga posisi Player berpindah
ke bawah*/
{
    /*kamus*/
    POINT P;
    /*algoritma*/
    P.X = (Pemain).posisi.X+1;
    P.Y = (Pemain).posisi.Y;
    Ruang ruangan;
    switch ((Pemain).ruangan){
        case 1 :
        ruangan = Ruangan[1];  
        break;
        case 2 :
        ruangan = Ruangan[2];  
        break;
        case 3 :
        ruangan = Ruangan[3];  
        break;
    }

    if (EQ(P,ruangan.P1)||EQ(P,ruangan.P2)) {
        GantiRuangan(Pemain);
    } else{
        for (int i=1;i<=4;i++){
            if (ruangan.TTable[i].kursi == 2) {
                for (int j=2;j<=3;j++) {
                    if (EQ(P,ruangan.TTable[i].posisi) || EQ(P,ruangan.TTable[i].TChair[j])) {
                        printf("Anda tidak dapat melangkahi Meja/Kursi");
                    } else {
                        (Pemain).posisi = P;
                    }
                }
            }
            else if (ruangan.TTable[i].kursi == 4) {
                for (int j=1;j<=4;j++) {
                    if (EQ(P,ruangan.TTable[i].posisi) || EQ(P,ruangan.TTable[i].TChair[j])) {
                        printf("Anda tidak dapat melangkahi Meja/Kursi");
                    } else {
                        (Pemain).posisi = P;
                    }
                }
            }
        } 
    }
}

void GL()
/*Command ini adalah singkatan dari ‘Go Left’, sehingga posisi Player berpindah
ke kiri*/
{
    /*kamus*/
    POINT P;
    /*algoritma*/
    P.X = (Pemain).posisi.X;
    P.Y = (Pemain).posisi.Y-1;
    Ruang ruangan;
    switch ((Pemain).ruangan){
        case 1 :
        ruangan = Ruangan[1];  
        break;
        case 2 :
        ruangan = Ruangan[2];  
        break;
        case 3 :
        ruangan = Ruangan[3];  
        break;
    }

    if (EQ(P,ruangan.P1)||EQ(P,ruangan.P2)) {
        GantiRuangan(Pemain);
    } else{
        for (int i=1;i<=4;i++){
            if (ruangan.TTable[i].kursi == 2) {
                for (int j=2;j<=3;j++) {
                    if (EQ(P,ruangan.TTable[i].posisi) || EQ(P,ruangan.TTable[i].TChair[j])) {
                        printf("Anda tidak dapat melangkahi Meja/Kursi");
                    } else {
                        (Pemain).posisi = P;
                    }
                }
            }
            else if (ruangan.TTable[i].kursi == 4) {
                for (int j=1;j<=4;j++) {
                    if (EQ(P,ruangan.TTable[i].posisi) || EQ(P,ruangan.TTable[i].TChair[j])) {
                        printf("Anda tidak dapat melangkahi Meja/Kursi");
                    } else {
                        (Pemain).posisi = P;
                    }
                }
            }
        } 
    }
}
void GR()
/*Command ini adalah singkatan dari ‘Go Right’, sehingga posisi Player berpindah
kekanan.*/
{
    /*kamus*/
    POINT P;
    /*algoritma*/
    P.X = (Pemain).posisi.X;
    P.Y = (Pemain).posisi.Y+1;
    Ruang ruangan;
    switch ((Pemain).ruangan){
        case 1 :
        ruangan = Ruangan[1];  
        break;
        case 2 :
        ruangan = Ruangan[2];  
        break;
        case 3 :
        ruangan = Ruangan[3];  
        break;
    }

    if (EQ(P,ruangan.P1)||EQ(P,ruangan.P2)) {
        GantiRuangan(Pemain);
    } else{
        for (int i=1;i<=4;i++){
            if (ruangan.TTable[i].kursi == 2) {
                for (int j=2;j<=3;j++) {
                    if (EQ(P,ruangan.TTable[i].posisi) || EQ(P,ruangan.TTable[i].TChair[j])) {
                        printf("Anda tidak dapat melangkahi Meja/Kursi");
                    } else {
                        (Pemain).posisi = P;
                    }
                }
            }
            else if (ruangan.TTable[i].kursi == 4) {
                for (int j=1;j<=4;j++) {
                    if (EQ(P,ruangan.TTable[i].posisi) || EQ(P,ruangan.TTable[i].TChair[j])) {
                        printf("Anda tidak dapat melangkahi Meja/Kursi");
                    } else {
                        (Pemain).posisi = P;
                    }
                }
            }
        } 
    }
}

/*void ORDER(Player Pemain,List *menu,Ruang ruangan)//Pemain bisa ambil brp banyak order?
/*Command ini digunakan untuk mengambil order dari meja yang bersebelahan
dengan Pemain*/
//{
    /*kamus*/

    /*algoritma*/
    /*if(IsNearTable(Pemain,ruangan))//IsNearTable buat nentuin apakah deket Pemain ada table atau nggak
    {


}*/
void PUT()
/*Command ini digunakan untuk menaruh makanan di hand ke nampan*/
{
  /*kamus*/
  Kata isi;
  /*Algoritma*/
  while(!IsEmptyStack(Tangan))
  {
    PopStack(&Tangan,&isi);
    PushStack(&(Dapur).T.bahan,isi);
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
   else printf("Anda sedang tidak dekat meja apapun!");
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
  CreateEmptyStack(&(Dapur).T.bahan);
}
void PLACE(Player Pemain, Ruang room, Queue antrian)
/*Command ini digunakan untuk menaruh pelanggan di meja dan kosong.
Pelanggan yang ditaruh adalah pelanggan pada top of queue*/
{
    if (IsEmptyQueue(antrian)) {
        printf("Tidak ada tamu yang menunggu\n");
        return;
    }
    int i;
    MejaMakan meja = IsNearTable(room);
    if(EQ(meja.posisi, room.TTable[1].posisi)) i = 1;
    else if(EQ(meja.posisi, room.TTable[2].posisi)) i = 2;
    else if(EQ(meja.posisi, room.TTable[3].posisi)) i = 3;
    else if(EQ(meja.posisi, room.TTable[4].posisi)) i = 4;
    if (meja.kursi == 0) {
        printf("Anda harus berada dekat meja makan\n");
        return;
    }
    if (Ruangan[Pemain.ruangan].TTable[i].kursi < InfoHead(antrian).info) {
        printf("Banyak kursi tidak memenuhi\n");
        return;
    }
    if (Ruangan[Pemain.ruangan].TTable[i].NCustomer > 0) {
        printf("Tempat sudah ditempati\n");
        return;
    }
    Ruangan[Pemain.ruangan].TTable[i].NCustomer = InfoHead(antrian).info;
    Ruangan[Pemain.ruangan].TTable[i].isOrderTaken = false;
    infotypeQueue X;
    DelQueue(&antrian,&X);
}

void GIVE(Player pemain,Stack *foodstack,int *money,Ruang ruangan)
/*Memberikan makanan yang berada di paling atas tumpukan ke pengunjung yang
bertetanggaan*/
{
  /*kamus*/
  Kata makanan;
  MejaMakan M =  IsNearTable(ruangan);
  /*Algoritma*/
  if(!IsEmptyStack(*foodstack)&&M.kursi!=0)
  {
    PopStack(foodstack,&makanan);
    *money = *money + (500 * M.NCustomer);
    M.NCustomer = 0;
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

MejaMakan IsNearTable(Ruang R)
/* Command ini digunakan untuk menentukan apakah Pemain berada di sebelah meja yang benar */
{
    //Kamus
    POINT P;
    boolean f=false;
    int i,j;
    //Algoritma
    P.X = Pemain.posisi.X;
    P.Y = Pemain.posisi.Y;
    P.X = P.X+1;
    while(i<=4 && !f)
    {
      while(j<=4 && !f)
      {
        if(EQ(P,R.TTable[i].TChair[j]))
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
      while(i<=4 && !f)
      {
        while(j<=4 && !f)
        {
          if(EQ(P,R.TTable[i].TChair[j]))
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

      while(i<=4 && !f)
      {
        while(j<=4 && !f)
        {
          if(EQ(P,R.TTable[i].TChair[j]))
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

      while(i<=4 && !f)
      {
        while(j<=4 && !f)
        {
          if(EQ(P,R.TTable[i].TChair[j]))
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
    return R.TTable[i];
  }
  R.TTable[0].kursi = 0;
  return R.TTable[0];
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
                Pemain.posisi = Ruangan[i].P1;
            } else if (pintu == 2) {
                Pemain.posisi = Ruangan[i].P2;
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