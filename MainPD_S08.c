#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"BBTPD_S08.c"

int main()
{
        int opcao;
        Fila *ptrF;
        ptrF = (Fila*) malloc (sizeof(Fila));
        inicializar(ptrF);

        do{
            Menu();
            printf("Selecione uma das opcoes abaixo:\n");
            scanf("%d", &opcao);
            fflush(stdin);

            switch(opcao){
                case 1:
                enfileirar(ptrF);
                break;

                case 2:
                impressao_naoclassica(ptrF);
                break;

                default:
                printf("Encerrando o programa\n");
                break;
            }
        }while(opcao != 3);
        return 0;
}
