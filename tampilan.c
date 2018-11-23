#include <stdio.h>
#include "boolean.h"
#include <string.h>

int main(){
    char kosong = ' ';
    char player = 'P';
    char kursikosong = 'X';
    char meja1 = '1';
    char meja2 = '2';
    char meja3 = '3';
    char meja4 = '4';
    char konsumen = 'C';
    char nama[] = "ASDFGH";
    char command[2];
    int uang = 500;
    int life = 100;
    int time = 5;
    printf("\n┌────────────────┬───────────────┬───────────────┬────────────┐\n");
    printf("│%s\t\t │ Money: %d\t │ Life: %d\t │Time: %d     │\n", nama, uang, life, time);
    printf("├────────────────┼───┬───┬───┬───┼───┬───┬───┬───┼────────────┤\n");
    printf("│Waiting Cust    │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │Food Stack  │\n", kosong, konsumen, kosong, kosong, kosong, kosong, kosong, kosong);
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│2               │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", konsumen, meja1, konsumen, player, kosong, konsumen, meja2, konsumen);
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│                │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", kosong, konsumen, kosong, kosong, kosong, kosong, kosong, kosong);
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│                │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", kosong, kosong, kosong, kosong, kosong, kosong, kosong, kosong);
    printf("├────────────────┼───┼───┼───┼───┼───┼───┼───┼───┼────────────┤\n");
    printf("│Order           │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │Hand        │\n", kosong, kosong, kosong, kosong, kosong, kosong, kosong, kosong);
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│                │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", kosong, kursikosong, kosong, kosong, kosong, kosong, kosong, kosong);
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│                │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", kursikosong, meja3, kursikosong, kosong, kosong, kursikosong, meja4, kursikosong);
    printf("│                ├───┼───┼───┼───┼───┼───┼───┼───│            │\n");
    printf("│                │ %c │ %c │ %c │ %c │ %c │ %c │ %c │ %c │            │\n", kosong, kursikosong, kosong, kosong, kosong, kosong, kosong, kosong);
    printf("└────────────────┴───┴───┴───┴───┴───┴───┴───┴───┴────────────┘\n");
    printf(" Command : ");
    scanf("%s", command);
}