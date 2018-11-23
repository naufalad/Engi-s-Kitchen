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
	#include "stackt.h"
	#include "prioqueue.h"
	#include "bintree.h"

	typedef struct{
		Kata nama;
		int money;
		int life;
		int time;
		POINT posisi;
	} Player;
	Player Pemain;
	JAM RealTime;
	typedef struct{
		POINT posisi;
		int kursi;

	} MejaMakan;

	typedef struct{
		POINT posisi;
		Kata bahan;
	} MejaDapur;
	//bakal disesuain sama real time, buat dipake di savegame
	//bakalan NextNDetik mulu tiap program berjalan(kecuali ga harus real time, kalo ga harus ntar bisa diconvert dr lama main)

	//TabKata Pesanan;
	//ubah array.h buat orderan, ElType = Kata(atau mesin kata?)

	MATRIKS Ruangan1;
	MATRIKS Ruangan2;
	MATRIKS Ruangan3;
	MATRIKS Dapur;
	//ubah matriks.h buat representasi ruangan, ElType tetep int, tapi kalo kosong=0, Meja=1-4, Player(P) = 5, Kursi kosong(X) = 6, kursi ada(C) = 7, Meja naroh bahan(M) = 8, Tray(T) = 9
	Kata command;
	//Mesin Karakter + Mesin Kata buat baca informasi player dr file eksternal, informasi peta(skrg lg dimana dll), baca command dr pengguna, sama baca savefile

	Queue Antrian;
	//Prioqueue buat antrean, isinya bakalan 4 sama 2, plus ditambahin variabel waktu nunggunya(30 satuan waktu)

	Stack Makanan;
	Stack Bahan;
	Stack Tangan;
	//Stack buat tumpukan makanan di tangan dan di nampan, infotype = Kata(atau mesin kata?)
	//urg bingung, apakah tumpukan di tangan itu maksudnya makanan yg lg dibawa, terus di nampan itu yg lg di tempat bikin makan dan itu dibuat stack jg?


	//List buat Implementasi graf(?)

	BinTree Resep;

	//Graph buat "world"nya <- carry us bim, kata kakaknya tanya ke anggota yg udh cp aja

	void ExitMessage(boolean SaveGame);

	void TampilanProgramUtama();
	//ntar bakal nampilin program utamanya
	void SaveFile();
	//bakal ngesave ke file eksternal dgn format yg di tampilan
	void LoadFile();
	//bakal dipake sama main menu yg Load game
	char MatriksToChar(int y);
	//ubah isi matriks jadi char
	//BinTree assignResep();
	

#endif