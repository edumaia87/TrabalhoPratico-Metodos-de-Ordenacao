#ifndef SORT_H
#define SORT_H
#include <fstream>

void menu(); // Menú onde poderá ser escolhido o método de ordenação desejado.
void menu2(); // Menú onde poderá ser escolhida a lista a ser ordenada.

//Métodos de Ordenação
int BubbleSort(int list[], int size);
void InsertionSort(int list[], int size);
void SelectionSort(int list[], int size);
void ShellSort(int list[], int size);

//Função que vai armazenar e tratar a opção escolhida pelo usuário.
void CallUserOption(int option, int op);

//Função que irá ler os arquivos.
void ReadFile(int v[], int option, int size);

// Funções que irão de fato ordenar os arquivos.
void SortFile10000(int v1[], int option, int op);
void SortFile10000(int v2[], int option, int op);
void SortFile100000(int v3[], int option, int op);

#endif