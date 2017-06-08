#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int Voos(int *assentosReservados[50][10]) // Função para calcular número de reservas feitas para cada avião.
{
    int i, j, lug=1, voo=1001, nreservas;
    for (i = 0; i<50; i++) //Imprimir Reservas já feitas
    {
        nreservas=10;
        printf("\n*** Voo %d ***", voo);
        for(j=0; j<10; j++)
        {
            lug ++;
            if(assentosReservados[i][j] == 0)
            {
                nreservas--;
            }
        }
        lug=1;
        voo ++;

        if (voo==1011 || voo==2011 || voo==3011 || voo==4011)
        {
            voo = voo + 990;
        }
        printf("\n Total de reservas: %d",nreservas );
        printf("\n");
    }

}

int imprimiTudo (int *assentosReservados[50][10]) // Função que imprime todas as reservas e total de passageiros por avião.
{
    int i, j, lug=1, voo=1001, nreservas;
    for (i = 0; i<50; i++) //Imprimir Reservas já feitas
    {
        printf("\n*** Voo %d ***\n", voo);
        nreservas=10;
        for(j=0; j<10; j++)
        {
            printf("%d - %09d ", lug, assentosReservados[i][j]);
            lug ++;
            if(assentosReservados[i][j] == 0)
            {
                nreservas--;
            }
            if (lug==6)
            {
                printf("\n");
            }
        }
        printf("\n");
        lug=1;
        voo ++;

        if (voo==1011 || voo==2011 || voo==3011 || voo==4011)
        {
            voo = voo + 990;
        }
        printf("ToTal de reservas: %d",nreservas );
        printf("\n");
    }
}


void assentosOcupados (int *assentosReservados[50][10]) //Preencher 70% das reservas NAO MEXER >>>> PRONTO>>>>
{
    int i, j, sotI, sotJ, contLugarOcup=0, cpf, aux=0;

    for (i = 0; i<50; i++) //Zerar a tabela
    {
        for(j=0; j<10; j++)
        {
            assentosReservados[i][j] = 0;
        }
    }

    while (contLugarOcup<=350) //preenche os lugares sortidos caso estejam vagos
    {

        sotI =  rand()%50; //sorteia um avião
        sotJ = rand()%10; // sorteia uma vaga
        aux = 0; // auxilia verificação de mesmo cpf por voo


        if (assentosReservados[sotI][sotJ] == 0) //verifica se a reserva tá vaga
        {
            cpf=(rand()%1000)*1000000;
            cpf=cpf+(rand()%1000)*1000;
            cpf=cpf+(rand()%1000);
            for (j=0; j<10; j++)  //confere se não existe outra reserva com o mesmo cpf
            {
                if (cpf==assentosReservados[sotI][j])
                {
                    aux = 1; //indica reserva com CFP igual
                }

            }
            if (aux==0)  // adiciona apenas se não tiver outra reserva com o mesmo cpf
            {
                assentosReservados[sotI][sotJ] = cpf;
                contLugarOcup ++;
            }
        }
    }


    return;
}

int imprimir(int *assentosReservados[50][10],int voo, int numero_voo) // Função para imprimir reservas pelo número do avião.
{

    int i, q, indice=1, num_reservas=10;

        printf("\n\n*** Voo %d ***\n", numero_voo);
        for(q=0; q<10; q++)
        {
            printf("%d ", indice, assentosReservados[voo][q]);
            indice ++;
            if(assentosReservados[voo][q] == 0)
            {
                num_reservas--;
            }
            if (indice==6)
            {
                printf("\n");
            }
        }
        printf("\n");
        indice=1;
        printf("\n Total de reservas:  %d \n",num_reservas );


    return;



}

void listaReservas(int resposta, int *assentosReservados[50][10])// Menu para escolha das opções de imprimir reservas.
{
    int voo, consulta;

    switch(resposta)
    {
        case 1:
            printf("\n\n");
            printf("Favor Digitar o Voo desejado.\n");
            scanf("%d", &voo);
            printf("\n\n");
            consulta = numIVoo(voo);
            if (consulta >=0 && consulta < 50)
            {
                printf("\n>>> Lista de reservas para o voo informado. <<<");
                imprimir(assentosReservados, consulta, voo);// Função para imprimir reservas pelo número do avião.
            }
        break;

        case 2:
            printf("\n>>> Numeros de reservas por voo. <<<");
            Voos(assentosReservados);// Função para calcular número de reservas feitas para cada avião.
            break;

        case 3:
            printf("\n>>> Numeros de reservas por voo e lista dos passageiros por assento. <<<");
            imprimiTudo(assentosReservados);// Função que imprime todas as reservas e total de passageiros por avião.
            break;
        case 4:
            return;
        default:
            printf("\n *** A opcao escolhida nao existe ***\n\n");
    }
    return;


}

