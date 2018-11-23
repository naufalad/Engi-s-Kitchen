/* File: bintree.c */
/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan
   karena melibatkan modul list rekursif. */

#include "bintree.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* *** Konstruktor *** */
void Allocate(addrNode *P)
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *P = (addrNode) malloc(sizeof(Node));
    }

BinTree Tree(Kata Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
    {
    /* KAMUS LOKAL */
    BinTree temp;
    /* ALGORITMA */
    temp = AlokNode(Akar);
    if (temp != Nil)
		{
        Left(temp) = L;
        Right(temp) = R;
		}
    return (temp);
    }
void MakeTree(Kata Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *P = Tree(Akar,L,R);
    }
BinTree BuildBalanceTree(int n)
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
    {
    /* KAMUS LOKAL */
    addrNode P;
	int nL, nR;
	Kata X;
	BinTree R, L;
	/* ALGORITMA */
	if (n == 0)
        {
		return Nil;
        }
	else
        {
		X = InputKata();
        P = (addrNode) malloc(sizeof (Node));
		if (P != Nil)
            {
			Akar(P) = X;
			nL = n/2; nR = n-nL-1;
			L = BuildBalanceTree(nL);
			R = BuildBalanceTree(nR);
			Left(P) = L;
			Right(P) = R;
            }
		return P;
        }
    }
void BuildTree(BinTree *P, int* idx)
    {
    /* KAMUS LOKAL */
    Kata kata1; int i;
    /* ALGORITMA */
    ADV();
    if (CC == ')')
        {
        (*P)=Nil;
        }
    else
        {
        Allocate(P);
        Text.Length = 0;
        i = 0;
        while ((CC !='(')&&(CC!=')'))
            {
            Text.TabKata[i] = CC;
            Text.Length++;
            ADV();
            i++;
            }
        Akar(*P) = Text;
        *idx = *idx + 1;
        BuildTree(&Left(*P),idx);
        BuildTree(&Right(*P),idx);
        }
    ADV();
    }

/* Manajemen Memory */
addrNode AlokNode(Kata X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    {
    /* KAMUS LOKAL */
    addrNode P;
    /* ALGORITMA */
    P = (addrNode) malloc (sizeof (Node));
    if (P != Nil)
		{
        Akar(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
		}
    return (P);
    }
void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    free(P);
    }

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (P == Nil);
    }
boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return ((P != Nil) && (Left(P) == Nil) && (Right(P) == Nil));
    }
boolean IsUnerLeft(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return ((P != Nil) && (Left(P) != Nil) && (Right(P) == Nil));
    }
boolean IsUnerRight(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return ((P != Nil) && (Left(P) == Nil) && (Right(P) != Nil));
    }
boolean IsBiner(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return ((P != Nil) && (Left(P) != Nil) && (Right(P) != Nil));
    }

/* *** Traversal *** */
void PrintPreorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P))
		{
        printf("()");
		}
    else
		{
        printf("(");
        OutputKata(Akar(P));
        printf("\n");
        PrintPreorder(Left(P));
        PrintPreorder(Right(P));
        printf(")");
		}
    }
void PrintInorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P))
		{
        printf("()");
		}
    else
		{
        printf("(");
        PrintInorder(Left(P));
        OutputKata(Akar(P));
        PrintInorder(Right(P));
        printf(")");
		}
    }
void PrintPostorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P))
		{
        printf("()");
		}
    else
		{
        printf("(");
        PrintPostorder(Left(P));
        PrintPostorder(Right(P));
        OutputKata(Akar(P));
        printf(")");
		}
    }
void PrintSpasi(int h)
    {
    /* KAMUS LOKAL */
    int i;
    /* ALGORTIMA */
    for (i = 1; 1 <= h; i ++)
        {
        printf(" ");
        }
    }
void PrintTreeRek (BinTree P, int h, int CLevel)
    {
	/* KAMUS LOKAL */
	int i;
    /* ALGORITMA */
    if (!IsTreeEmpty(P))
		{
        for (i = 1; i <= h*(CLevel-1); i++)
			{
            printf(" ");
			}
        OutputKata(Akar(P));
        printID(Akar(P));
        if (Left(P) != Nil)
			{
            PrintTreeRek(Left(P), h, CLevel+1);
			}
        if (Right(P) != Nil)
			{
            PrintTreeRek(Right(P), h, CLevel+1);
			}
		}
    }
void PrintTree(BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    PrintTreeRek (P,h,1);
    }

/* *** Searching *** */
boolean SearchTree(BinTree P, Kata X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P))
		{
        return false;
		}
    else
		{
        if (IsEqKata(Akar(P),X))
			{
            return true;
			}
        else
			{
            return ((SearchTree(Left(P), X)) || (SearchTree(Right(P), X)));
			}
		}
    }

/* *** Fungsi-Fungsi Lain *** */
int NbElmtTree(BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P))
		{
        return 0;
		}
    else
		{
        return (1 + NbElmtTree(Left(P)) + NbElmtTree(Right(P)));
		}
    }
int NbDaun(BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P))
		{
        return 0;
		}
    else if (IsTreeOneElmt(P))
		{
        return 1;
		}
    else
		{
        if (IsUnerLeft(P))
			{
            return (NbDaun(Left(P)));
			}
        else if (IsUnerRight(P))
			{
            return (NbDaun(Right(P)));
			}
        else
			{
            return (NbDaun(Left(P)) + NbDaun(Right(P)));
			}
		}
    }
boolean IsSkewLeft(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P))
		{
        return true;
		}
    else if (IsTreeOneElmt(P))
		{
        return true;
		}
    else
		{
        if (IsUnerLeft(P))
			{
            return (IsSkewLeft(Left(P)));
			}
        else
			{
            return false;
			}
		}
    }
boolean IsSkewRight(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P))
		{
        return true;
		}
    else if (IsTreeOneElmt(P))
		{
        return true;
		}
    else
		{
        if (IsUnerRight(P))
			{
            return (IsSkewRight(Left(P)));
			}
        else
			{
            return false;
			}
		}
    }
int Level(BinTree P, Kata X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (SearchTree(P, X))
		{
        if (IsTreeOneElmt(P))
			{
            return 1;
			}
        else
			{
            return (1 + Level(Left(P), X) + Level(Right(P), X));
			}
		}
    else
		{
        return 0;
		}
    }
int Tinggi(BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
    {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (IsTreeEmpty(P))
		{
        return 0;
		}
    else
		{
        if (Tinggi(Left(P)) > Tinggi(Right(P)))
			{
            return (1 + Tinggi(Left(P)));
			}
        else
			{
            return (1 + Tinggi(Right(P)));
			}
		}
    }
