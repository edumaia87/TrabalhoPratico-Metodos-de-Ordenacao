#include <iostream>
#include <fstream>
#include <time.h>
#include <windows.h>
#include "Sort.hpp"
#define tam1 1000
#define tam2 10000
#define tam3 100000
using namespace std;

int v1[tam1]; //Vetor para as Listas de tamanho 1000
int v2[tam2]; //Vetor para as Listas de tamanho 10000
int v3[tam3]; //Vetor para as Listas de tamanho 100000

//Menu Principal.
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

//Menu onde será escolhida a Lista a ser ordenada.
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

void CallMenu(int optionSort, int optionInstance) {
    do {
        menu2();
        cout << "Escolha a instância desejada: ";

        cin >> optionInstance;
        system("cls");

        switch(optionInstance) {
            case 1:
                //SortFile1000(arq, v1, tamanho, optionSort, optionInstance);  
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
        }
    } while (optionInstance!= 7);

    system("pause");
}

//Métodos de Ordenação.
int BubbleSort(int list[], int size) {
    int aux, trade, tradeCount = 0;

    for(int i = 0; i < size-1; i++) {
        trade = 0;
        for(int j = 1; j <size-i; j++) {
            if(list[j] > list[j-1]) {
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
            cout << endl;
        }
    }
}

// Funções para realizar a leitura dos arquivos.
int ReadFile1000(ifstream &arq, int v[], int option) { 
    int count = 0;

    //CallMenu(option, optionInstance);
    if(option == 1) {
        arq.open("ListaAleatoria-1000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            while(!arq.eof()) {
                arq >> v[count]; 
                count++;
            }
        }
        arq.close();

    } else if(option == 2) {
        ifstream arq;
        arq.open("ListaQuaseOrdenada-1000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            while(!arq.eof()) {
                arq >> v[count]; 
                count++;
            }
        }
    
        arq.close();

    } else if(option == 3) {
        ifstream arq;
        arq.open("ListaInversamenteOrdenada-1000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            while(!arq.eof()) {
                arq >> v[count]; 
                count++;
            }
        }
    
        arq.close();

    } else if(option == 4) {
        ifstream arq;
        arq.open("ListaOrdenada-1000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            while(!arq.eof()) {
                arq >> v[count]; 
                count++;
            }
        }
    
        arq.close();
    } else {
        cerr << "Opção inválida";
    }   
}

int ReadFile10000(ifstream &arq, int v1[], int option) {
    int count = 0;
    
    if(option == 1) {
        ifstream arq;
        arq.open("ListaAleatoria-10000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            while(!arq.eof()) {
                arq >> v1[count]; 
                count++;
            }
        }
    
        arq.close();
        
    } else if(option == 2) {
        ifstream arq;
        arq.open("ListaQuaseOrdenada-10000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            while(!arq.eof()) {
                arq >> v1[count]; 
                count++;
            }
        }
    
        arq.close();

    } else if(option == 3) {
        ifstream arq;
        arq.open("ListaInversamenteOrdenada-10000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            while(!arq.eof()) {
                arq >> v1[count]; 
                count++;
            }
        }
    
        arq.close();

    } else if(option == 4) {
        ifstream arq;
        arq.open("ListaOrdenada-10000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            while(!arq.eof()) {
                arq >> v1[count]; 
                count++;
            }
        }
    
    arq.close();

    } else {
        cerr << "Opção inválida";
    }   
}

int ReadFile100000(ifstream &arq, int v2[], int option) {
    int count = 0;
    if(option == 1) {
        ifstream arq;
        arq.open("ListaAleatoria-100000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            while(!arq.eof()) {
                arq >> v2[count]; 
                count++;
            }
        }
    
    arq.close();
        
    } else if(option == 2) {
        ifstream arq;
        arq.open("ListaQuaseOrdenada-100000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            while(!arq.eof()) {
                arq >> v2[count]; 
                count++;
            }
        }
    
    arq.close();

    } else if(option == 3) {
        ifstream arq;
        arq.open("ListaInversamenteOrdenada-100000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            while(!arq.eof()) {
                arq >> v2[count]; 
                count++;
            }
        }
    
    arq.close();

    } else if(option == 4) {
        ifstream arq;
        arq.open("ListaOrdenada-100000.txt");

        if (arq.fail()) {
            cerr << "Houve um problema ao criar o arquivo!\n";
            arq.clear();
        } else {
            while(!arq.eof()) {
                arq >> v2[count]; 
                count++;
            }
        }
    
        arq.close();

    } else {
        cerr << "Opção inválida";
    }  
}

