#include "mesinkata.h"
#include <stdio.h>

int main(){
    Kata X = InputKata();
    OutputKata(X);
    Kata X = StringToKata("Tes");
    OutputKata(X);
    return 0;
}