#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>
#define tam 1000

using namespace std;

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

void PrintArray(int v[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        cout << v[i] << " ";
    }
    cout << endl << endl;
}

int teste() {
    int optionInstance;

    menu2();
    cout << "Escolha a instância desejada: ";
    cin >> optionInstance;
    system("cls");

    return optionInstance;
}

void ReadFile1000(ifstream &arq, int v[], int option) { 
    int count = 0;

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

int SortFile1000(ifstream &arq, int v1[], int size, int option) {
    clock_t startCount, endCount; // Variáveis que receberão a contagem do inicio e fim da ordenação.
    long double clockCount, elapsedTime; // Variáveis que receberão respectivamente o tempo de execução e a conversão para segundos.

    ReadFile1000(arq, v1, option); // Chamada da função que lê os arquivos de tamanho 1000.

    if(option == 1) {
        startCount = clock(); // Inicio da contagem.
        BubbleSort(v1, size);        // Ordenando os números presentes no arquivo.
        endCount = clock();   //Encerramento da contagem.

        clockCount = endCount - startCount; // Calculando o tempo de execução.
        elapsedTime = clockCount / CLOCKS_PER_SEC; // Faz a conversão para segundos.

        PrintArray(v1, size);
    // } else if(option == 2) {
    //     startCount = clock(); 
    //     InsertionSort(v1, size);        
    //     endCount = clock();  

    //     clockCount = endCount - startCount; 
    //     elapsedTime = clockCount / CLOCKS_PER_SEC; 

    //     PrintArray(v1, tam1);

    // } else if(option == 3) {
    //     startCount = clock(); 
    //     SelectionSort(v1, size);       
    //     endCount = clock();  

    //     clockCount = endCount - startCount;
    //     elapsedTime = clockCount / CLOCKS_PER_SEC; 

        

    // } else if(option == 4) {
    //     startCount = clock(); 
    //     //QuickSort(v, size);       
    //     endCount = clock();  

    //     clockCount = endCount - startCount;
    //     elapsedTime = clockCount / CLOCKS_PER_SEC; 

    //    // PrintArray(v1, tam1);
        
    // }  else if(option == 5) {
    //     startCount = clock(); 
    //     //MergeSort(v, size);       
    //     endCount = clock();  

    //     clockCount = endCount - startCount;
    //     elapsedTime = clockCount / CLOCKS_PER_SEC; 

        //PrintArray(v1, tam1);
        
    } //else if(option == 6) {
    //     startCount = clock(); 
    //     ShellSort(v1, size);       
    //     endCount = clock();  

    //     clockCount = endCount - startCount;
    //     elapsedTime = clockCount / CLOCKS_PER_SEC; 

    //     //PrintArray(v1, tam1); 
    // }

    return elapsedTime;
}

void CallMenu(ifstream &arq, int v1[], int size, int option) {
    option = teste();
    do {
        if(option == 1) {
            SortFile1000(arq, v1, size, 1);  
        }
    } while(option != 7);
}

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    
    ifstream arq;
    int v[tam], option;

    do {
        menu();
        cout << "Escolha uma opção: ";
        cin >> option;
        switch(option) {
            case 1:
                int op = teste();
                CallMenu(arq, v, tam, op);
                break;
            // case 2:
            //     ReadFile1000(arq, v, option);
            //     //ImprimeVetor(v, tam); 
            //     break;
            // case 3:
            //     ReadFile1000(arq, v, option);
            //    // ImprimeVetor(v, tam); 
            //     break;
            // case 4:
            //     ReadFile1000(arq, v, option); 
            //    // ImprimeVetor(v, tam);
            //     break;
        }
    } while(option != 5);

    return 0;
}