int numIVoo (int vooInf) //identifica o I do voo informado pelo usuario.<<<< se a função retornar 99, voo nao existe<<<<PRONTO<<<
{
    switch (vooInf)
    {
    case 1001:
        return (0);
        break;
    case 1002:
        return (1);
        break;
    case 1003:
        return (2);
        break;
    case 1004:
        return (3);
        break;
    case 1005:
        return (4);
        break;
    case 1006:
        return (5);
        break;
    case 1007:
        return (6);
        break;
    case 1008:
        return (7);
        break;
    case 1009:
        return (8);
        break;
    case 1010:
        return (9);
        break;
    case 2001:
        return (10);
        break;
    case 2002:
        return (11);
        break;
    case 2003:
        return (12);
        break;
    case 2004:
        return (13);
        break;
    case 2005:
        return (14);
        break;
    case 2006:
        return (15);
        break;
    case 2007:
        return (16);
        break;
    case 2008:
        return (17);
        break;
    case 2009:
        return (18);
        break;
    case 2010:
        return (19);
        break;
    case 3001:
        return (20);
        break;
    case 3002:
        return (21);
        break;
    case 3003:
        return (22);
        break;
    case 3004:
        return (23);
        break;
    case 3005:
        return (24);
        break;
    case 3006:
        return (25);
        break;
    case 3007:
        return (26);
        break;
    case 3008:
        return (27);
        break;
    case 3009:
        return (28);
        break;
    case 3010:
        return (29);
        break;
    case 4001:
        return (30);
        break;
    case 4002:
        return (31);
        break;
    case 4003:
        return (32);
        break;
    case 4004:
        return (33);
        break;
    case 4005:
        return (34);
        break;
    case 4006:
        return (35);
        break;
    case 4007:
        return (36);
        break;
    case 4008:
        return (37);
        break;
    case 4009:
        return (38);
        break;
    case 4010:
        return (39);
        break;
    case 5001:
        return (40);
        break;
    case 5002:
        return (41);
        break;
    case 5003:
        return (42);
        break;
    case 5004:
        return (43);
        break;
    case 5005:
        return (44);
        break;
    case 5006:
        return (45);
        break;
    case 5007:
        return (46);
        break;
    case 5008:
        return (47);
        break;
    case 5009:
        return (48);
        break;
    case 5010:
        return (49);
        break;
    default:
        printf("\n*** CODIGO 0 *** \n>>> Esse voo nao existe ***\n*** Confira o numero digitado e tente novamente <<<\n\n");
        return (99);
    }
}

int mostrarReservas (int *assentosReservados[50][10]) //MOSTRAR VAGAS DE TODOS OS AVIOES >>>>>>>>PRONTO>>>>>>NAO MEXER
{
    int i, j, lug=1, voo=1001;
    for (i = 0; i<50; i++) //Imprimir Reservas já feitas
    {
        printf("\n\n*** Voo %d ***\n", voo);
        for(j=0; j<10; j++)
        {
            printf("%d - %09d ", lug, assentosReservados[i][j]);
            lug ++;
            if (lug==6)
            {
                printf("\n");
            }
        }
        printf("\n");
        lug=1;
        voo ++;

        if (voo==1011 || voo==2011 || voo==3011 || voo==4011)
        {
            voo = voo + 990;
        }
    }
}

int assentosVagos (int iInf, int *assentosReservados[50][10]) //funcao para mostrar as vagas de UM avião <<<PRONTO<<< NAO MEXER <<<
{
    int j, i, lug=1, cont=0;
    for (i = 0; i<50; i++) //corre as linhas procurando o avião
    {
        if (iInf == i)  //se o aviao informado for igual a linha, o programa realiza um FOR com o J para verificar as vagas
        {
            for(j=0; j<10; j++)
            {
                if (assentosReservados[i][j] == 0)
                {
                    printf(">> %d << ", lug);
                    cont++;
                }
                lug ++;
            }
            if (cont==0)
            {
                printf("\n>> 0 <<\n***CODIGO 1***\n>>> O voo não possui assentos vagos <<<\n");
                return (0);
            }
            else if (cont==1)
            {
                printf("\n*** E o Unico Assento Disponivel***\n");
                return (1);
            }
            else
            {
                printf("\n***Sao os Assentos Disponiveis.***\n");
                return (1);
            }
        }
    }
}

void mostrarInclu (int voo, int *assentosReservados[50][10])  //mostrar na tela APENAS UM VOO <<< PRONTO <<< NAO MEXER <<<
{
    int j, lug = 1;
    for (j=0; j<10; j++)
    {
        printf("%d - %09d ", lug, assentosReservados[voo][j]);
        lug ++;
        if (lug==6)
        {
            printf("\n");
        }
    }
    printf("\n\n");
}

