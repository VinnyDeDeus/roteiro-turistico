#ifndef _ORDEM_H
#define _ORDEM_H

#include <stdio.h>
#include "evento.h"

// BUBBLE SORT
void BubbleSort(Evento *A, int n);

// SELECTION SORT
void SelectionSort(Evento *A, int n);

// INSERTION SORT
void InsertionSort(Evento *A, int n);

// SHELLSORT
void Shellsort(Evento *A, int n);

// HEAPSORT
void MaxHeapify(Evento *A, int i, int n);
void BuildMaxHeap(Evento *A, int n);
void Heapsort(Evento *A, int n);

// MERGESORT
void Merge(Evento *A, int p, int q, int r);
void Mergesort(Evento *A, int p, int r);

// QUICKSORT
int Particao(Evento *A, int p, int r);
void Quicksort(Evento *A, int p, int r);

// p = 0, r = 2

#endif // _ORDEM_H