void PrintArray(int v[], int size){
    for(int i = 0; i < size; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

// Funções que irão ordernar de fato os arquivos
int SortFile1000(ifstream &arq, int v1[], int size, int option, int op) {
    clock_t startCount, endCount; // Variáveis que receberão a contagem do inicio e fim da ordenação.
    long double clockCount, elapsedTime; // Variáveis que receberão respectivamente o tempo de execução e a conversão para segundos.

    ReadFile1000(arq, v1, op); // Chamada da função que lê os arquivos de tamanho 1000.

    if(option == 1) {
        startCount = clock(); // Inicio da contagem.
        BubbleSort(v1, size);        // Ordenando os números presentes no arquivo.
        endCount = clock();   //Encerramento da contagem.

        clockCount = endCount - startCount; // Calculando o tempo de execução.
        elapsedTime = clockCount / CLOCKS_PER_SEC; // Faz a conversão para segundos.

    } else if(option == 2) {
        startCount = clock(); 
        InsertionSort(v1, size);        
        endCount = clock();  

        clockCount = endCount - startCount; 
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v1, tam1);

    } else if(option == 3) {
        startCount = clock(); 
        SelectionSort(v1, size);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v1, tam1);

    } else if(option == 4) {
        startCount = clock(); 
        //QuickSort(v, size);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v1, tam1);
        
    }  else if(option == 5) {
        startCount = clock(); 
        //MergeSort(v, size);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v1, tam1);
        
    } else if(option == 6) {
        startCount = clock(); 
        ShellSort(v1, size);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v1, tam1); 
    }
}
void SortFile10000(ifstream arq, int v2[], int size, int option, int op) {
    clock_t startCount, endCount;
    long double clockCount, elapsedTime;

    ReadFile10000(arq, v2, option);
    if(op == 1) {
        startCount = clock(); // Inicio da contagem.
        BubbleSort(v2, size);        // Ordenando os números presentes no arquivo.
        endCount = clock();   //Encerramento da contagem.

        clockCount = endCount - startCount; // Calculando o tempo de execução.
        elapsedTime = clockCount / CLOCKS_PER_SEC; // Faz a conversão para segundos.

        PrintArray(v2, tam2);

    } else if(op == 2) {
        startCount = clock(); 
        InsertionSort(v2, tam2); 
        endCount = clock(); 

        clockCount = endCount - startCount; 
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v2, tam2);

    } else if(op == 3) {
        startCount = clock(); 
        SelectionSort(v2, size);      
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC;

        PrintArray(v2, tam2);

    } else if(op == 4) {
        startCount = clock(); 
        //QuickSort(v2, size);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v2, tam2);
        
    }  else if(op == 5) {
        startCount = clock(); 
        //MergeSort(v2, size);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v2, tam2);
        
    } else if(op == 6) {
        startCount = clock(); 
        ShellSort(v2, size);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v2, tam2); 
    }
}
void SortFile100000(ifstream arq, int v3[], int size, int option, int op) {
    clock_t startCount, endCount;
    long double clockCount, elapsedTime;

    ReadFile100000(arq, v3, option);

    if(op == 1) {
        startCount = clock(); 
        BubbleSort(v3, size);       
        endCount = clock(); 

        clockCount = endCount - startCount; 
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        //PrintArray();
    }else if(op == 2) {
        startCount = clock(); 
        InsertionSort(v3, size); 
        endCount = clock(); 

        clockCount = endCount - startCount; 
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v3, tam3);

    } else if(op == 3) {
        startCount = clock(); 
        SelectionSort(v3, size);      
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC;

        PrintArray(v3, tam3);

    } else if(op == 4) {
        startCount = clock(); 
        //QuickSort(v3, size);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v3, tam3);
        
    }  else if(op == 5) {
        startCount = clock(); 
        //MergeSort(v3, size);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v3, tam3);
        
    } else if(op == 6) {
        startCount = clock(); 
        ShellSort(v3, size);       
        endCount = clock();  

        clockCount = endCount - startCount;
        elapsedTime = clockCount / CLOCKS_PER_SEC; 

        PrintArray(v3, tam3); 
    }
}

