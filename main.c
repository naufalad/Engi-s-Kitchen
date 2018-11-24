//main program

#include <stdio.h>
#include "boolean.h"
#include "ADT.h"
#include "cobatubes.h"

int main(){
	int pilihan;
	boolean StartGame = false;
	boolean exit = false;
	
	Resep = assignResep();
	RealTime = CurrentTime();
	printf("===============SELAMAT DATANG DI ENGI'S KITCHEN EXPANSION!===============\n\n");


	do{
		printf("MAIN MENU : \n");
		printf("1. New Game\n");
		printf("2. Start Game\n");
		printf("3. Load Game\n");
		printf("4. Exit\n");
		printf("Masukkan Pilihan Anda : ");
		scanf("%d", &pilihan);
		init_all();
		switch (pilihan){
			case 1 :
			printf("Masukkan nama anda(Max 6 huruf) : ");
			char c;
			scanf("%c", &c);
			Pemain.nama = InputKata();
			printf("\n\n");
			printf("Untuk mulai permainan, silahkan pilih Start Game pada Main Menu.\n\n");
			break;
			
			case 2 :
			if(!(IsEqKata(Pemain.nama, StringToKata("")))) StartGame = true;
			else printf("Nama belum di input! Silahkan kembali ke main menu dan pilih New Game atau Load Game.\n\n");
			break;
			//ngecek udh ada namanya atau belom, kalo belom suruh input lg

			case 3 : 
			LoadFile();
			printf("Untuk mulai permainan, silahkan pilih Start Game pada Main Menu.\n");
			//read file eksternal
			case 4 :
			ExitMessage(false);
			exit = true;
			break;
		}
		
				
	}while((StartGame == false)&&(exit==false));
	if(StartGame){
		printf("\nSelamat datang, Chef ");
		OutputKata(Pemain.nama);
		printf(".\n\n");
		printf("Dikisahkan pada suatu hari, anda sebagai seorang Chef membuka suatu restoran bernama Engi's Kitchen. Hanya dalam satu tahun, restoran tersebut berkembang pesat dan sudah bisa dibilang sukses dan berjaya.\n\n");
		printf("Sekarang anda berencana mengembangkan bisnis ini lebih lanjut. Namun sebelum itu, anda mencoba mensimulasikannya terlebih dahulu dengan program ini.\n\n");
		printf("Anggaplah simulasi ini seperti anda menjalankan restoran yang sebenarnya, Selamat bermain!\n\n");
		

		//MAIN WHILE LOOP
		char c;
		scanf("%c", &c);
		do{ 
			assignMatriks();
			TampilanProgramUtama();
			command= InputKata();
			if(IsEqKata(command, StringToKata("GU"))) GU(&Pemain);
			else if(IsEqKata(command, StringToKata("GD"))) GD(&Pemain);
			else if(IsEqKata(command, StringToKata("GL"))) GL(&Pemain);
			else if(IsEqKata(command, StringToKata("GR"))) GR(&Pemain);
			//else if(IsEqKata(command, StringToKata("ORDER"))) ORDER();
			else if(IsEqKata(command, StringToKata("PUT"))) PUT(&Tangan, &(Dapur).T.bahan);
			//else if(IsEqKata(command, StringToKata("TAKE"))) TAKE(&Tangan, );
			else if(IsEqKata(command, StringToKata("CH"))) CH(&Tangan);
			else if(IsEqKata(command, StringToKata("CT"))) CT(&(Dapur).T.bahan);
			//else if(IsEqKata(command, StringToKata("PLACE"))) PLACE();
			//else if(IsEqKata(command, StringToKata("GIVE"))) GIVE(Pemain, &Makanan, );
			else if(IsEqKata(command, StringToKata("RECIPE"))) RECIPE(Resep);
			else if(IsEqKata(command, StringToKata("SAVE"))) SAVE();
			else if(IsEqKata(command, StringToKata("LOAD"))) LOAD();
			else if(IsEqKata(command, StringToKata("EXIT"))) EXIT(&exit);
			TulisPOINT(Pemain.posisi);
			//buat ngelakuin sesuai inputan
		}while(!exit);
		printf("Jam Sekarang : ");
		TulisJAM(RealTime);
		printf("Mau disave?[1 untuk Ya]");
		scanf("%d", &pilihan);
		if (pilihan==1) ExitMessage(true);
		else ExitMessage(false);
		}
	
	return 0;
}