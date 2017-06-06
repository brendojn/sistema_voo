#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <time.h>

int voo,cod,indice,pass,i;
int numero_voo[50],passageiros[10],numero_pass[50];

int incluir(int voo, int cpf){
    for (i = 1; i <=50; i++){
        if(numero_voo[indice] == voo){
                printf("Assentos livres no voo solicitado!\n");
            for (pass = 1; pass <= 10; pass++){
                if(passageiros[pass] == 0){
                    printf("Assento:%d.\n", pass);
                }
                else
                    printf("Voo lotado!\n");
            }
        }
    }
}

int excluir(int voo, int cpf){


    for (indice = 1; indice <=50; indice++){
        if(numero_voo[indice] == voo){
            for (pass = 1; pass<=10; pass++){
                if(passageiros[pass] == cpf){
                    passageiros[pass] == 0;
                    cod = 2;
                    numero_pass[indice]--;
                }
                else
                    cod = 1;
            }
        }
        else
            cod = 0;
    }
    return cod;
}

int imprimir(int voo){


   for (indice = 1; indice <=50; indice++){
        if(numero_voo[indice] == voo){
            printf("VOO %d\n",numero_voo[indice]);
            printf("Numero de reservas %d\n",numero_pass[indice]);
            for (pass = 1; pass <= 10; pass++){
                if(passageiros[pass] != 0){
                printf("CPF Pass:%d  -- Assento:%d\n",passageiros[pass], pass);
                cod = 1;
                }

            }
            printf("Fim da relacao!");
        }
        else
            cod = 0;

    }
    if(cod = 0){
        return cod;
    }
}



int numerovoo(){



int  mil, q, i, indice = 1;

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

    numerovoo();
    int opcao,cpf,numero_voo[50],i,impri;

    printf("Digite o codigo da opcao desejada:\n (1)Incluir reserva.\n (2)Excluir reserva.\n (3)Imprimir reservas.\n");
    scanf("%d",&opcao);
    if(opcao == 1){
        printf("Digite o numero do voo:");
        scanf("%d",&voo);
        printf("Digite o numero CPF do passageiro:");
        scanf("%d",&cpf);
        incluir(voo,cpf);
    }


    if(opcao == 2){
        printf("Digite o numero do voo:");
        scanf("%d",&voo);
        printf("Digite o numero CPF do passageiro:");
        scanf("%d",&cpf);
        excluir(voo,cpf);
            if(cod = 0){
                printf("Voo inexistente!\n");
            }
            else if(cod = 1){
                printf("Passageiro inexistente no voo selecionado!\n");

            }
                else if(cod = 2){
                    printf("Reserva excluida com sucesso!\nNumero total de passageiros no voo:%d\n",numero_pass[voo]);
                }
    }
    else if(opcao == 3){
            printf("Qual tipo de dados devem ser impressos:\n (1)Para dados de um unico voo!\n (2)Para a ocucapacao de todos os voos!\n (3)Para dados completos de todos os voos!\n ");
            scanf("%d",&impri);
            if(impri == 1){
                printf("Digite o numero do voo para imprimir os dados:\n");
                scanf("%d",&voo);
                imprimir(voo);
                if(cod = 0){
                    printf("Voo inesxistente!\n");
                }
            }
            else if(impri == 2){
                    numerovoo();
                    for (indice = 1; indice <= 50; indice++){
                        printf("O voo %d possui %d reversas!\n", numero_voo[indice], numero_pass[indice]);
                    }

                }
                else if(impri == 3){
                        for (indice = 1; indice <= 50; indice++){
                            imprimir(numero_voo[indice]);

                        }
                     }
     }

return main();
}
