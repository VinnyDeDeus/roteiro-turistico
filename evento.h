#ifndef _EVENTO_H
#define _EVENTO_H

typedef struct {
    char nome[100];
    int avaliacao;
} Evento;

Evento GerarEvento();

void ImprimirEvento(Evento x);

#endif // _EVENTO_H