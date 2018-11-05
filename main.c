//main program

#include <stdio.h>
#include "boolean.h"
//include semua

int main()
{
	int pilihan;
	boolean StartGame = false;
	
	printf("===============SELAMAT DATANG DI ENGI'S KITCHEN EXPANSION!===============\n\n");
	printf("Kelas K-1\n");
	printf("Kelompok Warteg Bahari\n");
	printf("Bimo Adityarahman Wiraputra/13517004\n");
	printf("Ricky Yuliawan Pohan/13517025\n");
	printf("Ahmad Rizqee Nurhani/13517058\n");
	printf("Naufal Aditya Dirgandhavi/13517064\n");
	printf("Ahmad Rizal Alifio/13517076\n\n");

	do{
		printf("MAIN MENU : \n");
		printf("1. New Game\n");
		printf("2. Start Game\n");
		printf("3. Load Game\n");
		printf("4. Exit\n");
		printf("Masukkan Pilihan Anda : ");
		scanf("%d", &pilihan);
		
		switch (pilihan){
			case 1 :
			printf("Masukkan nama anda : ");
			scanf("%d", Pemain.nama);
			//apakah mau di validasi inputannya?
			printf("Untuk mulai permainan, silahkan pilih Start Game pada Main Menu.\n")
			break;
			//scanf nama
			
			case 2 :
			if(Pemain.nama != Nil) StartGame = true;
			else printf("Nama belum di input! Silahkan kembali ke main menu dan pilih New Game atau Load Game.\n")
			break;
			//ngecek udh ada namanya atau belom, kalo belom suruh input lg

			case 3 : 
			//Status pemain(nama, life, money, time, posisi), queue, hand, nampan dll
			printf("Untuk mulai permainan, silahkan pilih Start Game pada Main Menu.\n")
			//read file eksternal
			case 4 :
			ExitGame(false);
			break;
		
		StartGame = true;
		
	}while(StartGame == false);
	//StartGame udh true
	printf("\nSelamat datang, Chef.\n\n");
	printf("Dikisahkan pada suatu hari, anda sebagai seorang Chef membuka suatu restoran bernama Engi's Kitchen. Hanya dalam satu tahun, restoran tersebut berkembang pesat dan sudah bisa dibilang sukses dan berjaya.\n");
	printf("Sekarang anda berencana mengembangkan bisnis ini lebih lanjut namun sebelum itu, anda mencoba mensimulasikannya terlebih dahulu dengan program ini.\n");
	printf("Anggaplah simulasi ini seperti anda menjalankan restoran yang sebenarnya, Selamat bermain!\n");
	


	return 0;
}

