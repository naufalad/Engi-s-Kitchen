/* File : adt.h */
/* kumpulan struktur data*/

//disini kita #include semua ADT praktikum

#ifndef adt_H
	#define adt_H

	typedef struct{
		String nama;
		long life;
		long money;
		long time;
		POINT posisi;
	}Player;

	static Player Pemain;
	static JAM RealTime;
	//bakal disesuain sama real time, buat dipake di savegame
	//bakalan NextNDetik mulu tiap program berjalan(kecuali ga harus real time, kalo ga harus ntar bisa diconvert dr lama main)

	//static TabString Pesanan;
	//ubah array.h buat orderan, ElType = String(atau mesin kata?)

	//static MATRIKS Ruangan1;
	//static MATRIKS Ruangan2;
	//static MATRIKS Ruangan3;
	//static MATRIKS Dapur;
	//ubah matriks.h buat representasi ruangan(jadi char), ElType = char

	//Mesin Karakter + Mesin Kata buat baca informasi player dr file eksternal, informasi peta(skrg lg dimana dll), baca command dr pengguna, sama baca savefile

	//static Queue Antrian;
	//Queue buat antrean, isinya bakalan 4 sama 2, plus ditambahin variabel waktu nunggunya(30 satuan waktu)

	//static Stack Makanan;
	//static Stack Bahan;
	//Stack buat tumpukan makanan di tangan dan di nampan, infotype = String(atau mesin kata?)
	//urg bingung, apakah tumpukan di tangan itu maksudnya makanan yg lg dibawa, terus di nampan itu yg lg di tempat bikin makan dan itu dibuat stack jg?


	//List buat Implementasi graf(?)

	//Tree buat resep <- belom diajarin

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

#endif
