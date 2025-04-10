#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arvore.h"
#include "ordem.h"

int main()
{
    // GERACAO AUTOMATICA DE CIDADES
    srand(time(NULL));
    TArvore arvore;
    printf("\n\t>>>>>> MSG: Gerando cidades...\n");
    
    // ESCOLHA DE METODO DE ORDENAGEM
    int metodo = 0;
    int aleatorio = 0;
    do {
        printf("\n\t------- METODOS DE ORDENAGEM -------");
        printf("\n\t1. Bubble Sort");
        printf("\n\t2. Selection Sort");
        printf("\n\t3. Insertion Sort");
        printf("\n\t4. Shellsort");
        printf("\n\t5. Heapsort");
        printf("\n\t6. Mergesort");
        printf("\n\t7. Quicksort");
        printf("\n\t8. Aleatorio");
        printf("\n\t------------------------------------\n");
        printf("\nEscolha o metodo de ordenagem: ");
        scanf("%d", &metodo);
        if(metodo == 8) {
            aleatorio = 1;
        }
        if(metodo <= 0 || metodo > 8) {
            printf("\n>>>>>> MSG: Digite uma opcao valida!!!\n");
            metodo = 0;
        }
    } while(metodo == 0);
    
    // GERACAO E ORDENAGEM DE EVENTOS
    for(int i = 0; i < 7; i++) {
        TItem item;
        item.cep = i + 1;
        item.media = 0;
        for(int j = 0; j < 3; j++) {
            // Evitar eventos semelhantes
            do {
                item.eventos[j] = GerarEvento();
            } while(strcmp(item.eventos[j].nome, item.eventos[j - 1].nome) == 0);
            item.media = item.media + item.eventos[j].avaliacao;
        }
        item.media = item.media / 3;
        if(aleatorio == 1) {
            metodo == rand() % 7 + 1; // METODO ALEATORIO
        }
        if(metodo == 1) {
            BubbleSort(item.eventos, 3);
        } else if(metodo == 2) {
            SelectionSort(item.eventos, 3);
        } else if(metodo == 3) {
            InsertionSort(item.eventos, 3);
        } else if(metodo == 4) {
            Shellsort(item.eventos, 3);
        } else if(metodo == 5) {
            Heapsort(item.eventos, 3);
        } else if(metodo == 6) {
            Mergesort(item.eventos, 0, 2);
        } else {
            Quicksort(item.eventos, 0, 2);
        }
        Inserir(&arvore.raiz, NULL, item);
    }
    printf("\n\t>>>>>> MSG: Cidades geradas!!!\n");
    
    // MENU PRINCIPAL
    int opcao;
    do {
        printf("\n\t---------- OPCOES DE MENU ----------");
        printf("\n\t1. EXIBIR CIDADES");
        printf("\n\t2. PESQUISAR CIDADE");
        printf("\n\t3. SAIR");
        printf("\n\t------------------------------------");
        
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                // Código para opção de menu EXIBIR CIDADES
                int ordem = 0;
                printf("\n1. Central");
                printf("\n2. Pre-Ordem");
                printf("\n3. Pos-Ordem");
                printf("\n\nDigite uma opcao: ");
                fflush(stdin);
                scanf("%d", &ordem);
                printf("\n");
                switch(ordem) {
                    case 1:
                        Central(arvore.raiz);
                        break;
                    case 2:
                        PreOrdem(arvore.raiz);
                        break;
                    case 3:
                        PosOrdem(arvore.raiz);
                        break;
                    default:
                        printf(">>>>>> MSG: Digite uma opcao valida!!!\n");
                    }
                break;
            case 2:
                // Código para opção de menu PESQUISAR CIDADE
                TItem pesquisa;
                printf("Insira o CEP: ");
                fflush(stdin);
                scanf("%d", &pesquisa.cep);
                if(Pesquisar(arvore.raiz, pesquisa) != NULL) {
                    printf("\nCidade %d (nota media: %.2f)\n", pesquisa.cep, Pesquisar(arvore.raiz, pesquisa) -> item.media);
                    for(int i = 0; i < 3; i++) {
                        ImprimirEvento(Pesquisar(arvore.raiz, pesquisa) -> item.eventos[i]);
                    }
                } else {
                    printf("\n>>>>>> MSG: CEP nao reconhecido. Digite uma opcao valida!!!\n");
                }
                break;
            case 3:
                // Código para opção de menu SAIR
                printf("\n\t>>>>>> MSG: Saindo do MODULO...!!!");
                break;
            default:
                printf("\n\t>>>>>> MSG: Digite uma opcao valida!!!\n");
            }
    } while(opcao != 3);

    return 0;
}