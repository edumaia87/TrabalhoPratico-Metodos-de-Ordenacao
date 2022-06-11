#include <iostream>
#include <fstream>
#include <time.h>
#include <windows.h>
#include "Sort.hpp"
#define tam1 1000
#define tam2 10000
#define tam3 100000

using namespace std;

int v1[tam1]; // Vetor para as Listas de tamanho 1000
int v2[tam2]; // Vetor para as Listas de tamanho 10000
int v3[tam3]; // Vetor para as Listas de tamanho 100000

// Menu Principal.
void menu() {
    system("color 0B");
    cout << "  \n        ����������������������������������������������������������������";
    cout << "  \n        �                                                              �";
    cout << "  \n        �                     MÉTODOS DE ORDENAÇÃO                     �";
    cout << "  \n        �                                                              �";
    cout << "  \n        ����������������������������������������������������������������";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 1 - BUBBLE SORT                                              �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 2 - INSERTION SORT                                           �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 3 - SELECTION SORT                                           �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 4 - QUICK SORT                                               �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 5 - MERGE SORT                                               �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 6 - SHELL SORT                                               �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 7 - SAIR                                                     �";
    cout << "  \n        �                                                              �";
    cout << "  \n        ����������������������������������������������������������������\n\n";
 
}

// Menu onde será escolhida a Lista a ser ordenada.
void menu2() {
    system("color 0B");
    cout << "  \n        ����������������������������������������������������������������";
    cout << "  \n        �                                                              �";
    cout << "  \n        �                     INSTÂNCIAS                               �";
    cout << "  \n        �                                                              �";
    cout << "  \n        ����������������������������������������������������������������";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 1 - LISTA ALEATÓRIA - 1000                                   �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 2 - LISTA QUASE ORDENADA - 1000                              �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 3 - LISTA INVERSAMENTE ORDENADA - 1000                       �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 4 - LISTA ORDENADA - 1000                                    �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 5 - LISTA ALEATÓRIA - 10000                                  �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 6 - LISTA QUASE ORDENADA - 10000                             �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 7 - LISTA INVERSAMENTE ORDENADA - 10000                      �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 8 - LISTA ORDENADA - 10000                                   �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 9 - LISTA ALEATÓRIA - 100000                                 �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 10 - LISTA QUASE ORDENADA - 100000                           �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 11 - LISTA INVERSAMENTE ORDENADA - 100000                    �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 12 - LISTA ORDENADA - 100000                                 �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 13 - VOLTAR                                                  �";
    cout << "  \n        �                                                              �";
    cout << "  \n        ����������������������������������������������������������������\n\n";
 
}

// Métodos de Ordenação.
int BubbleSort(int list[], int size, unsigned long long *comparisons) {
    int aux, trade, tradeCount = 0;

    for(int i = 0; i < size-1; i++) {
        trade = 0;
        for(int j = 1; j <size-i; j++) {
            if(list[j] < list[j-1]) {
                aux = list[j];
                list[j] = list[j-1];
                list[j-1] = aux;
                trade = 1;
                tradeCount++;
                (*comparisons)++;
            } else {
                (*comparisons)++;
            }
        }
        if(trade == 0) {
            break;
        }
    }
    return tradeCount;
}

void InsertionSort(int list[], int size, unsigned long long *comparisons) {
    int key, j;

    for (int i=1; i<size; i++) {
        key = list[i];
        j = i-1;
        (*comparisons)++;
        while(j>=0 && list[j] > key) {
            list[j+1] = list[j];           
            j--;  
            (*comparisons)++;  
        }
        list[j+1] = key;
    }
}

void SelectionSort(int list[], int size, unsigned long long *comparisons) {
    int min, aux;

    for(int i=0; i<size-1; i++) {
        min = i;
        for(int j=i+1; j<size; j++) {
            if(list[j] < list[min]) {
                min = j;
                (*comparisons)++;
            } else {
                (*comparisons)++;
            }        
        }
        aux = list[i];
        list[i] = list[min];
        list[min] = aux;
    }
}

