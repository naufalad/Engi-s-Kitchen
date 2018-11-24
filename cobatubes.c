//kemungkinan dari command
#include "cobatubes.h"

void GU(Player *pemain,Ruang ruangan)//pemain adalah lokasi dari pemain saat itu,Time adalah waktu yag telah lewat
//Command ini adalah singkatan dari ‘Go Up’, sehingga posisi Player berpindah ke
//atas
{
    /*kamus*/
    POINT P;
    /*algoritma*/
    P.X = (*pemain).posisi.X-1;
    P.Y = (*pemain).posisi.Y;

    if (P = ruangan.P1) {
        GantiRuangan();
    }
    for (int i=1;i<=4;i++){
        if (ruangan.TTable[i].kursi == 2) {
            for (int j=2;j<=3;j++) {
                if ((P = ruangan.TTable[i].posisi) || (P = ruangan.TTable[i].Tchair[j])) {
                    printf("Anda tidak dapat melangkahi Meja/Kursi");
                } else {
                    (*pemain).posisi = P;
                }
            }
        }
        else if (ruangan.TTable[i].kursi == 4) {
            for (int j=1;j<=4;j++) {
                if ((P = ruangan.TTable[i].posisi) || (P = ruangan.TTable[i].Tchair[j])) {
                    printf("Anda tidak dapat melangkahi Meja/Kursi");
                } else {
                    (*pemain).posisi = P;
                }
            }
        }
    }
}
void GD(Player *pemain,Ruang ruangan)
/*Command ini adalah singkatan dari ‘Go Down’, sehingga posisi Player berpindah
ke bawah*/
{
    /*kamus*/
    POINT P;
    /*algoritma*/
    P.X = (*pemain).posisi.X+1;
    P.Y = (*pemain).posisi.Y;

    if (P = ruangan.P1) {
        GantiRuangan();
    }
    for (int i=1;i<=4;i++){
        if (ruangan.TTable[i].kursi == 2) {
            for (int j=2;j<=3;j++) {
                if ((P = ruangan.TTable[i].posisi) || (P = ruangan.TTable[i].Tchair[j])) {
                    printf("Anda tidak dapat melangkahi Meja/Kursi");
                } else {
                    (*pemain).posisi = P;
                }
            }
        }
        else if (ruangan.TTable[i].kursi == 4) {
            for (int j=1;j<=4;j++) {
                if ((P = ruangan.TTable[i].posisi) || (P = ruangan.TTable[i].Tchair[j])) {
                    printf("Anda tidak dapat melangkahi Meja/Kursi");
                } else {
                    (*pemain).posisi = P;
                }
            }
        }
    }
}

void GL(Player *pemain,Ruang ruangan)
/*Command ini adalah singkatan dari ‘Go Left’, sehingga posisi Player berpindah
ke kiri*/
{
    /*kamus*/
    POINT P;
    /*algoritma*/
    P.X = (*pemain).posisi.X;
    P.Y = (*pemain).posisi.Y-1;

    if (P = ruangan.P1) {
        GantiRuangan();
    }
    for (int i=1;i<=4;i++){
        if (ruangan.TTable[i].kursi == 2) {
            for (int j=2;j<=3;j++) {
                if ((P = ruangan.TTable[i].posisi) || (P = ruangan.TTable[i].Tchair[j])) {
                    printf("Anda tidak dapat melangkahi Meja/Kursi");
                } else {
                    (*pemain).posisi = P;
                }
            }
        }
        else if (ruangan.TTable[i].kursi == 4) {
            for (int j=1;j<=4;j++) {
                if ((P = ruangan.TTable[i].posisi) || (P = ruangan.TTable[i].Tchair[j])) {
                    printf("Anda tidak dapat melangkahi Meja/Kursi");
                } else {
                    (*pemain).posisi = P;
                }
            }
        }
    }
}
void GR(Player *pemain,Ruang ruangan)
/*Command ini adalah singkatan dari ‘Go Right’, sehingga posisi Player berpindah
kekanan.*/
{
    /*kamus*/
    POINT P;
    /*algoritma*/
    P.X = (*pemain).posisi.X;
    P.Y = (*pemain).posisi.Y+1;

    if (P = ruangan.P1) {
        GantiRuangan();
    }
    for (int i=1;i<=4;i++){
        if (ruangan.TTable[i].kursi == 2) {
            for (int j=2;j<=3;j++) {
                if ((P = ruangan.TTable[i].posisi) || (P = ruangan.TTable[i].Tchair[j])) {
                    printf("Anda tidak dapat melangkahi Meja/Kursi");
                } else {
                    (*pemain).posisi = P;
                }
            }
        }
        else if (ruangan.TTable[i].kursi == 4) {
            for (int j=1;j<=4;j++) {
                if ((P = ruangan.TTable[i].posisi) || (P = ruangan.TTable[i].Tchair[j])) {
                    printf("Anda tidak dapat melangkahi Meja/Kursi");
                } else {
                    (*pemain).posisi = P;
                }
            }
        }
    }
}

