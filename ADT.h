/* File : ADT.h */
/* kumpulan struktur data*/


#ifndef adt_H
#define adt_H

	#include "boolean.h"
	#include "point.h"
	#include "jam.h"
	#include "mesinkar.h"
	#include "mesinkata.h"
	#include "arraykata.h"
	#include "matriks.h"
	#include "stackt.c"
	#include "prioqueue.h"

	typedef struct{
		Kata nama;
		int money;
		int life;
		int time;
		POINT posisi;
	} Player;

	typedef struct{
		POINT posisi;
		int kursi;

	} MejaMakan;

	typedef struct{
		POINT posisi;
		Kata bahan;
	} MejaDapur;

	
	static Player Pemain;
	static JAM RealTime = CurrentTime();
	//bakal disesuain sama real time, buat dipake di savegame
	//bakalan NextNDetik mulu tiap program berjalan(kecuali ga harus real time, kalo ga harus ntar bisa diconvert dr lama main)

	static TabKata Pesanan;
	//ubah array.h buat orderan, ElType = Kata(atau mesin kata?)

	static MATRIKS Ruangan1;
	static MATRIKS Ruangan2;
	static MATRIKS Ruangan3;
	static MATRIKS Dapur;
	//ubah matriks.h buat representasi ruangan, ElType tetep int, tapi kalo kosong=0, Meja=1-4, Player(P) = 5, Kursi kosong(X) = 6, kursi ada(C) = 7, Meja naroh bahan(M) = 8, Tray(T) = 9
	static Kata command;
	//Mesin Karakter + Mesin Kata buat baca informasi player dr file eksternal, informasi peta(skrg lg dimana dll), baca command dr pengguna, sama baca savefile

	static Queue Antrian;
	//Prioqueue buat antrean, isinya bakalan 4 sama 2, plus ditambahin variabel waktu nunggunya(30 satuan waktu)

	static Stack Makanan;
	static Stack Bahan;
	//Stack buat tumpukan makanan di tangan dan di nampan, infotype = Kata(atau mesin kata?)
	//urg bingung, apakah tumpukan di tangan itu maksudnya makanan yg lg dibawa, terus di nampan itu yg lg di tempat bikin makan dan itu dibuat stack jg?


	//List buat Implementasi graf(?)

	//Tree buat resep

	//Graph buat "world"nya <- carry us bim, kata kakaknya tanya ke anggota yg udh cp aja

	void ExitMessage(boolean SaveGame);
	//ntar bakal dipake di command exit sama exitnya main menu, dia bakal nampilin message kalo keluar game dan bakalan ngesave kalo savegamenya true
	//tampilin credit pembuat game
	/*	printf("Kelas K-1\n");
	printf("Kelompok Warteg Bahari\n");
	printf("Bimo Adityarahman Wiraputra/13517004\n");
	printf("Ricky Yuliawan Pohan/13517025\n");
	printf("Ahmad Rizqee Nurhani/13517058\n");
	printf("Naufal Aditya Dirgandhavi/13517064\n");
	printf("Ahmad Rizal Alifio/13517076\n\n");*/

	void TampilanProgramUtama();
	//ntar bakal nampilin program utamanya
	void SaveFile();
	//bakal ngesave ke file eksternal dgn format yg di tampilan
	void LoadFile();
	//bakal dipake sama main menu yg Load game
	char MatriksToChar(int y);
	//ubah isi matriks jadi char

#endif