void QuickSort(int list[],int left, int right, unsigned long long *comparisons) {

    int temp, i = left, j = right;
    int pivot = list[(left + right) / 2];

    while(i <= j){
        while(list[i] < pivot){
            i++;
        }
        while(list[j] > pivot){
            j--;
        }
        (*comparisons)++;
        if(i <= j){
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
            i++;
            j--;
        }
    }
    (*comparisons)++;
    if(left < j){
        QuickSort(list,left,j,comparisons);
    }
    if(i < right){
        QuickSort(list,i,right,comparisons);
    }
}

// Une 2 subvetores L e M dentro do vetor principal.
void Merge(int list[], int p, int q, int r, unsigned long long *comparisons) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = list[p + i];
    }
        
    for (int j = 0; j < n2; j++) {
        M[j] = list[q + 1 + j];
    }
        
    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= M[j]) {
            list[k] = L[i];
            i++;
        } else {
            list[k] = M[j];
            j++;
        }
            k++;
    }

    while (i < n1) {
        list[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        list[k] = M[j];
        j++;
        k++;
    }
}

// Divide o vetor em 2 subvetores ordenam os 2 e depois os une.
void MergeSort(int list[], int left, int right, unsigned long long *comparisons) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        MergeSort(list, left, middle, comparisons);
        MergeSort(list, middle + 1, right, comparisons);
        Merge(list, left, middle, right, comparisons);
    }
}

void ShellSort(int list[], int size, unsigned long long *comparisons) {
    int h, x, i, j;

    for(h=1; h<size; h=3*h+1);
    while(h>1) {
        h = h/3;
        for(i=h; i<size; i++) {
            x = list[i];
            j = i;
            while(j>=h && list[j-h] > x) {
                list[j] = list[j-h];
                j = j - h;
                (*comparisons)++;
            }
            list[j] = x;
            (*comparisons)++;
        }
    }
}

int ReadInstanceOption() { // Função que armazenará a opção da instância escolhida pelo usuário.
    int instanceOption;

    menu2();
    cout << "Escolha a instância desejada: ";
    cin >> instanceOption;
    system("cls");

    return instanceOption;
}

void ReadFile(int v[], int option, int size) { // Função para realizar a leitura dos arquivos.
    ifstream arq; 

    if(option == 1) {
        arq.open("ListaAleatoria-1000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            for (int i = 0; i < size; i++) {
               arq >> v[i]; 
            }
        }
        arq.close();

    } else if(option == 2) {
        arq.open("ListaQuaseOrdenada-1000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            for (int i = 0; i < size; i++) {
               arq >> v[i]; 
            }
        }
    
        arq.close();

    } else if(option == 3) {
        arq.open("ListaInversamenteOrdenada-1000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            for (int i = 0; i < size; i++) {
               arq >> v[i]; 
            }
        }
    
        arq.close();

    } else if(option == 4) {
        arq.open("ListaOrdenada-1000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            for (int i = 0; i < size; i++) {
               arq >> v[i]; 
            }
        }
    
        arq.close();
    } else if(option == 5) {
        arq.open("ListaAleatoria-10000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            for (int i = 0; i < size; i++) {
               arq >> v[i]; 
            }
        }
    
        arq.close();
    } else if(option == 6) {
        arq.open("ListaQuaseOrdenada-10000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            for (int i = 0; i < size; i++) {
               arq >> v[i]; 
            }
        }
    
        arq.close();
    } else if(option == 7) {
        arq.open("ListaInversamenteOrdenada-10000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            for (int i = 0; i < size; i++) {
               arq >> v[i]; 
            }
        }
    
        arq.close();
    } else if(option == 8) {
        arq.open("ListaOrdenada-10000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            for (int i = 0; i < size; i++) {
               arq >> v[i]; 
            }
        }
    
        arq.close();

    } else if(option == 9) {
        arq.open("ListaAleatoria-100000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            for (int i = 0; i < size; i++) {
               arq >> v[i]; 
            }
        }
        arq.close();

    } else if(option == 10) {
        arq.open("ListaQuaseOrdenada-100000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            for (int i = 0; i < size; i++) {
               arq >> v[i]; 
            }
        }
    
        arq.close();

    } else if(option == 11) {
        arq.open("ListaInversamenteOrdenada-100000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            for (int i = 0; i < size; i++) {
               arq >> v[i]; 
            }
        }
    
        arq.close();

    } else if(option == 12) {
        arq.open("ListaOrdenada-100000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            for (int i = 0; i < size; i++) {
               arq >> v[i]; 
            }
        }
    
        arq.close();
    }
}

