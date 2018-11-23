//kemungkinan dari command
#include "ADT.h"
void GU(POINT *pemain,waktu *Time)//pemain adalah lokasi dari pemain saat itu,Time adalah waktu yag telah lewat
//Command ini adalah singkatan dari �Go Up�, sehingga posisi player berpindah ke
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
/*Command ini adalah singkatan dari �Go Down�, sehingga posisi player berpindah
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
/*Command ini adalah singkatan dari �Go Left�, sehingga posisi player berpindah
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
/*Command ini adalah singkatan dari �Go Right�, sehingga posisi player berpindah
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


void ORDER(POINT pemain,waktu *Time,char[][] *order)//pemain bisa ambil brp banyak order?
/*Command ini digunakan untuk mengambil order dari meja yang bersebelahan
dengan pemain*/
{

}
void PUT()
/*Command ini digunakan untuk menaruh makanan di hand ke nampan*/
{

}
void TAKE();
/*Command ini digunakan untuk mengambil bahan yang bersebelahan dengan
pemain*/
void CH();
/*Command ini digunakan untuk membuang seluruh bahan makanan yang
terdapat di tangan pemain*/
void CT();
/*Command ini digunakan untuk membuang seluruh makanan yang berada di
dalam tray*/
void PLACE();
/*Command ini digunakan untuk menaruh pelanggan di meja dan kosong.
Pelanggan yang ditaruh adalah pelanggan pada top of queue*/
void GIVE();
/*Memberikan makanan yang berada di paling atas tumpukan ke pengunjung yang
bertetanggaan*/
void RECIPE();
/*Command ini digunakan untuk menampilkan pohon makanan.*/
void SAVE();
/*Command ini digunakan untuk menyimpan state permainan saat ini agar dapat
dilanjutkan kemudian. Metode interaksi bebas*/
void LOAD();
/*Command ini digunakan untuk melanjutkan permainan sesuai dengan state yang
ada pada text file. Metode interaksi bebas*/
void EXIT();
/*Command ini digunakan untuk keluar dari program.*/
