//kemungkinan dari command
#include "ADT.h"
#include "stackt.h"
#include "bintree.c"
void Gu(POINT *pemain,waktu *Time)//pemain adalah lokasi dari pemain saat itu,Time adalah waktu yag telah lewat
//Command ini adalah singkatan dari ‘Go Up’, sehingga posisi player berpindah ke
//atas
{
    /*kamus*/
    POINT P;
    /*algoritma*/
    if(*pemain.y == EdgeAtas/*batas atas dari peta*/)
    {
        P.x = *pemain.x;
        P.y = *pemain.y +1;
        if(P.y == pintu.y && P.x == pintu.x)
        {
            gantiruangan(*pemain);//mengganti lokasi pemain dari satu ruangan ke ruangan lain
            *Time += 1;
        }
        else
            printf("Tidak bisa bergerak keatas!");
    }
    else
    {
        if((*pemain.y + 1) == Tempatduduk ||(*pemain.y + 1) == kursi)
        {
            printf("Pemain tidak boleh menginjak meja ataupun kursi!")
        }
        else
        {
            *pemain.y += 1;
            Time += 1;
        }
    }
}
void GD(POINT *pemain,waktu *Time)
/*Command ini adalah singkatan dari ‘Go Down’, sehingga posisi player berpindah
ke bawah*/
{
    /*kamus*/
    POINT P;
    /*algoritma*/
    if(*pemain.y == EdgeBawah/*batas bawah dari peta*/)
    {
        P.x = *pemain.x;
        P.y = *pemain.y -1;
        if(P.y == pintu.y && P.x == pintu.x)
        {
            gantiruangan(*pemain);//mengganti lokasi pemain dari satu ruangan ke ruangan lain
            *Time += 1
        }
        else
            printf("Tidak bisa bergerak kebawah!");
    }
    else
    {
        if((*pemain.y - 1) == Tempatduduk ||(*pemain.y - 1) == kursi)
        {
            printf("Pemain tidak boleh menginjak meja ataupun kursi!")
        }
        else
        {
            *pemain.y -= 1;
            *Time += 1;
        }
    }
}
void GL(POINT *pemain,waktu *Time)
/*Command ini adalah singkatan dari ‘Go Left’, sehingga posisi player berpindah
ke kiri*/
{
    /*kamus*/
    POINT P;
    /*algoritma*/
    if(*pemain.x == EdgeKiri/*batas kanan dari peta*/)
    {
        P.x = *pemain.x - 1;
        P.y = *pemain.y
        if(P.x == pintu.x &&P.y == pintu.y)
        {
            gantiruangan(*pemain);
            *Time += 1;
        }
        else
            printf("Tidak bisa bergerak kekiri!");
    }
    else
    {
        if((*pemain.x - 1) == Tempatduduk ||(*pemain.x - 1) == kursi)
        {
            printf("Pemain tidak boleh menginjak meja ataupun kursi!")
        }
        else
        {
            *pemain.x -= 1;
            *Time += 1;
        }
    }
}
void GR(POINT *pemain,waktu *Time)
/*Command ini adalah singkatan dari ‘Go Right’, sehingga posisi player berpindah
kekanan.*/
{
    /*kamus*/
    POINT P;
    /*algoritma*/
    if(*pemain.x == EdgeKiri/*batas kanan dari peta*/)
    {
        P.x = *pemain.x + 1;
        P.y = *pemain.y
        if(P.x == pintu.x &&P.y == pintu.y)
        {
            gantiruangan(*pemain);
            *Time += 1;
        }
        else
            printf("Tidak bisa bergerak kekiri!");
    }
    else
    {
        if((*pemain.x + 1) == Tempatduduk ||(*pemain.x + 1) == kursi)
        {
            printf("Pemain tidak boleh menginjak meja ataupun kursi!")
        }
        else
        {
            *pemain.x += 1;
            *Time += 1;
        }
    }
}


void ORDER(POINT pemain,List *menu,char[] order)//pemain bisa ambil brp banyak order?
/*Command ini digunakan untuk mengambil order dari meja yang bersebelahan
dengan pemain*/
{
    /*kamus*/

    /*algoritma*/
    if(IsNearTable(pemain))//IsNearTable buat nentuin apakah deket pemain ada table atau nggak
    {


}
void PUT(Stack *Hand,Stack *Tray)
/*Command ini digunakan untuk menaruh makanan di hand ke nampan*/
{
  /*kamus*/
  char[] isi;
  /*Algoritma*/
  while(!IsEmpty(*Hand))
    POP(Hand,&isi);
    Push(Tray,isi);
}
void TAKE(Stack *Hand,char* bahan)
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
void PLACE(POINT pemain,)
/*Command ini digunakan untuk menaruh pelanggan di meja dan kosong.
Pelanggan yang ditaruh adalah pelanggan pada top of queue*/
{
    /*kamus*/

    /*algoritma*/
    if(IsNearTable(pemain)
void GIVE()
/*Memberikan makanan yang berada di paling atas tumpukan ke pengunjung yang
bertetanggaan*/
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
