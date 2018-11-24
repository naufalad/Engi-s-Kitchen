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
	#include <stdlib.h>

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
	typedef struct{
		POINT posisi; //mejanya ada di titik berapa
		int kursi; //ada berapa customer yang bisa ditempatkan disitu
		int NCustomer; //lagi ada berapa orang yang ngedudukin
		boolean isOrderTaken;
		POINT TChair[5];
	} MejaMakan;
	typedef struct{
		POINT posisi;
		Kata bahan;
	} MejaDapur;
	typedef struct{
		POINT P1;
		POINT P2;
		MejaMakan TTable[5];
	}Ruang;
	typedef struct{
		POINT posisi;
		Stack bahan;
	}Tray;
	typedef struct{
		POINT P1;
		POINT P2;
		Tray T;
		MejaDapur M[17];
	} RuangDapur;


	extern Player Pemain;
	extern JAM RealTime;
	extern TabPesanan Pesanan;
	extern Ruang Ruangan[4];
	extern MATRIKS Tampilan;
	extern RuangDapur Dapur;
	extern Kata command;
	extern Queue Antrian;
	extern Stack Makanan;
	extern Stack Tangan;
	extern Graph Denah;
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
	Kata GetRandomMenuName(int MenuIdx);
#endif