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
	#include "graph.h"

	#define EdgeAtas 1
	#define EdgeBawah 8
	typedef struct{
		Kata nama;
		int money;
		int life;
		int time;
		POINT posisi;
		int ruangan;
	} Player;

	extern Player Pemain;
	extern JAM RealTime;

	typedef struct{
		POINT posisi; //mejanya ada di titik berapa
		int kursi; //ada berapa customer yang bisa ditempatkan disitu
		int NCustomer;
		boolean isOrderTaken;
		POINT TChair[5];
	} MejaMakan;


	typedef struct{
		POINT posisi;
		Kata bahan;
	} MejaDapur;
	
	extern TabPesanan Pesanan;

	typedef struct{
		POINT P1;
		POINT P2;
		MejaMakan TTable[5];
	}Ruang;

	extern Ruang Ruangan[4];

	typedef struct{
		POINT posisi;
		Stack bahan;
	}Tray;

	typedef struct{
		POINT P1;
		POINT P2;
		Tray T;
		MejaDapur M[16];
	} RuangDapur;

	extern MATRIKS Tampilan;
	extern RuangDapur Dapur;
	//ubah matriks.h buat representasi ruangan, ElType tetep int, tapi kalo kosong=0, Meja=1-4, Player(P) = 5, Kursi kosong(X) = 6, kursi ada(C) = 7, Meja naroh bahan(M) = 8, Tray(T) = 9
	extern Kata command;
	//Mesin Karakter + Mesin Kata buat baca informasi player dr file eksternal, informasi peta(skrg lg dimana dll), baca command dr pengguna, sama baca savefile
	extern Queue Antrian;
	//Prioqueue buat antrian, isinya bakalan 4 sama 2, plus ditambahin variabel waktu nunggunya(30 satuan waktu)

	extern Stack Makanan;
	extern Stack Tangan;
	//Stack buat tumpukan makanan di tangan dan di nampan, infotype = Kata(atau mesin kata?)
	//urg bingung, apakah tumpukan di tangan itu maksudnya makanan yg lg dibawa, terus di nampan itu yg lg di tempat bikin makan dan itu dibuat stack jg?

	extern Graph Denah;
	//List buat Implementasi graf(?)

	extern BinTree Resep;


	void ExitMessage(boolean SaveGame);

	void TampilanProgramUtama();
	//ntar bakal nampilin program utamanya
	void SaveFile();
	//bakal ngesave ke file eksternal dgn format yg di tampilan
	void LoadFile();
	//bakal dipake sama main menu yg Load game
	char MatriksToChar(int y);
	//ubah isi matriks jadi char
	BinTree assignResep();
	void init_ruangan1();
	void init_ruangan2();
	void init_ruangan3();
	void init_dapur();
	void InitDenah();
	void init_matriks();
	void init_player();
	void init_all();
	void assignMatriks();
	int GetRandomMenu();
	int GetRandomPrio();
	int GetRandomNCust();
	int GetRandomArrival();
#endif