void ORDER(Player pemain,List *menu,KRuang ruangan)//pemain bisa ambil brp banyak order?
/*Command ini digunakan untuk mengambil order dari meja yang bersebelahan
dengan pemain*/
{
    /*kamus*/

    /*algoritma*/
    if(IsNearTable(pemain,ruangan))//IsNearTable buat nentuin apakah deket pemain ada table atau nggak
    {


}
void PUT(Stack *Hand,Stack *Tray)
/*Command ini digunakan untuk menaruh makanan di hand ke nampan*/
{
  /*kamus*/
  Kata isi;
  /*Algoritma*/
  while(!IsEmpty(*Hand))
  {
    POP(Hand,&isi);
    Push(Tray,isi);
  }
}
void TAKE(Stack *Hand,Kata bahan)
/*Command ini digunakan untuk mengambil bahan yang bersebelahan dengan
pemain*/
{
  /*kamus*/

  /*Algoritma*/
  push(Hand,bahan);
}
void CH(Stack *Hand, int *time)
/*Command ini digunakan untuk membuang seluruh bahan makanan yang
terdapat di tangan pemain*/
{
  /*kamus*/

  /*Algoritma*/
  CreateEmpty(Hand);
}
void CT(Stack *Tray)
/*Command ini digunakan untuk membuang seluruh makanan yang berada di
dalam tray*/
{
  /*kamus*/

  /*Algoritma*/
  CreateEmpty(Tray);
}
void PLACE(Player pemain, Ruang room, Queue antrian)
/*Command ini digunakan untuk menaruh pelanggan di meja dan kosong.
Pelanggan yang ditaruh adalah pelanggan pada top of queue*/
{
    /*kamus*/

    /*algoritma*/
    if(IsNearTable(pemain,ruangan))
    {
      if(customermeja == 0)
      {
        if(!)
      }
    }
void GIVE(Player pemain,Stack *foodstack,int *ncustemer,int *money,Ruang ruangan)
/*Memberikan makanan yang berada di paling atas tumpukan ke pengunjung yang
bertetanggaan*/
{
  /*kamus*/
  Kata makanan;
  /*Algoritma*/
  if(!IsEmptyStack(*foodstack) && IsNearTable(pemain,ruangan)&& ncustemer != 0)
  {
    POP(foodstack,&makanan);
    *money = 500*ncustemer;
    *ncustemer = 0;
    *time++
  }

}
void RECIPE(BinTree resep)
/*Command ini digunakan untuk menampilkan pohon makanan.*/
{
  PrintTree(resep,2);
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
void EXIT()
/*Command ini digunakan untuk keluar dari program.*/
{
    /*kamus*/
    char jawaban;
    boolean f;
    /*algoritma*/
    printf("Apakah file ingin di save sebelum exit?(y/n)\n");
    scanf("%c",&jawaban);
    if(jawaban == 'y' || 'Y')
        f = true;
    else
        f = false;
    ExitMessage(f);
    delay(10000);
    exit(0);
}

MejaMakan IsNearTable(Player Pemain, Ruang R)
/* Command ini digunakan untuk menentukan apakah pemain berada di sebelah meja yang benar */
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

    } else if (Pemain.ruangan == 4) {
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
