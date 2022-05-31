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
int BubbleSort(int list[], int size) {
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
            } 
        }
        if(trade == 0) {
            break;
        }
    }
    return tradeCount;
}

void InsertionSort(int list[], int size) {
    int key, j;

    for (int i=1; i<size; i++) {
        key = list[i];
        j = i-1;

        while(j>=0 && list[j] > key) {
            list[j+1] = list[j];           
            j--;    
        }
        list[j+1] = key;

        // cout << i << "º Passo" << endl;
        // for(int i=0; i<n; i++) {
        //         cout << list[i] << " ";
        //     } 
        // cout << endl; 
    }

    // cout<< "\n" << "Resultado final" << endl;
    // for(int i=0; i<size; i++) {
    //     cout << list[i] << " ";
    // }  
}

void SelectionSort(int list[], int size) {
    int min, aux;

    for(int i=0; i<size-1; i++) {
        min = i;
        for(int j=i+1; j<size; j++) {
            if(list[j] < list[min]) {
                min = j;
            }            
        }
        aux = list[i];
        list[i] = list[min];
        list[min] = aux;

    //     cout << i+1 << "º Passo" << endl;
    //     for(int i=0; i<n; i++) {
    //             cout << list[i] << " ";
    //         } 
    //     cout << endl; 
    }
}

int compare(const void *a, const void *b) { // função que complementa o Quick Sort.
    const int *x = (int *)a;
    const int *y = (int *)b;

    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;

    return 0;
}

// Une 2 subvetores L e M dentro do vetor principal.
void Merge(int list[], int p, int q, int r) {

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
void MergeSort(int list[], int left, int right) {
    if (left < right) {
        // middle é o ponto onde o vetor é dividido em 2 subvetores.
        int middle = left + (right - left) / 2;

        MergeSort(list, left, middle);
        MergeSort(list, middle + 1, right);

        // Une os subvetores ordenados.
        Merge(list, left, middle, right);
    }
}

void ShellSort(int list[], int size) {
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

                // cout << i << "º Passo" << endl;
                // for(int i=0; i<n; i++) {
                //     cout << list[i] << " ";
                // }
            }
            list[j] = x;
        }
    }
}

int ReadOptionInstance() { // Função que armazenará a opção da instância escolhida pelo usuário.
    int optionInstance;

    menu2();
    cout << "Escolha a instância desejada: ";
    cin >> optionInstance;
    system("cls");

    return optionInstance;
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

// Funções que irão ordernar de fato os arquivos
void SortFile1000(int v1[], int option, int op) {  // Função que irá ordernar os arquivos de tamanho 1.000.
    clock_t startCount, endCount; // Variáveis que receberão a contagem do inicio e fim da ordenação.
    long double clockCount, elapsedTime; // Variáveis que receberão respectivamente o tempo de execução e a conversão para segundos.

    ReadFile(v1, op, tam1); // Chamada da função que lê o arquivo;

    if(option == 1) {
        startCount = clock(); // Inicio da contagem.
        BubbleSort(v1, tam1);        // Ordenando os números presentes no arquivo.
        endCount = clock();   //Encerramento da contagem.

        clockCount = endCount - startCount; // Calculando o tempo de execução.
        elapsedTime = clockCount / CLOCKS_PER_SEC; // Faz a conversão para segundos.
        
        PrintArray(v1, tam1);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;

    } else if(option == 2) {
        startCount = clock(); 
        InsertionSort(v1, tam1);        
        endCount = clock();  

        clockCount = endCount - startCount; 
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v1, tam1);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;

    } else if(option == 3) {
        startCount = clock(); 
        SelectionSort(v1, tam1);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v1, tam1);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;

    } else if(option == 4) {
        startCount = clock(); 
        qsort(v1, tam1, sizeof(int), compare);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v1, tam1);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;

    }  else if(option == 5) {
        startCount = clock(); 
        MergeSort(v1, 0, tam1 - 1);     
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v1, tam1);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;

    } else if(option == 6) {
        startCount = clock(); 
        ShellSort(v1, tam1);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v1, tam1); 
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
    }
}
void SortFile10000(int v2[], int option, int op) { // Função que irá ordernar os arquivos de tamanho 10.000.
    clock_t startCount, endCount;
    long double clockCount, elapsedTime;

    ReadFile(v2, op, tam2);
    if(option == 1) {
        startCount = clock();
        BubbleSort(v2, tam2);       
        endCount = clock();  

        clockCount = endCount - startCount; 
        elapsedTime = clockCount / CLOCKS_PER_SEC;

        PrintArray(v2, tam2);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;

    } else if(option == 2) {
        startCount = clock(); 
        InsertionSort(v2, tam2); 
        endCount = clock(); 

        clockCount = endCount - startCount; 
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v2, tam2);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;

    } else if(option == 3) {
        startCount = clock(); 
        SelectionSort(v2, tam2);      
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC;

        PrintArray(v2, tam2);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;

    } else if(option == 4) {
        startCount = clock(); 
        qsort(v2, tam2, sizeof(int), compare);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v2, tam2);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;

    }  else if(option == 5) {
        startCount = clock(); 
        MergeSort(v2, 0, tam2 - 1);        
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v2, tam2);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;

    } else if(option == 6) {
        startCount = clock(); 
        ShellSort(v2, tam2);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v2, tam2); 
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
    }
}
void SortFile100000(int v3[], int option, int op) { // Função que irá ordernar os arquivos de tamanho 100.000.
    clock_t startCount, endCount;
    long double clockCount, elapsedTime;

    ReadFile(v3, op, tam3);

    if(option == 1) {
        startCount = clock(); 
        BubbleSort(v3, tam3);       
        endCount = clock(); 

        clockCount = endCount - startCount; 
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v3, tam3); 
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;

    }else if(option == 2) {
        startCount = clock(); 
        InsertionSort(v3, tam3); 
        endCount = clock(); 

        clockCount = endCount - startCount; 
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v3, tam3);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;

    } else if(option == 3) {
        startCount = clock(); 
        SelectionSort(v3, tam3);      
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC;

        PrintArray(v3, tam3);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;

    } else if(option == 4) {
        startCount = clock(); 
        qsort(v3, tam3, sizeof(int), compare);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v3, tam3);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;

    }  else if(option == 5) {
        startCount = clock(); 
        MergeSort(v3, 0, tam3 - 1);        
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v3, tam3);
        cout << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;

    } else if(option == 6) {
        startCount = clock(); 
        ShellSort(v3, tam3);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v3, tam3); 
        cout  << endl << "Tempo decorrido: " << elapsedTime << " segundos." << endl;
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

