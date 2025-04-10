#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "evento.h"
#include "ordem.h"

// BUBBLE SORT
void BubbleSort(Evento *A, int n) {
    int i, j;
    Evento x;
    for(i = 0; i < n - 1; ++i) {
        for(j = 0; j < n - i - 1; ++j) {
            if(A[j].avaliacao < A[j + 1].avaliacao) {
                x = A[j];
                A[j] = A[j + 1];
                A[j + 1] = x;
            }
        }
    }
}

// SELECTION SORT
void SelectionSort(Evento *A, int n) {
    int i, j, Max;
    Evento x;
    for(i = 0; i < n - 1; i++) {
        Max = i;
        for(j = i + 1; j < n; j++) {
            if(A[j].avaliacao > A[Max].avaliacao) {
                Max = j;
            }
        }
        // movimentação
        if(i != Max) {
            x = A[i];
            A[i] = A[Max];
            A[Max] = x;
        }
    }
}

// INSERTION SORT
void InsertionSort(Evento *A, int n) {
    int i, j;
    Evento x;
    for(i = 1; i < n; i++) {
        x = A[i];
        j = i - 1;
        while(j >= 0 && A[j].avaliacao < x.avaliacao) {
            A[j + 1] = A[j]; // movimentação
            j--;
        }
        A[j + 1] = x; // inserção
    }
}

// SHELLSORT
void Shellsort(Evento *A, int n) {
    int i, j;
    int h = 1;
    Evento x;
    do {
        h = h * 3 + 1;
    } while(h < n);
    do {
        h /= 3;
        for(i = h; i < n; i++) {
            x = A[i];
            j = i;
            while(j >= h && A[j - h].avaliacao < x.avaliacao) {
                A[j] = A[j - h];
                j -= h;
            }
            A[j] = x;
        }
    } while(h != 1);
}

// HEAPSORT
void MaxHeapify(Evento *A, int i, int n) {
    Evento aux;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    int maior = i;
    if(esq < n && A[esq].avaliacao < A[maior].avaliacao) {
        maior = esq;
    }
    if(dir < n && A[dir].avaliacao < A[maior].avaliacao) {
        maior = dir;
    }
    if(maior != i) {
        aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;
        MaxHeapify(A, maior, n);
    }
}

void BuildMaxHeap(Evento *A, int n) {
    int i;
    for(i = n / 2 - 1; i >= 0; i--) {
        MaxHeapify(A, i, n);
    }
}

void Heapsort(Evento *A, int n) {
    Evento aux;
    int tam = n;
    BuildMaxHeap(A, n);
    for(int i = n - 1; i > 0; i--) {
        aux = A[0];
        A[0] = A[i];
        A[i] = aux;
        tam--;
        MaxHeapify(A, 0, tam);
    }
}

// MERGESORT
void Merge(Evento *A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    Evento L[n1], R[n2];
    for(int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
    }
    int i = 0, j = 0, k = p;
    while(i < n1 && j < n2) {
        if(L[i].avaliacao > R[j].avaliacao) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void Mergesort(Evento *A, int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        Mergesort(A, p, q);
        Mergesort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

// QUICKSORT
int Particao(Evento *A, int p, int r) {
    int i, j;
    Evento x, aux;
    x = A[r];
    i = p - 1;
    for(j = p; j < r; j++) {
        if(A[j].avaliacao > x.avaliacao) {
            i++;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }
    aux = A[i + 1];
    A[i + 1] = A[r];
    A[r] = aux;
    return i + 1;
}

void Quicksort(Evento *A, int p, int r) {
    if(p < r) {
        int q = Particao(A, p, r);
        Quicksort(A, p, q - 1);
        Quicksort(A, q + 1, r);
    }
}