void PrintArray(int v[], int size) {
    for(int i = 0; i < size; i++) { 
        cout << v[i] << " ";
    }
    cout << endl << endl;
}

//Função que irá gravar os dados das análises no arquivo
void WriteFile(long double elapsedTime, unsigned long long comparisons, int methodOption, int instanceOption) { 
    ofstream arq("Analises.txt", ios::app);

    if(!arq.fail()) {
        if(methodOption == 1 && instanceOption == 1) { // Compara o que será gravado baseada nas escolhas de método e instâncias feitas pelo usuário
            arq << "Método utilizado: BubbleSort - Lista aleatória de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 1 && instanceOption == 2) {
            arq << endl << "Método utilizado: BubbleSort - Lista quase ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 1 && instanceOption == 3) {
            arq << endl << "Método utilizado: BubbleSort - Lista inversamente ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 1 && instanceOption == 4) {
            arq << endl << "Método utilizado: BubbleSort - Lista ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 1 && instanceOption == 5) {
            arq << endl << "Método utilizado: Insertion - Lista aleatória de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 1 && instanceOption == 6) {
            arq << endl << "Método utilizado: BubbleSort - Lista quase ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 1 && instanceOption == 7) {
            arq << endl << "Método utilizado: BubbleSort - Lista inversamente ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 1 && instanceOption == 8) {
            arq << endl << "Método utilizado: BubbleSort - Lista ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 1 && instanceOption == 9) {
            arq << endl << "Método utilizado: BubbleSort - Lista aleatória de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 1 && instanceOption == 10) {
            arq << endl << "Método utilizado: BubbleSort - Lista quase ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 1 && instanceOption == 11) {
            arq << endl << "Método utilizado: BubbleSort - Lista inversamente ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 1 && instanceOption == 12) {
            arq << endl << "Método utilizado: BubbleSort - Lista ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 2 && instanceOption == 1) {
            arq << endl << "Método utilizado: InsertionSort - Lista aleatória de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 2 && instanceOption == 2) {
            arq << endl << "Método utilizado: InsertionSort - Lista quase ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 2 && instanceOption == 3) {
            arq << endl << "Método utilizado: InsertionSort - Lista inversamente ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 2 && instanceOption == 4) {
            arq << endl << "Método utilizado: InsertionSort - Lista ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 2 && instanceOption == 5) {
            arq << endl << "Método utilizado: InsertionSort - Lista aleatória de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 2 && instanceOption == 6) {
            arq << endl << "Método utilizado: InsertionSort - Lista quase ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 2 && instanceOption == 7) {
            arq << endl << "Método utilizado: InsertionSort - Lista inversamente ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 2 && instanceOption == 8) {
            arq << endl << "Método utilizado: InsertionSort - Lista ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 2 && instanceOption == 9) {
            arq << endl << "Método utilizado: InsertionSort - Lista aleatória de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 2 && instanceOption == 10) {
            arq << endl << "Método utilizado: InsertionSort - Lista quase ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 2 && instanceOption == 11) {
            arq << endl << "Método utilizado: InsertionSort - Lista inversamente ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 2 && instanceOption == 12) {
            arq << endl << "Método utilizado: InsertionSort - Lista ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 3 && instanceOption == 1) {
            arq << endl << "Método utilizado: SelectionSort - Lista aleatória de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 3 && instanceOption == 2) {
            arq << endl << "Método utilizado: SelectionSort - Lista quase ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 3 && instanceOption == 3) {
            arq << endl << "Método utilizado: SelectionSort - Lista inversamente ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 3 && instanceOption == 4) {
            arq << endl << "Método utilizado: SelectionSort - Lista ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 3 && instanceOption == 5) {
            arq << "Método utilizado: SelectionSort - Lista aleatória de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 3 && instanceOption == 6) {
            arq << endl << "Método utilizado: SelectionSort - Lista quase ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 3 && instanceOption == 7) {
            arq << endl << "Método utilizado: SelectionSort - Lista inversamente ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 3 && instanceOption == 8) {
            arq << endl << "Método utilizado: SelectionSort - Lista ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 3 && instanceOption == 9) {
            arq << endl << "Método utilizado: SelectionSort - Lista aleatória de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 3 && instanceOption == 10) {
            arq << endl << "Método utilizado: SelectionSort - Lista quase ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 3 && instanceOption == 11) {
            arq << endl << "Método utilizado: SelectionSort - Lista inversamente ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 3 && instanceOption == 12) {
            arq << endl << "Método utilizado: SelectionSort - Lista ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 4 && instanceOption == 1) {
            arq << endl << "Método utilizado: QuickSort - Lista aleatória de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 4 && instanceOption == 2) {
            arq << endl << "Método utilizado: QuickSort - Lista quase ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 4 && instanceOption == 3) {
            arq << endl << "Método utilizado: QuickSort - Lista inversamente ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 4 && instanceOption == 4) {
            arq << endl << "Método utilizado: QuickSort - Lista ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 4 && instanceOption == 5) {
            arq << endl << "Método utilizado: QuickSort - Lista aleatória de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 4 && instanceOption == 6) {
            arq << endl << "Método utilizado: QuickSort - Lista quase ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 4 && instanceOption == 7) {
            arq << endl << "Método utilizado: QuickSort - Lista inversamente ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 4 && instanceOption == 8) {
            arq << endl << "Método utilizado: QuickSort - Lista ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 4 && instanceOption == 9) {
            arq << endl << "Método utilizado: QuickSort - Lista aleatória de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 4 && instanceOption == 10) {
            arq << endl << "Método utilizado: QuickSort - Lista quase ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 4 && instanceOption == 11) {
            arq << endl << "Método utilizado: QuickSort - Lista inversamente ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 4 && instanceOption == 12) {
            arq << endl << "Método utilizado: QuickSort - Lista ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 5 && instanceOption == 1) {
            arq << endl << "Método utilizado: MergeSort - Lista aleatória de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 5 && instanceOption == 2) {
            arq << endl << "Método utilizado: MergeSort - Lista quase ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 5 && instanceOption == 3) {
            arq << endl << "Método utilizado: MergeSort - Lista inversamente ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 5 && instanceOption == 4) {
            arq << endl << "Método utilizado: MergeSort - Lista ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 5 && instanceOption == 5) {
            arq << "Método utilizado: MergeSort - Lista aleatória de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 5 && instanceOption == 6) {
            arq << endl << "Método utilizado: MergeSort - Lista quase ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 5 && instanceOption == 7) {
            arq << endl << "Método utilizado: MergeSort - Lista inversamente ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 5 && instanceOption == 8) {
            arq << endl << "Método utilizado: MergeSort - Lista ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 5 && instanceOption == 9) {
            arq << endl << "Método utilizado: MergeSort - Lista aleatória de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 5 && instanceOption == 10) {
            arq << endl << "Método utilizado: MergeSort - Lista quase ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 5 && instanceOption == 11) {
            arq << endl << "Método utilizado: MergeSort - Lista inversamente ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 5 && instanceOption == 12) {
            arq << endl << "Método utilizado: MergeSort - Lista ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 6 && instanceOption == 1) {
            arq << endl << "Método utilizado: ShellSort - Lista aleatória de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 6 && instanceOption == 2) {
            arq << endl << "Método utilizado: ShellSort - Lista quase ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 6 && instanceOption == 3) {
            arq << endl << "Método utilizado: ShellSort - Lista inversamente ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 6 && instanceOption == 4) {
            arq << endl << "Método utilizado: ShellSort - Lista ordenada de 1000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 6 && instanceOption == 5) {
            arq << endl << "Método utilizado: ShellSort - Lista aleatória de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 6 && instanceOption == 6) {
            arq << endl << "Método utilizado: ShellSort - Lista quase ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 6 && instanceOption == 7) {
            arq << endl << "Método utilizado: ShellSort - Lista inversamente ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 6 && instanceOption == 8) {
            arq << endl << "Método utilizado: ShellSort - Lista ordenada de 10000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 6 && instanceOption == 9) {
            arq << endl << "Método utilizado: ShellSort - Lista aleatória de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 6 && instanceOption == 10) {
            arq << endl << "Método utilizado: ShellSort - Lista quase ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 6 && instanceOption == 11) {
            arq << endl << "Método utilizado: ShellSort - Lista inversamente ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } else if(methodOption == 6 && instanceOption == 12) {
            arq << endl << "Método utilizado: ShellSort - Lista ordenada de 100000!";
            arq << endl << "Tempo decorrido: " << elapsedTime << " segundos.";
            arq << endl << "Comparacoes: " << comparisons;

        } 
    } 
    arq.close();
}

