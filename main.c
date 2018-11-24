//main program

#include <stdio.h>
#include "boolean.h"
#include "ADT.h"
#include "cobatubes.h"
#include <unistd.h>

int main(){
	char pilihan,c;
	boolean StartGame = false;
	boolean exit = false;
	const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
	Resep = assignResep();
	RealTime = CurrentTime();
	init_all();
	printf("===============SELAMAT DATANG DI ENGI'S KITCHEN EXPANSION!===============\n\n");


	do{
		printf("MAIN MENU : \n");
		printf("1. New Game\n");
		printf("2. Start Game\n");
		printf("3. Load Game\n");
		printf("4. Exit\n");
		printf("Masukkan Pilihan Anda : ");
		scanf(" %c", &pilihan);
		switch (pilihan){
			case '1' :
			printf("Masukkan nama anda(Max 6 huruf) : ");
			Pemain.nama = InputKata();
			printf("\n\n");
			printf("Untuk mulai permainan, silahkan pilih Start Game pada Main Menu.\n\n");
			break;
			
			case '2' :
			if(!(IsEqKata(Pemain.nama, StringToKata("")))) StartGame = true;
			else printf("Nama belum di input! Silahkan kembali ke main menu dan pilih New Game atau Load Game.\n\n");
			break;
			//ngecek udh ada namanya atau belom, kalo belom suruh input lg

			case '3' : 
			LoadFile();
			printf("Untuk mulai permainan, silahkan pilih Start Game pada Main Menu.\n");
			break;
			//read file eksternal
			case '4' :
			ExitMessage(false);
			exit = true;
			break;
			default:
			printf("Inputan tidak dikenali, silahkan cek kembali.\n");
			break;
		}
		
				
	}while((StartGame == false)&&(exit==false));
	if(StartGame){
		printf("\nSelamat datang, Chef ");
		OutputKata(Pemain.nama);
		printf(".\n\n");
		printf("Anda sebagai seorang Chef membuka suatu restoran bernama Engi's Kitchen. Hanya dalam satu tahun, restoran tersebut berkembang pesat dan sudah bisa dibilang sukses dan berjaya.\n\n");
		printf("Sekarang anda berencana mengembangkan bisnis ini lebih lanjut. Sebelum itu, anda mencoba mensimulasikannya terlebih dahulu dengan program ini.\n\n");
		printf("Anggaplah simulasi ini seperti anda menjalankan restoran yang sebenarnya, Selamat bermain!\n\n");
		

		//MAIN WHILE LOOP
		scanf("%c", &c);
		do{ 
			assignMatriks();
			TampilanProgramUtama();
			command= InputKata();
			if(IsEqKata(command, StringToKata("GU"))) GU();
			else if(IsEqKata(command, StringToKata("GD"))) GD();
			else if(IsEqKata(command, StringToKata("GL"))) GL();
			else if(IsEqKata(command, StringToKata("GR"))) GR();
			else if(IsEqKata(command, StringToKata("ORDER"))) ORDER();
			else if(IsEqKata(command, StringToKata("PUT"))) PUT();
			else if(IsEqKata(command, StringToKata("TAKE"))) TAKE();
			else if(IsEqKata(command, StringToKata("CH"))) CH();
			else if(IsEqKata(command, StringToKata("CT"))) CT();
			else if(IsEqKata(command, StringToKata("PLACE"))) PLACE();
			else if(IsEqKata(command, StringToKata("GIVE"))) GIVE();
			else if(IsEqKata(command, StringToKata("RECIPE"))) RECIPE();
			else if(IsEqKata(command, StringToKata("SAVE"))) SAVE();
			else if(IsEqKata(command, StringToKata("LOAD"))) LOAD();
			else if(IsEqKata(command, StringToKata("EXIT"))) EXIT(&exit);
			else CHEAT(command);
			if(Pemain.life==0){
      		  printf("\nSayang sekali, kamu kehilangan kepercayaan dari para customer, dan akhirnya kamu memutuskan untuk gulung tikar... Skor kamu : %d\n\n", Pemain.money);
			  exit=true;
    		} 
		}while(!exit);
		printf("Jam Sekarang : ");
		TulisJAM(RealTime);
		printf("Mau disave?[Y untuk Ya] ");
		scanf(" %c", &pilihan);
		if (pilihan=='Y') ExitMessage(true);
		else ExitMessage(false);
		}
	
	return 0;
}