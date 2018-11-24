//kemungkinan dari command
#include "cobatubes.h"

void Gu(player *pemain,int *Time,int ruangan)//pemain adalah lokasi dari pemain saat itu,Time adalah waktu yag telah lewat
//Command ini adalah singkatan dari ‘Go Up’, sehingga posisi player berpindah ke
//atas
{
    /*kamus*/
    POINT P;
    /*algoritma*/
    if(*pemain.x == 1/*batas atas dari peta*/)
    {
        P.x = *pemain.x-1;
        P.y = *pemain.y ;
        if(ruangan == 3)
        {
          if(P.y ==  5 )
          {
              gantiruangan(*pemain);//mengganti lokasi pemain dari satu ruangan ke ruangan lain
              *Time += 1;
          }
          else
              printf("Tidak bisa bergerak keatas!");
          }
        else if(ruangan == 4)
        {
          if(P.y ==  5 )
          {
              gantiruangan(*pemain);//mengganti lokasi pemain dari satu ruangan ke ruangan lain
              *Time += 1;
          }
          else
              printf("Tidak bisa bergerak keatas!");
              *Time += 1;
          }
      }
    else
    {
        if(IsNearTable(pemain,ruangan))
        {
            printf("Pemain tidak boleh menginjak meja ataupun kursi!")
            *Time += 1
        }
        else
        {
            *pemain.y -= 1;
            *Time += 1;
        }
    }
}
void GD(Player *pemain,int *Time,int ruangan)
/*Command ini adalah singkatan dari ‘Go Down’, sehingga posisi player berpindah
ke bawah*/
{
    /*kamus*/
    POINT P;
    /*algoritma*/
    if(*pemain.x == 8/*batas atas dari peta*/)
    {
        P.x = *pemain.x+1;
        P.y = *pemain.y;
        if(ruangan == 1)
        {
          if(P.y == 5)
          {
              gantiruangan(*pemain);//mengganti lokasi pemain dari satu ruangan ke ruangan lain
              *Time += 1;
          }
          else
              printf("Tidak bisa bergerak kebawah");
              *Time += 1;
          }
        else if(ruangan == 2)
        {
          if(P.y ==  5 )
          {
              gantiruangan(*pemain);//mengganti lokasi pemain dari satu ruangan ke ruangan lain
              *Time += 1;
          }
          else
              printf("Tidak bisa bergerak keatas!");
              *Time += 1;
          }
      }
    else
    {
        if(IsNearTable(pemain,ruangan))
        {
            printf("Pemain tidak boleh menginjak meja ataupun kursi!")
            *Time += 1
        }
        else
        {
            *pemain.y -= 1;
            *Time += 1;
        }
    }
}void GL(Player *pemain,int *Time,int ruangan)
/*Command ini adalah singkatan dari ‘Go Left’, sehingga posisi player berpindah
ke kiri*/
{
    /*kamus*/
    POINT P;
    /*algoritma*/
    if(*pemain.y == 1/*batas kanan dari peta*/)
    {
        P.x = *pemain.x;
        P.y = *pemain.y -1 ;
        if(ruangan == 2)
        {
          if(P.x == 2)
          {
              gantiruangan(*pemain);
              *Time += 1;
          }
          else
            printf("Tidak bisa bergerak kekiri!");
        }
        else if(ruangan == 3)
        {
          if(P.x == 2)
          {
              gantiruangan(*pemain);
              *Time += 1;
          }
          else
            printf("Tidak bisa bergerak kekiri!");
        }
      }
    else
    {
        if(IsNearTable(*pemain,ruangan))
        {
            printf("Pemain tidak boleh menginjak meja ataupun kursi!")
            *Time += 1;
        }
        else
        {
            *pemain.y -= 1;
            *Time += 1;
        }
    }
}
void GR(Player *pemain,int *Time,int ruangan)
/*Command ini adalah singkatan dari ‘Go Right’, sehingga posisi player berpindah
kekanan.*/
{
    /*kamus*/
    POINT P;
    /*algoritma*/
    if(*pemain.y == 8/*batas kanan dari peta*/)
    {
        P.x = *pemain.x;
        P.y = *pemain.y +1 ;
        if(ruangan == 1)
        {
          if(P.x == 5)
          {
              gantiruangan(*pemain);
              *Time += 1;
          }
          else
            printf("Tidak bisa bergerak kekanan!");
        }
        else if(ruangan == 1)
        {
          if(P.x == 5)
          {
              gantiruangan(*pemain);
              *Time += 1;
          }
          else
            printf("Tidak bisa bergerak kekanan!");
        }
      }
    else
    {
        if(IsNearTable(*pemain,ruangan))
        {
            printf("Pemain tidak boleh menginjak meja ataupun kursi!")
            *Time += 1;
        }
        else
        {
            *pemain.y += 1;
            *Time += 1;
        }
    }
}void ORDER(Player pemain,List *menu,Kata order,int ruangan)//pemain bisa ambil brp banyak order?
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
void CH(Stack *Hand)
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
void PLACE(Player pemain,int *customermeja,Queue antrian,int ruangan)
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
void GIVE(Player pemain,Stack *foodstack,int *ncustemer,int *money,int *time,int ruangan)
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

boolean IsNearSatTable(Player Pemain, Ruang R, tabpesanan ArOrder) 
/* Command ini digunakan untuk menentukan apakah pemain berada di sebelah meja yang benar */
{
    //Kamus
    int roomID;
    //Algoritma
    for (int i=1;i<=4,i++) {
        
    }
}