// Funções que irão ordernar de fato os arquivos
void SortFile1000(int v1[], int option, int op) {  // Função que irá ordernar os arquivos de tamanho 1.000.
    unsigned long long comparisons = 0;
    clock_t startCount, endCount; // Variáveis que receberão a contagem do inicio e fim da ordenação.
    long double clockCount, elapsedTime; // Variáveis que receberão respectivamente o tempo de execução e a conversão para segundos.

    ReadFile(v1, op, tam1); // Chamada da função que lê o arquivo;

    if(option == 1) {
        startCount = clock(); // Inicio da contagem.
        BubbleSort(v1, tam1, &comparisons);        // Ordenando os números presentes no arquivo.
        endCount = clock();   //Encerramento da contagem.

        clockCount = endCount - startCount; // Calculando o tempo de execução.
        elapsedTime = clockCount / CLOCKS_PER_SEC; // Faz a conversão para segundos.
        
        PrintArray(v1, tam1);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op); //Realiza a gravação no arquivo.

    } else if(option == 2) {
        startCount = clock(); 
        InsertionSort(v1, tam1, &comparisons);        
        endCount = clock();  

        clockCount = endCount - startCount; 
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v1, tam1);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op); 

    } else if(option == 3) {
        startCount = clock(); 
        SelectionSort(v1, tam1, &comparisons);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v1, tam1);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op); 

    } else if(option == 4) {
        startCount = clock(); 
        QuickSort(v1,0, tam1, &comparisons);   
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v1, tam1);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op);

    }  else if(option == 5) {
        startCount = clock(); 
        MergeSort(v1, 0, tam1 - 1, &comparisons);     
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v1, tam1);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op);

    } else if(option == 6) {
        startCount = clock(); 
        ShellSort(v1, tam1, &comparisons);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v1, tam1); 
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op);

    }
}
void SortFile10000(int v2[], int option, int op) { // Função que irá ordernar os arquivos de tamanho 10.000.
    unsigned long long comparisons = 0;
    clock_t startCount, endCount;
    long double clockCount, elapsedTime;
 
    ReadFile(v2, op, tam2);
    if(option == 1) {
        startCount = clock();
        BubbleSort(v2, tam2, &comparisons);       
        endCount = clock();  

        clockCount = endCount - startCount; 
        elapsedTime = clockCount / CLOCKS_PER_SEC;

        PrintArray(v2, tam2);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op);

    } else if(option == 2) {
        startCount = clock(); 
        InsertionSort(v2, tam2, &comparisons); 
        endCount = clock(); 

        clockCount = endCount - startCount; 
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v2, tam2);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op);

    } else if(option == 3) {
        startCount = clock(); 
        SelectionSort(v2, tam2, &comparisons);      
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC;

        PrintArray(v2, tam2);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op);

    } else if(option == 4) {
        startCount = clock(); 
        QuickSort(v2, 0, tam2, &comparisons);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v2, tam2);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op);

    }  else if(option == 5) {
        startCount = clock(); 
        MergeSort(v2, 0, tam2 - 1, &comparisons);        
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v2, tam2);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op);

    } else if(option == 6) {
        startCount = clock(); 
        ShellSort(v2, tam2, &comparisons);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v2, tam2); 
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op);
    }
}
void SortFile100000(int v3[], int option, int op) { // Função que irá ordernar os arquivos de tamanho 100.000.
    unsigned long long comparisons = 0;
    clock_t startCount, endCount;
    long double clockCount, elapsedTime;

    ReadFile(v3, op, tam3);

    if(option == 1) {
        startCount = clock(); 
        BubbleSort(v3, tam3, &comparisons);       
        endCount = clock(); 

        clockCount = endCount - startCount; 
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v3, tam3); 
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op);

    }else if(option == 2) {
        startCount = clock(); 
        InsertionSort(v3, tam3, &comparisons); 
        endCount = clock(); 

        clockCount = endCount - startCount; 
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v3, tam3);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op);

    } else if(option == 3) {
        startCount = clock(); 
        SelectionSort(v3, tam3, &comparisons);      
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC;

        PrintArray(v3, tam3);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op);

    } else if(option == 4) {
        startCount = clock(); 
        QuickSort(v3, 0, tam3, &comparisons);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v3, tam3);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op);

    }  else if(option == 5) {
        startCount = clock(); 
        MergeSort(v3, 0, tam3 - 1, &comparisons);        
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v3, tam3);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op);

    } else if(option == 6) {
        startCount = clock(); 
        ShellSort(v3, tam3, &comparisons);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v3, tam3); 
        cout  << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
        cout << endl << "Comparacoes: " << comparisons << endl;

        WriteFile(elapsedTime, comparisons, option, op);
    }
}

