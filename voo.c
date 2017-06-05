#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <time.h>



int gerarCpf()
{
    int n, i;

    // Inicializa a semente com o relógio interno do computador.
    srand( (unsigned)time(NULL) );

    for(i=1 ; i <= 350 ; i++)
    {
        n = (rand()%1000)*1000000;
        n = n + (rand()%1000)*1000;
        n = n + (rand()%1000);
        // Imprime o número com 9 dígitos, completando-o com zeros à esquerda.
        printf("Numero = %09d\n", n);
    }

    return (0);

}


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
    int cpf[350], numero_voo[50], i,assentos[500],x=0,pos=0;
    numerovoo(numero_voo);
   /* for(i = 0; i < 50; i++){
        printf("\n %d", numero_voo[i]);
    }*/
    gerarCpf(cpf);

    for(x;x<500;x++){
        assentos[x] = 0;
    }

    for(x=0;x<350;x++){
        pos = cpf[x]%500;
        assentos[pos]=cpf[x];


        printf("\nAssento na posicao %d recebeu %d",pos,cpf[x]);
        }
    }