int incluirReserva(int cpf, int voo, int assentoEscolhido, int *assentosReservados[50][10]) //Função de incluir reservas. NAO MEXER
{
    int j;
    assentoEscolhido --;
    for (j=0; j<10; j++)
    {
        if (assentosReservados[voo][j] == cpf)
        {
            return 2;
        }
    }
    if (assentosReservados[voo][assentoEscolhido] != 0)
    {
        return 3;
    }
    else
    {
        assentosReservados[voo][assentoEscolhido]=cpf;
        return 4;
    }

}

int excluirReserva(int cpf, int voo, int *assentosReservados[50][10]) //Função de Excluir reservas. **** PRONTO <<< NAO MEXER...
{
            int j, aux = 0;
                    for (j=0; j<10; j++)
                    {
                        if (assentosReservados[voo][j] == cpf)
                            {
                                assentosReservados[voo][j] = 0;
                                return (2);
                            }
                    }
                            return (1);

}



int main () //Menu Principal
{
    int opcaoEscolhida, i, j, cpf, voo, opcIncl, assentoEscolhido, resIncl, restExcl, resimprime;
    int assentosReservados [50][10];

    assentosOcupados(assentosReservados);    // chama a funcao de preencher automaticamente as tabelas
    mostrarReservas(assentosReservados);      //mostrar todas as vagas

    //Menu
    printf("\n\n>>> Digite o numero opcao desejada: \n 1 - Incluir Reserva \n 2 - Excluir Reserva \n 3 - Imprimir Reserva. \n 0 - Sair \n\n");
    scanf("%d",&opcaoEscolhida);
    while (opcaoEscolhida != 0) //Seleciona funcao desejada
    {
        switch (opcaoEscolhida)
        {
        case 1: //INCLUIR CPF
            printf("Favor Digitar o CPF do passageiro.\n");
            scanf("%d", &cpf);
            printf("Favor Digitar o Voo desejado.\n");
            scanf("%d", &voo);
            printf("\n\n");
            voo = numIVoo(voo);
            //printf("Voo Desejado %d", voo); teste para verificar o valor de I
            if (voo >=0 && voo < 50)
            {
                opcIncl = assentosVagos(voo, assentosReservados);
                if (opcIncl==1)
                {
                    printf("\n>>>Digite o assento requirido.\n");
                    scanf("%d",&assentoEscolhido);

                    resIncl = incluirReserva(cpf, voo, assentoEscolhido, assentosReservados);
                    switch (resIncl)
                    {
                    case 2:
                        printf(" *** CODIGO 2: *** \n>>> Passageiro ja possui reserva nesse voo. <<<");
                        break;
                    case 3:
                        printf("*** CODIGO 3: ***\n >>> O assento selecionado NAO esta vago, favor tentar novamente <<<");
                        break;
                    case 4:
                        printf("*** CODIGO 4: ***\n >>> INCLUSAO REALIZADA COM SUCESSO <<<\n\n");
                        mostrarInclu(voo, assentosReservados);
                        break;
                    }
                }
            }
            system("pause");
            break;
        case 2:

            printf("Favor Digitar o CPF do passageiro.\n");
            scanf("%d", &cpf);
            printf("Favor Digitar o Referente Voo.\n");
            scanf("%d", &voo);

            voo = numIVoo(voo);

            if (voo >=0 && voo < 50)
            {

                restExcl = excluirReserva(cpf, voo, assentosReservados);

                switch (restExcl)
                {
                case 1:
                    printf("\n\n*** CODIGO 1: *** \n>>> PASSAGEIRO NAO POSSUI RESERVA NESSE VOO. <<<\n\n");
                    break;
                case 2:
                    printf("\n\n*** CODIGO 2: ***\n >>> RESERVA EXCLUIDA COM SUCESSO <<<\n\n");
                    mostrarInclu(voo, assentosReservados);
                    printf("\n\n");
                    break;
                }
            }
            system("pause");
            break;
        case 3:
            printf("\n *** Imprimir Reserva *** \n\n");
            printf("\n\n>>> Digite o numero opcao desejada: \n 1 - Lista de reservas por voo \n 2 - Numero de reservas realizadas para cada voo\n 3 - Total de reservas para cada voo com lista de passageiros \n 4 - Voltar \n\n");

            scanf("%d",&resimprime);
            listaReservas(resimprime,assentosReservados);
            system("pause");
            break;
        default:
            printf("\n *** A opcao escolhida nao existe ***\n\n");
            system("pause");
        }
        printf("\n\n>>> Digite o numero opcao desejada: \n 1 - Incluir Reserva \n 2 - Excluir Reserva \n 3 - Imprimir Reserva. \n 0 - Sair \n\n");
        scanf("%d",&opcaoEscolhida);
    }
    printf("\n *** Opcao de SAIR foi selecionada ***  \n *** O Programa Sera Fechado ***\n\n");
    system("pause");
    return (0);
}
