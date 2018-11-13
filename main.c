//main program

#include <stdio.h>
#include "boolean.h"
#include "ADT.h"
#include "command.h"

int main()
{
	int pilihan;
	boolean StartGame = false;
	boolean exit = false;
	
	printf("===============SELAMAT DATANG DI ENGI'S KITCHEN EXPANSION!===============\n\n");


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
			//input kata pemain.nama
			//apakah mau di validasi inputannya?
			printf("Untuk mulai permainan, silahkan pilih Start Game pada Main Menu.\n")
			break;
			
			case 2 :
			if(Pemain.nama != NULL) StartGame = true;
			else printf("Nama belum di input! Silahkan kembali ke main menu dan pilih New Game atau Load Game.\n")
			break;
			//ngecek udh ada namanya atau belom, kalo belom suruh input lg

			case 3 : 
			LoadFile();
			printf("Untuk mulai permainan, silahkan pilih Start Game pada Main Menu.\n")
			//read file eksternal
			case 4 :
			ExitGame(false);
			exit = true;
			break;
		
				
	}while((StartGame == false)&&(exit==false));
	if(StartGame){
		printf("\nSelamat datang, Chef");
		//output nama
		printf(".\n\n");
		printf("Dikisahkan pada suatu hari, anda sebagai seorang Chef membuka suatu restoran bernama Engi's Kitchen. Hanya dalam satu tahun, restoran tersebut berkembang pesat dan sudah bisa dibilang sukses dan berjaya.\n");
		printf("Sekarang anda berencana mengembangkan bisnis ini lebih lanjut namun sebelum itu, anda mencoba mensimulasikannya terlebih dahulu dengan program ini.\n");
		printf("Anggaplah simulasi ini seperti anda menjalankan restoran yang sebenarnya, Selamat bermain!\n");
		
		/*do{ 
			TampilanProgramUtama() 
			switch command{
				case "GU":
				GU();
				break;
			}
			//buat ngelakuin sesuai inputan, pake switch case
		}while (command!=Exit);*/
		printf("Jam Sekarang : ");
		//output RealTime
		printf("Mau disave?[1 untuk Ya]");
		scanf("%d", &pilihan);
		if (pilihan) ExitGame(true);
		else ExitGame(false);


	return 0;
}