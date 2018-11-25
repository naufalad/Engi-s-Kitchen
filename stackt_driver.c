#include "stackt.h"

int main() {
    Stack stek;
    Kata temp;
    char* tempa;
    CreateEmptyStack(&stek);

    if(IsEmptyStack(stek)) {
        printf("kosong\n");
    } else {
        printf("gakosong\n");
    }

    temp = StringToKata("Input_1");
    PushStack(&stek,temp);

    temp = StringToKata("Input_2");
    PushStack(&stek,temp);

    temp = StringToKata("Input_3");
    PushStack(&stek,temp);

    PopStack(&stek,&temp);
    TulisStack(stek);
    OutputKata(temp);
    return 0;
}