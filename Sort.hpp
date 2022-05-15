#ifndef SORT_H
#define SORT_H

void menu(); // Menú onde poderá ser escolhido o método de ordenação desejado.
void menu2(); // Menú onde poderá ser escolhida a lista a ser ordenada.

//Métodos de Ordenação
int BubbleSort(int list[]);
void InsertionSort(int list[], int n);
void SelectionSort(int list[], int n);
void ShellSort(int list[], int n);

//Função do segundo menú.
void CallMenu(int list[], int n); 

//Funções que irão ler os arquivos.
int ReadFile1000(ifstream arq, int v[], int option); 
int ReadFile10000(ifstream arq, int v1[], int option);
int ReadFile100000(ifstream arq, int v2[], int option);

int SortFile10000(ifstream arq, int v1[], int n, int option, int op);
int SortFile10000(ifstream arq, int v2[], int n, int option, int op);
#endif