void CallUserOption(int option, int op) { //Função que vai armazenar e tratar a opção escolhida pelo usuário.
    if((option == 1) && (op  == 1 || op == 2 || op == 3 || op == 4)) {
        SortFile1000(v1, option, op);  
    } else if((option == 1) && (op  == 5 || op == 6 || op == 7 || op == 8)) {
        SortFile10000(v2, option, op); 
    } else if((option == 1) && (op  == 9 || op == 10 || op == 11 || op == 12)) {
        SortFile100000(v3, option, op); 
    } else if((option == 2) && (op  == 1 || op == 2 || op == 3 || op == 4)) {
        SortFile1000(v1, option, op);  
    } else if((option == 2) && (op  == 5 || op == 6 || op == 7 || op == 8)) {
        SortFile10000(v2, option, op); 
    } else if((option == 2) && (op  == 9 || op == 10 || op == 11 || op == 12)) {
        SortFile100000(v3, option, op); 
    } else if((option == 3) && (op  == 1 || op == 2 || op == 3 || op == 4)) {
        SortFile1000(v1, option, op);  
    } else if((option == 3) && (op  == 5 || op == 6 || op == 7 || op == 8)) {
        SortFile10000(v2, option, op); 
    } else if((option == 3) && (op  == 9 || op == 10 || op == 11 || op == 12)) {
        SortFile100000(v3, option, op); 
    } else if((option == 4) && (op  == 1 || op == 2 || op == 3 || op == 4)) {
        SortFile1000(v1, option, op);  
    } else if((option == 4) && (op  == 5 || op == 6 || op == 7 || op == 8)) {
        SortFile10000(v2, option, op); 
    } else if((option == 4) && (op  == 9 || op == 10 || op == 11 || op == 12)) {
        SortFile100000(v3, option, op); 
    } else if((option == 5) && (op  == 1 || op == 2 || op == 3 || op == 4)) {
        SortFile1000(v1, option, op);  
    } else if((option == 5) && (op  == 5 || op == 6 || op == 7 || op == 8)) {
        SortFile10000(v2, option, op); 
    } else if((option == 5) && (op  == 9 || op == 10 || op == 11 || op == 12)) {
        SortFile100000(v3, option, op); 
    } else if((option == 6) && (op  == 1 || op == 2 || op == 3 || op == 4)) {
        SortFile1000(v1, option, op);  
    } else if((option == 6) && (op  == 5 || op == 6 || op == 7 || op == 8)) {
        SortFile10000(v2, option, op); 
    } else if((option == 6) && (op  == 9 || op == 10 || op == 11 || op == 12)) {
        SortFile100000(v3, option, op); 
    } 
} // Baseado na escolha do usuário, essa função entenderá qual método e instância deseja se utilizar.


