#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evento.h"

// NOMES DISPONIVEIS
char *listaDeNomes[] = {
    "Festival de Musica",
    "Feira de Artesanato",
    "Esposicao de Arte",
    "Show ao Vivo",
    "Feira de Livro",
    "Corrida de Rua",
    "Show de Fogos de Artificio",
    "Semana de Moda",
    "Encontro de Ciclistas",
    "Rodeio"
};

Evento GerarEvento() {
    Evento Aux;
    strcpy(Aux.nome, listaDeNomes[rand() % 9]); // SELECAO DE NOMES USANDO FUNCAO RAND()
    Aux.avaliacao = 1 + rand() % 10; // ATRIBUICAO DE NOTA USANDO FUNCAO RAND()
    return Aux;
}

void ImprimirEvento(Evento x) {
    printf("%s (nota %d)\n", x.nome, x.avaliacao);
}