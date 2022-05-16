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

//Função do segundo menú.
void CallMenu(int list[], int n); 

//Funções que irão ler os arquivos.
int ReadFile1000(ifstream arq, int v[],int size, int option); 
int ReadFile10000(ifstream arq, int v1[], int size, int option);
int ReadFile100000(ifstream arq, int v2[], int size, int option);

void SortFile10000(ifstream arq, int v1[], int size, int option, int op);
void SortFile10000(ifstream arq, int v2[], int size, int option, int op);
void SortFile100000(ifstream arq, int v3[], int size, int option, int op);

#endif