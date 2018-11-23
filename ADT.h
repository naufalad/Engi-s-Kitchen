/* File : ADT.h */
/* kumpulan struktur data*/


#ifndef adt_H
#define adt_H

	#include "boolean.h"
	#include "point.h"
	#include "jam.h"
	#include "mesinkar.h"
	#include "mesinkata.h"
	#include "arraypesanan.h"
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
		int ruangan;
	} Player;
	Player Pemain;
	JAM RealTime;
	typedef struct{
		POINT posisi; //mejanya ada di titik berapa
		int kursi; //ada berapa customer yang bisa ditempatkan disitu
		int NCustomer;
	} MejaMakan;

	typedef struct{
		POINT posisi;
		Kata bahan;
	} MejaDapur;
	//bakal disesuain sama real time, buat dipake di savegame
	//bakalan NextNDetik mulu tiap program berjalan(kecuali ga harus real time, kalo ga harus ntar bisa diconvert dr lama main)

	TabPesanan Pesanan;
	//ubah array.h buat orderan, ElType = Kata(atau mesin kata?)
	typedef struct{
		MATRIKS M;
		POINT P1;
		POINT P2;
		MejaMakan M1;
		MejaMakan M2;
		MejaMakan M3;
		MejaMakan M4;
	}Ruang;
	Ruang Ruangan1;
	Ruang Ruangan2;
	Ruang Ruangan3;
	typedef struct{
		POINT posisi;
		Stack bahan;
	}Tray;
	typedef struct{
		MATRIKS M;
		POINT P1;
		POINT P2;
		Tray T;
		MejaDapur M1;
		MejaDapur M2;
		MejaDapur M3;
		MejaDapur M4;
		MejaDapur M5;
		MejaDapur M6;
		MejaDapur M7;
		MejaDapur M8;
		MejaDapur M9;
		MejaDapur M10;
		MejaDapur M11;
		MejaDapur M12;
		MejaDapur M13;
		MejaDapur M14;
		MejaDapur M15;
	}RuangDapur;

	RuangDapur Dapur;
	//ubah matriks.h buat representasi ruangan, ElType tetep int, tapi kalo kosong=0, Meja=1-4, Player(P) = 5, Kursi kosong(X) = 6, kursi ada(C) = 7, Meja naroh bahan(M) = 8, Tray(T) = 9
	Kata command;
	//Mesin Karakter + Mesin Kata buat baca informasi player dr file eksternal, informasi peta(skrg lg dimana dll), baca command dr pengguna, sama baca savefile

	Queue Antrian;
	//Prioqueue buat antrian, isinya bakalan 4 sama 2, plus ditambahin variabel waktu nunggunya(30 satuan waktu)

	Stack Makanan;
	Stack Tangan;
	//Stack buat tumpukan makanan di tangan dan di nampan, infotype = Kata(atau mesin kata?)
	//urg bingung, apakah tumpukan di tangan itu maksudnya makanan yg lg dibawa, terus di nampan itu yg lg di tempat bikin makan dan itu dibuat stack jg?


	//List buat Implementasi graf(?)

	BinTree Resep;


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
	void init_ruangan1(Ruang *Ruangan1);
	void init_ruangan2(Ruang *Ruangan1);
	void init_ruangan3(Ruang *Ruangan1);
	void init_dapur(RuangDapur *Dapur);

#endif