#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <time.h>

int numerovoo(int *numero_voo){
int i, mil, q, indice = 0;

    for(q = 1; q <= 5; q++){
        mil = 1000;
        mil = mil * q;
        numero_voo[indice] = mil;
        for(i = 1; i <= 10; i++ ){
          numero_voo[indice] = mil + i;
          indice ++;
        }
    }
}



int main(){
    int numero_voo[50], i;
    numerovoo(numero_voo);
    for(i = 0; i < 50; i++){
        printf("\n %d", numero_voo[i]);
    }


}
